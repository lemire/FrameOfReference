/**
*
* This code is released under the
* Apache License Version 2.0 http://www.apache.org/licenses/.
* (c) Daniel Lemire 2013
*/

#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#ifdef _OPENMP
#include <omp.h>
#endif
#include <cmath>
#include <iomanip>
#include <fstream>
#include "bpacking.h"
#include "compression.h"
#include "turbocompression.h"

using namespace std;

class WallClockTimer {
public:
  struct timeval t1, t2;

public:
  WallClockTimer() : t1(), t2() {
    gettimeofday(&t1, 0);
    t2 = t1;
  }
  void reset() {
    gettimeofday(&t1, 0);
    t2 = t1;
  }
  int elapsed() {
    return ((t2.tv_sec - t1.tv_sec) * 1000) +
           ((t2.tv_usec - t1.tv_usec) / 1000);
  }
  int split() {
    gettimeofday(&t2, 0);
    return elapsed();
  }
};

void displayUsage() { cout << "run as test nameoffile" << endl; }

vector<uint32_t> loadVector(string filename) {
  vector<uint32_t> answer;
  answer.reserve(1024 * 32); // expect sizeable arrays
  ifstream logFile(filename.c_str());
  if (!logFile.is_open()) {
    cerr << " Couldn't open query vector file " << filename << endl;
    displayUsage();
    return answer;
  }
  cout << "# Parsing vector file " << filename << endl;

  logFile.exceptions(ios::badbit); // will throw an exception if something goes
                                   // wrong, saves us the trouble of checking
                                   // the IO status
  string line;
  for (; logFile && getline(logFile, line);) {
    uint32_t id = atoi(line.c_str());
    answer.push_back(id);
  }
  return answer;
}

void unit() {
  vector<uint32_t> test;
  for (uint32_t i = 0; i < 100; ++i)
    test.push_back(i);
  vector<uint32_t> comp(test.size() + 1024);
  vector<uint32_t> recover(test.size() + 1024);

  compress(test.data(), test.size(), comp.data());
  uint32_t nvalue = 0;
  uncompress(comp.data(), recover.data(), nvalue);
  recover.resize(nvalue);

  if (recover != test)
    throw runtime_error("bug");
}

void deepunit() {
  for (int k = 0; k < 32; ++k) {
    vector<uint32_t> test;
    for (uint32_t i = 0; i < 100; ++i) {
      test.push_back(0);
      test.push_back(0xFFFFFFFF >> k);
    }
    vector<uint32_t> comp(test.size() + 1024);
    vector<uint32_t> recover(test.size() + 1024);

    compress(test.data(), test.size(), comp.data());
    uint32_t nvalue = 0;
    uncompress(comp.data(), recover.data(), nvalue);
    recover.resize(nvalue);

    if (recover != test)
      throw runtime_error("bug");
  }
}

void turbounit() {
  vector<uint32_t> test;
  for (uint32_t i = 0; i < 100; ++i)
    test.push_back(i);
  vector<uint8_t> comp(4 * test.size() + 1024);
  vector<uint32_t> recover(test.size() + 1024);

  turbocompress(test.data(), test.size(), comp.data());
  uint32_t nvalue = 0;
  turbouncompress(comp.data(), recover.data(), nvalue);

  recover.resize(nvalue);

  if (recover != test)
    throw runtime_error("bug");
}

void turbodeepunit() {
  for (int k = 31; k >= 0; --k) {
    vector<uint32_t> test;
    for (uint32_t i = 0; i < 100; ++i) {
      test.push_back(0);
      test.push_back(0xFFFFFFFF >> k);
    }
    vector<uint8_t> comp(test.size() * 4 + 1024);
    vector<uint32_t> recover(test.size() + 1024);

    turbocompress(test.data(), test.size(), comp.data());
    uint32_t nvalue = 0;
    turbouncompress(comp.data(), recover.data(), nvalue);
    recover.resize(nvalue);
    if (recover != test) {
      throw runtime_error("bug");
    }
  }
}


void turbounit64() {
  vector<uint64_t> test;
  for (uint64_t i = 0; i < 100; ++i)
    test.push_back(i);
  vector<uint8_t> comp(4 * test.size() + 1024);
  vector<uint64_t> recover(test.size() + 1024);

  turbocompress64(test.data(), test.size(), comp.data());
  uint32_t nvalue = 0;
  turbouncompress64(comp.data(), recover.data(), nvalue);

  recover.resize(nvalue);
  if (recover != test)
    throw runtime_error("bug64");
}

void turbodeepunit64() {
  for (int k = 31; k >= 0; --k) {
    vector<uint64_t> test;
    for (uint64_t i = 0; i < 100; ++i) {
      test.push_back(0);
      test.push_back(0xFFFFFFFF >> k);
    }
    vector<uint8_t> comp(test.size() * 4 + 1024);
    vector<uint64_t> recover(test.size() + 1024);

    turbocompress64(test.data(), test.size(), comp.data());
    uint32_t nvalue = 0;
    turbouncompress64(comp.data(), recover.data(), nvalue);
    recover.resize(nvalue);
    if (recover != test) {
      throw runtime_error("bug64d");
    }
  }
}


void benchmark(vector<uint32_t> &data) {
  std::cout << "[standard benchmark]" << std::endl;
  vector<uint32_t> buffer(data.size());

  if (data.size() == 0) {
    cout << "Empty vector" << endl;
    return;
  }
  cout << "vector size = " << data.size() << endl;
  cout << "vector size = " << data.size() * sizeof(uint32_t) / 1024.0 << "KB"
       << endl;

  vector<uint32_t> compdata(data.size() + 2048);
  uint32_t *out = compress(data.data(), data.size(), compdata.data());
  cout << "compression rate:" << setprecision(2)
       << data.size() * 1.0 / (out - compdata.data()) << endl;
  cout << "bits/int:" << setprecision(4)
       << (out - compdata.data()) * 32.0 / data.size() << endl;
  cout << "volume: " << setprecision(2) << (out - compdata.data()) * 4.0 / 1024
       << "KB" << endl;

  uint32_t nvalue = 0;
  uncompress(compdata.data(), buffer.data(), nvalue);
  buffer.resize(nvalue);
  if (buffer != data)
    throw runtime_error("bug");

  double numberofintegers = 0;
  int N = (1 << 28) / data.size();
  uint32_t bogus = 0;
  WallClockTimer timer;
  for (int k = 0; k < N; ++k) {
    uncompress(compdata.data(), buffer.data(), nvalue);
    numberofintegers += nvalue;
    bogus += buffer.back() + buffer.front();
  }
  uint64_t timems = timer.split();
  cout << "decoding time per int: " << setprecision(2)
       << timems / numberofintegers * 1000 * 1000 << "ns" << endl;
  cout << "decoding time per array: " << setprecision(2)
       << static_cast<double>(timems) / N * 1000 << "ms" << endl;
  cout << "# ignore me " << bogus << endl;
  cout << endl;
}

void turbobenchmark(vector<uint32_t> &data) {
  std::cout << "[turbo benchmark]" << std::endl;
  vector<uint32_t> buffer(data.size());

  if (data.size() == 0) {
    cout << "Empty vector" << endl;
    return;
  }
  cout << "vector size = " << data.size() << endl;
  cout << "vector size = " << data.size() * sizeof(uint32_t) / 1024.0 << "KB"
       << endl;

  vector<uint8_t> compdata(data.size() * sizeof(uint32_t) + 2048);
  const uint8_t *out = turbocompress(data.data(), data.size(), compdata.data());
  cout << "compression rate:" << setprecision(2)
       << data.size() * 1.0 * sizeof(uint32_t) / (out - compdata.data())
       << endl;
  cout << "bits/int:" << setprecision(4)
       << (out - compdata.data()) * 8.0 / data.size() << endl;
  cout << "volume: " << setprecision(2) << (out - compdata.data()) * 1.0 / 1024
       << "KB" << endl;

  uint32_t nvalue = 0;
  turbouncompress(compdata.data(), buffer.data(), nvalue);
  buffer.resize(nvalue);
  if (buffer != data)
    throw runtime_error("bug");

  double numberofintegers = 0;
  int N = (1 << 28) / data.size();
  uint32_t bogus = 0;
  WallClockTimer timer;
  for (int k = 0; k < N; ++k) {
    turbouncompress(compdata.data(), buffer.data(), nvalue);
    numberofintegers += nvalue;
    bogus += buffer.back() + buffer.front();
  }
  uint64_t timems = timer.split();
  cout << "decoding time per int: " << setprecision(2)
       << timems / numberofintegers * 1000 * 1000 << "ns" << endl;
  cout << "decoding time per array: " << setprecision(2)
       << static_cast<double>(timems) / N * 1000 << "ms" << endl;
  cout << "# ignore me " << bogus << endl;
  cout << endl;
}

void turbobenchmark64(vector<uint32_t> &data32) {
  std::cout << "[turbo benchmark64]" << std::endl;
  vector<uint64_t> data;

  for (vector<uint32_t>::const_iterator i = data32.begin(); i != data32.end(); ++i)
    data.push_back(*i);

  vector<uint64_t> buffer(data);

  if (data.size() == 0) {
    cout << "Empty vector" << endl;
    return;
  }
  cout << "vector size = " << data.size() << endl;
  cout << "vector size = " << data.size() * sizeof(uint64_t) / 1024.0 << "KB"
       << endl;

  vector<uint8_t> compdata(data.size() * sizeof(uint32_t) + 2048);
  const uint8_t *out = turbocompress64(data.data(), data.size(), compdata.data());
  cout << "compression rate:" << setprecision(2)
       << data.size() * 1.0 * sizeof(uint64_t) / (out - compdata.data())
       << endl;
  cout << "bits/int:" << setprecision(4)
       << (out - compdata.data()) * 8.0 / data.size() << endl;
  cout << "volume: " << setprecision(2) << (out - compdata.data()) * 1.0 / 1024
       << "KB" << endl;

  uint32_t nvalue = 0;
  turbouncompress64(compdata.data(), buffer.data(), nvalue);
  buffer.resize(nvalue);
  if (buffer != data)
    throw runtime_error("bug");

  double numberofintegers = 0;
  int N = (1 << 28) / data.size();
  uint32_t bogus = 0;
  WallClockTimer timer;
  for (int k = 0; k < N; ++k) {
    turbouncompress64(compdata.data(), buffer.data(), nvalue);
    numberofintegers += nvalue;
    bogus += buffer.back() + buffer.front();
  }
  uint64_t timems = timer.split();
  cout << "decoding time per int: " << setprecision(2)
       << timems / numberofintegers * 1000 * 1000 << "ns" << endl;
  cout << "decoding time per array: " << setprecision(2)
       << static_cast<double>(timems) / N * 1000 << "ms" << endl;
  cout << "# ignore me " << bogus << endl;
  cout << endl;
}

int main(int argc, char **argv) {
  unit();
  deepunit();

  turbounit();
  turbodeepunit();

  turbounit64();
  turbodeepunit64();
  if (argc <= 1) {
    displayUsage();
    return -1;
  }
  string filename = argv[1];
#ifdef _OPENMP
  cout << "OpenMP support is available" << endl;
  int k;
#pragma omp parallel
  {
#pragma omp master
    {
      k = omp_get_num_threads();
      cout << "Number of Threads requested = " << k << endl;
    }
  }
#else
  cout << "No OpenMP support" << endl;
#endif

#ifdef _OPENMP
  k = 0;
#pragma omp parallel
#pragma omp atomic
  k++;
  cout << "Number of Threads counted = " << k << endl;
#endif

  cout << "####### processing " << filename << endl;
  vector<uint32_t> data = loadVector(filename);
  cout << endl;

  benchmark(data);
  turbobenchmark(data);
  turbobenchmark64(data);

  return 0;
}
