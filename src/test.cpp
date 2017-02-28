/**
*
* This code is released under the
* Apache License Version 2.0 http://www.apache.org/licenses/.
* (c) Daniel Lemire 2013
*/
#include <chrono>
#include <sys/stat.h>
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


//
// VS2012 bug: high_precision_clock is defined as system_clock and precision is
// about 15 MS!!
// See: https://connect.microsoft.com/VisualStudio/feedback/details/719443
//
// Implementation has been taken from a post on stackoverflow and adapted here
// http://stackoverflow.com/questions/13263277/difference-between-stdsystem-clock-and-stdsteady-clock
//
#ifdef _WIN32
#define NOMINMAX
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>

struct qpc_clock {
	typedef std::chrono::nanoseconds duration;
	typedef duration::rep rep;
	typedef duration::period period;
	typedef std::chrono::time_point<qpc_clock, duration> time_point;
	static time_point now() {
		static bool isInited = false;
		static LARGE_INTEGER frequency = { 0, 0 };
		if (!isInited) {
			if (QueryPerformanceFrequency(&frequency) == 0) {
				throw std::logic_error("QueryPerformanceCounter not supported: " +
					std::to_string(GetLastError()));
			}
			isInited = true;
		}
		LARGE_INTEGER counter;
		QueryPerformanceCounter(&counter);
		return time_point(duration(static_cast<rep>((double)counter.QuadPart /
			frequency.QuadPart *
			period::den / period::num)));
	}
};

#endif

/**
*  author: Preston Bannister
*/
class WallClockTimer {
public:
#ifdef _WIN32
	typedef qpc_clock clock;
#else
	typedef std::chrono::high_resolution_clock clock;
#endif

	std::chrono::time_point<clock> t1, t2;
	WallClockTimer() : t1(), t2() {
		t1 = clock::now();
		t2 = t1;
	}
	void reset() {
		t1 = clock::now();
		t2 = t1;
	}
	uint64_t elapsed() {
		std::chrono::microseconds delta =
			std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
		return delta.count();
	}
	uint64_t split() {
		t2 = clock::now();
		return elapsed();
	}
};

#ifndef _WIN32
#include <sys/time.h>
#include <sys/resource.h>
class CPUTimer {
public:
	// clock_t t1, t2;
	struct rusage t1, t2;

	CPUTimer() : t1(), t2() {
		getrusage(RUSAGE_SELF, &t1);
		// t1 = clock();
		t2 = t1;
	}
	void reset() {
		getrusage(RUSAGE_SELF, &t1);
		t2 = t1;
	}
	// proxy for userelapsed
	uint64_t elapsed() { return totalelapsed(); }

	uint64_t totalelapsed() { return userelapsed() + systemelapsed(); }
	// returns the *user* CPU time in micro seconds (mu s)
	uint64_t userelapsed() {
		return ((t2.ru_utime.tv_sec - t1.ru_utime.tv_sec) * 1000ULL * 1000ULL) +
			((t2.ru_utime.tv_usec - t1.ru_utime.tv_usec));
	}

	// returns the *system* CPU time in micro seconds (mu s)
	uint64_t systemelapsed() {
		return ((t2.ru_stime.tv_sec - t1.ru_stime.tv_sec) * 1000ULL * 1000ULL) +
			((t2.ru_stime.tv_usec - t1.ru_stime.tv_usec));
	}

	uint64_t split() {
		getrusage(RUSAGE_SELF, &t2);
		return elapsed();
	}
};

#endif

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
