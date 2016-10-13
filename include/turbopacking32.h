
#ifndef INCLUDE_TURBOPACKING32_H
#define INCLUDE_TURBOPACKING32_H
#include <iso646.h> // mostly for Microsoft compilers
#include <stdint.h> // part of Visual Studio 2010 and better
#ifndef UINT64_C
#define UINT64_C(c) (c ## ULL)
#endif

/**
* (c) Daniel Lemire
* Apache License 2.0
*/
/** turbopacking32 starts here **/
/**
* this code mimics the way TurboPFor packs short arrays of integers.
* We pack and unpack always at least a full 64-bit word, plus whatever
* is necessary to get to an even number of bytes.
*/
typedef void (*packforblockfnc)(const uint32_t base, const uint32_t **pin,
                                uint8_t **pw);
typedef void (*unpackforblockfnc)(const uint32_t base, const uint8_t **pw,
                                  uint32_t **pout);

static void packforblock0(const uint32_t, const uint32_t **pin, uint8_t **pw) {
  (void)pw;
  *pin += 32; /* we consumed 32 32-bit integers */
}

/* we are going to pack 32 1-bit values, touching 1 64-bit words, using 4 bytes
 */
static void packforblock1(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  1 64-bit word */
  uint64_t w0;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 1;
  w0 |= (uint64_t)(in[2] - base) << 2;
  w0 |= (uint64_t)(in[3] - base) << 3;
  w0 |= (uint64_t)(in[4] - base) << 4;
  w0 |= (uint64_t)(in[5] - base) << 5;
  w0 |= (uint64_t)(in[6] - base) << 6;
  w0 |= (uint64_t)(in[7] - base) << 7;
  w0 |= (uint64_t)(in[8] - base) << 8;
  w0 |= (uint64_t)(in[9] - base) << 9;
  w0 |= (uint64_t)(in[10] - base) << 10;
  w0 |= (uint64_t)(in[11] - base) << 11;
  w0 |= (uint64_t)(in[12] - base) << 12;
  w0 |= (uint64_t)(in[13] - base) << 13;
  w0 |= (uint64_t)(in[14] - base) << 14;
  w0 |= (uint64_t)(in[15] - base) << 15;
  w0 |= (uint64_t)(in[16] - base) << 16;
  w0 |= (uint64_t)(in[17] - base) << 17;
  w0 |= (uint64_t)(in[18] - base) << 18;
  w0 |= (uint64_t)(in[19] - base) << 19;
  w0 |= (uint64_t)(in[20] - base) << 20;
  w0 |= (uint64_t)(in[21] - base) << 21;
  w0 |= (uint64_t)(in[22] - base) << 22;
  w0 |= (uint64_t)(in[23] - base) << 23;
  w0 |= (uint64_t)(in[24] - base) << 24;
  w0 |= (uint64_t)(in[25] - base) << 25;
  w0 |= (uint64_t)(in[26] - base) << 26;
  w0 |= (uint64_t)(in[27] - base) << 27;
  w0 |= (uint64_t)(in[28] - base) << 28;
  w0 |= (uint64_t)(in[29] - base) << 29;
  w0 |= (uint64_t)(in[30] - base) << 30;
  w0 |= (uint64_t)(in[31] - base) << 31;
  pw64[0] = w0;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 4;   /* we used up 4 output bytes */
}

/* we are going to pack 32 2-bit values, touching 1 64-bit words, using 8 bytes
 */
static void packforblock2(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  1 64-bit word */
  uint64_t w0;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 2;
  w0 |= (uint64_t)(in[2] - base) << 4;
  w0 |= (uint64_t)(in[3] - base) << 6;
  w0 |= (uint64_t)(in[4] - base) << 8;
  w0 |= (uint64_t)(in[5] - base) << 10;
  w0 |= (uint64_t)(in[6] - base) << 12;
  w0 |= (uint64_t)(in[7] - base) << 14;
  w0 |= (uint64_t)(in[8] - base) << 16;
  w0 |= (uint64_t)(in[9] - base) << 18;
  w0 |= (uint64_t)(in[10] - base) << 20;
  w0 |= (uint64_t)(in[11] - base) << 22;
  w0 |= (uint64_t)(in[12] - base) << 24;
  w0 |= (uint64_t)(in[13] - base) << 26;
  w0 |= (uint64_t)(in[14] - base) << 28;
  w0 |= (uint64_t)(in[15] - base) << 30;
  w0 |= (uint64_t)(in[16] - base) << 32;
  w0 |= (uint64_t)(in[17] - base) << 34;
  w0 |= (uint64_t)(in[18] - base) << 36;
  w0 |= (uint64_t)(in[19] - base) << 38;
  w0 |= (uint64_t)(in[20] - base) << 40;
  w0 |= (uint64_t)(in[21] - base) << 42;
  w0 |= (uint64_t)(in[22] - base) << 44;
  w0 |= (uint64_t)(in[23] - base) << 46;
  w0 |= (uint64_t)(in[24] - base) << 48;
  w0 |= (uint64_t)(in[25] - base) << 50;
  w0 |= (uint64_t)(in[26] - base) << 52;
  w0 |= (uint64_t)(in[27] - base) << 54;
  w0 |= (uint64_t)(in[28] - base) << 56;
  w0 |= (uint64_t)(in[29] - base) << 58;
  w0 |= (uint64_t)(in[30] - base) << 60;
  w0 |= (uint64_t)(in[31] - base) << 62;
  pw64[0] = w0;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 8;   /* we used up 8 output bytes */
}

/* we are going to pack 32 3-bit values, touching 2 64-bit words, using 12 bytes
 */
static void packforblock3(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 3;
  w0 |= (uint64_t)(in[2] - base) << 6;
  w0 |= (uint64_t)(in[3] - base) << 9;
  w0 |= (uint64_t)(in[4] - base) << 12;
  w0 |= (uint64_t)(in[5] - base) << 15;
  w0 |= (uint64_t)(in[6] - base) << 18;
  w0 |= (uint64_t)(in[7] - base) << 21;
  w0 |= (uint64_t)(in[8] - base) << 24;
  w0 |= (uint64_t)(in[9] - base) << 27;
  w0 |= (uint64_t)(in[10] - base) << 30;
  w0 |= (uint64_t)(in[11] - base) << 33;
  w0 |= (uint64_t)(in[12] - base) << 36;
  w0 |= (uint64_t)(in[13] - base) << 39;
  w0 |= (uint64_t)(in[14] - base) << 42;
  w0 |= (uint64_t)(in[15] - base) << 45;
  w0 |= (uint64_t)(in[16] - base) << 48;
  w0 |= (uint64_t)(in[17] - base) << 51;
  w0 |= (uint64_t)(in[18] - base) << 54;
  w0 |= (uint64_t)(in[19] - base) << 57;
  w0 |= (uint64_t)(in[20] - base) << 60;
  w0 |= (uint64_t)(in[21] - base) << 63;
  w1 = (uint64_t)(in[21] - base) >> 1;
  w1 |= (uint64_t)(in[22] - base) << 2;
  w1 |= (uint64_t)(in[23] - base) << 5;
  w1 |= (uint64_t)(in[24] - base) << 8;
  w1 |= (uint64_t)(in[25] - base) << 11;
  w1 |= (uint64_t)(in[26] - base) << 14;
  w1 |= (uint64_t)(in[27] - base) << 17;
  w1 |= (uint64_t)(in[28] - base) << 20;
  w1 |= (uint64_t)(in[29] - base) << 23;
  w1 |= (uint64_t)(in[30] - base) << 26;
  w1 |= (uint64_t)(in[31] - base) << 29;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 12;  /* we used up 12 output bytes */
}

/* we are going to pack 32 4-bit values, touching 2 64-bit words, using 16 bytes
 */
static void packforblock4(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 4;
  w0 |= (uint64_t)(in[2] - base) << 8;
  w0 |= (uint64_t)(in[3] - base) << 12;
  w0 |= (uint64_t)(in[4] - base) << 16;
  w0 |= (uint64_t)(in[5] - base) << 20;
  w0 |= (uint64_t)(in[6] - base) << 24;
  w0 |= (uint64_t)(in[7] - base) << 28;
  w0 |= (uint64_t)(in[8] - base) << 32;
  w0 |= (uint64_t)(in[9] - base) << 36;
  w0 |= (uint64_t)(in[10] - base) << 40;
  w0 |= (uint64_t)(in[11] - base) << 44;
  w0 |= (uint64_t)(in[12] - base) << 48;
  w0 |= (uint64_t)(in[13] - base) << 52;
  w0 |= (uint64_t)(in[14] - base) << 56;
  w0 |= (uint64_t)(in[15] - base) << 60;
  w1 = (uint64_t)(in[16] - base);
  w1 |= (uint64_t)(in[17] - base) << 4;
  w1 |= (uint64_t)(in[18] - base) << 8;
  w1 |= (uint64_t)(in[19] - base) << 12;
  w1 |= (uint64_t)(in[20] - base) << 16;
  w1 |= (uint64_t)(in[21] - base) << 20;
  w1 |= (uint64_t)(in[22] - base) << 24;
  w1 |= (uint64_t)(in[23] - base) << 28;
  w1 |= (uint64_t)(in[24] - base) << 32;
  w1 |= (uint64_t)(in[25] - base) << 36;
  w1 |= (uint64_t)(in[26] - base) << 40;
  w1 |= (uint64_t)(in[27] - base) << 44;
  w1 |= (uint64_t)(in[28] - base) << 48;
  w1 |= (uint64_t)(in[29] - base) << 52;
  w1 |= (uint64_t)(in[30] - base) << 56;
  w1 |= (uint64_t)(in[31] - base) << 60;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 16;  /* we used up 16 output bytes */
}

/* we are going to pack 32 5-bit values, touching 3 64-bit words, using 20 bytes
 */
static void packforblock5(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  3 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 5;
  w0 |= (uint64_t)(in[2] - base) << 10;
  w0 |= (uint64_t)(in[3] - base) << 15;
  w0 |= (uint64_t)(in[4] - base) << 20;
  w0 |= (uint64_t)(in[5] - base) << 25;
  w0 |= (uint64_t)(in[6] - base) << 30;
  w0 |= (uint64_t)(in[7] - base) << 35;
  w0 |= (uint64_t)(in[8] - base) << 40;
  w0 |= (uint64_t)(in[9] - base) << 45;
  w0 |= (uint64_t)(in[10] - base) << 50;
  w0 |= (uint64_t)(in[11] - base) << 55;
  w0 |= (uint64_t)(in[12] - base) << 60;
  w1 = (uint64_t)(in[12] - base) >> 4;
  w1 |= (uint64_t)(in[13] - base) << 1;
  w1 |= (uint64_t)(in[14] - base) << 6;
  w1 |= (uint64_t)(in[15] - base) << 11;
  w1 |= (uint64_t)(in[16] - base) << 16;
  w1 |= (uint64_t)(in[17] - base) << 21;
  w1 |= (uint64_t)(in[18] - base) << 26;
  w1 |= (uint64_t)(in[19] - base) << 31;
  w1 |= (uint64_t)(in[20] - base) << 36;
  w1 |= (uint64_t)(in[21] - base) << 41;
  w1 |= (uint64_t)(in[22] - base) << 46;
  w1 |= (uint64_t)(in[23] - base) << 51;
  w1 |= (uint64_t)(in[24] - base) << 56;
  w1 |= (uint64_t)(in[25] - base) << 61;
  w2 = (uint64_t)(in[25] - base) >> 3;
  w2 |= (uint64_t)(in[26] - base) << 2;
  w2 |= (uint64_t)(in[27] - base) << 7;
  w2 |= (uint64_t)(in[28] - base) << 12;
  w2 |= (uint64_t)(in[29] - base) << 17;
  w2 |= (uint64_t)(in[30] - base) << 22;
  w2 |= (uint64_t)(in[31] - base) << 27;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 20;  /* we used up 20 output bytes */
}

/* we are going to pack 32 6-bit values, touching 3 64-bit words, using 24 bytes
 */
static void packforblock6(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  3 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 6;
  w0 |= (uint64_t)(in[2] - base) << 12;
  w0 |= (uint64_t)(in[3] - base) << 18;
  w0 |= (uint64_t)(in[4] - base) << 24;
  w0 |= (uint64_t)(in[5] - base) << 30;
  w0 |= (uint64_t)(in[6] - base) << 36;
  w0 |= (uint64_t)(in[7] - base) << 42;
  w0 |= (uint64_t)(in[8] - base) << 48;
  w0 |= (uint64_t)(in[9] - base) << 54;
  w0 |= (uint64_t)(in[10] - base) << 60;
  w1 = (uint64_t)(in[10] - base) >> 4;
  w1 |= (uint64_t)(in[11] - base) << 2;
  w1 |= (uint64_t)(in[12] - base) << 8;
  w1 |= (uint64_t)(in[13] - base) << 14;
  w1 |= (uint64_t)(in[14] - base) << 20;
  w1 |= (uint64_t)(in[15] - base) << 26;
  w1 |= (uint64_t)(in[16] - base) << 32;
  w1 |= (uint64_t)(in[17] - base) << 38;
  w1 |= (uint64_t)(in[18] - base) << 44;
  w1 |= (uint64_t)(in[19] - base) << 50;
  w1 |= (uint64_t)(in[20] - base) << 56;
  w1 |= (uint64_t)(in[21] - base) << 62;
  w2 = (uint64_t)(in[21] - base) >> 2;
  w2 |= (uint64_t)(in[22] - base) << 4;
  w2 |= (uint64_t)(in[23] - base) << 10;
  w2 |= (uint64_t)(in[24] - base) << 16;
  w2 |= (uint64_t)(in[25] - base) << 22;
  w2 |= (uint64_t)(in[26] - base) << 28;
  w2 |= (uint64_t)(in[27] - base) << 34;
  w2 |= (uint64_t)(in[28] - base) << 40;
  w2 |= (uint64_t)(in[29] - base) << 46;
  w2 |= (uint64_t)(in[30] - base) << 52;
  w2 |= (uint64_t)(in[31] - base) << 58;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 24;  /* we used up 24 output bytes */
}

/* we are going to pack 32 7-bit values, touching 4 64-bit words, using 28 bytes
 */
static void packforblock7(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  4 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 7;
  w0 |= (uint64_t)(in[2] - base) << 14;
  w0 |= (uint64_t)(in[3] - base) << 21;
  w0 |= (uint64_t)(in[4] - base) << 28;
  w0 |= (uint64_t)(in[5] - base) << 35;
  w0 |= (uint64_t)(in[6] - base) << 42;
  w0 |= (uint64_t)(in[7] - base) << 49;
  w0 |= (uint64_t)(in[8] - base) << 56;
  w0 |= (uint64_t)(in[9] - base) << 63;
  w1 = (uint64_t)(in[9] - base) >> 1;
  w1 |= (uint64_t)(in[10] - base) << 6;
  w1 |= (uint64_t)(in[11] - base) << 13;
  w1 |= (uint64_t)(in[12] - base) << 20;
  w1 |= (uint64_t)(in[13] - base) << 27;
  w1 |= (uint64_t)(in[14] - base) << 34;
  w1 |= (uint64_t)(in[15] - base) << 41;
  w1 |= (uint64_t)(in[16] - base) << 48;
  w1 |= (uint64_t)(in[17] - base) << 55;
  w1 |= (uint64_t)(in[18] - base) << 62;
  w2 = (uint64_t)(in[18] - base) >> 2;
  w2 |= (uint64_t)(in[19] - base) << 5;
  w2 |= (uint64_t)(in[20] - base) << 12;
  w2 |= (uint64_t)(in[21] - base) << 19;
  w2 |= (uint64_t)(in[22] - base) << 26;
  w2 |= (uint64_t)(in[23] - base) << 33;
  w2 |= (uint64_t)(in[24] - base) << 40;
  w2 |= (uint64_t)(in[25] - base) << 47;
  w2 |= (uint64_t)(in[26] - base) << 54;
  w2 |= (uint64_t)(in[27] - base) << 61;
  w3 = (uint64_t)(in[27] - base) >> 3;
  w3 |= (uint64_t)(in[28] - base) << 4;
  w3 |= (uint64_t)(in[29] - base) << 11;
  w3 |= (uint64_t)(in[30] - base) << 18;
  w3 |= (uint64_t)(in[31] - base) << 25;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 28;  /* we used up 28 output bytes */
}

/* we are going to pack 32 8-bit values, touching 4 64-bit words, using 32 bytes
 */
static void packforblock8(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  4 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 8;
  w0 |= (uint64_t)(in[2] - base) << 16;
  w0 |= (uint64_t)(in[3] - base) << 24;
  w0 |= (uint64_t)(in[4] - base) << 32;
  w0 |= (uint64_t)(in[5] - base) << 40;
  w0 |= (uint64_t)(in[6] - base) << 48;
  w0 |= (uint64_t)(in[7] - base) << 56;
  w1 = (uint64_t)(in[8] - base);
  w1 |= (uint64_t)(in[9] - base) << 8;
  w1 |= (uint64_t)(in[10] - base) << 16;
  w1 |= (uint64_t)(in[11] - base) << 24;
  w1 |= (uint64_t)(in[12] - base) << 32;
  w1 |= (uint64_t)(in[13] - base) << 40;
  w1 |= (uint64_t)(in[14] - base) << 48;
  w1 |= (uint64_t)(in[15] - base) << 56;
  w2 = (uint64_t)(in[16] - base);
  w2 |= (uint64_t)(in[17] - base) << 8;
  w2 |= (uint64_t)(in[18] - base) << 16;
  w2 |= (uint64_t)(in[19] - base) << 24;
  w2 |= (uint64_t)(in[20] - base) << 32;
  w2 |= (uint64_t)(in[21] - base) << 40;
  w2 |= (uint64_t)(in[22] - base) << 48;
  w2 |= (uint64_t)(in[23] - base) << 56;
  w3 = (uint64_t)(in[24] - base);
  w3 |= (uint64_t)(in[25] - base) << 8;
  w3 |= (uint64_t)(in[26] - base) << 16;
  w3 |= (uint64_t)(in[27] - base) << 24;
  w3 |= (uint64_t)(in[28] - base) << 32;
  w3 |= (uint64_t)(in[29] - base) << 40;
  w3 |= (uint64_t)(in[30] - base) << 48;
  w3 |= (uint64_t)(in[31] - base) << 56;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 32;  /* we used up 32 output bytes */
}

/* we are going to pack 32 9-bit values, touching 5 64-bit words, using 36 bytes
 */
static void packforblock9(const uint32_t base, const uint32_t **pin,
                          uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  5 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 9;
  w0 |= (uint64_t)(in[2] - base) << 18;
  w0 |= (uint64_t)(in[3] - base) << 27;
  w0 |= (uint64_t)(in[4] - base) << 36;
  w0 |= (uint64_t)(in[5] - base) << 45;
  w0 |= (uint64_t)(in[6] - base) << 54;
  w0 |= (uint64_t)(in[7] - base) << 63;
  w1 = (uint64_t)(in[7] - base) >> 1;
  w1 |= (uint64_t)(in[8] - base) << 8;
  w1 |= (uint64_t)(in[9] - base) << 17;
  w1 |= (uint64_t)(in[10] - base) << 26;
  w1 |= (uint64_t)(in[11] - base) << 35;
  w1 |= (uint64_t)(in[12] - base) << 44;
  w1 |= (uint64_t)(in[13] - base) << 53;
  w1 |= (uint64_t)(in[14] - base) << 62;
  w2 = (uint64_t)(in[14] - base) >> 2;
  w2 |= (uint64_t)(in[15] - base) << 7;
  w2 |= (uint64_t)(in[16] - base) << 16;
  w2 |= (uint64_t)(in[17] - base) << 25;
  w2 |= (uint64_t)(in[18] - base) << 34;
  w2 |= (uint64_t)(in[19] - base) << 43;
  w2 |= (uint64_t)(in[20] - base) << 52;
  w2 |= (uint64_t)(in[21] - base) << 61;
  w3 = (uint64_t)(in[21] - base) >> 3;
  w3 |= (uint64_t)(in[22] - base) << 6;
  w3 |= (uint64_t)(in[23] - base) << 15;
  w3 |= (uint64_t)(in[24] - base) << 24;
  w3 |= (uint64_t)(in[25] - base) << 33;
  w3 |= (uint64_t)(in[26] - base) << 42;
  w3 |= (uint64_t)(in[27] - base) << 51;
  w3 |= (uint64_t)(in[28] - base) << 60;
  w4 = (uint64_t)(in[28] - base) >> 4;
  w4 |= (uint64_t)(in[29] - base) << 5;
  w4 |= (uint64_t)(in[30] - base) << 14;
  w4 |= (uint64_t)(in[31] - base) << 23;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 36;  /* we used up 36 output bytes */
}

/* we are going to pack 32 10-bit values, touching 5 64-bit words, using 40
 * bytes */
static void packforblock10(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  5 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 10;
  w0 |= (uint64_t)(in[2] - base) << 20;
  w0 |= (uint64_t)(in[3] - base) << 30;
  w0 |= (uint64_t)(in[4] - base) << 40;
  w0 |= (uint64_t)(in[5] - base) << 50;
  w0 |= (uint64_t)(in[6] - base) << 60;
  w1 = (uint64_t)(in[6] - base) >> 4;
  w1 |= (uint64_t)(in[7] - base) << 6;
  w1 |= (uint64_t)(in[8] - base) << 16;
  w1 |= (uint64_t)(in[9] - base) << 26;
  w1 |= (uint64_t)(in[10] - base) << 36;
  w1 |= (uint64_t)(in[11] - base) << 46;
  w1 |= (uint64_t)(in[12] - base) << 56;
  w2 = (uint64_t)(in[12] - base) >> 8;
  w2 |= (uint64_t)(in[13] - base) << 2;
  w2 |= (uint64_t)(in[14] - base) << 12;
  w2 |= (uint64_t)(in[15] - base) << 22;
  w2 |= (uint64_t)(in[16] - base) << 32;
  w2 |= (uint64_t)(in[17] - base) << 42;
  w2 |= (uint64_t)(in[18] - base) << 52;
  w2 |= (uint64_t)(in[19] - base) << 62;
  w3 = (uint64_t)(in[19] - base) >> 2;
  w3 |= (uint64_t)(in[20] - base) << 8;
  w3 |= (uint64_t)(in[21] - base) << 18;
  w3 |= (uint64_t)(in[22] - base) << 28;
  w3 |= (uint64_t)(in[23] - base) << 38;
  w3 |= (uint64_t)(in[24] - base) << 48;
  w3 |= (uint64_t)(in[25] - base) << 58;
  w4 = (uint64_t)(in[25] - base) >> 6;
  w4 |= (uint64_t)(in[26] - base) << 4;
  w4 |= (uint64_t)(in[27] - base) << 14;
  w4 |= (uint64_t)(in[28] - base) << 24;
  w4 |= (uint64_t)(in[29] - base) << 34;
  w4 |= (uint64_t)(in[30] - base) << 44;
  w4 |= (uint64_t)(in[31] - base) << 54;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 40;  /* we used up 40 output bytes */
}

/* we are going to pack 32 11-bit values, touching 6 64-bit words, using 44
 * bytes */
static void packforblock11(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  6 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 11;
  w0 |= (uint64_t)(in[2] - base) << 22;
  w0 |= (uint64_t)(in[3] - base) << 33;
  w0 |= (uint64_t)(in[4] - base) << 44;
  w0 |= (uint64_t)(in[5] - base) << 55;
  w1 = (uint64_t)(in[5] - base) >> 9;
  w1 |= (uint64_t)(in[6] - base) << 2;
  w1 |= (uint64_t)(in[7] - base) << 13;
  w1 |= (uint64_t)(in[8] - base) << 24;
  w1 |= (uint64_t)(in[9] - base) << 35;
  w1 |= (uint64_t)(in[10] - base) << 46;
  w1 |= (uint64_t)(in[11] - base) << 57;
  w2 = (uint64_t)(in[11] - base) >> 7;
  w2 |= (uint64_t)(in[12] - base) << 4;
  w2 |= (uint64_t)(in[13] - base) << 15;
  w2 |= (uint64_t)(in[14] - base) << 26;
  w2 |= (uint64_t)(in[15] - base) << 37;
  w2 |= (uint64_t)(in[16] - base) << 48;
  w2 |= (uint64_t)(in[17] - base) << 59;
  w3 = (uint64_t)(in[17] - base) >> 5;
  w3 |= (uint64_t)(in[18] - base) << 6;
  w3 |= (uint64_t)(in[19] - base) << 17;
  w3 |= (uint64_t)(in[20] - base) << 28;
  w3 |= (uint64_t)(in[21] - base) << 39;
  w3 |= (uint64_t)(in[22] - base) << 50;
  w3 |= (uint64_t)(in[23] - base) << 61;
  w4 = (uint64_t)(in[23] - base) >> 3;
  w4 |= (uint64_t)(in[24] - base) << 8;
  w4 |= (uint64_t)(in[25] - base) << 19;
  w4 |= (uint64_t)(in[26] - base) << 30;
  w4 |= (uint64_t)(in[27] - base) << 41;
  w4 |= (uint64_t)(in[28] - base) << 52;
  w4 |= (uint64_t)(in[29] - base) << 63;
  w5 = (uint64_t)(in[29] - base) >> 1;
  w5 |= (uint64_t)(in[30] - base) << 10;
  w5 |= (uint64_t)(in[31] - base) << 21;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 44;  /* we used up 44 output bytes */
}

/* we are going to pack 32 12-bit values, touching 6 64-bit words, using 48
 * bytes */
static void packforblock12(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  6 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 12;
  w0 |= (uint64_t)(in[2] - base) << 24;
  w0 |= (uint64_t)(in[3] - base) << 36;
  w0 |= (uint64_t)(in[4] - base) << 48;
  w0 |= (uint64_t)(in[5] - base) << 60;
  w1 = (uint64_t)(in[5] - base) >> 4;
  w1 |= (uint64_t)(in[6] - base) << 8;
  w1 |= (uint64_t)(in[7] - base) << 20;
  w1 |= (uint64_t)(in[8] - base) << 32;
  w1 |= (uint64_t)(in[9] - base) << 44;
  w1 |= (uint64_t)(in[10] - base) << 56;
  w2 = (uint64_t)(in[10] - base) >> 8;
  w2 |= (uint64_t)(in[11] - base) << 4;
  w2 |= (uint64_t)(in[12] - base) << 16;
  w2 |= (uint64_t)(in[13] - base) << 28;
  w2 |= (uint64_t)(in[14] - base) << 40;
  w2 |= (uint64_t)(in[15] - base) << 52;
  w3 = (uint64_t)(in[16] - base);
  w3 |= (uint64_t)(in[17] - base) << 12;
  w3 |= (uint64_t)(in[18] - base) << 24;
  w3 |= (uint64_t)(in[19] - base) << 36;
  w3 |= (uint64_t)(in[20] - base) << 48;
  w3 |= (uint64_t)(in[21] - base) << 60;
  w4 = (uint64_t)(in[21] - base) >> 4;
  w4 |= (uint64_t)(in[22] - base) << 8;
  w4 |= (uint64_t)(in[23] - base) << 20;
  w4 |= (uint64_t)(in[24] - base) << 32;
  w4 |= (uint64_t)(in[25] - base) << 44;
  w4 |= (uint64_t)(in[26] - base) << 56;
  w5 = (uint64_t)(in[26] - base) >> 8;
  w5 |= (uint64_t)(in[27] - base) << 4;
  w5 |= (uint64_t)(in[28] - base) << 16;
  w5 |= (uint64_t)(in[29] - base) << 28;
  w5 |= (uint64_t)(in[30] - base) << 40;
  w5 |= (uint64_t)(in[31] - base) << 52;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 48;  /* we used up 48 output bytes */
}

/* we are going to pack 32 13-bit values, touching 7 64-bit words, using 52
 * bytes */
static void packforblock13(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  7 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 13;
  w0 |= (uint64_t)(in[2] - base) << 26;
  w0 |= (uint64_t)(in[3] - base) << 39;
  w0 |= (uint64_t)(in[4] - base) << 52;
  w1 = (uint64_t)(in[4] - base) >> 12;
  w1 |= (uint64_t)(in[5] - base) << 1;
  w1 |= (uint64_t)(in[6] - base) << 14;
  w1 |= (uint64_t)(in[7] - base) << 27;
  w1 |= (uint64_t)(in[8] - base) << 40;
  w1 |= (uint64_t)(in[9] - base) << 53;
  w2 = (uint64_t)(in[9] - base) >> 11;
  w2 |= (uint64_t)(in[10] - base) << 2;
  w2 |= (uint64_t)(in[11] - base) << 15;
  w2 |= (uint64_t)(in[12] - base) << 28;
  w2 |= (uint64_t)(in[13] - base) << 41;
  w2 |= (uint64_t)(in[14] - base) << 54;
  w3 = (uint64_t)(in[14] - base) >> 10;
  w3 |= (uint64_t)(in[15] - base) << 3;
  w3 |= (uint64_t)(in[16] - base) << 16;
  w3 |= (uint64_t)(in[17] - base) << 29;
  w3 |= (uint64_t)(in[18] - base) << 42;
  w3 |= (uint64_t)(in[19] - base) << 55;
  w4 = (uint64_t)(in[19] - base) >> 9;
  w4 |= (uint64_t)(in[20] - base) << 4;
  w4 |= (uint64_t)(in[21] - base) << 17;
  w4 |= (uint64_t)(in[22] - base) << 30;
  w4 |= (uint64_t)(in[23] - base) << 43;
  w4 |= (uint64_t)(in[24] - base) << 56;
  w5 = (uint64_t)(in[24] - base) >> 8;
  w5 |= (uint64_t)(in[25] - base) << 5;
  w5 |= (uint64_t)(in[26] - base) << 18;
  w5 |= (uint64_t)(in[27] - base) << 31;
  w5 |= (uint64_t)(in[28] - base) << 44;
  w5 |= (uint64_t)(in[29] - base) << 57;
  w6 = (uint64_t)(in[29] - base) >> 7;
  w6 |= (uint64_t)(in[30] - base) << 6;
  w6 |= (uint64_t)(in[31] - base) << 19;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 52;  /* we used up 52 output bytes */
}

/* we are going to pack 32 14-bit values, touching 7 64-bit words, using 56
 * bytes */
static void packforblock14(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  7 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 14;
  w0 |= (uint64_t)(in[2] - base) << 28;
  w0 |= (uint64_t)(in[3] - base) << 42;
  w0 |= (uint64_t)(in[4] - base) << 56;
  w1 = (uint64_t)(in[4] - base) >> 8;
  w1 |= (uint64_t)(in[5] - base) << 6;
  w1 |= (uint64_t)(in[6] - base) << 20;
  w1 |= (uint64_t)(in[7] - base) << 34;
  w1 |= (uint64_t)(in[8] - base) << 48;
  w1 |= (uint64_t)(in[9] - base) << 62;
  w2 = (uint64_t)(in[9] - base) >> 2;
  w2 |= (uint64_t)(in[10] - base) << 12;
  w2 |= (uint64_t)(in[11] - base) << 26;
  w2 |= (uint64_t)(in[12] - base) << 40;
  w2 |= (uint64_t)(in[13] - base) << 54;
  w3 = (uint64_t)(in[13] - base) >> 10;
  w3 |= (uint64_t)(in[14] - base) << 4;
  w3 |= (uint64_t)(in[15] - base) << 18;
  w3 |= (uint64_t)(in[16] - base) << 32;
  w3 |= (uint64_t)(in[17] - base) << 46;
  w3 |= (uint64_t)(in[18] - base) << 60;
  w4 = (uint64_t)(in[18] - base) >> 4;
  w4 |= (uint64_t)(in[19] - base) << 10;
  w4 |= (uint64_t)(in[20] - base) << 24;
  w4 |= (uint64_t)(in[21] - base) << 38;
  w4 |= (uint64_t)(in[22] - base) << 52;
  w5 = (uint64_t)(in[22] - base) >> 12;
  w5 |= (uint64_t)(in[23] - base) << 2;
  w5 |= (uint64_t)(in[24] - base) << 16;
  w5 |= (uint64_t)(in[25] - base) << 30;
  w5 |= (uint64_t)(in[26] - base) << 44;
  w5 |= (uint64_t)(in[27] - base) << 58;
  w6 = (uint64_t)(in[27] - base) >> 6;
  w6 |= (uint64_t)(in[28] - base) << 8;
  w6 |= (uint64_t)(in[29] - base) << 22;
  w6 |= (uint64_t)(in[30] - base) << 36;
  w6 |= (uint64_t)(in[31] - base) << 50;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 56;  /* we used up 56 output bytes */
}

/* we are going to pack 32 15-bit values, touching 8 64-bit words, using 60
 * bytes */
static void packforblock15(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  8 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 15;
  w0 |= (uint64_t)(in[2] - base) << 30;
  w0 |= (uint64_t)(in[3] - base) << 45;
  w0 |= (uint64_t)(in[4] - base) << 60;
  w1 = (uint64_t)(in[4] - base) >> 4;
  w1 |= (uint64_t)(in[5] - base) << 11;
  w1 |= (uint64_t)(in[6] - base) << 26;
  w1 |= (uint64_t)(in[7] - base) << 41;
  w1 |= (uint64_t)(in[8] - base) << 56;
  w2 = (uint64_t)(in[8] - base) >> 8;
  w2 |= (uint64_t)(in[9] - base) << 7;
  w2 |= (uint64_t)(in[10] - base) << 22;
  w2 |= (uint64_t)(in[11] - base) << 37;
  w2 |= (uint64_t)(in[12] - base) << 52;
  w3 = (uint64_t)(in[12] - base) >> 12;
  w3 |= (uint64_t)(in[13] - base) << 3;
  w3 |= (uint64_t)(in[14] - base) << 18;
  w3 |= (uint64_t)(in[15] - base) << 33;
  w3 |= (uint64_t)(in[16] - base) << 48;
  w3 |= (uint64_t)(in[17] - base) << 63;
  w4 = (uint64_t)(in[17] - base) >> 1;
  w4 |= (uint64_t)(in[18] - base) << 14;
  w4 |= (uint64_t)(in[19] - base) << 29;
  w4 |= (uint64_t)(in[20] - base) << 44;
  w4 |= (uint64_t)(in[21] - base) << 59;
  w5 = (uint64_t)(in[21] - base) >> 5;
  w5 |= (uint64_t)(in[22] - base) << 10;
  w5 |= (uint64_t)(in[23] - base) << 25;
  w5 |= (uint64_t)(in[24] - base) << 40;
  w5 |= (uint64_t)(in[25] - base) << 55;
  w6 = (uint64_t)(in[25] - base) >> 9;
  w6 |= (uint64_t)(in[26] - base) << 6;
  w6 |= (uint64_t)(in[27] - base) << 21;
  w6 |= (uint64_t)(in[28] - base) << 36;
  w6 |= (uint64_t)(in[29] - base) << 51;
  w7 = (uint64_t)(in[29] - base) >> 13;
  w7 |= (uint64_t)(in[30] - base) << 2;
  w7 |= (uint64_t)(in[31] - base) << 17;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 60;  /* we used up 60 output bytes */
}

/* we are going to pack 32 16-bit values, touching 8 64-bit words, using 64
 * bytes */
static void packforblock16(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  8 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 16;
  w0 |= (uint64_t)(in[2] - base) << 32;
  w0 |= (uint64_t)(in[3] - base) << 48;
  w1 = (uint64_t)(in[4] - base);
  w1 |= (uint64_t)(in[5] - base) << 16;
  w1 |= (uint64_t)(in[6] - base) << 32;
  w1 |= (uint64_t)(in[7] - base) << 48;
  w2 = (uint64_t)(in[8] - base);
  w2 |= (uint64_t)(in[9] - base) << 16;
  w2 |= (uint64_t)(in[10] - base) << 32;
  w2 |= (uint64_t)(in[11] - base) << 48;
  w3 = (uint64_t)(in[12] - base);
  w3 |= (uint64_t)(in[13] - base) << 16;
  w3 |= (uint64_t)(in[14] - base) << 32;
  w3 |= (uint64_t)(in[15] - base) << 48;
  w4 = (uint64_t)(in[16] - base);
  w4 |= (uint64_t)(in[17] - base) << 16;
  w4 |= (uint64_t)(in[18] - base) << 32;
  w4 |= (uint64_t)(in[19] - base) << 48;
  w5 = (uint64_t)(in[20] - base);
  w5 |= (uint64_t)(in[21] - base) << 16;
  w5 |= (uint64_t)(in[22] - base) << 32;
  w5 |= (uint64_t)(in[23] - base) << 48;
  w6 = (uint64_t)(in[24] - base);
  w6 |= (uint64_t)(in[25] - base) << 16;
  w6 |= (uint64_t)(in[26] - base) << 32;
  w6 |= (uint64_t)(in[27] - base) << 48;
  w7 = (uint64_t)(in[28] - base);
  w7 |= (uint64_t)(in[29] - base) << 16;
  w7 |= (uint64_t)(in[30] - base) << 32;
  w7 |= (uint64_t)(in[31] - base) << 48;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 64;  /* we used up 64 output bytes */
}

/* we are going to pack 32 17-bit values, touching 9 64-bit words, using 68
 * bytes */
static void packforblock17(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  9 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 17;
  w0 |= (uint64_t)(in[2] - base) << 34;
  w0 |= (uint64_t)(in[3] - base) << 51;
  w1 = (uint64_t)(in[3] - base) >> 13;
  w1 |= (uint64_t)(in[4] - base) << 4;
  w1 |= (uint64_t)(in[5] - base) << 21;
  w1 |= (uint64_t)(in[6] - base) << 38;
  w1 |= (uint64_t)(in[7] - base) << 55;
  w2 = (uint64_t)(in[7] - base) >> 9;
  w2 |= (uint64_t)(in[8] - base) << 8;
  w2 |= (uint64_t)(in[9] - base) << 25;
  w2 |= (uint64_t)(in[10] - base) << 42;
  w2 |= (uint64_t)(in[11] - base) << 59;
  w3 = (uint64_t)(in[11] - base) >> 5;
  w3 |= (uint64_t)(in[12] - base) << 12;
  w3 |= (uint64_t)(in[13] - base) << 29;
  w3 |= (uint64_t)(in[14] - base) << 46;
  w3 |= (uint64_t)(in[15] - base) << 63;
  w4 = (uint64_t)(in[15] - base) >> 1;
  w4 |= (uint64_t)(in[16] - base) << 16;
  w4 |= (uint64_t)(in[17] - base) << 33;
  w4 |= (uint64_t)(in[18] - base) << 50;
  w5 = (uint64_t)(in[18] - base) >> 14;
  w5 |= (uint64_t)(in[19] - base) << 3;
  w5 |= (uint64_t)(in[20] - base) << 20;
  w5 |= (uint64_t)(in[21] - base) << 37;
  w5 |= (uint64_t)(in[22] - base) << 54;
  w6 = (uint64_t)(in[22] - base) >> 10;
  w6 |= (uint64_t)(in[23] - base) << 7;
  w6 |= (uint64_t)(in[24] - base) << 24;
  w6 |= (uint64_t)(in[25] - base) << 41;
  w6 |= (uint64_t)(in[26] - base) << 58;
  w7 = (uint64_t)(in[26] - base) >> 6;
  w7 |= (uint64_t)(in[27] - base) << 11;
  w7 |= (uint64_t)(in[28] - base) << 28;
  w7 |= (uint64_t)(in[29] - base) << 45;
  w7 |= (uint64_t)(in[30] - base) << 62;
  w8 = (uint64_t)(in[30] - base) >> 2;
  w8 |= (uint64_t)(in[31] - base) << 15;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 68;  /* we used up 68 output bytes */
}

/* we are going to pack 32 18-bit values, touching 9 64-bit words, using 72
 * bytes */
static void packforblock18(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  9 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 18;
  w0 |= (uint64_t)(in[2] - base) << 36;
  w0 |= (uint64_t)(in[3] - base) << 54;
  w1 = (uint64_t)(in[3] - base) >> 10;
  w1 |= (uint64_t)(in[4] - base) << 8;
  w1 |= (uint64_t)(in[5] - base) << 26;
  w1 |= (uint64_t)(in[6] - base) << 44;
  w1 |= (uint64_t)(in[7] - base) << 62;
  w2 = (uint64_t)(in[7] - base) >> 2;
  w2 |= (uint64_t)(in[8] - base) << 16;
  w2 |= (uint64_t)(in[9] - base) << 34;
  w2 |= (uint64_t)(in[10] - base) << 52;
  w3 = (uint64_t)(in[10] - base) >> 12;
  w3 |= (uint64_t)(in[11] - base) << 6;
  w3 |= (uint64_t)(in[12] - base) << 24;
  w3 |= (uint64_t)(in[13] - base) << 42;
  w3 |= (uint64_t)(in[14] - base) << 60;
  w4 = (uint64_t)(in[14] - base) >> 4;
  w4 |= (uint64_t)(in[15] - base) << 14;
  w4 |= (uint64_t)(in[16] - base) << 32;
  w4 |= (uint64_t)(in[17] - base) << 50;
  w5 = (uint64_t)(in[17] - base) >> 14;
  w5 |= (uint64_t)(in[18] - base) << 4;
  w5 |= (uint64_t)(in[19] - base) << 22;
  w5 |= (uint64_t)(in[20] - base) << 40;
  w5 |= (uint64_t)(in[21] - base) << 58;
  w6 = (uint64_t)(in[21] - base) >> 6;
  w6 |= (uint64_t)(in[22] - base) << 12;
  w6 |= (uint64_t)(in[23] - base) << 30;
  w6 |= (uint64_t)(in[24] - base) << 48;
  w7 = (uint64_t)(in[24] - base) >> 16;
  w7 |= (uint64_t)(in[25] - base) << 2;
  w7 |= (uint64_t)(in[26] - base) << 20;
  w7 |= (uint64_t)(in[27] - base) << 38;
  w7 |= (uint64_t)(in[28] - base) << 56;
  w8 = (uint64_t)(in[28] - base) >> 8;
  w8 |= (uint64_t)(in[29] - base) << 10;
  w8 |= (uint64_t)(in[30] - base) << 28;
  w8 |= (uint64_t)(in[31] - base) << 46;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 72;  /* we used up 72 output bytes */
}

/* we are going to pack 32 19-bit values, touching 10 64-bit words, using 76
 * bytes */
static void packforblock19(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  10 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 19;
  w0 |= (uint64_t)(in[2] - base) << 38;
  w0 |= (uint64_t)(in[3] - base) << 57;
  w1 = (uint64_t)(in[3] - base) >> 7;
  w1 |= (uint64_t)(in[4] - base) << 12;
  w1 |= (uint64_t)(in[5] - base) << 31;
  w1 |= (uint64_t)(in[6] - base) << 50;
  w2 = (uint64_t)(in[6] - base) >> 14;
  w2 |= (uint64_t)(in[7] - base) << 5;
  w2 |= (uint64_t)(in[8] - base) << 24;
  w2 |= (uint64_t)(in[9] - base) << 43;
  w2 |= (uint64_t)(in[10] - base) << 62;
  w3 = (uint64_t)(in[10] - base) >> 2;
  w3 |= (uint64_t)(in[11] - base) << 17;
  w3 |= (uint64_t)(in[12] - base) << 36;
  w3 |= (uint64_t)(in[13] - base) << 55;
  w4 = (uint64_t)(in[13] - base) >> 9;
  w4 |= (uint64_t)(in[14] - base) << 10;
  w4 |= (uint64_t)(in[15] - base) << 29;
  w4 |= (uint64_t)(in[16] - base) << 48;
  w5 = (uint64_t)(in[16] - base) >> 16;
  w5 |= (uint64_t)(in[17] - base) << 3;
  w5 |= (uint64_t)(in[18] - base) << 22;
  w5 |= (uint64_t)(in[19] - base) << 41;
  w5 |= (uint64_t)(in[20] - base) << 60;
  w6 = (uint64_t)(in[20] - base) >> 4;
  w6 |= (uint64_t)(in[21] - base) << 15;
  w6 |= (uint64_t)(in[22] - base) << 34;
  w6 |= (uint64_t)(in[23] - base) << 53;
  w7 = (uint64_t)(in[23] - base) >> 11;
  w7 |= (uint64_t)(in[24] - base) << 8;
  w7 |= (uint64_t)(in[25] - base) << 27;
  w7 |= (uint64_t)(in[26] - base) << 46;
  w8 = (uint64_t)(in[26] - base) >> 18;
  w8 |= (uint64_t)(in[27] - base) << 1;
  w8 |= (uint64_t)(in[28] - base) << 20;
  w8 |= (uint64_t)(in[29] - base) << 39;
  w8 |= (uint64_t)(in[30] - base) << 58;
  w9 = (uint64_t)(in[30] - base) >> 6;
  w9 |= (uint64_t)(in[31] - base) << 13;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 76;  /* we used up 76 output bytes */
}

/* we are going to pack 32 20-bit values, touching 10 64-bit words, using 80
 * bytes */
static void packforblock20(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  10 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 20;
  w0 |= (uint64_t)(in[2] - base) << 40;
  w0 |= (uint64_t)(in[3] - base) << 60;
  w1 = (uint64_t)(in[3] - base) >> 4;
  w1 |= (uint64_t)(in[4] - base) << 16;
  w1 |= (uint64_t)(in[5] - base) << 36;
  w1 |= (uint64_t)(in[6] - base) << 56;
  w2 = (uint64_t)(in[6] - base) >> 8;
  w2 |= (uint64_t)(in[7] - base) << 12;
  w2 |= (uint64_t)(in[8] - base) << 32;
  w2 |= (uint64_t)(in[9] - base) << 52;
  w3 = (uint64_t)(in[9] - base) >> 12;
  w3 |= (uint64_t)(in[10] - base) << 8;
  w3 |= (uint64_t)(in[11] - base) << 28;
  w3 |= (uint64_t)(in[12] - base) << 48;
  w4 = (uint64_t)(in[12] - base) >> 16;
  w4 |= (uint64_t)(in[13] - base) << 4;
  w4 |= (uint64_t)(in[14] - base) << 24;
  w4 |= (uint64_t)(in[15] - base) << 44;
  w5 = (uint64_t)(in[16] - base);
  w5 |= (uint64_t)(in[17] - base) << 20;
  w5 |= (uint64_t)(in[18] - base) << 40;
  w5 |= (uint64_t)(in[19] - base) << 60;
  w6 = (uint64_t)(in[19] - base) >> 4;
  w6 |= (uint64_t)(in[20] - base) << 16;
  w6 |= (uint64_t)(in[21] - base) << 36;
  w6 |= (uint64_t)(in[22] - base) << 56;
  w7 = (uint64_t)(in[22] - base) >> 8;
  w7 |= (uint64_t)(in[23] - base) << 12;
  w7 |= (uint64_t)(in[24] - base) << 32;
  w7 |= (uint64_t)(in[25] - base) << 52;
  w8 = (uint64_t)(in[25] - base) >> 12;
  w8 |= (uint64_t)(in[26] - base) << 8;
  w8 |= (uint64_t)(in[27] - base) << 28;
  w8 |= (uint64_t)(in[28] - base) << 48;
  w9 = (uint64_t)(in[28] - base) >> 16;
  w9 |= (uint64_t)(in[29] - base) << 4;
  w9 |= (uint64_t)(in[30] - base) << 24;
  w9 |= (uint64_t)(in[31] - base) << 44;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 80;  /* we used up 80 output bytes */
}

/* we are going to pack 32 21-bit values, touching 11 64-bit words, using 84
 * bytes */
static void packforblock21(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  11 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 21;
  w0 |= (uint64_t)(in[2] - base) << 42;
  w0 |= (uint64_t)(in[3] - base) << 63;
  w1 = (uint64_t)(in[3] - base) >> 1;
  w1 |= (uint64_t)(in[4] - base) << 20;
  w1 |= (uint64_t)(in[5] - base) << 41;
  w1 |= (uint64_t)(in[6] - base) << 62;
  w2 = (uint64_t)(in[6] - base) >> 2;
  w2 |= (uint64_t)(in[7] - base) << 19;
  w2 |= (uint64_t)(in[8] - base) << 40;
  w2 |= (uint64_t)(in[9] - base) << 61;
  w3 = (uint64_t)(in[9] - base) >> 3;
  w3 |= (uint64_t)(in[10] - base) << 18;
  w3 |= (uint64_t)(in[11] - base) << 39;
  w3 |= (uint64_t)(in[12] - base) << 60;
  w4 = (uint64_t)(in[12] - base) >> 4;
  w4 |= (uint64_t)(in[13] - base) << 17;
  w4 |= (uint64_t)(in[14] - base) << 38;
  w4 |= (uint64_t)(in[15] - base) << 59;
  w5 = (uint64_t)(in[15] - base) >> 5;
  w5 |= (uint64_t)(in[16] - base) << 16;
  w5 |= (uint64_t)(in[17] - base) << 37;
  w5 |= (uint64_t)(in[18] - base) << 58;
  w6 = (uint64_t)(in[18] - base) >> 6;
  w6 |= (uint64_t)(in[19] - base) << 15;
  w6 |= (uint64_t)(in[20] - base) << 36;
  w6 |= (uint64_t)(in[21] - base) << 57;
  w7 = (uint64_t)(in[21] - base) >> 7;
  w7 |= (uint64_t)(in[22] - base) << 14;
  w7 |= (uint64_t)(in[23] - base) << 35;
  w7 |= (uint64_t)(in[24] - base) << 56;
  w8 = (uint64_t)(in[24] - base) >> 8;
  w8 |= (uint64_t)(in[25] - base) << 13;
  w8 |= (uint64_t)(in[26] - base) << 34;
  w8 |= (uint64_t)(in[27] - base) << 55;
  w9 = (uint64_t)(in[27] - base) >> 9;
  w9 |= (uint64_t)(in[28] - base) << 12;
  w9 |= (uint64_t)(in[29] - base) << 33;
  w9 |= (uint64_t)(in[30] - base) << 54;
  w10 = (uint64_t)(in[30] - base) >> 10;
  w10 |= (uint64_t)(in[31] - base) << 11;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 84;  /* we used up 84 output bytes */
}

/* we are going to pack 32 22-bit values, touching 11 64-bit words, using 88
 * bytes */
static void packforblock22(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  11 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 22;
  w0 |= (uint64_t)(in[2] - base) << 44;
  w1 = (uint64_t)(in[2] - base) >> 20;
  w1 |= (uint64_t)(in[3] - base) << 2;
  w1 |= (uint64_t)(in[4] - base) << 24;
  w1 |= (uint64_t)(in[5] - base) << 46;
  w2 = (uint64_t)(in[5] - base) >> 18;
  w2 |= (uint64_t)(in[6] - base) << 4;
  w2 |= (uint64_t)(in[7] - base) << 26;
  w2 |= (uint64_t)(in[8] - base) << 48;
  w3 = (uint64_t)(in[8] - base) >> 16;
  w3 |= (uint64_t)(in[9] - base) << 6;
  w3 |= (uint64_t)(in[10] - base) << 28;
  w3 |= (uint64_t)(in[11] - base) << 50;
  w4 = (uint64_t)(in[11] - base) >> 14;
  w4 |= (uint64_t)(in[12] - base) << 8;
  w4 |= (uint64_t)(in[13] - base) << 30;
  w4 |= (uint64_t)(in[14] - base) << 52;
  w5 = (uint64_t)(in[14] - base) >> 12;
  w5 |= (uint64_t)(in[15] - base) << 10;
  w5 |= (uint64_t)(in[16] - base) << 32;
  w5 |= (uint64_t)(in[17] - base) << 54;
  w6 = (uint64_t)(in[17] - base) >> 10;
  w6 |= (uint64_t)(in[18] - base) << 12;
  w6 |= (uint64_t)(in[19] - base) << 34;
  w6 |= (uint64_t)(in[20] - base) << 56;
  w7 = (uint64_t)(in[20] - base) >> 8;
  w7 |= (uint64_t)(in[21] - base) << 14;
  w7 |= (uint64_t)(in[22] - base) << 36;
  w7 |= (uint64_t)(in[23] - base) << 58;
  w8 = (uint64_t)(in[23] - base) >> 6;
  w8 |= (uint64_t)(in[24] - base) << 16;
  w8 |= (uint64_t)(in[25] - base) << 38;
  w8 |= (uint64_t)(in[26] - base) << 60;
  w9 = (uint64_t)(in[26] - base) >> 4;
  w9 |= (uint64_t)(in[27] - base) << 18;
  w9 |= (uint64_t)(in[28] - base) << 40;
  w9 |= (uint64_t)(in[29] - base) << 62;
  w10 = (uint64_t)(in[29] - base) >> 2;
  w10 |= (uint64_t)(in[30] - base) << 20;
  w10 |= (uint64_t)(in[31] - base) << 42;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 88;  /* we used up 88 output bytes */
}

/* we are going to pack 32 23-bit values, touching 12 64-bit words, using 92
 * bytes */
static void packforblock23(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  12 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 23;
  w0 |= (uint64_t)(in[2] - base) << 46;
  w1 = (uint64_t)(in[2] - base) >> 18;
  w1 |= (uint64_t)(in[3] - base) << 5;
  w1 |= (uint64_t)(in[4] - base) << 28;
  w1 |= (uint64_t)(in[5] - base) << 51;
  w2 = (uint64_t)(in[5] - base) >> 13;
  w2 |= (uint64_t)(in[6] - base) << 10;
  w2 |= (uint64_t)(in[7] - base) << 33;
  w2 |= (uint64_t)(in[8] - base) << 56;
  w3 = (uint64_t)(in[8] - base) >> 8;
  w3 |= (uint64_t)(in[9] - base) << 15;
  w3 |= (uint64_t)(in[10] - base) << 38;
  w3 |= (uint64_t)(in[11] - base) << 61;
  w4 = (uint64_t)(in[11] - base) >> 3;
  w4 |= (uint64_t)(in[12] - base) << 20;
  w4 |= (uint64_t)(in[13] - base) << 43;
  w5 = (uint64_t)(in[13] - base) >> 21;
  w5 |= (uint64_t)(in[14] - base) << 2;
  w5 |= (uint64_t)(in[15] - base) << 25;
  w5 |= (uint64_t)(in[16] - base) << 48;
  w6 = (uint64_t)(in[16] - base) >> 16;
  w6 |= (uint64_t)(in[17] - base) << 7;
  w6 |= (uint64_t)(in[18] - base) << 30;
  w6 |= (uint64_t)(in[19] - base) << 53;
  w7 = (uint64_t)(in[19] - base) >> 11;
  w7 |= (uint64_t)(in[20] - base) << 12;
  w7 |= (uint64_t)(in[21] - base) << 35;
  w7 |= (uint64_t)(in[22] - base) << 58;
  w8 = (uint64_t)(in[22] - base) >> 6;
  w8 |= (uint64_t)(in[23] - base) << 17;
  w8 |= (uint64_t)(in[24] - base) << 40;
  w8 |= (uint64_t)(in[25] - base) << 63;
  w9 = (uint64_t)(in[25] - base) >> 1;
  w9 |= (uint64_t)(in[26] - base) << 22;
  w9 |= (uint64_t)(in[27] - base) << 45;
  w10 = (uint64_t)(in[27] - base) >> 19;
  w10 |= (uint64_t)(in[28] - base) << 4;
  w10 |= (uint64_t)(in[29] - base) << 27;
  w10 |= (uint64_t)(in[30] - base) << 50;
  w11 = (uint64_t)(in[30] - base) >> 14;
  w11 |= (uint64_t)(in[31] - base) << 9;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 92;  /* we used up 92 output bytes */
}

/* we are going to pack 32 24-bit values, touching 12 64-bit words, using 96
 * bytes */
static void packforblock24(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  12 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 24;
  w0 |= (uint64_t)(in[2] - base) << 48;
  w1 = (uint64_t)(in[2] - base) >> 16;
  w1 |= (uint64_t)(in[3] - base) << 8;
  w1 |= (uint64_t)(in[4] - base) << 32;
  w1 |= (uint64_t)(in[5] - base) << 56;
  w2 = (uint64_t)(in[5] - base) >> 8;
  w2 |= (uint64_t)(in[6] - base) << 16;
  w2 |= (uint64_t)(in[7] - base) << 40;
  w3 = (uint64_t)(in[8] - base);
  w3 |= (uint64_t)(in[9] - base) << 24;
  w3 |= (uint64_t)(in[10] - base) << 48;
  w4 = (uint64_t)(in[10] - base) >> 16;
  w4 |= (uint64_t)(in[11] - base) << 8;
  w4 |= (uint64_t)(in[12] - base) << 32;
  w4 |= (uint64_t)(in[13] - base) << 56;
  w5 = (uint64_t)(in[13] - base) >> 8;
  w5 |= (uint64_t)(in[14] - base) << 16;
  w5 |= (uint64_t)(in[15] - base) << 40;
  w6 = (uint64_t)(in[16] - base);
  w6 |= (uint64_t)(in[17] - base) << 24;
  w6 |= (uint64_t)(in[18] - base) << 48;
  w7 = (uint64_t)(in[18] - base) >> 16;
  w7 |= (uint64_t)(in[19] - base) << 8;
  w7 |= (uint64_t)(in[20] - base) << 32;
  w7 |= (uint64_t)(in[21] - base) << 56;
  w8 = (uint64_t)(in[21] - base) >> 8;
  w8 |= (uint64_t)(in[22] - base) << 16;
  w8 |= (uint64_t)(in[23] - base) << 40;
  w9 = (uint64_t)(in[24] - base);
  w9 |= (uint64_t)(in[25] - base) << 24;
  w9 |= (uint64_t)(in[26] - base) << 48;
  w10 = (uint64_t)(in[26] - base) >> 16;
  w10 |= (uint64_t)(in[27] - base) << 8;
  w10 |= (uint64_t)(in[28] - base) << 32;
  w10 |= (uint64_t)(in[29] - base) << 56;
  w11 = (uint64_t)(in[29] - base) >> 8;
  w11 |= (uint64_t)(in[30] - base) << 16;
  w11 |= (uint64_t)(in[31] - base) << 40;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 96;  /* we used up 96 output bytes */
}

/* we are going to pack 32 25-bit values, touching 13 64-bit words, using 100
 * bytes */
static void packforblock25(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  13 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  uint64_t w12;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 25;
  w0 |= (uint64_t)(in[2] - base) << 50;
  w1 = (uint64_t)(in[2] - base) >> 14;
  w1 |= (uint64_t)(in[3] - base) << 11;
  w1 |= (uint64_t)(in[4] - base) << 36;
  w1 |= (uint64_t)(in[5] - base) << 61;
  w2 = (uint64_t)(in[5] - base) >> 3;
  w2 |= (uint64_t)(in[6] - base) << 22;
  w2 |= (uint64_t)(in[7] - base) << 47;
  w3 = (uint64_t)(in[7] - base) >> 17;
  w3 |= (uint64_t)(in[8] - base) << 8;
  w3 |= (uint64_t)(in[9] - base) << 33;
  w3 |= (uint64_t)(in[10] - base) << 58;
  w4 = (uint64_t)(in[10] - base) >> 6;
  w4 |= (uint64_t)(in[11] - base) << 19;
  w4 |= (uint64_t)(in[12] - base) << 44;
  w5 = (uint64_t)(in[12] - base) >> 20;
  w5 |= (uint64_t)(in[13] - base) << 5;
  w5 |= (uint64_t)(in[14] - base) << 30;
  w5 |= (uint64_t)(in[15] - base) << 55;
  w6 = (uint64_t)(in[15] - base) >> 9;
  w6 |= (uint64_t)(in[16] - base) << 16;
  w6 |= (uint64_t)(in[17] - base) << 41;
  w7 = (uint64_t)(in[17] - base) >> 23;
  w7 |= (uint64_t)(in[18] - base) << 2;
  w7 |= (uint64_t)(in[19] - base) << 27;
  w7 |= (uint64_t)(in[20] - base) << 52;
  w8 = (uint64_t)(in[20] - base) >> 12;
  w8 |= (uint64_t)(in[21] - base) << 13;
  w8 |= (uint64_t)(in[22] - base) << 38;
  w8 |= (uint64_t)(in[23] - base) << 63;
  w9 = (uint64_t)(in[23] - base) >> 1;
  w9 |= (uint64_t)(in[24] - base) << 24;
  w9 |= (uint64_t)(in[25] - base) << 49;
  w10 = (uint64_t)(in[25] - base) >> 15;
  w10 |= (uint64_t)(in[26] - base) << 10;
  w10 |= (uint64_t)(in[27] - base) << 35;
  w10 |= (uint64_t)(in[28] - base) << 60;
  w11 = (uint64_t)(in[28] - base) >> 4;
  w11 |= (uint64_t)(in[29] - base) << 21;
  w11 |= (uint64_t)(in[30] - base) << 46;
  w12 = (uint64_t)(in[30] - base) >> 18;
  w12 |= (uint64_t)(in[31] - base) << 7;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  pw64[12] = w12;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 100; /* we used up 100 output bytes */
}

/* we are going to pack 32 26-bit values, touching 13 64-bit words, using 104
 * bytes */
static void packforblock26(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  13 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  uint64_t w12;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 26;
  w0 |= (uint64_t)(in[2] - base) << 52;
  w1 = (uint64_t)(in[2] - base) >> 12;
  w1 |= (uint64_t)(in[3] - base) << 14;
  w1 |= (uint64_t)(in[4] - base) << 40;
  w2 = (uint64_t)(in[4] - base) >> 24;
  w2 |= (uint64_t)(in[5] - base) << 2;
  w2 |= (uint64_t)(in[6] - base) << 28;
  w2 |= (uint64_t)(in[7] - base) << 54;
  w3 = (uint64_t)(in[7] - base) >> 10;
  w3 |= (uint64_t)(in[8] - base) << 16;
  w3 |= (uint64_t)(in[9] - base) << 42;
  w4 = (uint64_t)(in[9] - base) >> 22;
  w4 |= (uint64_t)(in[10] - base) << 4;
  w4 |= (uint64_t)(in[11] - base) << 30;
  w4 |= (uint64_t)(in[12] - base) << 56;
  w5 = (uint64_t)(in[12] - base) >> 8;
  w5 |= (uint64_t)(in[13] - base) << 18;
  w5 |= (uint64_t)(in[14] - base) << 44;
  w6 = (uint64_t)(in[14] - base) >> 20;
  w6 |= (uint64_t)(in[15] - base) << 6;
  w6 |= (uint64_t)(in[16] - base) << 32;
  w6 |= (uint64_t)(in[17] - base) << 58;
  w7 = (uint64_t)(in[17] - base) >> 6;
  w7 |= (uint64_t)(in[18] - base) << 20;
  w7 |= (uint64_t)(in[19] - base) << 46;
  w8 = (uint64_t)(in[19] - base) >> 18;
  w8 |= (uint64_t)(in[20] - base) << 8;
  w8 |= (uint64_t)(in[21] - base) << 34;
  w8 |= (uint64_t)(in[22] - base) << 60;
  w9 = (uint64_t)(in[22] - base) >> 4;
  w9 |= (uint64_t)(in[23] - base) << 22;
  w9 |= (uint64_t)(in[24] - base) << 48;
  w10 = (uint64_t)(in[24] - base) >> 16;
  w10 |= (uint64_t)(in[25] - base) << 10;
  w10 |= (uint64_t)(in[26] - base) << 36;
  w10 |= (uint64_t)(in[27] - base) << 62;
  w11 = (uint64_t)(in[27] - base) >> 2;
  w11 |= (uint64_t)(in[28] - base) << 24;
  w11 |= (uint64_t)(in[29] - base) << 50;
  w12 = (uint64_t)(in[29] - base) >> 14;
  w12 |= (uint64_t)(in[30] - base) << 12;
  w12 |= (uint64_t)(in[31] - base) << 38;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  pw64[12] = w12;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 104; /* we used up 104 output bytes */
}

/* we are going to pack 32 27-bit values, touching 14 64-bit words, using 108
 * bytes */
static void packforblock27(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  14 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  uint64_t w12;
  uint64_t w13;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 27;
  w0 |= (uint64_t)(in[2] - base) << 54;
  w1 = (uint64_t)(in[2] - base) >> 10;
  w1 |= (uint64_t)(in[3] - base) << 17;
  w1 |= (uint64_t)(in[4] - base) << 44;
  w2 = (uint64_t)(in[4] - base) >> 20;
  w2 |= (uint64_t)(in[5] - base) << 7;
  w2 |= (uint64_t)(in[6] - base) << 34;
  w2 |= (uint64_t)(in[7] - base) << 61;
  w3 = (uint64_t)(in[7] - base) >> 3;
  w3 |= (uint64_t)(in[8] - base) << 24;
  w3 |= (uint64_t)(in[9] - base) << 51;
  w4 = (uint64_t)(in[9] - base) >> 13;
  w4 |= (uint64_t)(in[10] - base) << 14;
  w4 |= (uint64_t)(in[11] - base) << 41;
  w5 = (uint64_t)(in[11] - base) >> 23;
  w5 |= (uint64_t)(in[12] - base) << 4;
  w5 |= (uint64_t)(in[13] - base) << 31;
  w5 |= (uint64_t)(in[14] - base) << 58;
  w6 = (uint64_t)(in[14] - base) >> 6;
  w6 |= (uint64_t)(in[15] - base) << 21;
  w6 |= (uint64_t)(in[16] - base) << 48;
  w7 = (uint64_t)(in[16] - base) >> 16;
  w7 |= (uint64_t)(in[17] - base) << 11;
  w7 |= (uint64_t)(in[18] - base) << 38;
  w8 = (uint64_t)(in[18] - base) >> 26;
  w8 |= (uint64_t)(in[19] - base) << 1;
  w8 |= (uint64_t)(in[20] - base) << 28;
  w8 |= (uint64_t)(in[21] - base) << 55;
  w9 = (uint64_t)(in[21] - base) >> 9;
  w9 |= (uint64_t)(in[22] - base) << 18;
  w9 |= (uint64_t)(in[23] - base) << 45;
  w10 = (uint64_t)(in[23] - base) >> 19;
  w10 |= (uint64_t)(in[24] - base) << 8;
  w10 |= (uint64_t)(in[25] - base) << 35;
  w10 |= (uint64_t)(in[26] - base) << 62;
  w11 = (uint64_t)(in[26] - base) >> 2;
  w11 |= (uint64_t)(in[27] - base) << 25;
  w11 |= (uint64_t)(in[28] - base) << 52;
  w12 = (uint64_t)(in[28] - base) >> 12;
  w12 |= (uint64_t)(in[29] - base) << 15;
  w12 |= (uint64_t)(in[30] - base) << 42;
  w13 = (uint64_t)(in[30] - base) >> 22;
  w13 |= (uint64_t)(in[31] - base) << 5;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  pw64[12] = w12;
  pw64[13] = w13;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 108; /* we used up 108 output bytes */
}

/* we are going to pack 32 28-bit values, touching 14 64-bit words, using 112
 * bytes */
static void packforblock28(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  14 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  uint64_t w12;
  uint64_t w13;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 28;
  w0 |= (uint64_t)(in[2] - base) << 56;
  w1 = (uint64_t)(in[2] - base) >> 8;
  w1 |= (uint64_t)(in[3] - base) << 20;
  w1 |= (uint64_t)(in[4] - base) << 48;
  w2 = (uint64_t)(in[4] - base) >> 16;
  w2 |= (uint64_t)(in[5] - base) << 12;
  w2 |= (uint64_t)(in[6] - base) << 40;
  w3 = (uint64_t)(in[6] - base) >> 24;
  w3 |= (uint64_t)(in[7] - base) << 4;
  w3 |= (uint64_t)(in[8] - base) << 32;
  w3 |= (uint64_t)(in[9] - base) << 60;
  w4 = (uint64_t)(in[9] - base) >> 4;
  w4 |= (uint64_t)(in[10] - base) << 24;
  w4 |= (uint64_t)(in[11] - base) << 52;
  w5 = (uint64_t)(in[11] - base) >> 12;
  w5 |= (uint64_t)(in[12] - base) << 16;
  w5 |= (uint64_t)(in[13] - base) << 44;
  w6 = (uint64_t)(in[13] - base) >> 20;
  w6 |= (uint64_t)(in[14] - base) << 8;
  w6 |= (uint64_t)(in[15] - base) << 36;
  w7 = (uint64_t)(in[16] - base);
  w7 |= (uint64_t)(in[17] - base) << 28;
  w7 |= (uint64_t)(in[18] - base) << 56;
  w8 = (uint64_t)(in[18] - base) >> 8;
  w8 |= (uint64_t)(in[19] - base) << 20;
  w8 |= (uint64_t)(in[20] - base) << 48;
  w9 = (uint64_t)(in[20] - base) >> 16;
  w9 |= (uint64_t)(in[21] - base) << 12;
  w9 |= (uint64_t)(in[22] - base) << 40;
  w10 = (uint64_t)(in[22] - base) >> 24;
  w10 |= (uint64_t)(in[23] - base) << 4;
  w10 |= (uint64_t)(in[24] - base) << 32;
  w10 |= (uint64_t)(in[25] - base) << 60;
  w11 = (uint64_t)(in[25] - base) >> 4;
  w11 |= (uint64_t)(in[26] - base) << 24;
  w11 |= (uint64_t)(in[27] - base) << 52;
  w12 = (uint64_t)(in[27] - base) >> 12;
  w12 |= (uint64_t)(in[28] - base) << 16;
  w12 |= (uint64_t)(in[29] - base) << 44;
  w13 = (uint64_t)(in[29] - base) >> 20;
  w13 |= (uint64_t)(in[30] - base) << 8;
  w13 |= (uint64_t)(in[31] - base) << 36;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  pw64[12] = w12;
  pw64[13] = w13;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 112; /* we used up 112 output bytes */
}

/* we are going to pack 32 29-bit values, touching 15 64-bit words, using 116
 * bytes */
static void packforblock29(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  15 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  uint64_t w12;
  uint64_t w13;
  uint64_t w14;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 29;
  w0 |= (uint64_t)(in[2] - base) << 58;
  w1 = (uint64_t)(in[2] - base) >> 6;
  w1 |= (uint64_t)(in[3] - base) << 23;
  w1 |= (uint64_t)(in[4] - base) << 52;
  w2 = (uint64_t)(in[4] - base) >> 12;
  w2 |= (uint64_t)(in[5] - base) << 17;
  w2 |= (uint64_t)(in[6] - base) << 46;
  w3 = (uint64_t)(in[6] - base) >> 18;
  w3 |= (uint64_t)(in[7] - base) << 11;
  w3 |= (uint64_t)(in[8] - base) << 40;
  w4 = (uint64_t)(in[8] - base) >> 24;
  w4 |= (uint64_t)(in[9] - base) << 5;
  w4 |= (uint64_t)(in[10] - base) << 34;
  w4 |= (uint64_t)(in[11] - base) << 63;
  w5 = (uint64_t)(in[11] - base) >> 1;
  w5 |= (uint64_t)(in[12] - base) << 28;
  w5 |= (uint64_t)(in[13] - base) << 57;
  w6 = (uint64_t)(in[13] - base) >> 7;
  w6 |= (uint64_t)(in[14] - base) << 22;
  w6 |= (uint64_t)(in[15] - base) << 51;
  w7 = (uint64_t)(in[15] - base) >> 13;
  w7 |= (uint64_t)(in[16] - base) << 16;
  w7 |= (uint64_t)(in[17] - base) << 45;
  w8 = (uint64_t)(in[17] - base) >> 19;
  w8 |= (uint64_t)(in[18] - base) << 10;
  w8 |= (uint64_t)(in[19] - base) << 39;
  w9 = (uint64_t)(in[19] - base) >> 25;
  w9 |= (uint64_t)(in[20] - base) << 4;
  w9 |= (uint64_t)(in[21] - base) << 33;
  w9 |= (uint64_t)(in[22] - base) << 62;
  w10 = (uint64_t)(in[22] - base) >> 2;
  w10 |= (uint64_t)(in[23] - base) << 27;
  w10 |= (uint64_t)(in[24] - base) << 56;
  w11 = (uint64_t)(in[24] - base) >> 8;
  w11 |= (uint64_t)(in[25] - base) << 21;
  w11 |= (uint64_t)(in[26] - base) << 50;
  w12 = (uint64_t)(in[26] - base) >> 14;
  w12 |= (uint64_t)(in[27] - base) << 15;
  w12 |= (uint64_t)(in[28] - base) << 44;
  w13 = (uint64_t)(in[28] - base) >> 20;
  w13 |= (uint64_t)(in[29] - base) << 9;
  w13 |= (uint64_t)(in[30] - base) << 38;
  w14 = (uint64_t)(in[30] - base) >> 26;
  w14 |= (uint64_t)(in[31] - base) << 3;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  pw64[12] = w12;
  pw64[13] = w13;
  pw64[14] = w14;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 116; /* we used up 116 output bytes */
}

/* we are going to pack 32 30-bit values, touching 15 64-bit words, using 120
 * bytes */
static void packforblock30(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  15 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  uint64_t w12;
  uint64_t w13;
  uint64_t w14;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 30;
  w0 |= (uint64_t)(in[2] - base) << 60;
  w1 = (uint64_t)(in[2] - base) >> 4;
  w1 |= (uint64_t)(in[3] - base) << 26;
  w1 |= (uint64_t)(in[4] - base) << 56;
  w2 = (uint64_t)(in[4] - base) >> 8;
  w2 |= (uint64_t)(in[5] - base) << 22;
  w2 |= (uint64_t)(in[6] - base) << 52;
  w3 = (uint64_t)(in[6] - base) >> 12;
  w3 |= (uint64_t)(in[7] - base) << 18;
  w3 |= (uint64_t)(in[8] - base) << 48;
  w4 = (uint64_t)(in[8] - base) >> 16;
  w4 |= (uint64_t)(in[9] - base) << 14;
  w4 |= (uint64_t)(in[10] - base) << 44;
  w5 = (uint64_t)(in[10] - base) >> 20;
  w5 |= (uint64_t)(in[11] - base) << 10;
  w5 |= (uint64_t)(in[12] - base) << 40;
  w6 = (uint64_t)(in[12] - base) >> 24;
  w6 |= (uint64_t)(in[13] - base) << 6;
  w6 |= (uint64_t)(in[14] - base) << 36;
  w7 = (uint64_t)(in[14] - base) >> 28;
  w7 |= (uint64_t)(in[15] - base) << 2;
  w7 |= (uint64_t)(in[16] - base) << 32;
  w7 |= (uint64_t)(in[17] - base) << 62;
  w8 = (uint64_t)(in[17] - base) >> 2;
  w8 |= (uint64_t)(in[18] - base) << 28;
  w8 |= (uint64_t)(in[19] - base) << 58;
  w9 = (uint64_t)(in[19] - base) >> 6;
  w9 |= (uint64_t)(in[20] - base) << 24;
  w9 |= (uint64_t)(in[21] - base) << 54;
  w10 = (uint64_t)(in[21] - base) >> 10;
  w10 |= (uint64_t)(in[22] - base) << 20;
  w10 |= (uint64_t)(in[23] - base) << 50;
  w11 = (uint64_t)(in[23] - base) >> 14;
  w11 |= (uint64_t)(in[24] - base) << 16;
  w11 |= (uint64_t)(in[25] - base) << 46;
  w12 = (uint64_t)(in[25] - base) >> 18;
  w12 |= (uint64_t)(in[26] - base) << 12;
  w12 |= (uint64_t)(in[27] - base) << 42;
  w13 = (uint64_t)(in[27] - base) >> 22;
  w13 |= (uint64_t)(in[28] - base) << 8;
  w13 |= (uint64_t)(in[29] - base) << 38;
  w14 = (uint64_t)(in[29] - base) >> 26;
  w14 |= (uint64_t)(in[30] - base) << 4;
  w14 |= (uint64_t)(in[31] - base) << 34;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  pw64[12] = w12;
  pw64[13] = w13;
  pw64[14] = w14;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 120; /* we used up 120 output bytes */
}

/* we are going to pack 32 31-bit values, touching 16 64-bit words, using 124
 * bytes */
static void packforblock31(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  16 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  uint64_t w12;
  uint64_t w13;
  uint64_t w14;
  uint64_t w15;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 31;
  w0 |= (uint64_t)(in[2] - base) << 62;
  w1 = (uint64_t)(in[2] - base) >> 2;
  w1 |= (uint64_t)(in[3] - base) << 29;
  w1 |= (uint64_t)(in[4] - base) << 60;
  w2 = (uint64_t)(in[4] - base) >> 4;
  w2 |= (uint64_t)(in[5] - base) << 27;
  w2 |= (uint64_t)(in[6] - base) << 58;
  w3 = (uint64_t)(in[6] - base) >> 6;
  w3 |= (uint64_t)(in[7] - base) << 25;
  w3 |= (uint64_t)(in[8] - base) << 56;
  w4 = (uint64_t)(in[8] - base) >> 8;
  w4 |= (uint64_t)(in[9] - base) << 23;
  w4 |= (uint64_t)(in[10] - base) << 54;
  w5 = (uint64_t)(in[10] - base) >> 10;
  w5 |= (uint64_t)(in[11] - base) << 21;
  w5 |= (uint64_t)(in[12] - base) << 52;
  w6 = (uint64_t)(in[12] - base) >> 12;
  w6 |= (uint64_t)(in[13] - base) << 19;
  w6 |= (uint64_t)(in[14] - base) << 50;
  w7 = (uint64_t)(in[14] - base) >> 14;
  w7 |= (uint64_t)(in[15] - base) << 17;
  w7 |= (uint64_t)(in[16] - base) << 48;
  w8 = (uint64_t)(in[16] - base) >> 16;
  w8 |= (uint64_t)(in[17] - base) << 15;
  w8 |= (uint64_t)(in[18] - base) << 46;
  w9 = (uint64_t)(in[18] - base) >> 18;
  w9 |= (uint64_t)(in[19] - base) << 13;
  w9 |= (uint64_t)(in[20] - base) << 44;
  w10 = (uint64_t)(in[20] - base) >> 20;
  w10 |= (uint64_t)(in[21] - base) << 11;
  w10 |= (uint64_t)(in[22] - base) << 42;
  w11 = (uint64_t)(in[22] - base) >> 22;
  w11 |= (uint64_t)(in[23] - base) << 9;
  w11 |= (uint64_t)(in[24] - base) << 40;
  w12 = (uint64_t)(in[24] - base) >> 24;
  w12 |= (uint64_t)(in[25] - base) << 7;
  w12 |= (uint64_t)(in[26] - base) << 38;
  w13 = (uint64_t)(in[26] - base) >> 26;
  w13 |= (uint64_t)(in[27] - base) << 5;
  w13 |= (uint64_t)(in[28] - base) << 36;
  w14 = (uint64_t)(in[28] - base) >> 28;
  w14 |= (uint64_t)(in[29] - base) << 3;
  w14 |= (uint64_t)(in[30] - base) << 34;
  w15 = (uint64_t)(in[30] - base) >> 30;
  w15 |= (uint64_t)(in[31] - base) << 1;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  pw64[12] = w12;
  pw64[13] = w13;
  pw64[14] = w14;
  pw64[15] = w15;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 124; /* we used up 124 output bytes */
}

/* we are going to pack 32 32-bit values, touching 16 64-bit words, using 128
 * bytes */
static void packforblock32(const uint32_t base, const uint32_t **pin,
                           uint8_t **pw) {
  uint64_t *pw64 = *(uint64_t **)pw;
  const uint32_t *in = *pin;
  /* we are going to touch  16 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  uint64_t w8;
  uint64_t w9;
  uint64_t w10;
  uint64_t w11;
  uint64_t w12;
  uint64_t w13;
  uint64_t w14;
  uint64_t w15;
  w0 = (uint64_t)(in[0] - base);
  w0 |= (uint64_t)(in[1] - base) << 32;
  w1 = (uint64_t)(in[2] - base);
  w1 |= (uint64_t)(in[3] - base) << 32;
  w2 = (uint64_t)(in[4] - base);
  w2 |= (uint64_t)(in[5] - base) << 32;
  w3 = (uint64_t)(in[6] - base);
  w3 |= (uint64_t)(in[7] - base) << 32;
  w4 = (uint64_t)(in[8] - base);
  w4 |= (uint64_t)(in[9] - base) << 32;
  w5 = (uint64_t)(in[10] - base);
  w5 |= (uint64_t)(in[11] - base) << 32;
  w6 = (uint64_t)(in[12] - base);
  w6 |= (uint64_t)(in[13] - base) << 32;
  w7 = (uint64_t)(in[14] - base);
  w7 |= (uint64_t)(in[15] - base) << 32;
  w8 = (uint64_t)(in[16] - base);
  w8 |= (uint64_t)(in[17] - base) << 32;
  w9 = (uint64_t)(in[18] - base);
  w9 |= (uint64_t)(in[19] - base) << 32;
  w10 = (uint64_t)(in[20] - base);
  w10 |= (uint64_t)(in[21] - base) << 32;
  w11 = (uint64_t)(in[22] - base);
  w11 |= (uint64_t)(in[23] - base) << 32;
  w12 = (uint64_t)(in[24] - base);
  w12 |= (uint64_t)(in[25] - base) << 32;
  w13 = (uint64_t)(in[26] - base);
  w13 |= (uint64_t)(in[27] - base) << 32;
  w14 = (uint64_t)(in[28] - base);
  w14 |= (uint64_t)(in[29] - base) << 32;
  w15 = (uint64_t)(in[30] - base);
  w15 |= (uint64_t)(in[31] - base) << 32;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  pw64[9] = w9;
  pw64[10] = w10;
  pw64[11] = w11;
  pw64[12] = w12;
  pw64[13] = w13;
  pw64[14] = w14;
  pw64[15] = w15;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 128; /* we used up 128 output bytes */
}

static void unpackforblock0(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  (void)pw;
  for (int k = 0; k < 32; k += 1) {
    (*pout)[k] = base;
  }
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 1-bit values, touching 1 64-bit words, using 4 bytes */
static void unpackforblock1(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(1);
  /* we are going to access  1 64-bit word */
  uint64_t w0 = pw64[0];
  *pw += 4; /* we used up 4 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 1) & mask);
  out[2] = base + (uint32_t)((w0 >> 2) & mask);
  out[3] = base + (uint32_t)((w0 >> 3) & mask);
  out[4] = base + (uint32_t)((w0 >> 4) & mask);
  out[5] = base + (uint32_t)((w0 >> 5) & mask);
  out[6] = base + (uint32_t)((w0 >> 6) & mask);
  out[7] = base + (uint32_t)((w0 >> 7) & mask);
  out[8] = base + (uint32_t)((w0 >> 8) & mask);
  out[9] = base + (uint32_t)((w0 >> 9) & mask);
  out[10] = base + (uint32_t)((w0 >> 10) & mask);
  out[11] = base + (uint32_t)((w0 >> 11) & mask);
  out[12] = base + (uint32_t)((w0 >> 12) & mask);
  out[13] = base + (uint32_t)((w0 >> 13) & mask);
  out[14] = base + (uint32_t)((w0 >> 14) & mask);
  out[15] = base + (uint32_t)((w0 >> 15) & mask);
  out[16] = base + (uint32_t)((w0 >> 16) & mask);
  out[17] = base + (uint32_t)((w0 >> 17) & mask);
  out[18] = base + (uint32_t)((w0 >> 18) & mask);
  out[19] = base + (uint32_t)((w0 >> 19) & mask);
  out[20] = base + (uint32_t)((w0 >> 20) & mask);
  out[21] = base + (uint32_t)((w0 >> 21) & mask);
  out[22] = base + (uint32_t)((w0 >> 22) & mask);
  out[23] = base + (uint32_t)((w0 >> 23) & mask);
  out[24] = base + (uint32_t)((w0 >> 24) & mask);
  out[25] = base + (uint32_t)((w0 >> 25) & mask);
  out[26] = base + (uint32_t)((w0 >> 26) & mask);
  out[27] = base + (uint32_t)((w0 >> 27) & mask);
  out[28] = base + (uint32_t)((w0 >> 28) & mask);
  out[29] = base + (uint32_t)((w0 >> 29) & mask);
  out[30] = base + (uint32_t)((w0 >> 30) & mask);
  out[31] = base + (uint32_t)((w0 >> 31) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 2-bit values, touching 1 64-bit words, using 8 bytes */
static void unpackforblock2(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(3);
  /* we are going to access  1 64-bit word */
  uint64_t w0 = pw64[0];
  *pw += 8; /* we used up 8 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 2) & mask);
  out[2] = base + (uint32_t)((w0 >> 4) & mask);
  out[3] = base + (uint32_t)((w0 >> 6) & mask);
  out[4] = base + (uint32_t)((w0 >> 8) & mask);
  out[5] = base + (uint32_t)((w0 >> 10) & mask);
  out[6] = base + (uint32_t)((w0 >> 12) & mask);
  out[7] = base + (uint32_t)((w0 >> 14) & mask);
  out[8] = base + (uint32_t)((w0 >> 16) & mask);
  out[9] = base + (uint32_t)((w0 >> 18) & mask);
  out[10] = base + (uint32_t)((w0 >> 20) & mask);
  out[11] = base + (uint32_t)((w0 >> 22) & mask);
  out[12] = base + (uint32_t)((w0 >> 24) & mask);
  out[13] = base + (uint32_t)((w0 >> 26) & mask);
  out[14] = base + (uint32_t)((w0 >> 28) & mask);
  out[15] = base + (uint32_t)((w0 >> 30) & mask);
  out[16] = base + (uint32_t)((w0 >> 32) & mask);
  out[17] = base + (uint32_t)((w0 >> 34) & mask);
  out[18] = base + (uint32_t)((w0 >> 36) & mask);
  out[19] = base + (uint32_t)((w0 >> 38) & mask);
  out[20] = base + (uint32_t)((w0 >> 40) & mask);
  out[21] = base + (uint32_t)((w0 >> 42) & mask);
  out[22] = base + (uint32_t)((w0 >> 44) & mask);
  out[23] = base + (uint32_t)((w0 >> 46) & mask);
  out[24] = base + (uint32_t)((w0 >> 48) & mask);
  out[25] = base + (uint32_t)((w0 >> 50) & mask);
  out[26] = base + (uint32_t)((w0 >> 52) & mask);
  out[27] = base + (uint32_t)((w0 >> 54) & mask);
  out[28] = base + (uint32_t)((w0 >> 56) & mask);
  out[29] = base + (uint32_t)((w0 >> 58) & mask);
  out[30] = base + (uint32_t)((w0 >> 60) & mask);
  out[31] = base + (uint32_t)(w0 >> 62);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 3-bit values, touching 2 64-bit words, using 12 bytes */
static void unpackforblock3(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(7);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  *pw += 12; /* we used up 12 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 3) & mask);
  out[2] = base + (uint32_t)((w0 >> 6) & mask);
  out[3] = base + (uint32_t)((w0 >> 9) & mask);
  out[4] = base + (uint32_t)((w0 >> 12) & mask);
  out[5] = base + (uint32_t)((w0 >> 15) & mask);
  out[6] = base + (uint32_t)((w0 >> 18) & mask);
  out[7] = base + (uint32_t)((w0 >> 21) & mask);
  out[8] = base + (uint32_t)((w0 >> 24) & mask);
  out[9] = base + (uint32_t)((w0 >> 27) & mask);
  out[10] = base + (uint32_t)((w0 >> 30) & mask);
  out[11] = base + (uint32_t)((w0 >> 33) & mask);
  out[12] = base + (uint32_t)((w0 >> 36) & mask);
  out[13] = base + (uint32_t)((w0 >> 39) & mask);
  out[14] = base + (uint32_t)((w0 >> 42) & mask);
  out[15] = base + (uint32_t)((w0 >> 45) & mask);
  out[16] = base + (uint32_t)((w0 >> 48) & mask);
  out[17] = base + (uint32_t)((w0 >> 51) & mask);
  out[18] = base + (uint32_t)((w0 >> 54) & mask);
  out[19] = base + (uint32_t)((w0 >> 57) & mask);
  out[20] = base + (uint32_t)((w0 >> 60) & mask);
  out[21] = base + (uint32_t)(((w0 >> 63) | (w1 << 1)) & mask);
  out[22] = base + (uint32_t)((w1 >> 2) & mask);
  out[23] = base + (uint32_t)((w1 >> 5) & mask);
  out[24] = base + (uint32_t)((w1 >> 8) & mask);
  out[25] = base + (uint32_t)((w1 >> 11) & mask);
  out[26] = base + (uint32_t)((w1 >> 14) & mask);
  out[27] = base + (uint32_t)((w1 >> 17) & mask);
  out[28] = base + (uint32_t)((w1 >> 20) & mask);
  out[29] = base + (uint32_t)((w1 >> 23) & mask);
  out[30] = base + (uint32_t)((w1 >> 26) & mask);
  out[31] = base + (uint32_t)((w1 >> 29) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 4-bit values, touching 2 64-bit words, using 16 bytes */
static void unpackforblock4(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(15);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  *pw += 16; /* we used up 16 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 4) & mask);
  out[2] = base + (uint32_t)((w0 >> 8) & mask);
  out[3] = base + (uint32_t)((w0 >> 12) & mask);
  out[4] = base + (uint32_t)((w0 >> 16) & mask);
  out[5] = base + (uint32_t)((w0 >> 20) & mask);
  out[6] = base + (uint32_t)((w0 >> 24) & mask);
  out[7] = base + (uint32_t)((w0 >> 28) & mask);
  out[8] = base + (uint32_t)((w0 >> 32) & mask);
  out[9] = base + (uint32_t)((w0 >> 36) & mask);
  out[10] = base + (uint32_t)((w0 >> 40) & mask);
  out[11] = base + (uint32_t)((w0 >> 44) & mask);
  out[12] = base + (uint32_t)((w0 >> 48) & mask);
  out[13] = base + (uint32_t)((w0 >> 52) & mask);
  out[14] = base + (uint32_t)((w0 >> 56) & mask);
  out[15] = base + (uint32_t)(w0 >> 60);
  out[16] = base + (uint32_t)((w1)&mask);
  out[17] = base + (uint32_t)((w1 >> 4) & mask);
  out[18] = base + (uint32_t)((w1 >> 8) & mask);
  out[19] = base + (uint32_t)((w1 >> 12) & mask);
  out[20] = base + (uint32_t)((w1 >> 16) & mask);
  out[21] = base + (uint32_t)((w1 >> 20) & mask);
  out[22] = base + (uint32_t)((w1 >> 24) & mask);
  out[23] = base + (uint32_t)((w1 >> 28) & mask);
  out[24] = base + (uint32_t)((w1 >> 32) & mask);
  out[25] = base + (uint32_t)((w1 >> 36) & mask);
  out[26] = base + (uint32_t)((w1 >> 40) & mask);
  out[27] = base + (uint32_t)((w1 >> 44) & mask);
  out[28] = base + (uint32_t)((w1 >> 48) & mask);
  out[29] = base + (uint32_t)((w1 >> 52) & mask);
  out[30] = base + (uint32_t)((w1 >> 56) & mask);
  out[31] = base + (uint32_t)(w1 >> 60);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 5-bit values, touching 3 64-bit words, using 20 bytes */
static void unpackforblock5(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(31);
  /* we are going to access  3 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  *pw += 20; /* we used up 20 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 5) & mask);
  out[2] = base + (uint32_t)((w0 >> 10) & mask);
  out[3] = base + (uint32_t)((w0 >> 15) & mask);
  out[4] = base + (uint32_t)((w0 >> 20) & mask);
  out[5] = base + (uint32_t)((w0 >> 25) & mask);
  out[6] = base + (uint32_t)((w0 >> 30) & mask);
  out[7] = base + (uint32_t)((w0 >> 35) & mask);
  out[8] = base + (uint32_t)((w0 >> 40) & mask);
  out[9] = base + (uint32_t)((w0 >> 45) & mask);
  out[10] = base + (uint32_t)((w0 >> 50) & mask);
  out[11] = base + (uint32_t)((w0 >> 55) & mask);
  out[12] = base + (uint32_t)(((w0 >> 60) | (w1 << 4)) & mask);
  out[13] = base + (uint32_t)((w1 >> 1) & mask);
  out[14] = base + (uint32_t)((w1 >> 6) & mask);
  out[15] = base + (uint32_t)((w1 >> 11) & mask);
  out[16] = base + (uint32_t)((w1 >> 16) & mask);
  out[17] = base + (uint32_t)((w1 >> 21) & mask);
  out[18] = base + (uint32_t)((w1 >> 26) & mask);
  out[19] = base + (uint32_t)((w1 >> 31) & mask);
  out[20] = base + (uint32_t)((w1 >> 36) & mask);
  out[21] = base + (uint32_t)((w1 >> 41) & mask);
  out[22] = base + (uint32_t)((w1 >> 46) & mask);
  out[23] = base + (uint32_t)((w1 >> 51) & mask);
  out[24] = base + (uint32_t)((w1 >> 56) & mask);
  out[25] = base + (uint32_t)(((w1 >> 61) | (w2 << 3)) & mask);
  out[26] = base + (uint32_t)((w2 >> 2) & mask);
  out[27] = base + (uint32_t)((w2 >> 7) & mask);
  out[28] = base + (uint32_t)((w2 >> 12) & mask);
  out[29] = base + (uint32_t)((w2 >> 17) & mask);
  out[30] = base + (uint32_t)((w2 >> 22) & mask);
  out[31] = base + (uint32_t)((w2 >> 27) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 6-bit values, touching 3 64-bit words, using 24 bytes */
static void unpackforblock6(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(63);
  /* we are going to access  3 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  *pw += 24; /* we used up 24 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 6) & mask);
  out[2] = base + (uint32_t)((w0 >> 12) & mask);
  out[3] = base + (uint32_t)((w0 >> 18) & mask);
  out[4] = base + (uint32_t)((w0 >> 24) & mask);
  out[5] = base + (uint32_t)((w0 >> 30) & mask);
  out[6] = base + (uint32_t)((w0 >> 36) & mask);
  out[7] = base + (uint32_t)((w0 >> 42) & mask);
  out[8] = base + (uint32_t)((w0 >> 48) & mask);
  out[9] = base + (uint32_t)((w0 >> 54) & mask);
  out[10] = base + (uint32_t)(((w0 >> 60) | (w1 << 4)) & mask);
  out[11] = base + (uint32_t)((w1 >> 2) & mask);
  out[12] = base + (uint32_t)((w1 >> 8) & mask);
  out[13] = base + (uint32_t)((w1 >> 14) & mask);
  out[14] = base + (uint32_t)((w1 >> 20) & mask);
  out[15] = base + (uint32_t)((w1 >> 26) & mask);
  out[16] = base + (uint32_t)((w1 >> 32) & mask);
  out[17] = base + (uint32_t)((w1 >> 38) & mask);
  out[18] = base + (uint32_t)((w1 >> 44) & mask);
  out[19] = base + (uint32_t)((w1 >> 50) & mask);
  out[20] = base + (uint32_t)((w1 >> 56) & mask);
  out[21] = base + (uint32_t)(((w1 >> 62) | (w2 << 2)) & mask);
  out[22] = base + (uint32_t)((w2 >> 4) & mask);
  out[23] = base + (uint32_t)((w2 >> 10) & mask);
  out[24] = base + (uint32_t)((w2 >> 16) & mask);
  out[25] = base + (uint32_t)((w2 >> 22) & mask);
  out[26] = base + (uint32_t)((w2 >> 28) & mask);
  out[27] = base + (uint32_t)((w2 >> 34) & mask);
  out[28] = base + (uint32_t)((w2 >> 40) & mask);
  out[29] = base + (uint32_t)((w2 >> 46) & mask);
  out[30] = base + (uint32_t)((w2 >> 52) & mask);
  out[31] = base + (uint32_t)(w2 >> 58);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 7-bit values, touching 4 64-bit words, using 28 bytes */
static void unpackforblock7(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(127);
  /* we are going to access  4 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  *pw += 28; /* we used up 28 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 7) & mask);
  out[2] = base + (uint32_t)((w0 >> 14) & mask);
  out[3] = base + (uint32_t)((w0 >> 21) & mask);
  out[4] = base + (uint32_t)((w0 >> 28) & mask);
  out[5] = base + (uint32_t)((w0 >> 35) & mask);
  out[6] = base + (uint32_t)((w0 >> 42) & mask);
  out[7] = base + (uint32_t)((w0 >> 49) & mask);
  out[8] = base + (uint32_t)((w0 >> 56) & mask);
  out[9] = base + (uint32_t)(((w0 >> 63) | (w1 << 1)) & mask);
  out[10] = base + (uint32_t)((w1 >> 6) & mask);
  out[11] = base + (uint32_t)((w1 >> 13) & mask);
  out[12] = base + (uint32_t)((w1 >> 20) & mask);
  out[13] = base + (uint32_t)((w1 >> 27) & mask);
  out[14] = base + (uint32_t)((w1 >> 34) & mask);
  out[15] = base + (uint32_t)((w1 >> 41) & mask);
  out[16] = base + (uint32_t)((w1 >> 48) & mask);
  out[17] = base + (uint32_t)((w1 >> 55) & mask);
  out[18] = base + (uint32_t)(((w1 >> 62) | (w2 << 2)) & mask);
  out[19] = base + (uint32_t)((w2 >> 5) & mask);
  out[20] = base + (uint32_t)((w2 >> 12) & mask);
  out[21] = base + (uint32_t)((w2 >> 19) & mask);
  out[22] = base + (uint32_t)((w2 >> 26) & mask);
  out[23] = base + (uint32_t)((w2 >> 33) & mask);
  out[24] = base + (uint32_t)((w2 >> 40) & mask);
  out[25] = base + (uint32_t)((w2 >> 47) & mask);
  out[26] = base + (uint32_t)((w2 >> 54) & mask);
  out[27] = base + (uint32_t)(((w2 >> 61) | (w3 << 3)) & mask);
  out[28] = base + (uint32_t)((w3 >> 4) & mask);
  out[29] = base + (uint32_t)((w3 >> 11) & mask);
  out[30] = base + (uint32_t)((w3 >> 18) & mask);
  out[31] = base + (uint32_t)((w3 >> 25) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 8-bit values, touching 4 64-bit words, using 32 bytes */
static void unpackforblock8(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(255);
  /* we are going to access  4 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  *pw += 32; /* we used up 32 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 8) & mask);
  out[2] = base + (uint32_t)((w0 >> 16) & mask);
  out[3] = base + (uint32_t)((w0 >> 24) & mask);
  out[4] = base + (uint32_t)((w0 >> 32) & mask);
  out[5] = base + (uint32_t)((w0 >> 40) & mask);
  out[6] = base + (uint32_t)((w0 >> 48) & mask);
  out[7] = base + (uint32_t)(w0 >> 56);
  out[8] = base + (uint32_t)((w1)&mask);
  out[9] = base + (uint32_t)((w1 >> 8) & mask);
  out[10] = base + (uint32_t)((w1 >> 16) & mask);
  out[11] = base + (uint32_t)((w1 >> 24) & mask);
  out[12] = base + (uint32_t)((w1 >> 32) & mask);
  out[13] = base + (uint32_t)((w1 >> 40) & mask);
  out[14] = base + (uint32_t)((w1 >> 48) & mask);
  out[15] = base + (uint32_t)(w1 >> 56);
  out[16] = base + (uint32_t)((w2)&mask);
  out[17] = base + (uint32_t)((w2 >> 8) & mask);
  out[18] = base + (uint32_t)((w2 >> 16) & mask);
  out[19] = base + (uint32_t)((w2 >> 24) & mask);
  out[20] = base + (uint32_t)((w2 >> 32) & mask);
  out[21] = base + (uint32_t)((w2 >> 40) & mask);
  out[22] = base + (uint32_t)((w2 >> 48) & mask);
  out[23] = base + (uint32_t)(w2 >> 56);
  out[24] = base + (uint32_t)((w3)&mask);
  out[25] = base + (uint32_t)((w3 >> 8) & mask);
  out[26] = base + (uint32_t)((w3 >> 16) & mask);
  out[27] = base + (uint32_t)((w3 >> 24) & mask);
  out[28] = base + (uint32_t)((w3 >> 32) & mask);
  out[29] = base + (uint32_t)((w3 >> 40) & mask);
  out[30] = base + (uint32_t)((w3 >> 48) & mask);
  out[31] = base + (uint32_t)(w3 >> 56);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 9-bit values, touching 5 64-bit words, using 36 bytes */
static void unpackforblock9(const uint32_t base, const uint8_t **pw,
                            uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(511);
  /* we are going to access  5 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  *pw += 36; /* we used up 36 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 9) & mask);
  out[2] = base + (uint32_t)((w0 >> 18) & mask);
  out[3] = base + (uint32_t)((w0 >> 27) & mask);
  out[4] = base + (uint32_t)((w0 >> 36) & mask);
  out[5] = base + (uint32_t)((w0 >> 45) & mask);
  out[6] = base + (uint32_t)((w0 >> 54) & mask);
  out[7] = base + (uint32_t)(((w0 >> 63) | (w1 << 1)) & mask);
  out[8] = base + (uint32_t)((w1 >> 8) & mask);
  out[9] = base + (uint32_t)((w1 >> 17) & mask);
  out[10] = base + (uint32_t)((w1 >> 26) & mask);
  out[11] = base + (uint32_t)((w1 >> 35) & mask);
  out[12] = base + (uint32_t)((w1 >> 44) & mask);
  out[13] = base + (uint32_t)((w1 >> 53) & mask);
  out[14] = base + (uint32_t)(((w1 >> 62) | (w2 << 2)) & mask);
  out[15] = base + (uint32_t)((w2 >> 7) & mask);
  out[16] = base + (uint32_t)((w2 >> 16) & mask);
  out[17] = base + (uint32_t)((w2 >> 25) & mask);
  out[18] = base + (uint32_t)((w2 >> 34) & mask);
  out[19] = base + (uint32_t)((w2 >> 43) & mask);
  out[20] = base + (uint32_t)((w2 >> 52) & mask);
  out[21] = base + (uint32_t)(((w2 >> 61) | (w3 << 3)) & mask);
  out[22] = base + (uint32_t)((w3 >> 6) & mask);
  out[23] = base + (uint32_t)((w3 >> 15) & mask);
  out[24] = base + (uint32_t)((w3 >> 24) & mask);
  out[25] = base + (uint32_t)((w3 >> 33) & mask);
  out[26] = base + (uint32_t)((w3 >> 42) & mask);
  out[27] = base + (uint32_t)((w3 >> 51) & mask);
  out[28] = base + (uint32_t)(((w3 >> 60) | (w4 << 4)) & mask);
  out[29] = base + (uint32_t)((w4 >> 5) & mask);
  out[30] = base + (uint32_t)((w4 >> 14) & mask);
  out[31] = base + (uint32_t)((w4 >> 23) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 10-bit values, touching 5 64-bit words, using 40 bytes */
static void unpackforblock10(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(1023);
  /* we are going to access  5 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  *pw += 40; /* we used up 40 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 10) & mask);
  out[2] = base + (uint32_t)((w0 >> 20) & mask);
  out[3] = base + (uint32_t)((w0 >> 30) & mask);
  out[4] = base + (uint32_t)((w0 >> 40) & mask);
  out[5] = base + (uint32_t)((w0 >> 50) & mask);
  out[6] = base + (uint32_t)(((w0 >> 60) | (w1 << 4)) & mask);
  out[7] = base + (uint32_t)((w1 >> 6) & mask);
  out[8] = base + (uint32_t)((w1 >> 16) & mask);
  out[9] = base + (uint32_t)((w1 >> 26) & mask);
  out[10] = base + (uint32_t)((w1 >> 36) & mask);
  out[11] = base + (uint32_t)((w1 >> 46) & mask);
  out[12] = base + (uint32_t)(((w1 >> 56) | (w2 << 8)) & mask);
  out[13] = base + (uint32_t)((w2 >> 2) & mask);
  out[14] = base + (uint32_t)((w2 >> 12) & mask);
  out[15] = base + (uint32_t)((w2 >> 22) & mask);
  out[16] = base + (uint32_t)((w2 >> 32) & mask);
  out[17] = base + (uint32_t)((w2 >> 42) & mask);
  out[18] = base + (uint32_t)((w2 >> 52) & mask);
  out[19] = base + (uint32_t)(((w2 >> 62) | (w3 << 2)) & mask);
  out[20] = base + (uint32_t)((w3 >> 8) & mask);
  out[21] = base + (uint32_t)((w3 >> 18) & mask);
  out[22] = base + (uint32_t)((w3 >> 28) & mask);
  out[23] = base + (uint32_t)((w3 >> 38) & mask);
  out[24] = base + (uint32_t)((w3 >> 48) & mask);
  out[25] = base + (uint32_t)(((w3 >> 58) | (w4 << 6)) & mask);
  out[26] = base + (uint32_t)((w4 >> 4) & mask);
  out[27] = base + (uint32_t)((w4 >> 14) & mask);
  out[28] = base + (uint32_t)((w4 >> 24) & mask);
  out[29] = base + (uint32_t)((w4 >> 34) & mask);
  out[30] = base + (uint32_t)((w4 >> 44) & mask);
  out[31] = base + (uint32_t)(w4 >> 54);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 11-bit values, touching 6 64-bit words, using 44 bytes */
static void unpackforblock11(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(2047);
  /* we are going to access  6 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  *pw += 44; /* we used up 44 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 11) & mask);
  out[2] = base + (uint32_t)((w0 >> 22) & mask);
  out[3] = base + (uint32_t)((w0 >> 33) & mask);
  out[4] = base + (uint32_t)((w0 >> 44) & mask);
  out[5] = base + (uint32_t)(((w0 >> 55) | (w1 << 9)) & mask);
  out[6] = base + (uint32_t)((w1 >> 2) & mask);
  out[7] = base + (uint32_t)((w1 >> 13) & mask);
  out[8] = base + (uint32_t)((w1 >> 24) & mask);
  out[9] = base + (uint32_t)((w1 >> 35) & mask);
  out[10] = base + (uint32_t)((w1 >> 46) & mask);
  out[11] = base + (uint32_t)(((w1 >> 57) | (w2 << 7)) & mask);
  out[12] = base + (uint32_t)((w2 >> 4) & mask);
  out[13] = base + (uint32_t)((w2 >> 15) & mask);
  out[14] = base + (uint32_t)((w2 >> 26) & mask);
  out[15] = base + (uint32_t)((w2 >> 37) & mask);
  out[16] = base + (uint32_t)((w2 >> 48) & mask);
  out[17] = base + (uint32_t)(((w2 >> 59) | (w3 << 5)) & mask);
  out[18] = base + (uint32_t)((w3 >> 6) & mask);
  out[19] = base + (uint32_t)((w3 >> 17) & mask);
  out[20] = base + (uint32_t)((w3 >> 28) & mask);
  out[21] = base + (uint32_t)((w3 >> 39) & mask);
  out[22] = base + (uint32_t)((w3 >> 50) & mask);
  out[23] = base + (uint32_t)(((w3 >> 61) | (w4 << 3)) & mask);
  out[24] = base + (uint32_t)((w4 >> 8) & mask);
  out[25] = base + (uint32_t)((w4 >> 19) & mask);
  out[26] = base + (uint32_t)((w4 >> 30) & mask);
  out[27] = base + (uint32_t)((w4 >> 41) & mask);
  out[28] = base + (uint32_t)((w4 >> 52) & mask);
  out[29] = base + (uint32_t)(((w4 >> 63) | (w5 << 1)) & mask);
  out[30] = base + (uint32_t)((w5 >> 10) & mask);
  out[31] = base + (uint32_t)((w5 >> 21) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 12-bit values, touching 6 64-bit words, using 48 bytes */
static void unpackforblock12(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(4095);
  /* we are going to access  6 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  *pw += 48; /* we used up 48 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 12) & mask);
  out[2] = base + (uint32_t)((w0 >> 24) & mask);
  out[3] = base + (uint32_t)((w0 >> 36) & mask);
  out[4] = base + (uint32_t)((w0 >> 48) & mask);
  out[5] = base + (uint32_t)(((w0 >> 60) | (w1 << 4)) & mask);
  out[6] = base + (uint32_t)((w1 >> 8) & mask);
  out[7] = base + (uint32_t)((w1 >> 20) & mask);
  out[8] = base + (uint32_t)((w1 >> 32) & mask);
  out[9] = base + (uint32_t)((w1 >> 44) & mask);
  out[10] = base + (uint32_t)(((w1 >> 56) | (w2 << 8)) & mask);
  out[11] = base + (uint32_t)((w2 >> 4) & mask);
  out[12] = base + (uint32_t)((w2 >> 16) & mask);
  out[13] = base + (uint32_t)((w2 >> 28) & mask);
  out[14] = base + (uint32_t)((w2 >> 40) & mask);
  out[15] = base + (uint32_t)(w2 >> 52);
  out[16] = base + (uint32_t)((w3)&mask);
  out[17] = base + (uint32_t)((w3 >> 12) & mask);
  out[18] = base + (uint32_t)((w3 >> 24) & mask);
  out[19] = base + (uint32_t)((w3 >> 36) & mask);
  out[20] = base + (uint32_t)((w3 >> 48) & mask);
  out[21] = base + (uint32_t)(((w3 >> 60) | (w4 << 4)) & mask);
  out[22] = base + (uint32_t)((w4 >> 8) & mask);
  out[23] = base + (uint32_t)((w4 >> 20) & mask);
  out[24] = base + (uint32_t)((w4 >> 32) & mask);
  out[25] = base + (uint32_t)((w4 >> 44) & mask);
  out[26] = base + (uint32_t)(((w4 >> 56) | (w5 << 8)) & mask);
  out[27] = base + (uint32_t)((w5 >> 4) & mask);
  out[28] = base + (uint32_t)((w5 >> 16) & mask);
  out[29] = base + (uint32_t)((w5 >> 28) & mask);
  out[30] = base + (uint32_t)((w5 >> 40) & mask);
  out[31] = base + (uint32_t)(w5 >> 52);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 13-bit values, touching 7 64-bit words, using 52 bytes */
static void unpackforblock13(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(8191);
  /* we are going to access  7 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  *pw += 52; /* we used up 52 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 13) & mask);
  out[2] = base + (uint32_t)((w0 >> 26) & mask);
  out[3] = base + (uint32_t)((w0 >> 39) & mask);
  out[4] = base + (uint32_t)(((w0 >> 52) | (w1 << 12)) & mask);
  out[5] = base + (uint32_t)((w1 >> 1) & mask);
  out[6] = base + (uint32_t)((w1 >> 14) & mask);
  out[7] = base + (uint32_t)((w1 >> 27) & mask);
  out[8] = base + (uint32_t)((w1 >> 40) & mask);
  out[9] = base + (uint32_t)(((w1 >> 53) | (w2 << 11)) & mask);
  out[10] = base + (uint32_t)((w2 >> 2) & mask);
  out[11] = base + (uint32_t)((w2 >> 15) & mask);
  out[12] = base + (uint32_t)((w2 >> 28) & mask);
  out[13] = base + (uint32_t)((w2 >> 41) & mask);
  out[14] = base + (uint32_t)(((w2 >> 54) | (w3 << 10)) & mask);
  out[15] = base + (uint32_t)((w3 >> 3) & mask);
  out[16] = base + (uint32_t)((w3 >> 16) & mask);
  out[17] = base + (uint32_t)((w3 >> 29) & mask);
  out[18] = base + (uint32_t)((w3 >> 42) & mask);
  out[19] = base + (uint32_t)(((w3 >> 55) | (w4 << 9)) & mask);
  out[20] = base + (uint32_t)((w4 >> 4) & mask);
  out[21] = base + (uint32_t)((w4 >> 17) & mask);
  out[22] = base + (uint32_t)((w4 >> 30) & mask);
  out[23] = base + (uint32_t)((w4 >> 43) & mask);
  out[24] = base + (uint32_t)(((w4 >> 56) | (w5 << 8)) & mask);
  out[25] = base + (uint32_t)((w5 >> 5) & mask);
  out[26] = base + (uint32_t)((w5 >> 18) & mask);
  out[27] = base + (uint32_t)((w5 >> 31) & mask);
  out[28] = base + (uint32_t)((w5 >> 44) & mask);
  out[29] = base + (uint32_t)(((w5 >> 57) | (w6 << 7)) & mask);
  out[30] = base + (uint32_t)((w6 >> 6) & mask);
  out[31] = base + (uint32_t)((w6 >> 19) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 14-bit values, touching 7 64-bit words, using 56 bytes */
static void unpackforblock14(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(16383);
  /* we are going to access  7 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  *pw += 56; /* we used up 56 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 14) & mask);
  out[2] = base + (uint32_t)((w0 >> 28) & mask);
  out[3] = base + (uint32_t)((w0 >> 42) & mask);
  out[4] = base + (uint32_t)(((w0 >> 56) | (w1 << 8)) & mask);
  out[5] = base + (uint32_t)((w1 >> 6) & mask);
  out[6] = base + (uint32_t)((w1 >> 20) & mask);
  out[7] = base + (uint32_t)((w1 >> 34) & mask);
  out[8] = base + (uint32_t)((w1 >> 48) & mask);
  out[9] = base + (uint32_t)(((w1 >> 62) | (w2 << 2)) & mask);
  out[10] = base + (uint32_t)((w2 >> 12) & mask);
  out[11] = base + (uint32_t)((w2 >> 26) & mask);
  out[12] = base + (uint32_t)((w2 >> 40) & mask);
  out[13] = base + (uint32_t)(((w2 >> 54) | (w3 << 10)) & mask);
  out[14] = base + (uint32_t)((w3 >> 4) & mask);
  out[15] = base + (uint32_t)((w3 >> 18) & mask);
  out[16] = base + (uint32_t)((w3 >> 32) & mask);
  out[17] = base + (uint32_t)((w3 >> 46) & mask);
  out[18] = base + (uint32_t)(((w3 >> 60) | (w4 << 4)) & mask);
  out[19] = base + (uint32_t)((w4 >> 10) & mask);
  out[20] = base + (uint32_t)((w4 >> 24) & mask);
  out[21] = base + (uint32_t)((w4 >> 38) & mask);
  out[22] = base + (uint32_t)(((w4 >> 52) | (w5 << 12)) & mask);
  out[23] = base + (uint32_t)((w5 >> 2) & mask);
  out[24] = base + (uint32_t)((w5 >> 16) & mask);
  out[25] = base + (uint32_t)((w5 >> 30) & mask);
  out[26] = base + (uint32_t)((w5 >> 44) & mask);
  out[27] = base + (uint32_t)(((w5 >> 58) | (w6 << 6)) & mask);
  out[28] = base + (uint32_t)((w6 >> 8) & mask);
  out[29] = base + (uint32_t)((w6 >> 22) & mask);
  out[30] = base + (uint32_t)((w6 >> 36) & mask);
  out[31] = base + (uint32_t)(w6 >> 50);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 15-bit values, touching 8 64-bit words, using 60 bytes */
static void unpackforblock15(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(32767);
  /* we are going to access  8 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  *pw += 60; /* we used up 60 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 15) & mask);
  out[2] = base + (uint32_t)((w0 >> 30) & mask);
  out[3] = base + (uint32_t)((w0 >> 45) & mask);
  out[4] = base + (uint32_t)(((w0 >> 60) | (w1 << 4)) & mask);
  out[5] = base + (uint32_t)((w1 >> 11) & mask);
  out[6] = base + (uint32_t)((w1 >> 26) & mask);
  out[7] = base + (uint32_t)((w1 >> 41) & mask);
  out[8] = base + (uint32_t)(((w1 >> 56) | (w2 << 8)) & mask);
  out[9] = base + (uint32_t)((w2 >> 7) & mask);
  out[10] = base + (uint32_t)((w2 >> 22) & mask);
  out[11] = base + (uint32_t)((w2 >> 37) & mask);
  out[12] = base + (uint32_t)(((w2 >> 52) | (w3 << 12)) & mask);
  out[13] = base + (uint32_t)((w3 >> 3) & mask);
  out[14] = base + (uint32_t)((w3 >> 18) & mask);
  out[15] = base + (uint32_t)((w3 >> 33) & mask);
  out[16] = base + (uint32_t)((w3 >> 48) & mask);
  out[17] = base + (uint32_t)(((w3 >> 63) | (w4 << 1)) & mask);
  out[18] = base + (uint32_t)((w4 >> 14) & mask);
  out[19] = base + (uint32_t)((w4 >> 29) & mask);
  out[20] = base + (uint32_t)((w4 >> 44) & mask);
  out[21] = base + (uint32_t)(((w4 >> 59) | (w5 << 5)) & mask);
  out[22] = base + (uint32_t)((w5 >> 10) & mask);
  out[23] = base + (uint32_t)((w5 >> 25) & mask);
  out[24] = base + (uint32_t)((w5 >> 40) & mask);
  out[25] = base + (uint32_t)(((w5 >> 55) | (w6 << 9)) & mask);
  out[26] = base + (uint32_t)((w6 >> 6) & mask);
  out[27] = base + (uint32_t)((w6 >> 21) & mask);
  out[28] = base + (uint32_t)((w6 >> 36) & mask);
  out[29] = base + (uint32_t)(((w6 >> 51) | (w7 << 13)) & mask);
  out[30] = base + (uint32_t)((w7 >> 2) & mask);
  out[31] = base + (uint32_t)((w7 >> 17) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 16-bit values, touching 8 64-bit words, using 64 bytes */
static void unpackforblock16(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(65535);
  /* we are going to access  8 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  *pw += 64; /* we used up 64 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 16) & mask);
  out[2] = base + (uint32_t)((w0 >> 32) & mask);
  out[3] = base + (uint32_t)(w0 >> 48);
  out[4] = base + (uint32_t)((w1)&mask);
  out[5] = base + (uint32_t)((w1 >> 16) & mask);
  out[6] = base + (uint32_t)((w1 >> 32) & mask);
  out[7] = base + (uint32_t)(w1 >> 48);
  out[8] = base + (uint32_t)((w2)&mask);
  out[9] = base + (uint32_t)((w2 >> 16) & mask);
  out[10] = base + (uint32_t)((w2 >> 32) & mask);
  out[11] = base + (uint32_t)(w2 >> 48);
  out[12] = base + (uint32_t)((w3)&mask);
  out[13] = base + (uint32_t)((w3 >> 16) & mask);
  out[14] = base + (uint32_t)((w3 >> 32) & mask);
  out[15] = base + (uint32_t)(w3 >> 48);
  out[16] = base + (uint32_t)((w4)&mask);
  out[17] = base + (uint32_t)((w4 >> 16) & mask);
  out[18] = base + (uint32_t)((w4 >> 32) & mask);
  out[19] = base + (uint32_t)(w4 >> 48);
  out[20] = base + (uint32_t)((w5)&mask);
  out[21] = base + (uint32_t)((w5 >> 16) & mask);
  out[22] = base + (uint32_t)((w5 >> 32) & mask);
  out[23] = base + (uint32_t)(w5 >> 48);
  out[24] = base + (uint32_t)((w6)&mask);
  out[25] = base + (uint32_t)((w6 >> 16) & mask);
  out[26] = base + (uint32_t)((w6 >> 32) & mask);
  out[27] = base + (uint32_t)(w6 >> 48);
  out[28] = base + (uint32_t)((w7)&mask);
  out[29] = base + (uint32_t)((w7 >> 16) & mask);
  out[30] = base + (uint32_t)((w7 >> 32) & mask);
  out[31] = base + (uint32_t)(w7 >> 48);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 17-bit values, touching 9 64-bit words, using 68 bytes */
static void unpackforblock17(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(131071);
  /* we are going to access  9 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  *pw += 68; /* we used up 68 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 17) & mask);
  out[2] = base + (uint32_t)((w0 >> 34) & mask);
  out[3] = base + (uint32_t)(((w0 >> 51) | (w1 << 13)) & mask);
  out[4] = base + (uint32_t)((w1 >> 4) & mask);
  out[5] = base + (uint32_t)((w1 >> 21) & mask);
  out[6] = base + (uint32_t)((w1 >> 38) & mask);
  out[7] = base + (uint32_t)(((w1 >> 55) | (w2 << 9)) & mask);
  out[8] = base + (uint32_t)((w2 >> 8) & mask);
  out[9] = base + (uint32_t)((w2 >> 25) & mask);
  out[10] = base + (uint32_t)((w2 >> 42) & mask);
  out[11] = base + (uint32_t)(((w2 >> 59) | (w3 << 5)) & mask);
  out[12] = base + (uint32_t)((w3 >> 12) & mask);
  out[13] = base + (uint32_t)((w3 >> 29) & mask);
  out[14] = base + (uint32_t)((w3 >> 46) & mask);
  out[15] = base + (uint32_t)(((w3 >> 63) | (w4 << 1)) & mask);
  out[16] = base + (uint32_t)((w4 >> 16) & mask);
  out[17] = base + (uint32_t)((w4 >> 33) & mask);
  out[18] = base + (uint32_t)(((w4 >> 50) | (w5 << 14)) & mask);
  out[19] = base + (uint32_t)((w5 >> 3) & mask);
  out[20] = base + (uint32_t)((w5 >> 20) & mask);
  out[21] = base + (uint32_t)((w5 >> 37) & mask);
  out[22] = base + (uint32_t)(((w5 >> 54) | (w6 << 10)) & mask);
  out[23] = base + (uint32_t)((w6 >> 7) & mask);
  out[24] = base + (uint32_t)((w6 >> 24) & mask);
  out[25] = base + (uint32_t)((w6 >> 41) & mask);
  out[26] = base + (uint32_t)(((w6 >> 58) | (w7 << 6)) & mask);
  out[27] = base + (uint32_t)((w7 >> 11) & mask);
  out[28] = base + (uint32_t)((w7 >> 28) & mask);
  out[29] = base + (uint32_t)((w7 >> 45) & mask);
  out[30] = base + (uint32_t)(((w7 >> 62) | (w8 << 2)) & mask);
  out[31] = base + (uint32_t)((w8 >> 15) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 18-bit values, touching 9 64-bit words, using 72 bytes */
static void unpackforblock18(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(262143);
  /* we are going to access  9 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  *pw += 72; /* we used up 72 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 18) & mask);
  out[2] = base + (uint32_t)((w0 >> 36) & mask);
  out[3] = base + (uint32_t)(((w0 >> 54) | (w1 << 10)) & mask);
  out[4] = base + (uint32_t)((w1 >> 8) & mask);
  out[5] = base + (uint32_t)((w1 >> 26) & mask);
  out[6] = base + (uint32_t)((w1 >> 44) & mask);
  out[7] = base + (uint32_t)(((w1 >> 62) | (w2 << 2)) & mask);
  out[8] = base + (uint32_t)((w2 >> 16) & mask);
  out[9] = base + (uint32_t)((w2 >> 34) & mask);
  out[10] = base + (uint32_t)(((w2 >> 52) | (w3 << 12)) & mask);
  out[11] = base + (uint32_t)((w3 >> 6) & mask);
  out[12] = base + (uint32_t)((w3 >> 24) & mask);
  out[13] = base + (uint32_t)((w3 >> 42) & mask);
  out[14] = base + (uint32_t)(((w3 >> 60) | (w4 << 4)) & mask);
  out[15] = base + (uint32_t)((w4 >> 14) & mask);
  out[16] = base + (uint32_t)((w4 >> 32) & mask);
  out[17] = base + (uint32_t)(((w4 >> 50) | (w5 << 14)) & mask);
  out[18] = base + (uint32_t)((w5 >> 4) & mask);
  out[19] = base + (uint32_t)((w5 >> 22) & mask);
  out[20] = base + (uint32_t)((w5 >> 40) & mask);
  out[21] = base + (uint32_t)(((w5 >> 58) | (w6 << 6)) & mask);
  out[22] = base + (uint32_t)((w6 >> 12) & mask);
  out[23] = base + (uint32_t)((w6 >> 30) & mask);
  out[24] = base + (uint32_t)(((w6 >> 48) | (w7 << 16)) & mask);
  out[25] = base + (uint32_t)((w7 >> 2) & mask);
  out[26] = base + (uint32_t)((w7 >> 20) & mask);
  out[27] = base + (uint32_t)((w7 >> 38) & mask);
  out[28] = base + (uint32_t)(((w7 >> 56) | (w8 << 8)) & mask);
  out[29] = base + (uint32_t)((w8 >> 10) & mask);
  out[30] = base + (uint32_t)((w8 >> 28) & mask);
  out[31] = base + (uint32_t)(w8 >> 46);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 19-bit values, touching 10 64-bit words, using 76 bytes */
static void unpackforblock19(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(524287);
  /* we are going to access  10 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  *pw += 76; /* we used up 76 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 19) & mask);
  out[2] = base + (uint32_t)((w0 >> 38) & mask);
  out[3] = base + (uint32_t)(((w0 >> 57) | (w1 << 7)) & mask);
  out[4] = base + (uint32_t)((w1 >> 12) & mask);
  out[5] = base + (uint32_t)((w1 >> 31) & mask);
  out[6] = base + (uint32_t)(((w1 >> 50) | (w2 << 14)) & mask);
  out[7] = base + (uint32_t)((w2 >> 5) & mask);
  out[8] = base + (uint32_t)((w2 >> 24) & mask);
  out[9] = base + (uint32_t)((w2 >> 43) & mask);
  out[10] = base + (uint32_t)(((w2 >> 62) | (w3 << 2)) & mask);
  out[11] = base + (uint32_t)((w3 >> 17) & mask);
  out[12] = base + (uint32_t)((w3 >> 36) & mask);
  out[13] = base + (uint32_t)(((w3 >> 55) | (w4 << 9)) & mask);
  out[14] = base + (uint32_t)((w4 >> 10) & mask);
  out[15] = base + (uint32_t)((w4 >> 29) & mask);
  out[16] = base + (uint32_t)(((w4 >> 48) | (w5 << 16)) & mask);
  out[17] = base + (uint32_t)((w5 >> 3) & mask);
  out[18] = base + (uint32_t)((w5 >> 22) & mask);
  out[19] = base + (uint32_t)((w5 >> 41) & mask);
  out[20] = base + (uint32_t)(((w5 >> 60) | (w6 << 4)) & mask);
  out[21] = base + (uint32_t)((w6 >> 15) & mask);
  out[22] = base + (uint32_t)((w6 >> 34) & mask);
  out[23] = base + (uint32_t)(((w6 >> 53) | (w7 << 11)) & mask);
  out[24] = base + (uint32_t)((w7 >> 8) & mask);
  out[25] = base + (uint32_t)((w7 >> 27) & mask);
  out[26] = base + (uint32_t)(((w7 >> 46) | (w8 << 18)) & mask);
  out[27] = base + (uint32_t)((w8 >> 1) & mask);
  out[28] = base + (uint32_t)((w8 >> 20) & mask);
  out[29] = base + (uint32_t)((w8 >> 39) & mask);
  out[30] = base + (uint32_t)(((w8 >> 58) | (w9 << 6)) & mask);
  out[31] = base + (uint32_t)((w9 >> 13) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 20-bit values, touching 10 64-bit words, using 80 bytes */
static void unpackforblock20(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(1048575);
  /* we are going to access  10 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  *pw += 80; /* we used up 80 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 20) & mask);
  out[2] = base + (uint32_t)((w0 >> 40) & mask);
  out[3] = base + (uint32_t)(((w0 >> 60) | (w1 << 4)) & mask);
  out[4] = base + (uint32_t)((w1 >> 16) & mask);
  out[5] = base + (uint32_t)((w1 >> 36) & mask);
  out[6] = base + (uint32_t)(((w1 >> 56) | (w2 << 8)) & mask);
  out[7] = base + (uint32_t)((w2 >> 12) & mask);
  out[8] = base + (uint32_t)((w2 >> 32) & mask);
  out[9] = base + (uint32_t)(((w2 >> 52) | (w3 << 12)) & mask);
  out[10] = base + (uint32_t)((w3 >> 8) & mask);
  out[11] = base + (uint32_t)((w3 >> 28) & mask);
  out[12] = base + (uint32_t)(((w3 >> 48) | (w4 << 16)) & mask);
  out[13] = base + (uint32_t)((w4 >> 4) & mask);
  out[14] = base + (uint32_t)((w4 >> 24) & mask);
  out[15] = base + (uint32_t)(w4 >> 44);
  out[16] = base + (uint32_t)((w5)&mask);
  out[17] = base + (uint32_t)((w5 >> 20) & mask);
  out[18] = base + (uint32_t)((w5 >> 40) & mask);
  out[19] = base + (uint32_t)(((w5 >> 60) | (w6 << 4)) & mask);
  out[20] = base + (uint32_t)((w6 >> 16) & mask);
  out[21] = base + (uint32_t)((w6 >> 36) & mask);
  out[22] = base + (uint32_t)(((w6 >> 56) | (w7 << 8)) & mask);
  out[23] = base + (uint32_t)((w7 >> 12) & mask);
  out[24] = base + (uint32_t)((w7 >> 32) & mask);
  out[25] = base + (uint32_t)(((w7 >> 52) | (w8 << 12)) & mask);
  out[26] = base + (uint32_t)((w8 >> 8) & mask);
  out[27] = base + (uint32_t)((w8 >> 28) & mask);
  out[28] = base + (uint32_t)(((w8 >> 48) | (w9 << 16)) & mask);
  out[29] = base + (uint32_t)((w9 >> 4) & mask);
  out[30] = base + (uint32_t)((w9 >> 24) & mask);
  out[31] = base + (uint32_t)(w9 >> 44);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 21-bit values, touching 11 64-bit words, using 84 bytes */
static void unpackforblock21(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(2097151);
  /* we are going to access  11 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  *pw += 84; /* we used up 84 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 21) & mask);
  out[2] = base + (uint32_t)((w0 >> 42) & mask);
  out[3] = base + (uint32_t)(((w0 >> 63) | (w1 << 1)) & mask);
  out[4] = base + (uint32_t)((w1 >> 20) & mask);
  out[5] = base + (uint32_t)((w1 >> 41) & mask);
  out[6] = base + (uint32_t)(((w1 >> 62) | (w2 << 2)) & mask);
  out[7] = base + (uint32_t)((w2 >> 19) & mask);
  out[8] = base + (uint32_t)((w2 >> 40) & mask);
  out[9] = base + (uint32_t)(((w2 >> 61) | (w3 << 3)) & mask);
  out[10] = base + (uint32_t)((w3 >> 18) & mask);
  out[11] = base + (uint32_t)((w3 >> 39) & mask);
  out[12] = base + (uint32_t)(((w3 >> 60) | (w4 << 4)) & mask);
  out[13] = base + (uint32_t)((w4 >> 17) & mask);
  out[14] = base + (uint32_t)((w4 >> 38) & mask);
  out[15] = base + (uint32_t)(((w4 >> 59) | (w5 << 5)) & mask);
  out[16] = base + (uint32_t)((w5 >> 16) & mask);
  out[17] = base + (uint32_t)((w5 >> 37) & mask);
  out[18] = base + (uint32_t)(((w5 >> 58) | (w6 << 6)) & mask);
  out[19] = base + (uint32_t)((w6 >> 15) & mask);
  out[20] = base + (uint32_t)((w6 >> 36) & mask);
  out[21] = base + (uint32_t)(((w6 >> 57) | (w7 << 7)) & mask);
  out[22] = base + (uint32_t)((w7 >> 14) & mask);
  out[23] = base + (uint32_t)((w7 >> 35) & mask);
  out[24] = base + (uint32_t)(((w7 >> 56) | (w8 << 8)) & mask);
  out[25] = base + (uint32_t)((w8 >> 13) & mask);
  out[26] = base + (uint32_t)((w8 >> 34) & mask);
  out[27] = base + (uint32_t)(((w8 >> 55) | (w9 << 9)) & mask);
  out[28] = base + (uint32_t)((w9 >> 12) & mask);
  out[29] = base + (uint32_t)((w9 >> 33) & mask);
  out[30] = base + (uint32_t)(((w9 >> 54) | (w10 << 10)) & mask);
  out[31] = base + (uint32_t)((w10 >> 11) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 22-bit values, touching 11 64-bit words, using 88 bytes */
static void unpackforblock22(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(4194303);
  /* we are going to access  11 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  *pw += 88; /* we used up 88 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 22) & mask);
  out[2] = base + (uint32_t)(((w0 >> 44) | (w1 << 20)) & mask);
  out[3] = base + (uint32_t)((w1 >> 2) & mask);
  out[4] = base + (uint32_t)((w1 >> 24) & mask);
  out[5] = base + (uint32_t)(((w1 >> 46) | (w2 << 18)) & mask);
  out[6] = base + (uint32_t)((w2 >> 4) & mask);
  out[7] = base + (uint32_t)((w2 >> 26) & mask);
  out[8] = base + (uint32_t)(((w2 >> 48) | (w3 << 16)) & mask);
  out[9] = base + (uint32_t)((w3 >> 6) & mask);
  out[10] = base + (uint32_t)((w3 >> 28) & mask);
  out[11] = base + (uint32_t)(((w3 >> 50) | (w4 << 14)) & mask);
  out[12] = base + (uint32_t)((w4 >> 8) & mask);
  out[13] = base + (uint32_t)((w4 >> 30) & mask);
  out[14] = base + (uint32_t)(((w4 >> 52) | (w5 << 12)) & mask);
  out[15] = base + (uint32_t)((w5 >> 10) & mask);
  out[16] = base + (uint32_t)((w5 >> 32) & mask);
  out[17] = base + (uint32_t)(((w5 >> 54) | (w6 << 10)) & mask);
  out[18] = base + (uint32_t)((w6 >> 12) & mask);
  out[19] = base + (uint32_t)((w6 >> 34) & mask);
  out[20] = base + (uint32_t)(((w6 >> 56) | (w7 << 8)) & mask);
  out[21] = base + (uint32_t)((w7 >> 14) & mask);
  out[22] = base + (uint32_t)((w7 >> 36) & mask);
  out[23] = base + (uint32_t)(((w7 >> 58) | (w8 << 6)) & mask);
  out[24] = base + (uint32_t)((w8 >> 16) & mask);
  out[25] = base + (uint32_t)((w8 >> 38) & mask);
  out[26] = base + (uint32_t)(((w8 >> 60) | (w9 << 4)) & mask);
  out[27] = base + (uint32_t)((w9 >> 18) & mask);
  out[28] = base + (uint32_t)((w9 >> 40) & mask);
  out[29] = base + (uint32_t)(((w9 >> 62) | (w10 << 2)) & mask);
  out[30] = base + (uint32_t)((w10 >> 20) & mask);
  out[31] = base + (uint32_t)(w10 >> 42);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 23-bit values, touching 12 64-bit words, using 92 bytes */
static void unpackforblock23(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(8388607);
  /* we are going to access  12 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  *pw += 92; /* we used up 92 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 23) & mask);
  out[2] = base + (uint32_t)(((w0 >> 46) | (w1 << 18)) & mask);
  out[3] = base + (uint32_t)((w1 >> 5) & mask);
  out[4] = base + (uint32_t)((w1 >> 28) & mask);
  out[5] = base + (uint32_t)(((w1 >> 51) | (w2 << 13)) & mask);
  out[6] = base + (uint32_t)((w2 >> 10) & mask);
  out[7] = base + (uint32_t)((w2 >> 33) & mask);
  out[8] = base + (uint32_t)(((w2 >> 56) | (w3 << 8)) & mask);
  out[9] = base + (uint32_t)((w3 >> 15) & mask);
  out[10] = base + (uint32_t)((w3 >> 38) & mask);
  out[11] = base + (uint32_t)(((w3 >> 61) | (w4 << 3)) & mask);
  out[12] = base + (uint32_t)((w4 >> 20) & mask);
  out[13] = base + (uint32_t)(((w4 >> 43) | (w5 << 21)) & mask);
  out[14] = base + (uint32_t)((w5 >> 2) & mask);
  out[15] = base + (uint32_t)((w5 >> 25) & mask);
  out[16] = base + (uint32_t)(((w5 >> 48) | (w6 << 16)) & mask);
  out[17] = base + (uint32_t)((w6 >> 7) & mask);
  out[18] = base + (uint32_t)((w6 >> 30) & mask);
  out[19] = base + (uint32_t)(((w6 >> 53) | (w7 << 11)) & mask);
  out[20] = base + (uint32_t)((w7 >> 12) & mask);
  out[21] = base + (uint32_t)((w7 >> 35) & mask);
  out[22] = base + (uint32_t)(((w7 >> 58) | (w8 << 6)) & mask);
  out[23] = base + (uint32_t)((w8 >> 17) & mask);
  out[24] = base + (uint32_t)((w8 >> 40) & mask);
  out[25] = base + (uint32_t)(((w8 >> 63) | (w9 << 1)) & mask);
  out[26] = base + (uint32_t)((w9 >> 22) & mask);
  out[27] = base + (uint32_t)(((w9 >> 45) | (w10 << 19)) & mask);
  out[28] = base + (uint32_t)((w10 >> 4) & mask);
  out[29] = base + (uint32_t)((w10 >> 27) & mask);
  out[30] = base + (uint32_t)(((w10 >> 50) | (w11 << 14)) & mask);
  out[31] = base + (uint32_t)((w11 >> 9) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 24-bit values, touching 12 64-bit words, using 96 bytes */
static void unpackforblock24(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(16777215);
  /* we are going to access  12 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  *pw += 96; /* we used up 96 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 24) & mask);
  out[2] = base + (uint32_t)(((w0 >> 48) | (w1 << 16)) & mask);
  out[3] = base + (uint32_t)((w1 >> 8) & mask);
  out[4] = base + (uint32_t)((w1 >> 32) & mask);
  out[5] = base + (uint32_t)(((w1 >> 56) | (w2 << 8)) & mask);
  out[6] = base + (uint32_t)((w2 >> 16) & mask);
  out[7] = base + (uint32_t)(w2 >> 40);
  out[8] = base + (uint32_t)((w3)&mask);
  out[9] = base + (uint32_t)((w3 >> 24) & mask);
  out[10] = base + (uint32_t)(((w3 >> 48) | (w4 << 16)) & mask);
  out[11] = base + (uint32_t)((w4 >> 8) & mask);
  out[12] = base + (uint32_t)((w4 >> 32) & mask);
  out[13] = base + (uint32_t)(((w4 >> 56) | (w5 << 8)) & mask);
  out[14] = base + (uint32_t)((w5 >> 16) & mask);
  out[15] = base + (uint32_t)(w5 >> 40);
  out[16] = base + (uint32_t)((w6)&mask);
  out[17] = base + (uint32_t)((w6 >> 24) & mask);
  out[18] = base + (uint32_t)(((w6 >> 48) | (w7 << 16)) & mask);
  out[19] = base + (uint32_t)((w7 >> 8) & mask);
  out[20] = base + (uint32_t)((w7 >> 32) & mask);
  out[21] = base + (uint32_t)(((w7 >> 56) | (w8 << 8)) & mask);
  out[22] = base + (uint32_t)((w8 >> 16) & mask);
  out[23] = base + (uint32_t)(w8 >> 40);
  out[24] = base + (uint32_t)((w9)&mask);
  out[25] = base + (uint32_t)((w9 >> 24) & mask);
  out[26] = base + (uint32_t)(((w9 >> 48) | (w10 << 16)) & mask);
  out[27] = base + (uint32_t)((w10 >> 8) & mask);
  out[28] = base + (uint32_t)((w10 >> 32) & mask);
  out[29] = base + (uint32_t)(((w10 >> 56) | (w11 << 8)) & mask);
  out[30] = base + (uint32_t)((w11 >> 16) & mask);
  out[31] = base + (uint32_t)(w11 >> 40);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 25-bit values, touching 13 64-bit words, using 100 bytes */
static void unpackforblock25(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(33554431);
  /* we are going to access  13 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  uint64_t w12 = pw64[12];
  *pw += 100; /* we used up 100 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 25) & mask);
  out[2] = base + (uint32_t)(((w0 >> 50) | (w1 << 14)) & mask);
  out[3] = base + (uint32_t)((w1 >> 11) & mask);
  out[4] = base + (uint32_t)((w1 >> 36) & mask);
  out[5] = base + (uint32_t)(((w1 >> 61) | (w2 << 3)) & mask);
  out[6] = base + (uint32_t)((w2 >> 22) & mask);
  out[7] = base + (uint32_t)(((w2 >> 47) | (w3 << 17)) & mask);
  out[8] = base + (uint32_t)((w3 >> 8) & mask);
  out[9] = base + (uint32_t)((w3 >> 33) & mask);
  out[10] = base + (uint32_t)(((w3 >> 58) | (w4 << 6)) & mask);
  out[11] = base + (uint32_t)((w4 >> 19) & mask);
  out[12] = base + (uint32_t)(((w4 >> 44) | (w5 << 20)) & mask);
  out[13] = base + (uint32_t)((w5 >> 5) & mask);
  out[14] = base + (uint32_t)((w5 >> 30) & mask);
  out[15] = base + (uint32_t)(((w5 >> 55) | (w6 << 9)) & mask);
  out[16] = base + (uint32_t)((w6 >> 16) & mask);
  out[17] = base + (uint32_t)(((w6 >> 41) | (w7 << 23)) & mask);
  out[18] = base + (uint32_t)((w7 >> 2) & mask);
  out[19] = base + (uint32_t)((w7 >> 27) & mask);
  out[20] = base + (uint32_t)(((w7 >> 52) | (w8 << 12)) & mask);
  out[21] = base + (uint32_t)((w8 >> 13) & mask);
  out[22] = base + (uint32_t)((w8 >> 38) & mask);
  out[23] = base + (uint32_t)(((w8 >> 63) | (w9 << 1)) & mask);
  out[24] = base + (uint32_t)((w9 >> 24) & mask);
  out[25] = base + (uint32_t)(((w9 >> 49) | (w10 << 15)) & mask);
  out[26] = base + (uint32_t)((w10 >> 10) & mask);
  out[27] = base + (uint32_t)((w10 >> 35) & mask);
  out[28] = base + (uint32_t)(((w10 >> 60) | (w11 << 4)) & mask);
  out[29] = base + (uint32_t)((w11 >> 21) & mask);
  out[30] = base + (uint32_t)(((w11 >> 46) | (w12 << 18)) & mask);
  out[31] = base + (uint32_t)((w12 >> 7) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 26-bit values, touching 13 64-bit words, using 104 bytes */
static void unpackforblock26(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(67108863);
  /* we are going to access  13 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  uint64_t w12 = pw64[12];
  *pw += 104; /* we used up 104 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 26) & mask);
  out[2] = base + (uint32_t)(((w0 >> 52) | (w1 << 12)) & mask);
  out[3] = base + (uint32_t)((w1 >> 14) & mask);
  out[4] = base + (uint32_t)(((w1 >> 40) | (w2 << 24)) & mask);
  out[5] = base + (uint32_t)((w2 >> 2) & mask);
  out[6] = base + (uint32_t)((w2 >> 28) & mask);
  out[7] = base + (uint32_t)(((w2 >> 54) | (w3 << 10)) & mask);
  out[8] = base + (uint32_t)((w3 >> 16) & mask);
  out[9] = base + (uint32_t)(((w3 >> 42) | (w4 << 22)) & mask);
  out[10] = base + (uint32_t)((w4 >> 4) & mask);
  out[11] = base + (uint32_t)((w4 >> 30) & mask);
  out[12] = base + (uint32_t)(((w4 >> 56) | (w5 << 8)) & mask);
  out[13] = base + (uint32_t)((w5 >> 18) & mask);
  out[14] = base + (uint32_t)(((w5 >> 44) | (w6 << 20)) & mask);
  out[15] = base + (uint32_t)((w6 >> 6) & mask);
  out[16] = base + (uint32_t)((w6 >> 32) & mask);
  out[17] = base + (uint32_t)(((w6 >> 58) | (w7 << 6)) & mask);
  out[18] = base + (uint32_t)((w7 >> 20) & mask);
  out[19] = base + (uint32_t)(((w7 >> 46) | (w8 << 18)) & mask);
  out[20] = base + (uint32_t)((w8 >> 8) & mask);
  out[21] = base + (uint32_t)((w8 >> 34) & mask);
  out[22] = base + (uint32_t)(((w8 >> 60) | (w9 << 4)) & mask);
  out[23] = base + (uint32_t)((w9 >> 22) & mask);
  out[24] = base + (uint32_t)(((w9 >> 48) | (w10 << 16)) & mask);
  out[25] = base + (uint32_t)((w10 >> 10) & mask);
  out[26] = base + (uint32_t)((w10 >> 36) & mask);
  out[27] = base + (uint32_t)(((w10 >> 62) | (w11 << 2)) & mask);
  out[28] = base + (uint32_t)((w11 >> 24) & mask);
  out[29] = base + (uint32_t)(((w11 >> 50) | (w12 << 14)) & mask);
  out[30] = base + (uint32_t)((w12 >> 12) & mask);
  out[31] = base + (uint32_t)(w12 >> 38);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 27-bit values, touching 14 64-bit words, using 108 bytes */
static void unpackforblock27(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(134217727);
  /* we are going to access  14 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  uint64_t w12 = pw64[12];
  uint64_t w13 = pw64[13];
  *pw += 108; /* we used up 108 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 27) & mask);
  out[2] = base + (uint32_t)(((w0 >> 54) | (w1 << 10)) & mask);
  out[3] = base + (uint32_t)((w1 >> 17) & mask);
  out[4] = base + (uint32_t)(((w1 >> 44) | (w2 << 20)) & mask);
  out[5] = base + (uint32_t)((w2 >> 7) & mask);
  out[6] = base + (uint32_t)((w2 >> 34) & mask);
  out[7] = base + (uint32_t)(((w2 >> 61) | (w3 << 3)) & mask);
  out[8] = base + (uint32_t)((w3 >> 24) & mask);
  out[9] = base + (uint32_t)(((w3 >> 51) | (w4 << 13)) & mask);
  out[10] = base + (uint32_t)((w4 >> 14) & mask);
  out[11] = base + (uint32_t)(((w4 >> 41) | (w5 << 23)) & mask);
  out[12] = base + (uint32_t)((w5 >> 4) & mask);
  out[13] = base + (uint32_t)((w5 >> 31) & mask);
  out[14] = base + (uint32_t)(((w5 >> 58) | (w6 << 6)) & mask);
  out[15] = base + (uint32_t)((w6 >> 21) & mask);
  out[16] = base + (uint32_t)(((w6 >> 48) | (w7 << 16)) & mask);
  out[17] = base + (uint32_t)((w7 >> 11) & mask);
  out[18] = base + (uint32_t)(((w7 >> 38) | (w8 << 26)) & mask);
  out[19] = base + (uint32_t)((w8 >> 1) & mask);
  out[20] = base + (uint32_t)((w8 >> 28) & mask);
  out[21] = base + (uint32_t)(((w8 >> 55) | (w9 << 9)) & mask);
  out[22] = base + (uint32_t)((w9 >> 18) & mask);
  out[23] = base + (uint32_t)(((w9 >> 45) | (w10 << 19)) & mask);
  out[24] = base + (uint32_t)((w10 >> 8) & mask);
  out[25] = base + (uint32_t)((w10 >> 35) & mask);
  out[26] = base + (uint32_t)(((w10 >> 62) | (w11 << 2)) & mask);
  out[27] = base + (uint32_t)((w11 >> 25) & mask);
  out[28] = base + (uint32_t)(((w11 >> 52) | (w12 << 12)) & mask);
  out[29] = base + (uint32_t)((w12 >> 15) & mask);
  out[30] = base + (uint32_t)(((w12 >> 42) | (w13 << 22)) & mask);
  out[31] = base + (uint32_t)((w13 >> 5) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 28-bit values, touching 14 64-bit words, using 112 bytes */
static void unpackforblock28(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(268435455);
  /* we are going to access  14 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  uint64_t w12 = pw64[12];
  uint64_t w13 = pw64[13];
  *pw += 112; /* we used up 112 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 28) & mask);
  out[2] = base + (uint32_t)(((w0 >> 56) | (w1 << 8)) & mask);
  out[3] = base + (uint32_t)((w1 >> 20) & mask);
  out[4] = base + (uint32_t)(((w1 >> 48) | (w2 << 16)) & mask);
  out[5] = base + (uint32_t)((w2 >> 12) & mask);
  out[6] = base + (uint32_t)(((w2 >> 40) | (w3 << 24)) & mask);
  out[7] = base + (uint32_t)((w3 >> 4) & mask);
  out[8] = base + (uint32_t)((w3 >> 32) & mask);
  out[9] = base + (uint32_t)(((w3 >> 60) | (w4 << 4)) & mask);
  out[10] = base + (uint32_t)((w4 >> 24) & mask);
  out[11] = base + (uint32_t)(((w4 >> 52) | (w5 << 12)) & mask);
  out[12] = base + (uint32_t)((w5 >> 16) & mask);
  out[13] = base + (uint32_t)(((w5 >> 44) | (w6 << 20)) & mask);
  out[14] = base + (uint32_t)((w6 >> 8) & mask);
  out[15] = base + (uint32_t)(w6 >> 36);
  out[16] = base + (uint32_t)((w7)&mask);
  out[17] = base + (uint32_t)((w7 >> 28) & mask);
  out[18] = base + (uint32_t)(((w7 >> 56) | (w8 << 8)) & mask);
  out[19] = base + (uint32_t)((w8 >> 20) & mask);
  out[20] = base + (uint32_t)(((w8 >> 48) | (w9 << 16)) & mask);
  out[21] = base + (uint32_t)((w9 >> 12) & mask);
  out[22] = base + (uint32_t)(((w9 >> 40) | (w10 << 24)) & mask);
  out[23] = base + (uint32_t)((w10 >> 4) & mask);
  out[24] = base + (uint32_t)((w10 >> 32) & mask);
  out[25] = base + (uint32_t)(((w10 >> 60) | (w11 << 4)) & mask);
  out[26] = base + (uint32_t)((w11 >> 24) & mask);
  out[27] = base + (uint32_t)(((w11 >> 52) | (w12 << 12)) & mask);
  out[28] = base + (uint32_t)((w12 >> 16) & mask);
  out[29] = base + (uint32_t)(((w12 >> 44) | (w13 << 20)) & mask);
  out[30] = base + (uint32_t)((w13 >> 8) & mask);
  out[31] = base + (uint32_t)(w13 >> 36);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 29-bit values, touching 15 64-bit words, using 116 bytes */
static void unpackforblock29(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(536870911);
  /* we are going to access  15 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  uint64_t w12 = pw64[12];
  uint64_t w13 = pw64[13];
  uint64_t w14 = pw64[14];
  *pw += 116; /* we used up 116 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 29) & mask);
  out[2] = base + (uint32_t)(((w0 >> 58) | (w1 << 6)) & mask);
  out[3] = base + (uint32_t)((w1 >> 23) & mask);
  out[4] = base + (uint32_t)(((w1 >> 52) | (w2 << 12)) & mask);
  out[5] = base + (uint32_t)((w2 >> 17) & mask);
  out[6] = base + (uint32_t)(((w2 >> 46) | (w3 << 18)) & mask);
  out[7] = base + (uint32_t)((w3 >> 11) & mask);
  out[8] = base + (uint32_t)(((w3 >> 40) | (w4 << 24)) & mask);
  out[9] = base + (uint32_t)((w4 >> 5) & mask);
  out[10] = base + (uint32_t)((w4 >> 34) & mask);
  out[11] = base + (uint32_t)(((w4 >> 63) | (w5 << 1)) & mask);
  out[12] = base + (uint32_t)((w5 >> 28) & mask);
  out[13] = base + (uint32_t)(((w5 >> 57) | (w6 << 7)) & mask);
  out[14] = base + (uint32_t)((w6 >> 22) & mask);
  out[15] = base + (uint32_t)(((w6 >> 51) | (w7 << 13)) & mask);
  out[16] = base + (uint32_t)((w7 >> 16) & mask);
  out[17] = base + (uint32_t)(((w7 >> 45) | (w8 << 19)) & mask);
  out[18] = base + (uint32_t)((w8 >> 10) & mask);
  out[19] = base + (uint32_t)(((w8 >> 39) | (w9 << 25)) & mask);
  out[20] = base + (uint32_t)((w9 >> 4) & mask);
  out[21] = base + (uint32_t)((w9 >> 33) & mask);
  out[22] = base + (uint32_t)(((w9 >> 62) | (w10 << 2)) & mask);
  out[23] = base + (uint32_t)((w10 >> 27) & mask);
  out[24] = base + (uint32_t)(((w10 >> 56) | (w11 << 8)) & mask);
  out[25] = base + (uint32_t)((w11 >> 21) & mask);
  out[26] = base + (uint32_t)(((w11 >> 50) | (w12 << 14)) & mask);
  out[27] = base + (uint32_t)((w12 >> 15) & mask);
  out[28] = base + (uint32_t)(((w12 >> 44) | (w13 << 20)) & mask);
  out[29] = base + (uint32_t)((w13 >> 9) & mask);
  out[30] = base + (uint32_t)(((w13 >> 38) | (w14 << 26)) & mask);
  out[31] = base + (uint32_t)((w14 >> 3) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 30-bit values, touching 15 64-bit words, using 120 bytes */
static void unpackforblock30(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(1073741823);
  /* we are going to access  15 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  uint64_t w12 = pw64[12];
  uint64_t w13 = pw64[13];
  uint64_t w14 = pw64[14];
  *pw += 120; /* we used up 120 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 30) & mask);
  out[2] = base + (uint32_t)(((w0 >> 60) | (w1 << 4)) & mask);
  out[3] = base + (uint32_t)((w1 >> 26) & mask);
  out[4] = base + (uint32_t)(((w1 >> 56) | (w2 << 8)) & mask);
  out[5] = base + (uint32_t)((w2 >> 22) & mask);
  out[6] = base + (uint32_t)(((w2 >> 52) | (w3 << 12)) & mask);
  out[7] = base + (uint32_t)((w3 >> 18) & mask);
  out[8] = base + (uint32_t)(((w3 >> 48) | (w4 << 16)) & mask);
  out[9] = base + (uint32_t)((w4 >> 14) & mask);
  out[10] = base + (uint32_t)(((w4 >> 44) | (w5 << 20)) & mask);
  out[11] = base + (uint32_t)((w5 >> 10) & mask);
  out[12] = base + (uint32_t)(((w5 >> 40) | (w6 << 24)) & mask);
  out[13] = base + (uint32_t)((w6 >> 6) & mask);
  out[14] = base + (uint32_t)(((w6 >> 36) | (w7 << 28)) & mask);
  out[15] = base + (uint32_t)((w7 >> 2) & mask);
  out[16] = base + (uint32_t)((w7 >> 32) & mask);
  out[17] = base + (uint32_t)(((w7 >> 62) | (w8 << 2)) & mask);
  out[18] = base + (uint32_t)((w8 >> 28) & mask);
  out[19] = base + (uint32_t)(((w8 >> 58) | (w9 << 6)) & mask);
  out[20] = base + (uint32_t)((w9 >> 24) & mask);
  out[21] = base + (uint32_t)(((w9 >> 54) | (w10 << 10)) & mask);
  out[22] = base + (uint32_t)((w10 >> 20) & mask);
  out[23] = base + (uint32_t)(((w10 >> 50) | (w11 << 14)) & mask);
  out[24] = base + (uint32_t)((w11 >> 16) & mask);
  out[25] = base + (uint32_t)(((w11 >> 46) | (w12 << 18)) & mask);
  out[26] = base + (uint32_t)((w12 >> 12) & mask);
  out[27] = base + (uint32_t)(((w12 >> 42) | (w13 << 22)) & mask);
  out[28] = base + (uint32_t)((w13 >> 8) & mask);
  out[29] = base + (uint32_t)(((w13 >> 38) | (w14 << 26)) & mask);
  out[30] = base + (uint32_t)((w14 >> 4) & mask);
  out[31] = base + (uint32_t)(w14 >> 34);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 31-bit values, touching 16 64-bit words, using 124 bytes */
static void unpackforblock31(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  const uint64_t mask = UINT64_C(2147483647);
  /* we are going to access  16 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  uint64_t w12 = pw64[12];
  uint64_t w13 = pw64[13];
  uint64_t w14 = pw64[14];
  uint64_t w15 = pw64[15];
  *pw += 124; /* we used up 124 input bytes */
  out[0] = base + (uint32_t)((w0)&mask);
  out[1] = base + (uint32_t)((w0 >> 31) & mask);
  out[2] = base + (uint32_t)(((w0 >> 62) | (w1 << 2)) & mask);
  out[3] = base + (uint32_t)((w1 >> 29) & mask);
  out[4] = base + (uint32_t)(((w1 >> 60) | (w2 << 4)) & mask);
  out[5] = base + (uint32_t)((w2 >> 27) & mask);
  out[6] = base + (uint32_t)(((w2 >> 58) | (w3 << 6)) & mask);
  out[7] = base + (uint32_t)((w3 >> 25) & mask);
  out[8] = base + (uint32_t)(((w3 >> 56) | (w4 << 8)) & mask);
  out[9] = base + (uint32_t)((w4 >> 23) & mask);
  out[10] = base + (uint32_t)(((w4 >> 54) | (w5 << 10)) & mask);
  out[11] = base + (uint32_t)((w5 >> 21) & mask);
  out[12] = base + (uint32_t)(((w5 >> 52) | (w6 << 12)) & mask);
  out[13] = base + (uint32_t)((w6 >> 19) & mask);
  out[14] = base + (uint32_t)(((w6 >> 50) | (w7 << 14)) & mask);
  out[15] = base + (uint32_t)((w7 >> 17) & mask);
  out[16] = base + (uint32_t)(((w7 >> 48) | (w8 << 16)) & mask);
  out[17] = base + (uint32_t)((w8 >> 15) & mask);
  out[18] = base + (uint32_t)(((w8 >> 46) | (w9 << 18)) & mask);
  out[19] = base + (uint32_t)((w9 >> 13) & mask);
  out[20] = base + (uint32_t)(((w9 >> 44) | (w10 << 20)) & mask);
  out[21] = base + (uint32_t)((w10 >> 11) & mask);
  out[22] = base + (uint32_t)(((w10 >> 42) | (w11 << 22)) & mask);
  out[23] = base + (uint32_t)((w11 >> 9) & mask);
  out[24] = base + (uint32_t)(((w11 >> 40) | (w12 << 24)) & mask);
  out[25] = base + (uint32_t)((w12 >> 7) & mask);
  out[26] = base + (uint32_t)(((w12 >> 38) | (w13 << 26)) & mask);
  out[27] = base + (uint32_t)((w13 >> 5) & mask);
  out[28] = base + (uint32_t)(((w13 >> 36) | (w14 << 28)) & mask);
  out[29] = base + (uint32_t)((w14 >> 3) & mask);
  out[30] = base + (uint32_t)(((w14 >> 34) | (w15 << 30)) & mask);
  out[31] = base + (uint32_t)((w15 >> 1) & mask);
  *pout += 32; /* we wrote 32 32-bit integers */
}

/* we packed 32 32-bit values, touching 16 64-bit words, using 128 bytes */
static void unpackforblock32(const uint32_t base, const uint8_t **pw,
                             uint32_t **pout) {
  const uint64_t *pw64 = *(const uint64_t **)pw;
  uint32_t *out = *pout;
  /* we are going to access  16 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  uint64_t w6 = pw64[6];
  uint64_t w7 = pw64[7];
  uint64_t w8 = pw64[8];
  uint64_t w9 = pw64[9];
  uint64_t w10 = pw64[10];
  uint64_t w11 = pw64[11];
  uint64_t w12 = pw64[12];
  uint64_t w13 = pw64[13];
  uint64_t w14 = pw64[14];
  uint64_t w15 = pw64[15];
  *pw += 128; /* we used up 128 input bytes */
  out[0] = base + (uint32_t)((w0));
  out[1] = base + (uint32_t)(w0 >> 32);
  out[2] = base + (uint32_t)((w1));
  out[3] = base + (uint32_t)(w1 >> 32);
  out[4] = base + (uint32_t)((w2));
  out[5] = base + (uint32_t)(w2 >> 32);
  out[6] = base + (uint32_t)((w3));
  out[7] = base + (uint32_t)(w3 >> 32);
  out[8] = base + (uint32_t)((w4));
  out[9] = base + (uint32_t)(w4 >> 32);
  out[10] = base + (uint32_t)((w5));
  out[11] = base + (uint32_t)(w5 >> 32);
  out[12] = base + (uint32_t)((w6));
  out[13] = base + (uint32_t)(w6 >> 32);
  out[14] = base + (uint32_t)((w7));
  out[15] = base + (uint32_t)(w7 >> 32);
  out[16] = base + (uint32_t)((w8));
  out[17] = base + (uint32_t)(w8 >> 32);
  out[18] = base + (uint32_t)((w9));
  out[19] = base + (uint32_t)(w9 >> 32);
  out[20] = base + (uint32_t)((w10));
  out[21] = base + (uint32_t)(w10 >> 32);
  out[22] = base + (uint32_t)((w11));
  out[23] = base + (uint32_t)(w11 >> 32);
  out[24] = base + (uint32_t)((w12));
  out[25] = base + (uint32_t)(w12 >> 32);
  out[26] = base + (uint32_t)((w13));
  out[27] = base + (uint32_t)(w13 >> 32);
  out[28] = base + (uint32_t)((w14));
  out[29] = base + (uint32_t)(w14 >> 32);
  out[30] = base + (uint32_t)((w15));
  out[31] = base + (uint32_t)(w15 >> 32);
  *pout += 32; /* we wrote 32 32-bit integers */
}

static packforblockfnc funcForPackArr[] = {
    &packforblock0,  &packforblock1,  &packforblock2,  &packforblock3,
    &packforblock4,  &packforblock5,  &packforblock6,  &packforblock7,
    &packforblock8,  &packforblock9,  &packforblock10, &packforblock11,
    &packforblock12, &packforblock13, &packforblock14, &packforblock15,
    &packforblock16, &packforblock17, &packforblock18, &packforblock19,
    &packforblock20, &packforblock21, &packforblock22, &packforblock23,
    &packforblock24, &packforblock25, &packforblock26, &packforblock27,
    &packforblock28, &packforblock29, &packforblock30, &packforblock31,
    &packforblock32};
static unpackforblockfnc funcForUnpackArr[] = {
    &unpackforblock0,  &unpackforblock1,  &unpackforblock2,  &unpackforblock3,
    &unpackforblock4,  &unpackforblock5,  &unpackforblock6,  &unpackforblock7,
    &unpackforblock8,  &unpackforblock9,  &unpackforblock10, &unpackforblock11,
    &unpackforblock12, &unpackforblock13, &unpackforblock14, &unpackforblock15,
    &unpackforblock16, &unpackforblock17, &unpackforblock18, &unpackforblock19,
    &unpackforblock20, &unpackforblock21, &unpackforblock22, &unpackforblock23,
    &unpackforblock24, &unpackforblock25, &unpackforblock26, &unpackforblock27,
    &unpackforblock28, &unpackforblock29, &unpackforblock30, &unpackforblock31,
    &unpackforblock32};
/**  turbopacking32.py ends here **/

#endif // INCLUDE_TURBOPACKING32_H
