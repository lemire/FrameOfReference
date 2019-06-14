

#ifndef TURBOCOMPRESSION_H_
#define TURBOCOMPRESSION_H_

#include "turbopacking32.h"
#include "turbopacking64.h"

#include "util.h"

/**
* "turbo" FOR packing uses an optimization to bit packing due to
* TurboPFor: we use 64-bit words as much as possible.
*
*/

/**
* Compresses "length" values from "in" to "out" and return a pointer to the end
* of the compressed stream.
* The format is "number of values, minimal value, maximal value, followed by
* packed data".
*
* Currently the implementation assumes that the integer arrays to be compressed
* are in multiples of 32, remaining integers are not compressed. Thus using this
* code on arrays smaller than 32 is wasteful. (This limitation will be removed
* in the future.)
*/
inline uint8_t *turbocompress(const uint32_t *in, uint32_t length,
                              uint8_t *out) {
  memcpy(out, &length, sizeof(length));
  out += sizeof(length);
  if (length == 0)
    return out;
  uint32_t m = in[0];
  uint32_t M = in[0];
  for (uint32_t i = 1; i < length; ++i) {
    if (in[i] > M)
      M = in[i];
    if (in[i] < m)
      m = in[i];
  }
  int b = bits(static_cast<uint32_t>(M - m));
  memcpy(out, &m, sizeof(m));
  out += sizeof(m);
  memcpy(out, &M, sizeof(M));
  out += sizeof(M);
  uint32_t k = 0;
  for (; k + 32 <= length; k += 32) {
    funcForPackArr[b](m, &in, &out);
  }
  // we could pack the rest, but we don't  bother
  memcpy(out, in, (length - k) * sizeof(uint32_t));
  out += (length - k) * sizeof(uint32_t);
  return out;
}

/*
* uncompress FOR data found in "in".
* The format is "number of values, minimal value, maximal value, followed by
* packed data".
* The 'nvalue' variable receives the number of decoded values (initial value is
* ignored)
* The values are stored in "out".
* We return a pointer to the end of the compressed input stream.
*/
inline const uint8_t *turbouncompress(const uint8_t *in, uint32_t *out,
                                      uint32_t &nvalue) {
  memcpy(&nvalue, in, sizeof(nvalue));
  in += sizeof(nvalue);
  if (nvalue == 0)
    return in;
  uint32_t m, M;
  memcpy(&m, in, sizeof(m));
  in += sizeof(m);
  memcpy(&M, in, sizeof(M));
  in += sizeof(M);
  int b = bits(static_cast<uint32_t>(M - m));
#ifdef _OPENMP
#pragma omp parallel for
#endif
  for (uint32_t k = 0; k < nvalue / 32; ++k) {
    // could code as funcForUnpackArr[b](m,&in,&out); but it hurts
    // parallelization
    const uint8_t *input = in + 32 * b * k / 8;
    uint32_t *output = out + k * 32;
    funcForUnpackArr[b](m, &input, &output);
  }
  in = in + (32 * b / 8) * (nvalue / 32);
  out = out + 32 * (nvalue / 32);

  // we could pack the rest, but we don't  bother
  uint32_t leftover = nvalue - nvalue / 32 * 32;
  memcpy(out, in, leftover * sizeof(uint32_t));
  in += leftover * sizeof(uint32_t);
  return in;
}



/**
* Compresses "length" values from "in" to "out" and return a pointer to the end
* of the compressed stream.
* The format is "number of values, minimal value, maximal value, followed by
* packed data".
*
* Currently the implementation assumes that the integer arrays to be compressed
* are in multiples of 32, remaining integers are not compressed. Thus using this
* code on arrays smaller than 32 is wasteful. (This limitation will be removed
* in the future.)
*/
inline uint8_t *turbocompress64(const uint64_t *in, uint32_t length,
                              uint8_t *out) {
  memcpy(out, &length, sizeof(length));
  out += sizeof(length);
  if (length == 0)
    return out;
  uint64_t m = in[0];
  uint64_t M = in[0];
  for (uint32_t i = 1; i < length; ++i) {
    if (in[i] > M)
      M = in[i];
    if (in[i] < m)
      m = in[i];
  }
  int b = bits64(static_cast<uint64_t>(M - m));
  memcpy(out, &m, sizeof(m));
  out += sizeof(m);
  memcpy(out, &M, sizeof(M));
  out += sizeof(M);

  uint32_t k = 0;
  for (; k + 32 <= length; k += 32) {
    funcForPackArr64[b](m, &in, &out);
  }
  // we could pack the rest, but we don't  bother
  memcpy(out, in, (length - k) * sizeof(uint64_t));
  out += (length - k) * sizeof(uint64_t);
  return out;
}

/*
* uncompress FOR data found in "in".
* The format is "number of values, minimal value, maximal value, followed by
* packed data".
* The 'nvalue' variable receives the number of decoded values (initial value is
* ignored)
* The values are stored in "out".
* We return a pointer to the end of the compressed input stream.
*/
inline const uint8_t *turbouncompress64(const uint8_t *in, uint64_t *out,
                                      uint32_t &nvalue) {
  memcpy(&nvalue, in, sizeof(nvalue));
  in += sizeof(nvalue);
  if (nvalue == 0)
    return in;
  uint64_t m, M;
  memcpy(&m, in, sizeof(m));
  in += sizeof(m);
  memcpy(&M, in, sizeof(M));
  in += sizeof(M);
  int b = bits64(static_cast<uint64_t>(M - m));
#ifdef _OPENMP
#pragma omp parallel for
#endif
  for (uint32_t k = 0; k < nvalue / 32; ++k) {
    // could code as funcForUnpackArr[b](m,&in,&out); but it hurts
    // parallelization
    const uint8_t *input = in + 32 * b * k / 8;
    uint64_t *output = out + k * 32;
    funcForUnpackArr64[b](m, &input, &output);
  }
  in = in + (32 * b / 8) * (nvalue / 32);
  out = out + 32 * (nvalue / 32);

  // we could pack the rest, but we don't  bother
  uint32_t leftover = nvalue - nvalue / 32 * 32;
  memcpy(out, in, leftover * sizeof(uint64_t));
  in += leftover * sizeof(uint64_t);
  return in;
}


#endif /* COMPRESSION_H_ */
