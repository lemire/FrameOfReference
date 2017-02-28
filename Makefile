.SUFFIXES:
#
.SUFFIXES: .cpp .o .c .h
# replace the YOURCXX variable with a path to a C++11 compatible compiler.
ifeq ($(INTEL), 1)
# if you wish to use the Intel compiler, please do "make INTEL=1".
    YOURCXX ?= /opt/intel/bin/icpc
ifeq ($(DEBUG),1)
    CXXFLAGS =  -std=c++11 -O3 -Wall -ansi  -DDEBUG=1 -D_GLIBCXX_DEBUG   -ggdb
else
    CXXFLAGS =  -std=c++11 -O3 -Wall -ansi  -DNDEBUG=1  -ggdb
endif # debug
else #intel
    YOURCXX ?= g++
ifeq ($(DEBUG),1)
    CXXFLAGS =   -std=c++11 -Weffc++ -pedantic -ggdb -DDEBUG=1 -D_GLIBCXX_DEBUG -Wall -Wextra  -Wcast-align  
else
    CXXFLAGS =  -std=c++11 -Weffc++ -pedantic -O3 -Wall -Wextra  -Wcast-align  
endif #debug
endif #intel




HEADERS= $(shell ls include/*h)

all: test
	@echo "type ./test sampledata.txt" 
	@echo "if you have OpenMP support, type make testmp" 

bpacking.o: include/bpacking.h src/bpacking.cpp
	$(CXX) $(CXXFLAGS) -c src/bpacking.cpp -Iinclude

testmp: $(HEADERS) src/test.cpp bpacking.o
ifeq ($(INTEL), 1)
	$(CXX)  -openmp -lpthread -D_OPENMP $(CXXFLAGS) -o testmp src/test.cpp bpacking.o  -Iinclude 	
else
	$(CXX)  -fopenmp -lpthread $(CXXFLAGS) -o testmp src/test.cpp bpacking.o  -Iinclude 	
endif

test: $(HEADERS) src/test.cpp bpacking.o
	$(CXX)  $(CXXFLAGS) -o test src/test.cpp bpacking.o  -Iinclude
	
clean: 
	rm -f *.o test testmp





