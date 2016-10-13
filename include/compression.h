/*
 * compression.h
 *
 *  Created on: Oct 28, 2013
 *      Author: lemire
 */

#ifndef COMPRESSION_H_
#define COMPRESSION_H_

#include "bpacking.h"
#include "util.h"

/**
* Compresses "length" values from "in" to "out" and return a pointer to the end of the compressed stream.
* The format is "number of values, minimal value, maximal value, followed by packed data".
*/
inline uint32_t * compress(uint32_t * in, uint32_t length, uint32_t * out) {
    out[0] = length;
    ++out;
    if(length == 0) return out;
    uint32_t m = in[0];
    uint32_t M = in[0];
    for(uint32_t i = 1; i < length; ++i) {
        if(in[i]>M) M=in[i];
        if(in[i]<m) m=in[i];
    }
    int b = bits(static_cast<uint32_t>(M-m));
    out[0] = m;
    ++out;
    out[0] = M;
    ++out;
    uint32_t k = 0;
    for(; k+32<=length; k+=32,in+=32) {
        out = pack32[b](m,in,out);
    }
    for(; k+16<=length; k+=16,in+=16) {
        out = pack16[b](m,in,out);
    }
    for(; k+8<=length; k+=8,in+=8) {
        out = pack8[b](m,in,out);
    }
    // we could pack the rest, but we don't  bother
    for(; k<length; ++k,in++,out++) {
        out[0] = in [0];
    }
    return out;
}

/*
* uncompress FOR data found in "in".
* The format is "number of values, minimal value, maximal value, followed by packed data".
* The 'nvalue' variable receives the number of decoded values (initial value is ignored)
* The values are stored in "out".
* We return a pointer to the end of the compressed input stream.
*/
inline uint32_t * uncompress(uint32_t * in, uint32_t * out, uint32_t & nvalue) {
    nvalue = in[0];
    ++in;
    if(nvalue == 0) return in;
    uint32_t m = in[0];
    ++in;
    uint32_t M = in[0];
    ++in;
    int b = bits(static_cast<uint32_t>(M-m));
#ifdef _OPENMP
    #pragma omp parallel for
#endif
    for(uint32_t k = 0; k<nvalue/32; ++k) {
        unpack32[b](m,in+b*k,out+32*k);
    }
    out = out + nvalue/32*32;
    in = in + nvalue/32*b;

    for(uint32_t k=nvalue/32*32; k+16<=nvalue; k+=16,out+=16) {
        in = unpack16[b](m,in,out);
    }
    for(uint32_t k=nvalue/16*16; k+8<=nvalue; k+=8,out+=8) {
        in = unpack8[b](m,in,out);
    }
    // we could pack the rest, but we don't  bother
    for(uint32_t k=nvalue/8*8; k<nvalue; ++k,in++,out++) {
        out[0] = in [0];
    }
    return in;
}

#endif /* COMPRESSION_H_ */
