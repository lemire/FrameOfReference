/*
 * compression.h
 *
 *  Created on: Oct 28, 2013
 *      Author: lemire
 */

#ifndef COMPRESSION_H_
#define COMPRESSION_H_

#include "bpacking.h"

typedef uint32_t * (*packfnc)( uint32_t,  uint32_t * , uint32_t * );

uint32_t * nullpacker( uint32_t,  uint32_t *   , uint32_t *    out) {
  return out;
}

uint32_t * nullunpacker8( uint32_t base,  uint32_t *  in , uint32_t * out) {
    for(int k = 0; k < 8; ++k) {
		 out[k] = base;
	}
	return in;
}

uint32_t * nullunpacker16( uint32_t base,  uint32_t *  in , uint32_t * out) {
    for(int k = 0; k < 8; ++k) {
		 out[k] = base;
	}
	return in;
}

uint32_t * nullunpacker32( uint32_t base,  uint32_t *  in , uint32_t * out) {
    for(int k = 0; k < 8; ++k) {
		 out[k] = base;
	}
	return in;
}


packfnc unpack8[33]={nullunpacker8,unpack1_8,
        unpack2_8,
        unpack3_8,
        unpack4_8,
        unpack5_8,
        unpack6_8,
        unpack7_8,
        unpack8_8,
        unpack9_8,
        unpack10_8,
        unpack11_8,
        unpack12_8,
        unpack13_8,
        unpack14_8,
        unpack15_8,
        unpack16_8,
        unpack17_8,
        unpack18_8,
        unpack19_8,
        unpack20_8,
        unpack21_8,
        unpack22_8,
        unpack23_8,
        unpack24_8,
        unpack25_8,
        unpack26_8,
        unpack27_8,
        unpack28_8,
        unpack29_8,
        unpack30_8,
        unpack31_8,
        unpack32_8};

packfnc pack8[33]={nullpacker,pack1_8,
        pack2_8,
        pack3_8,
        pack4_8,
        pack5_8,
        pack6_8,
        pack7_8,
        pack8_8,
        pack9_8,
        pack10_8,
        pack11_8,
        pack12_8,
        pack13_8,
        pack14_8,
        pack15_8,
        pack16_8,
        pack17_8,
        pack18_8,
        pack19_8,
        pack20_8,
        pack21_8,
        pack22_8,
        pack23_8,
        pack24_8,
        pack25_8,
        pack26_8,
        pack27_8,
        pack28_8,
        pack29_8,
        pack30_8,
        pack31_8,
        pack32_8};

packfnc unpack16[33]={nullunpacker16,unpack1_16,
        unpack2_16,
        unpack3_16,
        unpack4_16,
        unpack5_16,
        unpack6_16,
        unpack7_16,
        unpack8_16,
        unpack9_16,
        unpack10_16,
        unpack11_16,
        unpack12_16,
        unpack13_16,
        unpack14_16,
        unpack15_16,
        unpack16_16,
        unpack17_16,
        unpack18_16,
        unpack19_16,
        unpack20_16,
        unpack21_16,
        unpack22_16,
        unpack23_16,
        unpack24_16,
        unpack25_16,
        unpack26_16,
        unpack27_16,
        unpack28_16,
        unpack29_16,
        unpack30_16,
        unpack31_16,
        unpack32_16};

packfnc pack16[33]={nullpacker,pack1_16,
        pack2_16,
        pack3_16,
        pack4_16,
        pack5_16,
        pack6_16,
        pack7_16,
        pack8_16,
        pack9_16,
        pack10_16,
        pack11_16,
        pack12_16,
        pack13_16,
        pack14_16,
        pack15_16,
        pack16_16,
        pack17_16,
        pack18_16,
        pack19_16,
        pack20_16,
        pack21_16,
        pack22_16,
        pack23_16,
        pack24_16,
        pack25_16,
        pack26_16,
        pack27_16,
        pack28_16,
        pack29_16,
        pack30_16,
        pack31_16,
        pack32_16};

packfnc unpack32[33]={nullunpacker32,unpack1_32,
        unpack2_32,
        unpack3_32,
        unpack4_32,
        unpack5_32,
        unpack6_32,
        unpack7_32,
        unpack8_32,
        unpack9_32,
        unpack10_32,
        unpack11_32,
        unpack12_32,
        unpack13_32,
        unpack14_32,
        unpack15_32,
        unpack16_32,
        unpack17_32,
        unpack18_32,
        unpack19_32,
        unpack20_32,
        unpack21_32,
        unpack22_32,
        unpack23_32,
        unpack24_32,
        unpack25_32,
        unpack26_32,
        unpack27_32,
        unpack28_32,
        unpack29_32,
        unpack30_32,
        unpack31_32,
        unpack32_32};

packfnc pack32[33]={nullpacker,pack1_32,
        pack2_32,
        pack3_32,
        pack4_32,
        pack5_32,
        pack6_32,
        pack7_32,
        pack8_32,
        pack9_32,
        pack10_32,
        pack11_32,
        pack12_32,
        pack13_32,
        pack14_32,
        pack15_32,
        pack16_32,
        pack17_32,
        pack18_32,
        pack19_32,
        pack20_32,
        pack21_32,
        pack22_32,
        pack23_32,
        pack24_32,
        pack25_32,
        pack26_32,
        pack27_32,
        pack28_32,
        pack29_32,
        pack30_32,
        pack31_32,
        pack32_32};

inline uint32_t bits(const uint32_t v) {
    return v == 0 ? 0 : 32 - __builtin_clz(v);
}

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
    for(;k<length;++k,in++,out++) {
        out[0] = in [0];
    }
    return out;
}

inline uint32_t * uncompress(uint32_t * in, uint32_t * out, uint32_t & nvalue) {
    nvalue = in[0];
    ++in;
    if(nvalue == 0) return out;
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
    for(uint32_t k=nvalue/8*8;k<nvalue;++k,in++,out++) {
        out[0] = in [0];
    }
    return in;
}

#endif /* COMPRESSION_H_ */
