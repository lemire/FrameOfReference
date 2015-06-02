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

using namespace std;

class WallClockTimer
{
public:
    struct timeval t1, t2;
public:
    WallClockTimer() : t1(), t2() {
        gettimeofday(&t1,0);
        t2 = t1;
    }
    void reset() {
        gettimeofday(&t1,0);
        t2 = t1;
    }
    int elapsed() {
        return ((t2.tv_sec - t1.tv_sec) * 1000) + ((t2.tv_usec - t1.tv_usec) / 1000);
    }
    int split() {
        gettimeofday(&t2,0);
        return elapsed();
    }
};



void displayUsage() {
    cout << "run as test nameoffile" << endl;
}

vector<uint32_t> loadVector(string filename) {
    vector < uint32_t > answer;
    answer.reserve(1024*32);// expect sizeable arrays
    ifstream logFile(filename.c_str());
    if (!logFile.is_open()) {
        cerr << " Couldn't open query vector file " << filename << endl;
        displayUsage( );
        return answer;
    }
    cout << "# Parsing vector file " << filename << endl;

    logFile.exceptions(ios::badbit); // will throw an exception if something goes wrong, saves us the trouble of checking the IO status
    string line;
    for (; logFile && getline(logFile, line);) {
        uint32_t id = atoi(line.c_str());
        answer.push_back(id);
    }
    return answer;
}

void unit() {
    vector<uint32_t> test;
    for(uint32_t i = 0 ; i < 100; ++i)
        test.push_back(i);
    vector<uint32_t> comp(test.size()+1024);
    vector<uint32_t> recover(test.size()+1024);

    compress(&test[0],test.size(),&comp[0]);
    uint32_t nvalue = 0;
    uncompress(&comp[0],&recover[0],nvalue);
    recover.resize(nvalue);

    if(recover != test) throw runtime_error("bug");
}

void benchmark(vector<uint32_t > & data) {
    vector<uint32_t> buffer(data.size());

    if(data.size()==0) {
        cout<<"Empty vector"<<endl;
        return;
    }
    cout<<"vector size = "<<data.size()<<endl;
    vector<uint32_t> compdata(data.size() + 2048);
    uint32_t * out = compress(&data[0],data.size(),&compdata[0]);
    cout<<"compression rate:"<<setprecision(2)<<data.size()*1.0/(out-&compdata[0])<<endl;
    cout<<"bits/int:" <<setprecision(4)<<(out-&compdata[0])*32.0/data.size()<<endl;
    cout<<"volume: " <<setprecision(2)<<(out-&compdata[0])*4.0/1024<<"KB"<<endl;

    uint32_t nvalue = 0;
    uncompress(&compdata[0],&buffer[0],nvalue);
    buffer.resize(nvalue);
    if(buffer != data) throw runtime_error("bug");

    double numberofintegers = 0;
    int N =  (1<<28)/data.size();
    uint32_t bogus = 0;
    WallClockTimer timer;
    for(int k = 0; k < N; ++k) {
        uncompress(&compdata[0],&buffer[0],nvalue);
        numberofintegers += nvalue;
        bogus += buffer.back() + buffer.front();
    }
    uint64_t timems = timer.split();
    cout<<"decoding time per int: "<< setprecision(2)<<timems/numberofintegers*1000*1000<<"ns"<<endl;
    cout<<"decoding time per array: "<< setprecision(2)<<static_cast<double>(timems)/N*1000<<"ms"<<endl;
    vector<uint32_t> newbuffer(data.size());
    cout<<"# ignore me "<<bogus<<endl;
    cout<<endl;
}


int main(int argc, char **argv) {
    unit();
    if (argc <= 1) {
        displayUsage();
        return -1;
    }
    string filename = argv[1];
#ifdef _OPENMP
    cout<<"OpenMP support is available"<<endl;
    int k ;
    #pragma omp parallel
    {
        #pragma omp master
        {
            k = omp_get_num_threads();
            cout<< "Number of Threads requested = "<< k<<endl;
        }
    }
#else
    cout<<"No OpenMP support"<<endl;
#endif

#ifdef _OPENMP
    k = 0;
    #pragma omp parallel
    #pragma omp atomic
    k++;
    cout<< "Number of Threads counted = "<<k<<endl;
#endif

    cout<<"####### processing "<<filename<<endl;
    vector<uint32_t> data = loadVector(filename);
    benchmark(data);

    size_t bigsize = 128*1024*1024/data.size() * data.size();
    cout<<"Creating big array...";
    cout.flush();
    vector<uint32_t> bigdata(bigsize);
    for(size_t t = 0; t < bigsize/data.size(); ++t)
        for(uint32_t i = 0; i < data.size(); ++i)
            bigdata[t*data.size() + i ]  = data[i];
    cout<<"ok"<<endl;
    benchmark(bigdata);
    return 0;
}

