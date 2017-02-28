# Frame of Reference (FOR) C++ library
[![Build Status](https://travis-ci.org/lemire/FrameOfReference.png)](https://travis-ci.org/lemire/FrameOfReference)

## What is this?

C++ library to pack and unpack vectors of integers having a small
range of values using a technique called Frame of Reference (Goldstein et al. 1998).
It should run fast even though it is written in simple C++.

## Code usage :

Given an array of 32-bit integers, you can compress it as follows:

```C
#include "compression.h"

...

uint32_t * inputdata = ... // length values
uint32_t * compresseddata = ... // enough data
uint32_t *out = compress(inputdata, length, compresseddata);
// compressed data lies between compresseddata and out
uint32_t nvalue = 0;
uint32_t * recoverydata = ... // available buffer with at least length elements
uncompress(compresseddata, recoverydata, nvalue);
// nvalue will be equal to length
```

There is a similar API with ``turbocompress`` and ``turbouncompress`` with the difference
that ``compresseddata`` uses an ``uint8_t`` pointer type.

```C
#include "turbocompression.h"

...

uint32_t * inputdata = ... // length values
uint8_t * compresseddata = ... // enough data
uint8_t *out = turbocompress(inputdata, length, compresseddata);
// compressed data lies between compresseddata and out
uint32_t nvalue = 0;
uint32_t * recoverydata = ... // available buffer with at least length elements
turbouncompress(compresseddata, recoverydata, nvalue);
// nvalue will be equal to length
```

We can also compress 64-bit arrays:

```C
#include "turbocompression.h"

...

uint64_t * inputdata = ... // length values
uint8_t * compresseddata = ... // enough data
uint8_t *out = turbocompress64(inputdata, length, compresseddata);
// compressed data lies between compresseddata and out
uint32_t nvalue = 0;
uint64_t * recoverydata = ... // available buffer with at least length elements
turbouncompress64(compresseddata, recoverydata, nvalue);
// nvalue will be equal to length
```

##  Usage (with Makefile)

To run a simple benchmark, do

     make
     ./test sampledata.txt

where sampledata.txt is a text data file with one integer per line.

For a parallelized version, type

     make testmp
     ./testmp sampledata.txt

This requires OpenMP support however.


##  Usage (with CMake under macOS and Linux)

You need to have ``cmake`` installed and available as a command.

     make release
     cd release
     cmake ..
     make
     make test

## Requirements:

This was tested with GNU G++ and clang++ After suitable adjustments, it should
build under most C++ compilers.

## Other relevant libraries

* Fast decoder for VByte-compressed integers https://github.com/lemire/MaskedVByte
* Fast integer compression in C using StreamVByte https://github.com/lemire/streamvbyte
* FastPFOR is a C++ research library well suited to compress unsorted arrays: https://github.com/lemire/FastPFor
* SIMDCompressionAndIntersection is a C++ research library well suited for sorted arrays (differential coding)
and computing intersections: https://github.com/lemire/SIMDCompressionAndIntersection

## References

* Goldstein J, Ramakrishnan R, Shaft U. Compressing relations and indexes. Proceedings of the Fourteenth International Conference on Data Engineering, ICDE ’98, IEEE Computer Society: Washington, DC, USA, 1998; 370–379.
* Daniel Lemire and Leonid Boytsov, Decoding billions of integers per second through vectorization, Software Practice & Experience 45 (1), 2015.  http://arxiv.org/abs/1209.2137 http://onlinelibrary.wiley.com/doi/10.1002/spe.2203/abstract
* Daniel Lemire, Leonid Boytsov, Nathan Kurz, SIMD Compression and the Intersection of Sorted Integers, Software Practice & Experience 46 (6), 2016. http://arxiv.org/abs/1401.6399
* Jeff Plaisance, Nathan Kurz, Daniel Lemire, Vectorized VByte Decoding, International Symposium on Web Algorithms 2015, 2015. http://arxiv.org/abs/1503.07387
* Wayne Xin Zhao, Xudong Zhang, Daniel Lemire, Dongdong Shan, Jian-Yun Nie, Hongfei Yan, Ji-Rong Wen, A General SIMD-based Approach to Accelerating Compression Algorithms, ACM Transactions on Information Systems 33 (3), 2015. http://arxiv.org/abs/1502.01916
