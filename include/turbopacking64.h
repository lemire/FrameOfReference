
#ifndef INCLUDE_TURBOPACKING64_H
#define INCLUDE_TURBOPACKING64_H
#include <iso646.h> // mostly for Microsoft compilers
#include <stdint.h> // part of Visual Studio 2010 and better


#ifndef UINT64_C
#define UINT64_C(c) (c ## ULL)
#endif


/**
* (c) Daniel Lemire
* Apache License 2.0
*/
/** turbopacking64 starts here **/
/**
* this code mimics the way TurboPFor packs short arrays of integers.
* We pack and unpack always at least a full 64-bit word, plus whatever
* is necessary to get to an even number of bytes.
*/
typedef void (*packforblockfnc_64)(const uint64_t base, const uint64_t ** pin, uint8_t ** pw);
typedef void (*unpackforblockfnc_64)(const uint64_t base, const uint8_t ** pw, uint64_t ** pout);

static void packforblock0_64(const uint64_t , const uint64_t ** pin, uint8_t ** pw) {
  (void)pw;
  *pin += 32; /* we consumed 32 64-bit integers */ 
}


/* we are going to pack 32 1-bit values, touching 1 64-bit words, using 4 bytes */ 
static void packforblock1_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  1 64-bit word */ 
  uint64_t w0;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 1;
  w0 |=  (in[2] - base) << 2;
  w0 |=  (in[3] - base) << 3;
  w0 |=  (in[4] - base) << 4;
  w0 |=  (in[5] - base) << 5;
  w0 |=  (in[6] - base) << 6;
  w0 |=  (in[7] - base) << 7;
  w0 |=  (in[8] - base) << 8;
  w0 |=  (in[9] - base) << 9;
  w0 |=  (in[10] - base) << 10;
  w0 |=  (in[11] - base) << 11;
  w0 |=  (in[12] - base) << 12;
  w0 |=  (in[13] - base) << 13;
  w0 |=  (in[14] - base) << 14;
  w0 |=  (in[15] - base) << 15;
  w0 |=  (in[16] - base) << 16;
  w0 |=  (in[17] - base) << 17;
  w0 |=  (in[18] - base) << 18;
  w0 |=  (in[19] - base) << 19;
  w0 |=  (in[20] - base) << 20;
  w0 |=  (in[21] - base) << 21;
  w0 |=  (in[22] - base) << 22;
  w0 |=  (in[23] - base) << 23;
  w0 |=  (in[24] - base) << 24;
  w0 |=  (in[25] - base) << 25;
  w0 |=  (in[26] - base) << 26;
  w0 |=  (in[27] - base) << 27;
  w0 |=  (in[28] - base) << 28;
  w0 |=  (in[29] - base) << 29;
  w0 |=  (in[30] - base) << 30;
  w0 |=  (in[31] - base) << 31;
  pw64[0] = w0;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 4; /* we used up 4 output bytes */ 
}


/* we are going to pack 32 2-bit values, touching 1 64-bit words, using 8 bytes */ 
static void packforblock2_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  1 64-bit word */ 
  uint64_t w0;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 2;
  w0 |=  (in[2] - base) << 4;
  w0 |=  (in[3] - base) << 6;
  w0 |=  (in[4] - base) << 8;
  w0 |=  (in[5] - base) << 10;
  w0 |=  (in[6] - base) << 12;
  w0 |=  (in[7] - base) << 14;
  w0 |=  (in[8] - base) << 16;
  w0 |=  (in[9] - base) << 18;
  w0 |=  (in[10] - base) << 20;
  w0 |=  (in[11] - base) << 22;
  w0 |=  (in[12] - base) << 24;
  w0 |=  (in[13] - base) << 26;
  w0 |=  (in[14] - base) << 28;
  w0 |=  (in[15] - base) << 30;
  w0 |=  (in[16] - base) << 32;
  w0 |=  (in[17] - base) << 34;
  w0 |=  (in[18] - base) << 36;
  w0 |=  (in[19] - base) << 38;
  w0 |=  (in[20] - base) << 40;
  w0 |=  (in[21] - base) << 42;
  w0 |=  (in[22] - base) << 44;
  w0 |=  (in[23] - base) << 46;
  w0 |=  (in[24] - base) << 48;
  w0 |=  (in[25] - base) << 50;
  w0 |=  (in[26] - base) << 52;
  w0 |=  (in[27] - base) << 54;
  w0 |=  (in[28] - base) << 56;
  w0 |=  (in[29] - base) << 58;
  w0 |=  (in[30] - base) << 60;
  w0 |=  (in[31] - base) << 62;
  pw64[0] = w0;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 8; /* we used up 8 output bytes */ 
}


/* we are going to pack 32 3-bit values, touching 2 64-bit words, using 12 bytes */ 
static void packforblock3_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  2 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 3;
  w0 |=  (in[2] - base) << 6;
  w0 |=  (in[3] - base) << 9;
  w0 |=  (in[4] - base) << 12;
  w0 |=  (in[5] - base) << 15;
  w0 |=  (in[6] - base) << 18;
  w0 |=  (in[7] - base) << 21;
  w0 |=  (in[8] - base) << 24;
  w0 |=  (in[9] - base) << 27;
  w0 |=  (in[10] - base) << 30;
  w0 |=  (in[11] - base) << 33;
  w0 |=  (in[12] - base) << 36;
  w0 |=  (in[13] - base) << 39;
  w0 |=  (in[14] - base) << 42;
  w0 |=  (in[15] - base) << 45;
  w0 |=  (in[16] - base) << 48;
  w0 |=  (in[17] - base) << 51;
  w0 |=  (in[18] - base) << 54;
  w0 |=  (in[19] - base) << 57;
  w0 |=  (in[20] - base) << 60;
  w0 |= (in[21] - base) << 63;
  w1 = (in[21] - base) >> 1;
  w1 |=  (in[22] - base) << 2;
  w1 |=  (in[23] - base) << 5;
  w1 |=  (in[24] - base) << 8;
  w1 |=  (in[25] - base) << 11;
  w1 |=  (in[26] - base) << 14;
  w1 |=  (in[27] - base) << 17;
  w1 |=  (in[28] - base) << 20;
  w1 |=  (in[29] - base) << 23;
  w1 |=  (in[30] - base) << 26;
  w1 |=  (in[31] - base) << 29;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 12; /* we used up 12 output bytes */ 
}


/* we are going to pack 32 4-bit values, touching 2 64-bit words, using 16 bytes */ 
static void packforblock4_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  2 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 4;
  w0 |=  (in[2] - base) << 8;
  w0 |=  (in[3] - base) << 12;
  w0 |=  (in[4] - base) << 16;
  w0 |=  (in[5] - base) << 20;
  w0 |=  (in[6] - base) << 24;
  w0 |=  (in[7] - base) << 28;
  w0 |=  (in[8] - base) << 32;
  w0 |=  (in[9] - base) << 36;
  w0 |=  (in[10] - base) << 40;
  w0 |=  (in[11] - base) << 44;
  w0 |=  (in[12] - base) << 48;
  w0 |=  (in[13] - base) << 52;
  w0 |=  (in[14] - base) << 56;
  w0 |=  (in[15] - base) << 60;
  w1 = (in[16] - base);
  w1 |=  (in[17] - base) << 4;
  w1 |=  (in[18] - base) << 8;
  w1 |=  (in[19] - base) << 12;
  w1 |=  (in[20] - base) << 16;
  w1 |=  (in[21] - base) << 20;
  w1 |=  (in[22] - base) << 24;
  w1 |=  (in[23] - base) << 28;
  w1 |=  (in[24] - base) << 32;
  w1 |=  (in[25] - base) << 36;
  w1 |=  (in[26] - base) << 40;
  w1 |=  (in[27] - base) << 44;
  w1 |=  (in[28] - base) << 48;
  w1 |=  (in[29] - base) << 52;
  w1 |=  (in[30] - base) << 56;
  w1 |=  (in[31] - base) << 60;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 16; /* we used up 16 output bytes */ 
}


/* we are going to pack 32 5-bit values, touching 3 64-bit words, using 20 bytes */ 
static void packforblock5_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  3 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 5;
  w0 |=  (in[2] - base) << 10;
  w0 |=  (in[3] - base) << 15;
  w0 |=  (in[4] - base) << 20;
  w0 |=  (in[5] - base) << 25;
  w0 |=  (in[6] - base) << 30;
  w0 |=  (in[7] - base) << 35;
  w0 |=  (in[8] - base) << 40;
  w0 |=  (in[9] - base) << 45;
  w0 |=  (in[10] - base) << 50;
  w0 |=  (in[11] - base) << 55;
  w0 |= (in[12] - base) << 60;
  w1 = (in[12] - base) >> 4;
  w1 |=  (in[13] - base) << 1;
  w1 |=  (in[14] - base) << 6;
  w1 |=  (in[15] - base) << 11;
  w1 |=  (in[16] - base) << 16;
  w1 |=  (in[17] - base) << 21;
  w1 |=  (in[18] - base) << 26;
  w1 |=  (in[19] - base) << 31;
  w1 |=  (in[20] - base) << 36;
  w1 |=  (in[21] - base) << 41;
  w1 |=  (in[22] - base) << 46;
  w1 |=  (in[23] - base) << 51;
  w1 |=  (in[24] - base) << 56;
  w1 |= (in[25] - base) << 61;
  w2 = (in[25] - base) >> 3;
  w2 |=  (in[26] - base) << 2;
  w2 |=  (in[27] - base) << 7;
  w2 |=  (in[28] - base) << 12;
  w2 |=  (in[29] - base) << 17;
  w2 |=  (in[30] - base) << 22;
  w2 |=  (in[31] - base) << 27;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 20; /* we used up 20 output bytes */ 
}


/* we are going to pack 32 6-bit values, touching 3 64-bit words, using 24 bytes */ 
static void packforblock6_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  3 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 6;
  w0 |=  (in[2] - base) << 12;
  w0 |=  (in[3] - base) << 18;
  w0 |=  (in[4] - base) << 24;
  w0 |=  (in[5] - base) << 30;
  w0 |=  (in[6] - base) << 36;
  w0 |=  (in[7] - base) << 42;
  w0 |=  (in[8] - base) << 48;
  w0 |=  (in[9] - base) << 54;
  w0 |= (in[10] - base) << 60;
  w1 = (in[10] - base) >> 4;
  w1 |=  (in[11] - base) << 2;
  w1 |=  (in[12] - base) << 8;
  w1 |=  (in[13] - base) << 14;
  w1 |=  (in[14] - base) << 20;
  w1 |=  (in[15] - base) << 26;
  w1 |=  (in[16] - base) << 32;
  w1 |=  (in[17] - base) << 38;
  w1 |=  (in[18] - base) << 44;
  w1 |=  (in[19] - base) << 50;
  w1 |=  (in[20] - base) << 56;
  w1 |= (in[21] - base) << 62;
  w2 = (in[21] - base) >> 2;
  w2 |=  (in[22] - base) << 4;
  w2 |=  (in[23] - base) << 10;
  w2 |=  (in[24] - base) << 16;
  w2 |=  (in[25] - base) << 22;
  w2 |=  (in[26] - base) << 28;
  w2 |=  (in[27] - base) << 34;
  w2 |=  (in[28] - base) << 40;
  w2 |=  (in[29] - base) << 46;
  w2 |=  (in[30] - base) << 52;
  w2 |=  (in[31] - base) << 58;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 24; /* we used up 24 output bytes */ 
}


/* we are going to pack 32 7-bit values, touching 4 64-bit words, using 28 bytes */ 
static void packforblock7_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  4 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 7;
  w0 |=  (in[2] - base) << 14;
  w0 |=  (in[3] - base) << 21;
  w0 |=  (in[4] - base) << 28;
  w0 |=  (in[5] - base) << 35;
  w0 |=  (in[6] - base) << 42;
  w0 |=  (in[7] - base) << 49;
  w0 |=  (in[8] - base) << 56;
  w0 |= (in[9] - base) << 63;
  w1 = (in[9] - base) >> 1;
  w1 |=  (in[10] - base) << 6;
  w1 |=  (in[11] - base) << 13;
  w1 |=  (in[12] - base) << 20;
  w1 |=  (in[13] - base) << 27;
  w1 |=  (in[14] - base) << 34;
  w1 |=  (in[15] - base) << 41;
  w1 |=  (in[16] - base) << 48;
  w1 |=  (in[17] - base) << 55;
  w1 |= (in[18] - base) << 62;
  w2 = (in[18] - base) >> 2;
  w2 |=  (in[19] - base) << 5;
  w2 |=  (in[20] - base) << 12;
  w2 |=  (in[21] - base) << 19;
  w2 |=  (in[22] - base) << 26;
  w2 |=  (in[23] - base) << 33;
  w2 |=  (in[24] - base) << 40;
  w2 |=  (in[25] - base) << 47;
  w2 |=  (in[26] - base) << 54;
  w2 |= (in[27] - base) << 61;
  w3 = (in[27] - base) >> 3;
  w3 |=  (in[28] - base) << 4;
  w3 |=  (in[29] - base) << 11;
  w3 |=  (in[30] - base) << 18;
  w3 |=  (in[31] - base) << 25;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 28; /* we used up 28 output bytes */ 
}


/* we are going to pack 32 8-bit values, touching 4 64-bit words, using 32 bytes */ 
static void packforblock8_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  4 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 8;
  w0 |=  (in[2] - base) << 16;
  w0 |=  (in[3] - base) << 24;
  w0 |=  (in[4] - base) << 32;
  w0 |=  (in[5] - base) << 40;
  w0 |=  (in[6] - base) << 48;
  w0 |=  (in[7] - base) << 56;
  w1 = (in[8] - base);
  w1 |=  (in[9] - base) << 8;
  w1 |=  (in[10] - base) << 16;
  w1 |=  (in[11] - base) << 24;
  w1 |=  (in[12] - base) << 32;
  w1 |=  (in[13] - base) << 40;
  w1 |=  (in[14] - base) << 48;
  w1 |=  (in[15] - base) << 56;
  w2 = (in[16] - base);
  w2 |=  (in[17] - base) << 8;
  w2 |=  (in[18] - base) << 16;
  w2 |=  (in[19] - base) << 24;
  w2 |=  (in[20] - base) << 32;
  w2 |=  (in[21] - base) << 40;
  w2 |=  (in[22] - base) << 48;
  w2 |=  (in[23] - base) << 56;
  w3 = (in[24] - base);
  w3 |=  (in[25] - base) << 8;
  w3 |=  (in[26] - base) << 16;
  w3 |=  (in[27] - base) << 24;
  w3 |=  (in[28] - base) << 32;
  w3 |=  (in[29] - base) << 40;
  w3 |=  (in[30] - base) << 48;
  w3 |=  (in[31] - base) << 56;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 32; /* we used up 32 output bytes */ 
}


/* we are going to pack 32 9-bit values, touching 5 64-bit words, using 36 bytes */ 
static void packforblock9_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  5 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 9;
  w0 |=  (in[2] - base) << 18;
  w0 |=  (in[3] - base) << 27;
  w0 |=  (in[4] - base) << 36;
  w0 |=  (in[5] - base) << 45;
  w0 |=  (in[6] - base) << 54;
  w0 |= (in[7] - base) << 63;
  w1 = (in[7] - base) >> 1;
  w1 |=  (in[8] - base) << 8;
  w1 |=  (in[9] - base) << 17;
  w1 |=  (in[10] - base) << 26;
  w1 |=  (in[11] - base) << 35;
  w1 |=  (in[12] - base) << 44;
  w1 |=  (in[13] - base) << 53;
  w1 |= (in[14] - base) << 62;
  w2 = (in[14] - base) >> 2;
  w2 |=  (in[15] - base) << 7;
  w2 |=  (in[16] - base) << 16;
  w2 |=  (in[17] - base) << 25;
  w2 |=  (in[18] - base) << 34;
  w2 |=  (in[19] - base) << 43;
  w2 |=  (in[20] - base) << 52;
  w2 |= (in[21] - base) << 61;
  w3 = (in[21] - base) >> 3;
  w3 |=  (in[22] - base) << 6;
  w3 |=  (in[23] - base) << 15;
  w3 |=  (in[24] - base) << 24;
  w3 |=  (in[25] - base) << 33;
  w3 |=  (in[26] - base) << 42;
  w3 |=  (in[27] - base) << 51;
  w3 |= (in[28] - base) << 60;
  w4 = (in[28] - base) >> 4;
  w4 |=  (in[29] - base) << 5;
  w4 |=  (in[30] - base) << 14;
  w4 |=  (in[31] - base) << 23;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 36; /* we used up 36 output bytes */ 
}


/* we are going to pack 32 10-bit values, touching 5 64-bit words, using 40 bytes */ 
static void packforblock10_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  5 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 10;
  w0 |=  (in[2] - base) << 20;
  w0 |=  (in[3] - base) << 30;
  w0 |=  (in[4] - base) << 40;
  w0 |=  (in[5] - base) << 50;
  w0 |= (in[6] - base) << 60;
  w1 = (in[6] - base) >> 4;
  w1 |=  (in[7] - base) << 6;
  w1 |=  (in[8] - base) << 16;
  w1 |=  (in[9] - base) << 26;
  w1 |=  (in[10] - base) << 36;
  w1 |=  (in[11] - base) << 46;
  w1 |= (in[12] - base) << 56;
  w2 = (in[12] - base) >> 8;
  w2 |=  (in[13] - base) << 2;
  w2 |=  (in[14] - base) << 12;
  w2 |=  (in[15] - base) << 22;
  w2 |=  (in[16] - base) << 32;
  w2 |=  (in[17] - base) << 42;
  w2 |=  (in[18] - base) << 52;
  w2 |= (in[19] - base) << 62;
  w3 = (in[19] - base) >> 2;
  w3 |=  (in[20] - base) << 8;
  w3 |=  (in[21] - base) << 18;
  w3 |=  (in[22] - base) << 28;
  w3 |=  (in[23] - base) << 38;
  w3 |=  (in[24] - base) << 48;
  w3 |= (in[25] - base) << 58;
  w4 = (in[25] - base) >> 6;
  w4 |=  (in[26] - base) << 4;
  w4 |=  (in[27] - base) << 14;
  w4 |=  (in[28] - base) << 24;
  w4 |=  (in[29] - base) << 34;
  w4 |=  (in[30] - base) << 44;
  w4 |=  (in[31] - base) << 54;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 40; /* we used up 40 output bytes */ 
}


/* we are going to pack 32 11-bit values, touching 6 64-bit words, using 44 bytes */ 
static void packforblock11_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  6 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 11;
  w0 |=  (in[2] - base) << 22;
  w0 |=  (in[3] - base) << 33;
  w0 |=  (in[4] - base) << 44;
  w0 |= (in[5] - base) << 55;
  w1 = (in[5] - base) >> 9;
  w1 |=  (in[6] - base) << 2;
  w1 |=  (in[7] - base) << 13;
  w1 |=  (in[8] - base) << 24;
  w1 |=  (in[9] - base) << 35;
  w1 |=  (in[10] - base) << 46;
  w1 |= (in[11] - base) << 57;
  w2 = (in[11] - base) >> 7;
  w2 |=  (in[12] - base) << 4;
  w2 |=  (in[13] - base) << 15;
  w2 |=  (in[14] - base) << 26;
  w2 |=  (in[15] - base) << 37;
  w2 |=  (in[16] - base) << 48;
  w2 |= (in[17] - base) << 59;
  w3 = (in[17] - base) >> 5;
  w3 |=  (in[18] - base) << 6;
  w3 |=  (in[19] - base) << 17;
  w3 |=  (in[20] - base) << 28;
  w3 |=  (in[21] - base) << 39;
  w3 |=  (in[22] - base) << 50;
  w3 |= (in[23] - base) << 61;
  w4 = (in[23] - base) >> 3;
  w4 |=  (in[24] - base) << 8;
  w4 |=  (in[25] - base) << 19;
  w4 |=  (in[26] - base) << 30;
  w4 |=  (in[27] - base) << 41;
  w4 |=  (in[28] - base) << 52;
  w4 |= (in[29] - base) << 63;
  w5 = (in[29] - base) >> 1;
  w5 |=  (in[30] - base) << 10;
  w5 |=  (in[31] - base) << 21;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 44; /* we used up 44 output bytes */ 
}


/* we are going to pack 32 12-bit values, touching 6 64-bit words, using 48 bytes */ 
static void packforblock12_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  6 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 12;
  w0 |=  (in[2] - base) << 24;
  w0 |=  (in[3] - base) << 36;
  w0 |=  (in[4] - base) << 48;
  w0 |= (in[5] - base) << 60;
  w1 = (in[5] - base) >> 4;
  w1 |=  (in[6] - base) << 8;
  w1 |=  (in[7] - base) << 20;
  w1 |=  (in[8] - base) << 32;
  w1 |=  (in[9] - base) << 44;
  w1 |= (in[10] - base) << 56;
  w2 = (in[10] - base) >> 8;
  w2 |=  (in[11] - base) << 4;
  w2 |=  (in[12] - base) << 16;
  w2 |=  (in[13] - base) << 28;
  w2 |=  (in[14] - base) << 40;
  w2 |=  (in[15] - base) << 52;
  w3 = (in[16] - base);
  w3 |=  (in[17] - base) << 12;
  w3 |=  (in[18] - base) << 24;
  w3 |=  (in[19] - base) << 36;
  w3 |=  (in[20] - base) << 48;
  w3 |= (in[21] - base) << 60;
  w4 = (in[21] - base) >> 4;
  w4 |=  (in[22] - base) << 8;
  w4 |=  (in[23] - base) << 20;
  w4 |=  (in[24] - base) << 32;
  w4 |=  (in[25] - base) << 44;
  w4 |= (in[26] - base) << 56;
  w5 = (in[26] - base) >> 8;
  w5 |=  (in[27] - base) << 4;
  w5 |=  (in[28] - base) << 16;
  w5 |=  (in[29] - base) << 28;
  w5 |=  (in[30] - base) << 40;
  w5 |=  (in[31] - base) << 52;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 48; /* we used up 48 output bytes */ 
}


/* we are going to pack 32 13-bit values, touching 7 64-bit words, using 52 bytes */ 
static void packforblock13_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  7 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 13;
  w0 |=  (in[2] - base) << 26;
  w0 |=  (in[3] - base) << 39;
  w0 |= (in[4] - base) << 52;
  w1 = (in[4] - base) >> 12;
  w1 |=  (in[5] - base) << 1;
  w1 |=  (in[6] - base) << 14;
  w1 |=  (in[7] - base) << 27;
  w1 |=  (in[8] - base) << 40;
  w1 |= (in[9] - base) << 53;
  w2 = (in[9] - base) >> 11;
  w2 |=  (in[10] - base) << 2;
  w2 |=  (in[11] - base) << 15;
  w2 |=  (in[12] - base) << 28;
  w2 |=  (in[13] - base) << 41;
  w2 |= (in[14] - base) << 54;
  w3 = (in[14] - base) >> 10;
  w3 |=  (in[15] - base) << 3;
  w3 |=  (in[16] - base) << 16;
  w3 |=  (in[17] - base) << 29;
  w3 |=  (in[18] - base) << 42;
  w3 |= (in[19] - base) << 55;
  w4 = (in[19] - base) >> 9;
  w4 |=  (in[20] - base) << 4;
  w4 |=  (in[21] - base) << 17;
  w4 |=  (in[22] - base) << 30;
  w4 |=  (in[23] - base) << 43;
  w4 |= (in[24] - base) << 56;
  w5 = (in[24] - base) >> 8;
  w5 |=  (in[25] - base) << 5;
  w5 |=  (in[26] - base) << 18;
  w5 |=  (in[27] - base) << 31;
  w5 |=  (in[28] - base) << 44;
  w5 |= (in[29] - base) << 57;
  w6 = (in[29] - base) >> 7;
  w6 |=  (in[30] - base) << 6;
  w6 |=  (in[31] - base) << 19;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 52; /* we used up 52 output bytes */ 
}


/* we are going to pack 32 14-bit values, touching 7 64-bit words, using 56 bytes */ 
static void packforblock14_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  7 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 14;
  w0 |=  (in[2] - base) << 28;
  w0 |=  (in[3] - base) << 42;
  w0 |= (in[4] - base) << 56;
  w1 = (in[4] - base) >> 8;
  w1 |=  (in[5] - base) << 6;
  w1 |=  (in[6] - base) << 20;
  w1 |=  (in[7] - base) << 34;
  w1 |=  (in[8] - base) << 48;
  w1 |= (in[9] - base) << 62;
  w2 = (in[9] - base) >> 2;
  w2 |=  (in[10] - base) << 12;
  w2 |=  (in[11] - base) << 26;
  w2 |=  (in[12] - base) << 40;
  w2 |= (in[13] - base) << 54;
  w3 = (in[13] - base) >> 10;
  w3 |=  (in[14] - base) << 4;
  w3 |=  (in[15] - base) << 18;
  w3 |=  (in[16] - base) << 32;
  w3 |=  (in[17] - base) << 46;
  w3 |= (in[18] - base) << 60;
  w4 = (in[18] - base) >> 4;
  w4 |=  (in[19] - base) << 10;
  w4 |=  (in[20] - base) << 24;
  w4 |=  (in[21] - base) << 38;
  w4 |= (in[22] - base) << 52;
  w5 = (in[22] - base) >> 12;
  w5 |=  (in[23] - base) << 2;
  w5 |=  (in[24] - base) << 16;
  w5 |=  (in[25] - base) << 30;
  w5 |=  (in[26] - base) << 44;
  w5 |= (in[27] - base) << 58;
  w6 = (in[27] - base) >> 6;
  w6 |=  (in[28] - base) << 8;
  w6 |=  (in[29] - base) << 22;
  w6 |=  (in[30] - base) << 36;
  w6 |=  (in[31] - base) << 50;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 56; /* we used up 56 output bytes */ 
}


/* we are going to pack 32 15-bit values, touching 8 64-bit words, using 60 bytes */ 
static void packforblock15_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  8 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 15;
  w0 |=  (in[2] - base) << 30;
  w0 |=  (in[3] - base) << 45;
  w0 |= (in[4] - base) << 60;
  w1 = (in[4] - base) >> 4;
  w1 |=  (in[5] - base) << 11;
  w1 |=  (in[6] - base) << 26;
  w1 |=  (in[7] - base) << 41;
  w1 |= (in[8] - base) << 56;
  w2 = (in[8] - base) >> 8;
  w2 |=  (in[9] - base) << 7;
  w2 |=  (in[10] - base) << 22;
  w2 |=  (in[11] - base) << 37;
  w2 |= (in[12] - base) << 52;
  w3 = (in[12] - base) >> 12;
  w3 |=  (in[13] - base) << 3;
  w3 |=  (in[14] - base) << 18;
  w3 |=  (in[15] - base) << 33;
  w3 |=  (in[16] - base) << 48;
  w3 |= (in[17] - base) << 63;
  w4 = (in[17] - base) >> 1;
  w4 |=  (in[18] - base) << 14;
  w4 |=  (in[19] - base) << 29;
  w4 |=  (in[20] - base) << 44;
  w4 |= (in[21] - base) << 59;
  w5 = (in[21] - base) >> 5;
  w5 |=  (in[22] - base) << 10;
  w5 |=  (in[23] - base) << 25;
  w5 |=  (in[24] - base) << 40;
  w5 |= (in[25] - base) << 55;
  w6 = (in[25] - base) >> 9;
  w6 |=  (in[26] - base) << 6;
  w6 |=  (in[27] - base) << 21;
  w6 |=  (in[28] - base) << 36;
  w6 |= (in[29] - base) << 51;
  w7 = (in[29] - base) >> 13;
  w7 |=  (in[30] - base) << 2;
  w7 |=  (in[31] - base) << 17;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 60; /* we used up 60 output bytes */ 
}


/* we are going to pack 32 16-bit values, touching 8 64-bit words, using 64 bytes */ 
static void packforblock16_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  8 64-bit words */ 
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  uint64_t w4;
  uint64_t w5;
  uint64_t w6;
  uint64_t w7;
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 16;
  w0 |=  (in[2] - base) << 32;
  w0 |=  (in[3] - base) << 48;
  w1 = (in[4] - base);
  w1 |=  (in[5] - base) << 16;
  w1 |=  (in[6] - base) << 32;
  w1 |=  (in[7] - base) << 48;
  w2 = (in[8] - base);
  w2 |=  (in[9] - base) << 16;
  w2 |=  (in[10] - base) << 32;
  w2 |=  (in[11] - base) << 48;
  w3 = (in[12] - base);
  w3 |=  (in[13] - base) << 16;
  w3 |=  (in[14] - base) << 32;
  w3 |=  (in[15] - base) << 48;
  w4 = (in[16] - base);
  w4 |=  (in[17] - base) << 16;
  w4 |=  (in[18] - base) << 32;
  w4 |=  (in[19] - base) << 48;
  w5 = (in[20] - base);
  w5 |=  (in[21] - base) << 16;
  w5 |=  (in[22] - base) << 32;
  w5 |=  (in[23] - base) << 48;
  w6 = (in[24] - base);
  w6 |=  (in[25] - base) << 16;
  w6 |=  (in[26] - base) << 32;
  w6 |=  (in[27] - base) << 48;
  w7 = (in[28] - base);
  w7 |=  (in[29] - base) << 16;
  w7 |=  (in[30] - base) << 32;
  w7 |=  (in[31] - base) << 48;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 64; /* we used up 64 output bytes */ 
}


/* we are going to pack 32 17-bit values, touching 9 64-bit words, using 68 bytes */ 
static void packforblock17_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 17;
  w0 |=  (in[2] - base) << 34;
  w0 |= (in[3] - base) << 51;
  w1 = (in[3] - base) >> 13;
  w1 |=  (in[4] - base) << 4;
  w1 |=  (in[5] - base) << 21;
  w1 |=  (in[6] - base) << 38;
  w1 |= (in[7] - base) << 55;
  w2 = (in[7] - base) >> 9;
  w2 |=  (in[8] - base) << 8;
  w2 |=  (in[9] - base) << 25;
  w2 |=  (in[10] - base) << 42;
  w2 |= (in[11] - base) << 59;
  w3 = (in[11] - base) >> 5;
  w3 |=  (in[12] - base) << 12;
  w3 |=  (in[13] - base) << 29;
  w3 |=  (in[14] - base) << 46;
  w3 |= (in[15] - base) << 63;
  w4 = (in[15] - base) >> 1;
  w4 |=  (in[16] - base) << 16;
  w4 |=  (in[17] - base) << 33;
  w4 |= (in[18] - base) << 50;
  w5 = (in[18] - base) >> 14;
  w5 |=  (in[19] - base) << 3;
  w5 |=  (in[20] - base) << 20;
  w5 |=  (in[21] - base) << 37;
  w5 |= (in[22] - base) << 54;
  w6 = (in[22] - base) >> 10;
  w6 |=  (in[23] - base) << 7;
  w6 |=  (in[24] - base) << 24;
  w6 |=  (in[25] - base) << 41;
  w6 |= (in[26] - base) << 58;
  w7 = (in[26] - base) >> 6;
  w7 |=  (in[27] - base) << 11;
  w7 |=  (in[28] - base) << 28;
  w7 |=  (in[29] - base) << 45;
  w7 |= (in[30] - base) << 62;
  w8 = (in[30] - base) >> 2;
  w8 |=  (in[31] - base) << 15;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 68; /* we used up 68 output bytes */ 
}


/* we are going to pack 32 18-bit values, touching 9 64-bit words, using 72 bytes */ 
static void packforblock18_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 18;
  w0 |=  (in[2] - base) << 36;
  w0 |= (in[3] - base) << 54;
  w1 = (in[3] - base) >> 10;
  w1 |=  (in[4] - base) << 8;
  w1 |=  (in[5] - base) << 26;
  w1 |=  (in[6] - base) << 44;
  w1 |= (in[7] - base) << 62;
  w2 = (in[7] - base) >> 2;
  w2 |=  (in[8] - base) << 16;
  w2 |=  (in[9] - base) << 34;
  w2 |= (in[10] - base) << 52;
  w3 = (in[10] - base) >> 12;
  w3 |=  (in[11] - base) << 6;
  w3 |=  (in[12] - base) << 24;
  w3 |=  (in[13] - base) << 42;
  w3 |= (in[14] - base) << 60;
  w4 = (in[14] - base) >> 4;
  w4 |=  (in[15] - base) << 14;
  w4 |=  (in[16] - base) << 32;
  w4 |= (in[17] - base) << 50;
  w5 = (in[17] - base) >> 14;
  w5 |=  (in[18] - base) << 4;
  w5 |=  (in[19] - base) << 22;
  w5 |=  (in[20] - base) << 40;
  w5 |= (in[21] - base) << 58;
  w6 = (in[21] - base) >> 6;
  w6 |=  (in[22] - base) << 12;
  w6 |=  (in[23] - base) << 30;
  w6 |= (in[24] - base) << 48;
  w7 = (in[24] - base) >> 16;
  w7 |=  (in[25] - base) << 2;
  w7 |=  (in[26] - base) << 20;
  w7 |=  (in[27] - base) << 38;
  w7 |= (in[28] - base) << 56;
  w8 = (in[28] - base) >> 8;
  w8 |=  (in[29] - base) << 10;
  w8 |=  (in[30] - base) << 28;
  w8 |=  (in[31] - base) << 46;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  pw64[4] = w4;
  pw64[5] = w5;
  pw64[6] = w6;
  pw64[7] = w7;
  pw64[8] = w8;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 72; /* we used up 72 output bytes */ 
}


/* we are going to pack 32 19-bit values, touching 10 64-bit words, using 76 bytes */ 
static void packforblock19_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 19;
  w0 |=  (in[2] - base) << 38;
  w0 |= (in[3] - base) << 57;
  w1 = (in[3] - base) >> 7;
  w1 |=  (in[4] - base) << 12;
  w1 |=  (in[5] - base) << 31;
  w1 |= (in[6] - base) << 50;
  w2 = (in[6] - base) >> 14;
  w2 |=  (in[7] - base) << 5;
  w2 |=  (in[8] - base) << 24;
  w2 |=  (in[9] - base) << 43;
  w2 |= (in[10] - base) << 62;
  w3 = (in[10] - base) >> 2;
  w3 |=  (in[11] - base) << 17;
  w3 |=  (in[12] - base) << 36;
  w3 |= (in[13] - base) << 55;
  w4 = (in[13] - base) >> 9;
  w4 |=  (in[14] - base) << 10;
  w4 |=  (in[15] - base) << 29;
  w4 |= (in[16] - base) << 48;
  w5 = (in[16] - base) >> 16;
  w5 |=  (in[17] - base) << 3;
  w5 |=  (in[18] - base) << 22;
  w5 |=  (in[19] - base) << 41;
  w5 |= (in[20] - base) << 60;
  w6 = (in[20] - base) >> 4;
  w6 |=  (in[21] - base) << 15;
  w6 |=  (in[22] - base) << 34;
  w6 |= (in[23] - base) << 53;
  w7 = (in[23] - base) >> 11;
  w7 |=  (in[24] - base) << 8;
  w7 |=  (in[25] - base) << 27;
  w7 |= (in[26] - base) << 46;
  w8 = (in[26] - base) >> 18;
  w8 |=  (in[27] - base) << 1;
  w8 |=  (in[28] - base) << 20;
  w8 |=  (in[29] - base) << 39;
  w8 |= (in[30] - base) << 58;
  w9 = (in[30] - base) >> 6;
  w9 |=  (in[31] - base) << 13;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 76; /* we used up 76 output bytes */ 
}


/* we are going to pack 32 20-bit values, touching 10 64-bit words, using 80 bytes */ 
static void packforblock20_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 20;
  w0 |=  (in[2] - base) << 40;
  w0 |= (in[3] - base) << 60;
  w1 = (in[3] - base) >> 4;
  w1 |=  (in[4] - base) << 16;
  w1 |=  (in[5] - base) << 36;
  w1 |= (in[6] - base) << 56;
  w2 = (in[6] - base) >> 8;
  w2 |=  (in[7] - base) << 12;
  w2 |=  (in[8] - base) << 32;
  w2 |= (in[9] - base) << 52;
  w3 = (in[9] - base) >> 12;
  w3 |=  (in[10] - base) << 8;
  w3 |=  (in[11] - base) << 28;
  w3 |= (in[12] - base) << 48;
  w4 = (in[12] - base) >> 16;
  w4 |=  (in[13] - base) << 4;
  w4 |=  (in[14] - base) << 24;
  w4 |=  (in[15] - base) << 44;
  w5 = (in[16] - base);
  w5 |=  (in[17] - base) << 20;
  w5 |=  (in[18] - base) << 40;
  w5 |= (in[19] - base) << 60;
  w6 = (in[19] - base) >> 4;
  w6 |=  (in[20] - base) << 16;
  w6 |=  (in[21] - base) << 36;
  w6 |= (in[22] - base) << 56;
  w7 = (in[22] - base) >> 8;
  w7 |=  (in[23] - base) << 12;
  w7 |=  (in[24] - base) << 32;
  w7 |= (in[25] - base) << 52;
  w8 = (in[25] - base) >> 12;
  w8 |=  (in[26] - base) << 8;
  w8 |=  (in[27] - base) << 28;
  w8 |= (in[28] - base) << 48;
  w9 = (in[28] - base) >> 16;
  w9 |=  (in[29] - base) << 4;
  w9 |=  (in[30] - base) << 24;
  w9 |=  (in[31] - base) << 44;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 80; /* we used up 80 output bytes */ 
}


/* we are going to pack 32 21-bit values, touching 11 64-bit words, using 84 bytes */ 
static void packforblock21_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 21;
  w0 |=  (in[2] - base) << 42;
  w0 |= (in[3] - base) << 63;
  w1 = (in[3] - base) >> 1;
  w1 |=  (in[4] - base) << 20;
  w1 |=  (in[5] - base) << 41;
  w1 |= (in[6] - base) << 62;
  w2 = (in[6] - base) >> 2;
  w2 |=  (in[7] - base) << 19;
  w2 |=  (in[8] - base) << 40;
  w2 |= (in[9] - base) << 61;
  w3 = (in[9] - base) >> 3;
  w3 |=  (in[10] - base) << 18;
  w3 |=  (in[11] - base) << 39;
  w3 |= (in[12] - base) << 60;
  w4 = (in[12] - base) >> 4;
  w4 |=  (in[13] - base) << 17;
  w4 |=  (in[14] - base) << 38;
  w4 |= (in[15] - base) << 59;
  w5 = (in[15] - base) >> 5;
  w5 |=  (in[16] - base) << 16;
  w5 |=  (in[17] - base) << 37;
  w5 |= (in[18] - base) << 58;
  w6 = (in[18] - base) >> 6;
  w6 |=  (in[19] - base) << 15;
  w6 |=  (in[20] - base) << 36;
  w6 |= (in[21] - base) << 57;
  w7 = (in[21] - base) >> 7;
  w7 |=  (in[22] - base) << 14;
  w7 |=  (in[23] - base) << 35;
  w7 |= (in[24] - base) << 56;
  w8 = (in[24] - base) >> 8;
  w8 |=  (in[25] - base) << 13;
  w8 |=  (in[26] - base) << 34;
  w8 |= (in[27] - base) << 55;
  w9 = (in[27] - base) >> 9;
  w9 |=  (in[28] - base) << 12;
  w9 |=  (in[29] - base) << 33;
  w9 |= (in[30] - base) << 54;
  w10 = (in[30] - base) >> 10;
  w10 |=  (in[31] - base) << 11;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 84; /* we used up 84 output bytes */ 
}


/* we are going to pack 32 22-bit values, touching 11 64-bit words, using 88 bytes */ 
static void packforblock22_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 22;
  w0 |= (in[2] - base) << 44;
  w1 = (in[2] - base) >> 20;
  w1 |=  (in[3] - base) << 2;
  w1 |=  (in[4] - base) << 24;
  w1 |= (in[5] - base) << 46;
  w2 = (in[5] - base) >> 18;
  w2 |=  (in[6] - base) << 4;
  w2 |=  (in[7] - base) << 26;
  w2 |= (in[8] - base) << 48;
  w3 = (in[8] - base) >> 16;
  w3 |=  (in[9] - base) << 6;
  w3 |=  (in[10] - base) << 28;
  w3 |= (in[11] - base) << 50;
  w4 = (in[11] - base) >> 14;
  w4 |=  (in[12] - base) << 8;
  w4 |=  (in[13] - base) << 30;
  w4 |= (in[14] - base) << 52;
  w5 = (in[14] - base) >> 12;
  w5 |=  (in[15] - base) << 10;
  w5 |=  (in[16] - base) << 32;
  w5 |= (in[17] - base) << 54;
  w6 = (in[17] - base) >> 10;
  w6 |=  (in[18] - base) << 12;
  w6 |=  (in[19] - base) << 34;
  w6 |= (in[20] - base) << 56;
  w7 = (in[20] - base) >> 8;
  w7 |=  (in[21] - base) << 14;
  w7 |=  (in[22] - base) << 36;
  w7 |= (in[23] - base) << 58;
  w8 = (in[23] - base) >> 6;
  w8 |=  (in[24] - base) << 16;
  w8 |=  (in[25] - base) << 38;
  w8 |= (in[26] - base) << 60;
  w9 = (in[26] - base) >> 4;
  w9 |=  (in[27] - base) << 18;
  w9 |=  (in[28] - base) << 40;
  w9 |= (in[29] - base) << 62;
  w10 = (in[29] - base) >> 2;
  w10 |=  (in[30] - base) << 20;
  w10 |=  (in[31] - base) << 42;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 88; /* we used up 88 output bytes */ 
}


/* we are going to pack 32 23-bit values, touching 12 64-bit words, using 92 bytes */ 
static void packforblock23_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 23;
  w0 |= (in[2] - base) << 46;
  w1 = (in[2] - base) >> 18;
  w1 |=  (in[3] - base) << 5;
  w1 |=  (in[4] - base) << 28;
  w1 |= (in[5] - base) << 51;
  w2 = (in[5] - base) >> 13;
  w2 |=  (in[6] - base) << 10;
  w2 |=  (in[7] - base) << 33;
  w2 |= (in[8] - base) << 56;
  w3 = (in[8] - base) >> 8;
  w3 |=  (in[9] - base) << 15;
  w3 |=  (in[10] - base) << 38;
  w3 |= (in[11] - base) << 61;
  w4 = (in[11] - base) >> 3;
  w4 |=  (in[12] - base) << 20;
  w4 |= (in[13] - base) << 43;
  w5 = (in[13] - base) >> 21;
  w5 |=  (in[14] - base) << 2;
  w5 |=  (in[15] - base) << 25;
  w5 |= (in[16] - base) << 48;
  w6 = (in[16] - base) >> 16;
  w6 |=  (in[17] - base) << 7;
  w6 |=  (in[18] - base) << 30;
  w6 |= (in[19] - base) << 53;
  w7 = (in[19] - base) >> 11;
  w7 |=  (in[20] - base) << 12;
  w7 |=  (in[21] - base) << 35;
  w7 |= (in[22] - base) << 58;
  w8 = (in[22] - base) >> 6;
  w8 |=  (in[23] - base) << 17;
  w8 |=  (in[24] - base) << 40;
  w8 |= (in[25] - base) << 63;
  w9 = (in[25] - base) >> 1;
  w9 |=  (in[26] - base) << 22;
  w9 |= (in[27] - base) << 45;
  w10 = (in[27] - base) >> 19;
  w10 |=  (in[28] - base) << 4;
  w10 |=  (in[29] - base) << 27;
  w10 |= (in[30] - base) << 50;
  w11 = (in[30] - base) >> 14;
  w11 |=  (in[31] - base) << 9;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 92; /* we used up 92 output bytes */ 
}


/* we are going to pack 32 24-bit values, touching 12 64-bit words, using 96 bytes */ 
static void packforblock24_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 24;
  w0 |= (in[2] - base) << 48;
  w1 = (in[2] - base) >> 16;
  w1 |=  (in[3] - base) << 8;
  w1 |=  (in[4] - base) << 32;
  w1 |= (in[5] - base) << 56;
  w2 = (in[5] - base) >> 8;
  w2 |=  (in[6] - base) << 16;
  w2 |=  (in[7] - base) << 40;
  w3 = (in[8] - base);
  w3 |=  (in[9] - base) << 24;
  w3 |= (in[10] - base) << 48;
  w4 = (in[10] - base) >> 16;
  w4 |=  (in[11] - base) << 8;
  w4 |=  (in[12] - base) << 32;
  w4 |= (in[13] - base) << 56;
  w5 = (in[13] - base) >> 8;
  w5 |=  (in[14] - base) << 16;
  w5 |=  (in[15] - base) << 40;
  w6 = (in[16] - base);
  w6 |=  (in[17] - base) << 24;
  w6 |= (in[18] - base) << 48;
  w7 = (in[18] - base) >> 16;
  w7 |=  (in[19] - base) << 8;
  w7 |=  (in[20] - base) << 32;
  w7 |= (in[21] - base) << 56;
  w8 = (in[21] - base) >> 8;
  w8 |=  (in[22] - base) << 16;
  w8 |=  (in[23] - base) << 40;
  w9 = (in[24] - base);
  w9 |=  (in[25] - base) << 24;
  w9 |= (in[26] - base) << 48;
  w10 = (in[26] - base) >> 16;
  w10 |=  (in[27] - base) << 8;
  w10 |=  (in[28] - base) << 32;
  w10 |= (in[29] - base) << 56;
  w11 = (in[29] - base) >> 8;
  w11 |=  (in[30] - base) << 16;
  w11 |=  (in[31] - base) << 40;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 96; /* we used up 96 output bytes */ 
}


/* we are going to pack 32 25-bit values, touching 13 64-bit words, using 100 bytes */ 
static void packforblock25_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 25;
  w0 |= (in[2] - base) << 50;
  w1 = (in[2] - base) >> 14;
  w1 |=  (in[3] - base) << 11;
  w1 |=  (in[4] - base) << 36;
  w1 |= (in[5] - base) << 61;
  w2 = (in[5] - base) >> 3;
  w2 |=  (in[6] - base) << 22;
  w2 |= (in[7] - base) << 47;
  w3 = (in[7] - base) >> 17;
  w3 |=  (in[8] - base) << 8;
  w3 |=  (in[9] - base) << 33;
  w3 |= (in[10] - base) << 58;
  w4 = (in[10] - base) >> 6;
  w4 |=  (in[11] - base) << 19;
  w4 |= (in[12] - base) << 44;
  w5 = (in[12] - base) >> 20;
  w5 |=  (in[13] - base) << 5;
  w5 |=  (in[14] - base) << 30;
  w5 |= (in[15] - base) << 55;
  w6 = (in[15] - base) >> 9;
  w6 |=  (in[16] - base) << 16;
  w6 |= (in[17] - base) << 41;
  w7 = (in[17] - base) >> 23;
  w7 |=  (in[18] - base) << 2;
  w7 |=  (in[19] - base) << 27;
  w7 |= (in[20] - base) << 52;
  w8 = (in[20] - base) >> 12;
  w8 |=  (in[21] - base) << 13;
  w8 |=  (in[22] - base) << 38;
  w8 |= (in[23] - base) << 63;
  w9 = (in[23] - base) >> 1;
  w9 |=  (in[24] - base) << 24;
  w9 |= (in[25] - base) << 49;
  w10 = (in[25] - base) >> 15;
  w10 |=  (in[26] - base) << 10;
  w10 |=  (in[27] - base) << 35;
  w10 |= (in[28] - base) << 60;
  w11 = (in[28] - base) >> 4;
  w11 |=  (in[29] - base) << 21;
  w11 |= (in[30] - base) << 46;
  w12 = (in[30] - base) >> 18;
  w12 |=  (in[31] - base) << 7;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 100; /* we used up 100 output bytes */ 
}


/* we are going to pack 32 26-bit values, touching 13 64-bit words, using 104 bytes */ 
static void packforblock26_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 26;
  w0 |= (in[2] - base) << 52;
  w1 = (in[2] - base) >> 12;
  w1 |=  (in[3] - base) << 14;
  w1 |= (in[4] - base) << 40;
  w2 = (in[4] - base) >> 24;
  w2 |=  (in[5] - base) << 2;
  w2 |=  (in[6] - base) << 28;
  w2 |= (in[7] - base) << 54;
  w3 = (in[7] - base) >> 10;
  w3 |=  (in[8] - base) << 16;
  w3 |= (in[9] - base) << 42;
  w4 = (in[9] - base) >> 22;
  w4 |=  (in[10] - base) << 4;
  w4 |=  (in[11] - base) << 30;
  w4 |= (in[12] - base) << 56;
  w5 = (in[12] - base) >> 8;
  w5 |=  (in[13] - base) << 18;
  w5 |= (in[14] - base) << 44;
  w6 = (in[14] - base) >> 20;
  w6 |=  (in[15] - base) << 6;
  w6 |=  (in[16] - base) << 32;
  w6 |= (in[17] - base) << 58;
  w7 = (in[17] - base) >> 6;
  w7 |=  (in[18] - base) << 20;
  w7 |= (in[19] - base) << 46;
  w8 = (in[19] - base) >> 18;
  w8 |=  (in[20] - base) << 8;
  w8 |=  (in[21] - base) << 34;
  w8 |= (in[22] - base) << 60;
  w9 = (in[22] - base) >> 4;
  w9 |=  (in[23] - base) << 22;
  w9 |= (in[24] - base) << 48;
  w10 = (in[24] - base) >> 16;
  w10 |=  (in[25] - base) << 10;
  w10 |=  (in[26] - base) << 36;
  w10 |= (in[27] - base) << 62;
  w11 = (in[27] - base) >> 2;
  w11 |=  (in[28] - base) << 24;
  w11 |= (in[29] - base) << 50;
  w12 = (in[29] - base) >> 14;
  w12 |=  (in[30] - base) << 12;
  w12 |=  (in[31] - base) << 38;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 104; /* we used up 104 output bytes */ 
}


/* we are going to pack 32 27-bit values, touching 14 64-bit words, using 108 bytes */ 
static void packforblock27_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 27;
  w0 |= (in[2] - base) << 54;
  w1 = (in[2] - base) >> 10;
  w1 |=  (in[3] - base) << 17;
  w1 |= (in[4] - base) << 44;
  w2 = (in[4] - base) >> 20;
  w2 |=  (in[5] - base) << 7;
  w2 |=  (in[6] - base) << 34;
  w2 |= (in[7] - base) << 61;
  w3 = (in[7] - base) >> 3;
  w3 |=  (in[8] - base) << 24;
  w3 |= (in[9] - base) << 51;
  w4 = (in[9] - base) >> 13;
  w4 |=  (in[10] - base) << 14;
  w4 |= (in[11] - base) << 41;
  w5 = (in[11] - base) >> 23;
  w5 |=  (in[12] - base) << 4;
  w5 |=  (in[13] - base) << 31;
  w5 |= (in[14] - base) << 58;
  w6 = (in[14] - base) >> 6;
  w6 |=  (in[15] - base) << 21;
  w6 |= (in[16] - base) << 48;
  w7 = (in[16] - base) >> 16;
  w7 |=  (in[17] - base) << 11;
  w7 |= (in[18] - base) << 38;
  w8 = (in[18] - base) >> 26;
  w8 |=  (in[19] - base) << 1;
  w8 |=  (in[20] - base) << 28;
  w8 |= (in[21] - base) << 55;
  w9 = (in[21] - base) >> 9;
  w9 |=  (in[22] - base) << 18;
  w9 |= (in[23] - base) << 45;
  w10 = (in[23] - base) >> 19;
  w10 |=  (in[24] - base) << 8;
  w10 |=  (in[25] - base) << 35;
  w10 |= (in[26] - base) << 62;
  w11 = (in[26] - base) >> 2;
  w11 |=  (in[27] - base) << 25;
  w11 |= (in[28] - base) << 52;
  w12 = (in[28] - base) >> 12;
  w12 |=  (in[29] - base) << 15;
  w12 |= (in[30] - base) << 42;
  w13 = (in[30] - base) >> 22;
  w13 |=  (in[31] - base) << 5;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 108; /* we used up 108 output bytes */ 
}


/* we are going to pack 32 28-bit values, touching 14 64-bit words, using 112 bytes */ 
static void packforblock28_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 28;
  w0 |= (in[2] - base) << 56;
  w1 = (in[2] - base) >> 8;
  w1 |=  (in[3] - base) << 20;
  w1 |= (in[4] - base) << 48;
  w2 = (in[4] - base) >> 16;
  w2 |=  (in[5] - base) << 12;
  w2 |= (in[6] - base) << 40;
  w3 = (in[6] - base) >> 24;
  w3 |=  (in[7] - base) << 4;
  w3 |=  (in[8] - base) << 32;
  w3 |= (in[9] - base) << 60;
  w4 = (in[9] - base) >> 4;
  w4 |=  (in[10] - base) << 24;
  w4 |= (in[11] - base) << 52;
  w5 = (in[11] - base) >> 12;
  w5 |=  (in[12] - base) << 16;
  w5 |= (in[13] - base) << 44;
  w6 = (in[13] - base) >> 20;
  w6 |=  (in[14] - base) << 8;
  w6 |=  (in[15] - base) << 36;
  w7 = (in[16] - base);
  w7 |=  (in[17] - base) << 28;
  w7 |= (in[18] - base) << 56;
  w8 = (in[18] - base) >> 8;
  w8 |=  (in[19] - base) << 20;
  w8 |= (in[20] - base) << 48;
  w9 = (in[20] - base) >> 16;
  w9 |=  (in[21] - base) << 12;
  w9 |= (in[22] - base) << 40;
  w10 = (in[22] - base) >> 24;
  w10 |=  (in[23] - base) << 4;
  w10 |=  (in[24] - base) << 32;
  w10 |= (in[25] - base) << 60;
  w11 = (in[25] - base) >> 4;
  w11 |=  (in[26] - base) << 24;
  w11 |= (in[27] - base) << 52;
  w12 = (in[27] - base) >> 12;
  w12 |=  (in[28] - base) << 16;
  w12 |= (in[29] - base) << 44;
  w13 = (in[29] - base) >> 20;
  w13 |=  (in[30] - base) << 8;
  w13 |=  (in[31] - base) << 36;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 112; /* we used up 112 output bytes */ 
}


/* we are going to pack 32 29-bit values, touching 15 64-bit words, using 116 bytes */ 
static void packforblock29_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 29;
  w0 |= (in[2] - base) << 58;
  w1 = (in[2] - base) >> 6;
  w1 |=  (in[3] - base) << 23;
  w1 |= (in[4] - base) << 52;
  w2 = (in[4] - base) >> 12;
  w2 |=  (in[5] - base) << 17;
  w2 |= (in[6] - base) << 46;
  w3 = (in[6] - base) >> 18;
  w3 |=  (in[7] - base) << 11;
  w3 |= (in[8] - base) << 40;
  w4 = (in[8] - base) >> 24;
  w4 |=  (in[9] - base) << 5;
  w4 |=  (in[10] - base) << 34;
  w4 |= (in[11] - base) << 63;
  w5 = (in[11] - base) >> 1;
  w5 |=  (in[12] - base) << 28;
  w5 |= (in[13] - base) << 57;
  w6 = (in[13] - base) >> 7;
  w6 |=  (in[14] - base) << 22;
  w6 |= (in[15] - base) << 51;
  w7 = (in[15] - base) >> 13;
  w7 |=  (in[16] - base) << 16;
  w7 |= (in[17] - base) << 45;
  w8 = (in[17] - base) >> 19;
  w8 |=  (in[18] - base) << 10;
  w8 |= (in[19] - base) << 39;
  w9 = (in[19] - base) >> 25;
  w9 |=  (in[20] - base) << 4;
  w9 |=  (in[21] - base) << 33;
  w9 |= (in[22] - base) << 62;
  w10 = (in[22] - base) >> 2;
  w10 |=  (in[23] - base) << 27;
  w10 |= (in[24] - base) << 56;
  w11 = (in[24] - base) >> 8;
  w11 |=  (in[25] - base) << 21;
  w11 |= (in[26] - base) << 50;
  w12 = (in[26] - base) >> 14;
  w12 |=  (in[27] - base) << 15;
  w12 |= (in[28] - base) << 44;
  w13 = (in[28] - base) >> 20;
  w13 |=  (in[29] - base) << 9;
  w13 |= (in[30] - base) << 38;
  w14 = (in[30] - base) >> 26;
  w14 |=  (in[31] - base) << 3;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 116; /* we used up 116 output bytes */ 
}


/* we are going to pack 32 30-bit values, touching 15 64-bit words, using 120 bytes */ 
static void packforblock30_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 30;
  w0 |= (in[2] - base) << 60;
  w1 = (in[2] - base) >> 4;
  w1 |=  (in[3] - base) << 26;
  w1 |= (in[4] - base) << 56;
  w2 = (in[4] - base) >> 8;
  w2 |=  (in[5] - base) << 22;
  w2 |= (in[6] - base) << 52;
  w3 = (in[6] - base) >> 12;
  w3 |=  (in[7] - base) << 18;
  w3 |= (in[8] - base) << 48;
  w4 = (in[8] - base) >> 16;
  w4 |=  (in[9] - base) << 14;
  w4 |= (in[10] - base) << 44;
  w5 = (in[10] - base) >> 20;
  w5 |=  (in[11] - base) << 10;
  w5 |= (in[12] - base) << 40;
  w6 = (in[12] - base) >> 24;
  w6 |=  (in[13] - base) << 6;
  w6 |= (in[14] - base) << 36;
  w7 = (in[14] - base) >> 28;
  w7 |=  (in[15] - base) << 2;
  w7 |=  (in[16] - base) << 32;
  w7 |= (in[17] - base) << 62;
  w8 = (in[17] - base) >> 2;
  w8 |=  (in[18] - base) << 28;
  w8 |= (in[19] - base) << 58;
  w9 = (in[19] - base) >> 6;
  w9 |=  (in[20] - base) << 24;
  w9 |= (in[21] - base) << 54;
  w10 = (in[21] - base) >> 10;
  w10 |=  (in[22] - base) << 20;
  w10 |= (in[23] - base) << 50;
  w11 = (in[23] - base) >> 14;
  w11 |=  (in[24] - base) << 16;
  w11 |= (in[25] - base) << 46;
  w12 = (in[25] - base) >> 18;
  w12 |=  (in[26] - base) << 12;
  w12 |= (in[27] - base) << 42;
  w13 = (in[27] - base) >> 22;
  w13 |=  (in[28] - base) << 8;
  w13 |= (in[29] - base) << 38;
  w14 = (in[29] - base) >> 26;
  w14 |=  (in[30] - base) << 4;
  w14 |=  (in[31] - base) << 34;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 120; /* we used up 120 output bytes */ 
}


/* we are going to pack 32 31-bit values, touching 16 64-bit words, using 124 bytes */ 
static void packforblock31_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 31;
  w0 |= (in[2] - base) << 62;
  w1 = (in[2] - base) >> 2;
  w1 |=  (in[3] - base) << 29;
  w1 |= (in[4] - base) << 60;
  w2 = (in[4] - base) >> 4;
  w2 |=  (in[5] - base) << 27;
  w2 |= (in[6] - base) << 58;
  w3 = (in[6] - base) >> 6;
  w3 |=  (in[7] - base) << 25;
  w3 |= (in[8] - base) << 56;
  w4 = (in[8] - base) >> 8;
  w4 |=  (in[9] - base) << 23;
  w4 |= (in[10] - base) << 54;
  w5 = (in[10] - base) >> 10;
  w5 |=  (in[11] - base) << 21;
  w5 |= (in[12] - base) << 52;
  w6 = (in[12] - base) >> 12;
  w6 |=  (in[13] - base) << 19;
  w6 |= (in[14] - base) << 50;
  w7 = (in[14] - base) >> 14;
  w7 |=  (in[15] - base) << 17;
  w7 |= (in[16] - base) << 48;
  w8 = (in[16] - base) >> 16;
  w8 |=  (in[17] - base) << 15;
  w8 |= (in[18] - base) << 46;
  w9 = (in[18] - base) >> 18;
  w9 |=  (in[19] - base) << 13;
  w9 |= (in[20] - base) << 44;
  w10 = (in[20] - base) >> 20;
  w10 |=  (in[21] - base) << 11;
  w10 |= (in[22] - base) << 42;
  w11 = (in[22] - base) >> 22;
  w11 |=  (in[23] - base) << 9;
  w11 |= (in[24] - base) << 40;
  w12 = (in[24] - base) >> 24;
  w12 |=  (in[25] - base) << 7;
  w12 |= (in[26] - base) << 38;
  w13 = (in[26] - base) >> 26;
  w13 |=  (in[27] - base) << 5;
  w13 |= (in[28] - base) << 36;
  w14 = (in[28] - base) >> 28;
  w14 |=  (in[29] - base) << 3;
  w14 |= (in[30] - base) << 34;
  w15 = (in[30] - base) >> 30;
  w15 |=  (in[31] - base) << 1;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 124; /* we used up 124 output bytes */ 
}


/* we are going to pack 32 32-bit values, touching 16 64-bit words, using 128 bytes */ 
static void packforblock32_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
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
  w0 = (in[0] - base);
  w0 |=  (in[1] - base) << 32;
  w1 = (in[2] - base);
  w1 |=  (in[3] - base) << 32;
  w2 = (in[4] - base);
  w2 |=  (in[5] - base) << 32;
  w3 = (in[6] - base);
  w3 |=  (in[7] - base) << 32;
  w4 = (in[8] - base);
  w4 |=  (in[9] - base) << 32;
  w5 = (in[10] - base);
  w5 |=  (in[11] - base) << 32;
  w6 = (in[12] - base);
  w6 |=  (in[13] - base) << 32;
  w7 = (in[14] - base);
  w7 |=  (in[15] - base) << 32;
  w8 = (in[16] - base);
  w8 |=  (in[17] - base) << 32;
  w9 = (in[18] - base);
  w9 |=  (in[19] - base) << 32;
  w10 = (in[20] - base);
  w10 |=  (in[21] - base) << 32;
  w11 = (in[22] - base);
  w11 |=  (in[23] - base) << 32;
  w12 = (in[24] - base);
  w12 |=  (in[25] - base) << 32;
  w13 = (in[26] - base);
  w13 |=  (in[27] - base) << 32;
  w14 = (in[28] - base);
  w14 |=  (in[29] - base) << 32;
  w15 = (in[30] - base);
  w15 |=  (in[31] - base) << 32;
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
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 128; /* we used up 128 output bytes */ 
}


/* we are going to pack 32 33-bit values, touching 17 64-bit words, using 132 bytes */ 
static void packforblock33_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  17 64-bit words */ 
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
  uint64_t w16;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 33;
  w1 = (in[1] - base) >> 31;
  w1 |=  (in[2] - base) << 2;
  w1 |= (in[3] - base) << 35;
  w2 = (in[3] - base) >> 29;
  w2 |=  (in[4] - base) << 4;
  w2 |= (in[5] - base) << 37;
  w3 = (in[5] - base) >> 27;
  w3 |=  (in[6] - base) << 6;
  w3 |= (in[7] - base) << 39;
  w4 = (in[7] - base) >> 25;
  w4 |=  (in[8] - base) << 8;
  w4 |= (in[9] - base) << 41;
  w5 = (in[9] - base) >> 23;
  w5 |=  (in[10] - base) << 10;
  w5 |= (in[11] - base) << 43;
  w6 = (in[11] - base) >> 21;
  w6 |=  (in[12] - base) << 12;
  w6 |= (in[13] - base) << 45;
  w7 = (in[13] - base) >> 19;
  w7 |=  (in[14] - base) << 14;
  w7 |= (in[15] - base) << 47;
  w8 = (in[15] - base) >> 17;
  w8 |=  (in[16] - base) << 16;
  w8 |= (in[17] - base) << 49;
  w9 = (in[17] - base) >> 15;
  w9 |=  (in[18] - base) << 18;
  w9 |= (in[19] - base) << 51;
  w10 = (in[19] - base) >> 13;
  w10 |=  (in[20] - base) << 20;
  w10 |= (in[21] - base) << 53;
  w11 = (in[21] - base) >> 11;
  w11 |=  (in[22] - base) << 22;
  w11 |= (in[23] - base) << 55;
  w12 = (in[23] - base) >> 9;
  w12 |=  (in[24] - base) << 24;
  w12 |= (in[25] - base) << 57;
  w13 = (in[25] - base) >> 7;
  w13 |=  (in[26] - base) << 26;
  w13 |= (in[27] - base) << 59;
  w14 = (in[27] - base) >> 5;
  w14 |=  (in[28] - base) << 28;
  w14 |= (in[29] - base) << 61;
  w15 = (in[29] - base) >> 3;
  w15 |=  (in[30] - base) << 30;
  w15 |= (in[31] - base) << 63;
  w16 = (in[31] - base) >> 1;
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
  pw64[16] = w16;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 132; /* we used up 132 output bytes */ 
}


/* we are going to pack 32 34-bit values, touching 17 64-bit words, using 136 bytes */ 
static void packforblock34_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  17 64-bit words */ 
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
  uint64_t w16;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 34;
  w1 = (in[1] - base) >> 30;
  w1 |=  (in[2] - base) << 4;
  w1 |= (in[3] - base) << 38;
  w2 = (in[3] - base) >> 26;
  w2 |=  (in[4] - base) << 8;
  w2 |= (in[5] - base) << 42;
  w3 = (in[5] - base) >> 22;
  w3 |=  (in[6] - base) << 12;
  w3 |= (in[7] - base) << 46;
  w4 = (in[7] - base) >> 18;
  w4 |=  (in[8] - base) << 16;
  w4 |= (in[9] - base) << 50;
  w5 = (in[9] - base) >> 14;
  w5 |=  (in[10] - base) << 20;
  w5 |= (in[11] - base) << 54;
  w6 = (in[11] - base) >> 10;
  w6 |=  (in[12] - base) << 24;
  w6 |= (in[13] - base) << 58;
  w7 = (in[13] - base) >> 6;
  w7 |=  (in[14] - base) << 28;
  w7 |= (in[15] - base) << 62;
  w8 = (in[15] - base) >> 2;
  w8 |= (in[16] - base) << 32;
  w9 = (in[16] - base) >> 32;
  w9 |=  (in[17] - base) << 2;
  w9 |= (in[18] - base) << 36;
  w10 = (in[18] - base) >> 28;
  w10 |=  (in[19] - base) << 6;
  w10 |= (in[20] - base) << 40;
  w11 = (in[20] - base) >> 24;
  w11 |=  (in[21] - base) << 10;
  w11 |= (in[22] - base) << 44;
  w12 = (in[22] - base) >> 20;
  w12 |=  (in[23] - base) << 14;
  w12 |= (in[24] - base) << 48;
  w13 = (in[24] - base) >> 16;
  w13 |=  (in[25] - base) << 18;
  w13 |= (in[26] - base) << 52;
  w14 = (in[26] - base) >> 12;
  w14 |=  (in[27] - base) << 22;
  w14 |= (in[28] - base) << 56;
  w15 = (in[28] - base) >> 8;
  w15 |=  (in[29] - base) << 26;
  w15 |= (in[30] - base) << 60;
  w16 = (in[30] - base) >> 4;
  w16 |=  (in[31] - base) << 30;
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
  pw64[16] = w16;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 136; /* we used up 136 output bytes */ 
}


/* we are going to pack 32 35-bit values, touching 18 64-bit words, using 140 bytes */ 
static void packforblock35_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  18 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 35;
  w1 = (in[1] - base) >> 29;
  w1 |=  (in[2] - base) << 6;
  w1 |= (in[3] - base) << 41;
  w2 = (in[3] - base) >> 23;
  w2 |=  (in[4] - base) << 12;
  w2 |= (in[5] - base) << 47;
  w3 = (in[5] - base) >> 17;
  w3 |=  (in[6] - base) << 18;
  w3 |= (in[7] - base) << 53;
  w4 = (in[7] - base) >> 11;
  w4 |=  (in[8] - base) << 24;
  w4 |= (in[9] - base) << 59;
  w5 = (in[9] - base) >> 5;
  w5 |= (in[10] - base) << 30;
  w6 = (in[10] - base) >> 34;
  w6 |=  (in[11] - base) << 1;
  w6 |= (in[12] - base) << 36;
  w7 = (in[12] - base) >> 28;
  w7 |=  (in[13] - base) << 7;
  w7 |= (in[14] - base) << 42;
  w8 = (in[14] - base) >> 22;
  w8 |=  (in[15] - base) << 13;
  w8 |= (in[16] - base) << 48;
  w9 = (in[16] - base) >> 16;
  w9 |=  (in[17] - base) << 19;
  w9 |= (in[18] - base) << 54;
  w10 = (in[18] - base) >> 10;
  w10 |=  (in[19] - base) << 25;
  w10 |= (in[20] - base) << 60;
  w11 = (in[20] - base) >> 4;
  w11 |= (in[21] - base) << 31;
  w12 = (in[21] - base) >> 33;
  w12 |=  (in[22] - base) << 2;
  w12 |= (in[23] - base) << 37;
  w13 = (in[23] - base) >> 27;
  w13 |=  (in[24] - base) << 8;
  w13 |= (in[25] - base) << 43;
  w14 = (in[25] - base) >> 21;
  w14 |=  (in[26] - base) << 14;
  w14 |= (in[27] - base) << 49;
  w15 = (in[27] - base) >> 15;
  w15 |=  (in[28] - base) << 20;
  w15 |= (in[29] - base) << 55;
  w16 = (in[29] - base) >> 9;
  w16 |=  (in[30] - base) << 26;
  w16 |= (in[31] - base) << 61;
  w17 = (in[31] - base) >> 3;
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
  pw64[16] = w16;
  pw64[17] = w17;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 140; /* we used up 140 output bytes */ 
}


/* we are going to pack 32 36-bit values, touching 18 64-bit words, using 144 bytes */ 
static void packforblock36_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  18 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 36;
  w1 = (in[1] - base) >> 28;
  w1 |=  (in[2] - base) << 8;
  w1 |= (in[3] - base) << 44;
  w2 = (in[3] - base) >> 20;
  w2 |=  (in[4] - base) << 16;
  w2 |= (in[5] - base) << 52;
  w3 = (in[5] - base) >> 12;
  w3 |=  (in[6] - base) << 24;
  w3 |= (in[7] - base) << 60;
  w4 = (in[7] - base) >> 4;
  w4 |= (in[8] - base) << 32;
  w5 = (in[8] - base) >> 32;
  w5 |=  (in[9] - base) << 4;
  w5 |= (in[10] - base) << 40;
  w6 = (in[10] - base) >> 24;
  w6 |=  (in[11] - base) << 12;
  w6 |= (in[12] - base) << 48;
  w7 = (in[12] - base) >> 16;
  w7 |=  (in[13] - base) << 20;
  w7 |= (in[14] - base) << 56;
  w8 = (in[14] - base) >> 8;
  w8 |=  (in[15] - base) << 28;
  w9 = (in[16] - base);
  w9 |= (in[17] - base) << 36;
  w10 = (in[17] - base) >> 28;
  w10 |=  (in[18] - base) << 8;
  w10 |= (in[19] - base) << 44;
  w11 = (in[19] - base) >> 20;
  w11 |=  (in[20] - base) << 16;
  w11 |= (in[21] - base) << 52;
  w12 = (in[21] - base) >> 12;
  w12 |=  (in[22] - base) << 24;
  w12 |= (in[23] - base) << 60;
  w13 = (in[23] - base) >> 4;
  w13 |= (in[24] - base) << 32;
  w14 = (in[24] - base) >> 32;
  w14 |=  (in[25] - base) << 4;
  w14 |= (in[26] - base) << 40;
  w15 = (in[26] - base) >> 24;
  w15 |=  (in[27] - base) << 12;
  w15 |= (in[28] - base) << 48;
  w16 = (in[28] - base) >> 16;
  w16 |=  (in[29] - base) << 20;
  w16 |= (in[30] - base) << 56;
  w17 = (in[30] - base) >> 8;
  w17 |=  (in[31] - base) << 28;
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
  pw64[16] = w16;
  pw64[17] = w17;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 144; /* we used up 144 output bytes */ 
}


/* we are going to pack 32 37-bit values, touching 19 64-bit words, using 148 bytes */ 
static void packforblock37_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  19 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 37;
  w1 = (in[1] - base) >> 27;
  w1 |=  (in[2] - base) << 10;
  w1 |= (in[3] - base) << 47;
  w2 = (in[3] - base) >> 17;
  w2 |=  (in[4] - base) << 20;
  w2 |= (in[5] - base) << 57;
  w3 = (in[5] - base) >> 7;
  w3 |= (in[6] - base) << 30;
  w4 = (in[6] - base) >> 34;
  w4 |=  (in[7] - base) << 3;
  w4 |= (in[8] - base) << 40;
  w5 = (in[8] - base) >> 24;
  w5 |=  (in[9] - base) << 13;
  w5 |= (in[10] - base) << 50;
  w6 = (in[10] - base) >> 14;
  w6 |=  (in[11] - base) << 23;
  w6 |= (in[12] - base) << 60;
  w7 = (in[12] - base) >> 4;
  w7 |= (in[13] - base) << 33;
  w8 = (in[13] - base) >> 31;
  w8 |=  (in[14] - base) << 6;
  w8 |= (in[15] - base) << 43;
  w9 = (in[15] - base) >> 21;
  w9 |=  (in[16] - base) << 16;
  w9 |= (in[17] - base) << 53;
  w10 = (in[17] - base) >> 11;
  w10 |=  (in[18] - base) << 26;
  w10 |= (in[19] - base) << 63;
  w11 = (in[19] - base) >> 1;
  w11 |= (in[20] - base) << 36;
  w12 = (in[20] - base) >> 28;
  w12 |=  (in[21] - base) << 9;
  w12 |= (in[22] - base) << 46;
  w13 = (in[22] - base) >> 18;
  w13 |=  (in[23] - base) << 19;
  w13 |= (in[24] - base) << 56;
  w14 = (in[24] - base) >> 8;
  w14 |= (in[25] - base) << 29;
  w15 = (in[25] - base) >> 35;
  w15 |=  (in[26] - base) << 2;
  w15 |= (in[27] - base) << 39;
  w16 = (in[27] - base) >> 25;
  w16 |=  (in[28] - base) << 12;
  w16 |= (in[29] - base) << 49;
  w17 = (in[29] - base) >> 15;
  w17 |=  (in[30] - base) << 22;
  w17 |= (in[31] - base) << 59;
  w18 = (in[31] - base) >> 5;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 148; /* we used up 148 output bytes */ 
}


/* we are going to pack 32 38-bit values, touching 19 64-bit words, using 152 bytes */ 
static void packforblock38_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  19 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 38;
  w1 = (in[1] - base) >> 26;
  w1 |=  (in[2] - base) << 12;
  w1 |= (in[3] - base) << 50;
  w2 = (in[3] - base) >> 14;
  w2 |=  (in[4] - base) << 24;
  w2 |= (in[5] - base) << 62;
  w3 = (in[5] - base) >> 2;
  w3 |= (in[6] - base) << 36;
  w4 = (in[6] - base) >> 28;
  w4 |=  (in[7] - base) << 10;
  w4 |= (in[8] - base) << 48;
  w5 = (in[8] - base) >> 16;
  w5 |=  (in[9] - base) << 22;
  w5 |= (in[10] - base) << 60;
  w6 = (in[10] - base) >> 4;
  w6 |= (in[11] - base) << 34;
  w7 = (in[11] - base) >> 30;
  w7 |=  (in[12] - base) << 8;
  w7 |= (in[13] - base) << 46;
  w8 = (in[13] - base) >> 18;
  w8 |=  (in[14] - base) << 20;
  w8 |= (in[15] - base) << 58;
  w9 = (in[15] - base) >> 6;
  w9 |= (in[16] - base) << 32;
  w10 = (in[16] - base) >> 32;
  w10 |=  (in[17] - base) << 6;
  w10 |= (in[18] - base) << 44;
  w11 = (in[18] - base) >> 20;
  w11 |=  (in[19] - base) << 18;
  w11 |= (in[20] - base) << 56;
  w12 = (in[20] - base) >> 8;
  w12 |= (in[21] - base) << 30;
  w13 = (in[21] - base) >> 34;
  w13 |=  (in[22] - base) << 4;
  w13 |= (in[23] - base) << 42;
  w14 = (in[23] - base) >> 22;
  w14 |=  (in[24] - base) << 16;
  w14 |= (in[25] - base) << 54;
  w15 = (in[25] - base) >> 10;
  w15 |= (in[26] - base) << 28;
  w16 = (in[26] - base) >> 36;
  w16 |=  (in[27] - base) << 2;
  w16 |= (in[28] - base) << 40;
  w17 = (in[28] - base) >> 24;
  w17 |=  (in[29] - base) << 14;
  w17 |= (in[30] - base) << 52;
  w18 = (in[30] - base) >> 12;
  w18 |=  (in[31] - base) << 26;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 152; /* we used up 152 output bytes */ 
}


/* we are going to pack 32 39-bit values, touching 20 64-bit words, using 156 bytes */ 
static void packforblock39_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  20 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 39;
  w1 = (in[1] - base) >> 25;
  w1 |=  (in[2] - base) << 14;
  w1 |= (in[3] - base) << 53;
  w2 = (in[3] - base) >> 11;
  w2 |= (in[4] - base) << 28;
  w3 = (in[4] - base) >> 36;
  w3 |=  (in[5] - base) << 3;
  w3 |= (in[6] - base) << 42;
  w4 = (in[6] - base) >> 22;
  w4 |=  (in[7] - base) << 17;
  w4 |= (in[8] - base) << 56;
  w5 = (in[8] - base) >> 8;
  w5 |= (in[9] - base) << 31;
  w6 = (in[9] - base) >> 33;
  w6 |=  (in[10] - base) << 6;
  w6 |= (in[11] - base) << 45;
  w7 = (in[11] - base) >> 19;
  w7 |=  (in[12] - base) << 20;
  w7 |= (in[13] - base) << 59;
  w8 = (in[13] - base) >> 5;
  w8 |= (in[14] - base) << 34;
  w9 = (in[14] - base) >> 30;
  w9 |=  (in[15] - base) << 9;
  w9 |= (in[16] - base) << 48;
  w10 = (in[16] - base) >> 16;
  w10 |=  (in[17] - base) << 23;
  w10 |= (in[18] - base) << 62;
  w11 = (in[18] - base) >> 2;
  w11 |= (in[19] - base) << 37;
  w12 = (in[19] - base) >> 27;
  w12 |=  (in[20] - base) << 12;
  w12 |= (in[21] - base) << 51;
  w13 = (in[21] - base) >> 13;
  w13 |= (in[22] - base) << 26;
  w14 = (in[22] - base) >> 38;
  w14 |=  (in[23] - base) << 1;
  w14 |= (in[24] - base) << 40;
  w15 = (in[24] - base) >> 24;
  w15 |=  (in[25] - base) << 15;
  w15 |= (in[26] - base) << 54;
  w16 = (in[26] - base) >> 10;
  w16 |= (in[27] - base) << 29;
  w17 = (in[27] - base) >> 35;
  w17 |=  (in[28] - base) << 4;
  w17 |= (in[29] - base) << 43;
  w18 = (in[29] - base) >> 21;
  w18 |=  (in[30] - base) << 18;
  w18 |= (in[31] - base) << 57;
  w19 = (in[31] - base) >> 7;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 156; /* we used up 156 output bytes */ 
}


/* we are going to pack 32 40-bit values, touching 20 64-bit words, using 160 bytes */ 
static void packforblock40_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  20 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 40;
  w1 = (in[1] - base) >> 24;
  w1 |=  (in[2] - base) << 16;
  w1 |= (in[3] - base) << 56;
  w2 = (in[3] - base) >> 8;
  w2 |= (in[4] - base) << 32;
  w3 = (in[4] - base) >> 32;
  w3 |=  (in[5] - base) << 8;
  w3 |= (in[6] - base) << 48;
  w4 = (in[6] - base) >> 16;
  w4 |=  (in[7] - base) << 24;
  w5 = (in[8] - base);
  w5 |= (in[9] - base) << 40;
  w6 = (in[9] - base) >> 24;
  w6 |=  (in[10] - base) << 16;
  w6 |= (in[11] - base) << 56;
  w7 = (in[11] - base) >> 8;
  w7 |= (in[12] - base) << 32;
  w8 = (in[12] - base) >> 32;
  w8 |=  (in[13] - base) << 8;
  w8 |= (in[14] - base) << 48;
  w9 = (in[14] - base) >> 16;
  w9 |=  (in[15] - base) << 24;
  w10 = (in[16] - base);
  w10 |= (in[17] - base) << 40;
  w11 = (in[17] - base) >> 24;
  w11 |=  (in[18] - base) << 16;
  w11 |= (in[19] - base) << 56;
  w12 = (in[19] - base) >> 8;
  w12 |= (in[20] - base) << 32;
  w13 = (in[20] - base) >> 32;
  w13 |=  (in[21] - base) << 8;
  w13 |= (in[22] - base) << 48;
  w14 = (in[22] - base) >> 16;
  w14 |=  (in[23] - base) << 24;
  w15 = (in[24] - base);
  w15 |= (in[25] - base) << 40;
  w16 = (in[25] - base) >> 24;
  w16 |=  (in[26] - base) << 16;
  w16 |= (in[27] - base) << 56;
  w17 = (in[27] - base) >> 8;
  w17 |= (in[28] - base) << 32;
  w18 = (in[28] - base) >> 32;
  w18 |=  (in[29] - base) << 8;
  w18 |= (in[30] - base) << 48;
  w19 = (in[30] - base) >> 16;
  w19 |=  (in[31] - base) << 24;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 160; /* we used up 160 output bytes */ 
}


/* we are going to pack 32 41-bit values, touching 21 64-bit words, using 164 bytes */ 
static void packforblock41_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  21 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 41;
  w1 = (in[1] - base) >> 23;
  w1 |=  (in[2] - base) << 18;
  w1 |= (in[3] - base) << 59;
  w2 = (in[3] - base) >> 5;
  w2 |= (in[4] - base) << 36;
  w3 = (in[4] - base) >> 28;
  w3 |=  (in[5] - base) << 13;
  w3 |= (in[6] - base) << 54;
  w4 = (in[6] - base) >> 10;
  w4 |= (in[7] - base) << 31;
  w5 = (in[7] - base) >> 33;
  w5 |=  (in[8] - base) << 8;
  w5 |= (in[9] - base) << 49;
  w6 = (in[9] - base) >> 15;
  w6 |= (in[10] - base) << 26;
  w7 = (in[10] - base) >> 38;
  w7 |=  (in[11] - base) << 3;
  w7 |= (in[12] - base) << 44;
  w8 = (in[12] - base) >> 20;
  w8 |=  (in[13] - base) << 21;
  w8 |= (in[14] - base) << 62;
  w9 = (in[14] - base) >> 2;
  w9 |= (in[15] - base) << 39;
  w10 = (in[15] - base) >> 25;
  w10 |=  (in[16] - base) << 16;
  w10 |= (in[17] - base) << 57;
  w11 = (in[17] - base) >> 7;
  w11 |= (in[18] - base) << 34;
  w12 = (in[18] - base) >> 30;
  w12 |=  (in[19] - base) << 11;
  w12 |= (in[20] - base) << 52;
  w13 = (in[20] - base) >> 12;
  w13 |= (in[21] - base) << 29;
  w14 = (in[21] - base) >> 35;
  w14 |=  (in[22] - base) << 6;
  w14 |= (in[23] - base) << 47;
  w15 = (in[23] - base) >> 17;
  w15 |= (in[24] - base) << 24;
  w16 = (in[24] - base) >> 40;
  w16 |=  (in[25] - base) << 1;
  w16 |= (in[26] - base) << 42;
  w17 = (in[26] - base) >> 22;
  w17 |=  (in[27] - base) << 19;
  w17 |= (in[28] - base) << 60;
  w18 = (in[28] - base) >> 4;
  w18 |= (in[29] - base) << 37;
  w19 = (in[29] - base) >> 27;
  w19 |=  (in[30] - base) << 14;
  w19 |= (in[31] - base) << 55;
  w20 = (in[31] - base) >> 9;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 164; /* we used up 164 output bytes */ 
}


/* we are going to pack 32 42-bit values, touching 21 64-bit words, using 168 bytes */ 
static void packforblock42_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  21 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 42;
  w1 = (in[1] - base) >> 22;
  w1 |=  (in[2] - base) << 20;
  w1 |= (in[3] - base) << 62;
  w2 = (in[3] - base) >> 2;
  w2 |= (in[4] - base) << 40;
  w3 = (in[4] - base) >> 24;
  w3 |=  (in[5] - base) << 18;
  w3 |= (in[6] - base) << 60;
  w4 = (in[6] - base) >> 4;
  w4 |= (in[7] - base) << 38;
  w5 = (in[7] - base) >> 26;
  w5 |=  (in[8] - base) << 16;
  w5 |= (in[9] - base) << 58;
  w6 = (in[9] - base) >> 6;
  w6 |= (in[10] - base) << 36;
  w7 = (in[10] - base) >> 28;
  w7 |=  (in[11] - base) << 14;
  w7 |= (in[12] - base) << 56;
  w8 = (in[12] - base) >> 8;
  w8 |= (in[13] - base) << 34;
  w9 = (in[13] - base) >> 30;
  w9 |=  (in[14] - base) << 12;
  w9 |= (in[15] - base) << 54;
  w10 = (in[15] - base) >> 10;
  w10 |= (in[16] - base) << 32;
  w11 = (in[16] - base) >> 32;
  w11 |=  (in[17] - base) << 10;
  w11 |= (in[18] - base) << 52;
  w12 = (in[18] - base) >> 12;
  w12 |= (in[19] - base) << 30;
  w13 = (in[19] - base) >> 34;
  w13 |=  (in[20] - base) << 8;
  w13 |= (in[21] - base) << 50;
  w14 = (in[21] - base) >> 14;
  w14 |= (in[22] - base) << 28;
  w15 = (in[22] - base) >> 36;
  w15 |=  (in[23] - base) << 6;
  w15 |= (in[24] - base) << 48;
  w16 = (in[24] - base) >> 16;
  w16 |= (in[25] - base) << 26;
  w17 = (in[25] - base) >> 38;
  w17 |=  (in[26] - base) << 4;
  w17 |= (in[27] - base) << 46;
  w18 = (in[27] - base) >> 18;
  w18 |= (in[28] - base) << 24;
  w19 = (in[28] - base) >> 40;
  w19 |=  (in[29] - base) << 2;
  w19 |= (in[30] - base) << 44;
  w20 = (in[30] - base) >> 20;
  w20 |=  (in[31] - base) << 22;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 168; /* we used up 168 output bytes */ 
}


/* we are going to pack 32 43-bit values, touching 22 64-bit words, using 172 bytes */ 
static void packforblock43_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  22 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 43;
  w1 = (in[1] - base) >> 21;
  w1 |= (in[2] - base) << 22;
  w2 = (in[2] - base) >> 42;
  w2 |=  (in[3] - base) << 1;
  w2 |= (in[4] - base) << 44;
  w3 = (in[4] - base) >> 20;
  w3 |= (in[5] - base) << 23;
  w4 = (in[5] - base) >> 41;
  w4 |=  (in[6] - base) << 2;
  w4 |= (in[7] - base) << 45;
  w5 = (in[7] - base) >> 19;
  w5 |= (in[8] - base) << 24;
  w6 = (in[8] - base) >> 40;
  w6 |=  (in[9] - base) << 3;
  w6 |= (in[10] - base) << 46;
  w7 = (in[10] - base) >> 18;
  w7 |= (in[11] - base) << 25;
  w8 = (in[11] - base) >> 39;
  w8 |=  (in[12] - base) << 4;
  w8 |= (in[13] - base) << 47;
  w9 = (in[13] - base) >> 17;
  w9 |= (in[14] - base) << 26;
  w10 = (in[14] - base) >> 38;
  w10 |=  (in[15] - base) << 5;
  w10 |= (in[16] - base) << 48;
  w11 = (in[16] - base) >> 16;
  w11 |= (in[17] - base) << 27;
  w12 = (in[17] - base) >> 37;
  w12 |=  (in[18] - base) << 6;
  w12 |= (in[19] - base) << 49;
  w13 = (in[19] - base) >> 15;
  w13 |= (in[20] - base) << 28;
  w14 = (in[20] - base) >> 36;
  w14 |=  (in[21] - base) << 7;
  w14 |= (in[22] - base) << 50;
  w15 = (in[22] - base) >> 14;
  w15 |= (in[23] - base) << 29;
  w16 = (in[23] - base) >> 35;
  w16 |=  (in[24] - base) << 8;
  w16 |= (in[25] - base) << 51;
  w17 = (in[25] - base) >> 13;
  w17 |= (in[26] - base) << 30;
  w18 = (in[26] - base) >> 34;
  w18 |=  (in[27] - base) << 9;
  w18 |= (in[28] - base) << 52;
  w19 = (in[28] - base) >> 12;
  w19 |= (in[29] - base) << 31;
  w20 = (in[29] - base) >> 33;
  w20 |=  (in[30] - base) << 10;
  w20 |= (in[31] - base) << 53;
  w21 = (in[31] - base) >> 11;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 172; /* we used up 172 output bytes */ 
}


/* we are going to pack 32 44-bit values, touching 22 64-bit words, using 176 bytes */ 
static void packforblock44_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  22 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 44;
  w1 = (in[1] - base) >> 20;
  w1 |= (in[2] - base) << 24;
  w2 = (in[2] - base) >> 40;
  w2 |=  (in[3] - base) << 4;
  w2 |= (in[4] - base) << 48;
  w3 = (in[4] - base) >> 16;
  w3 |= (in[5] - base) << 28;
  w4 = (in[5] - base) >> 36;
  w4 |=  (in[6] - base) << 8;
  w4 |= (in[7] - base) << 52;
  w5 = (in[7] - base) >> 12;
  w5 |= (in[8] - base) << 32;
  w6 = (in[8] - base) >> 32;
  w6 |=  (in[9] - base) << 12;
  w6 |= (in[10] - base) << 56;
  w7 = (in[10] - base) >> 8;
  w7 |= (in[11] - base) << 36;
  w8 = (in[11] - base) >> 28;
  w8 |=  (in[12] - base) << 16;
  w8 |= (in[13] - base) << 60;
  w9 = (in[13] - base) >> 4;
  w9 |= (in[14] - base) << 40;
  w10 = (in[14] - base) >> 24;
  w10 |=  (in[15] - base) << 20;
  w11 = (in[16] - base);
  w11 |= (in[17] - base) << 44;
  w12 = (in[17] - base) >> 20;
  w12 |= (in[18] - base) << 24;
  w13 = (in[18] - base) >> 40;
  w13 |=  (in[19] - base) << 4;
  w13 |= (in[20] - base) << 48;
  w14 = (in[20] - base) >> 16;
  w14 |= (in[21] - base) << 28;
  w15 = (in[21] - base) >> 36;
  w15 |=  (in[22] - base) << 8;
  w15 |= (in[23] - base) << 52;
  w16 = (in[23] - base) >> 12;
  w16 |= (in[24] - base) << 32;
  w17 = (in[24] - base) >> 32;
  w17 |=  (in[25] - base) << 12;
  w17 |= (in[26] - base) << 56;
  w18 = (in[26] - base) >> 8;
  w18 |= (in[27] - base) << 36;
  w19 = (in[27] - base) >> 28;
  w19 |=  (in[28] - base) << 16;
  w19 |= (in[29] - base) << 60;
  w20 = (in[29] - base) >> 4;
  w20 |= (in[30] - base) << 40;
  w21 = (in[30] - base) >> 24;
  w21 |=  (in[31] - base) << 20;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 176; /* we used up 176 output bytes */ 
}


/* we are going to pack 32 45-bit values, touching 23 64-bit words, using 180 bytes */ 
static void packforblock45_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  23 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 45;
  w1 = (in[1] - base) >> 19;
  w1 |= (in[2] - base) << 26;
  w2 = (in[2] - base) >> 38;
  w2 |=  (in[3] - base) << 7;
  w2 |= (in[4] - base) << 52;
  w3 = (in[4] - base) >> 12;
  w3 |= (in[5] - base) << 33;
  w4 = (in[5] - base) >> 31;
  w4 |=  (in[6] - base) << 14;
  w4 |= (in[7] - base) << 59;
  w5 = (in[7] - base) >> 5;
  w5 |= (in[8] - base) << 40;
  w6 = (in[8] - base) >> 24;
  w6 |= (in[9] - base) << 21;
  w7 = (in[9] - base) >> 43;
  w7 |=  (in[10] - base) << 2;
  w7 |= (in[11] - base) << 47;
  w8 = (in[11] - base) >> 17;
  w8 |= (in[12] - base) << 28;
  w9 = (in[12] - base) >> 36;
  w9 |=  (in[13] - base) << 9;
  w9 |= (in[14] - base) << 54;
  w10 = (in[14] - base) >> 10;
  w10 |= (in[15] - base) << 35;
  w11 = (in[15] - base) >> 29;
  w11 |=  (in[16] - base) << 16;
  w11 |= (in[17] - base) << 61;
  w12 = (in[17] - base) >> 3;
  w12 |= (in[18] - base) << 42;
  w13 = (in[18] - base) >> 22;
  w13 |= (in[19] - base) << 23;
  w14 = (in[19] - base) >> 41;
  w14 |=  (in[20] - base) << 4;
  w14 |= (in[21] - base) << 49;
  w15 = (in[21] - base) >> 15;
  w15 |= (in[22] - base) << 30;
  w16 = (in[22] - base) >> 34;
  w16 |=  (in[23] - base) << 11;
  w16 |= (in[24] - base) << 56;
  w17 = (in[24] - base) >> 8;
  w17 |= (in[25] - base) << 37;
  w18 = (in[25] - base) >> 27;
  w18 |=  (in[26] - base) << 18;
  w18 |= (in[27] - base) << 63;
  w19 = (in[27] - base) >> 1;
  w19 |= (in[28] - base) << 44;
  w20 = (in[28] - base) >> 20;
  w20 |= (in[29] - base) << 25;
  w21 = (in[29] - base) >> 39;
  w21 |=  (in[30] - base) << 6;
  w21 |= (in[31] - base) << 51;
  w22 = (in[31] - base) >> 13;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 180; /* we used up 180 output bytes */ 
}


/* we are going to pack 32 46-bit values, touching 23 64-bit words, using 184 bytes */ 
static void packforblock46_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  23 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 46;
  w1 = (in[1] - base) >> 18;
  w1 |= (in[2] - base) << 28;
  w2 = (in[2] - base) >> 36;
  w2 |=  (in[3] - base) << 10;
  w2 |= (in[4] - base) << 56;
  w3 = (in[4] - base) >> 8;
  w3 |= (in[5] - base) << 38;
  w4 = (in[5] - base) >> 26;
  w4 |= (in[6] - base) << 20;
  w5 = (in[6] - base) >> 44;
  w5 |=  (in[7] - base) << 2;
  w5 |= (in[8] - base) << 48;
  w6 = (in[8] - base) >> 16;
  w6 |= (in[9] - base) << 30;
  w7 = (in[9] - base) >> 34;
  w7 |=  (in[10] - base) << 12;
  w7 |= (in[11] - base) << 58;
  w8 = (in[11] - base) >> 6;
  w8 |= (in[12] - base) << 40;
  w9 = (in[12] - base) >> 24;
  w9 |= (in[13] - base) << 22;
  w10 = (in[13] - base) >> 42;
  w10 |=  (in[14] - base) << 4;
  w10 |= (in[15] - base) << 50;
  w11 = (in[15] - base) >> 14;
  w11 |= (in[16] - base) << 32;
  w12 = (in[16] - base) >> 32;
  w12 |=  (in[17] - base) << 14;
  w12 |= (in[18] - base) << 60;
  w13 = (in[18] - base) >> 4;
  w13 |= (in[19] - base) << 42;
  w14 = (in[19] - base) >> 22;
  w14 |= (in[20] - base) << 24;
  w15 = (in[20] - base) >> 40;
  w15 |=  (in[21] - base) << 6;
  w15 |= (in[22] - base) << 52;
  w16 = (in[22] - base) >> 12;
  w16 |= (in[23] - base) << 34;
  w17 = (in[23] - base) >> 30;
  w17 |=  (in[24] - base) << 16;
  w17 |= (in[25] - base) << 62;
  w18 = (in[25] - base) >> 2;
  w18 |= (in[26] - base) << 44;
  w19 = (in[26] - base) >> 20;
  w19 |= (in[27] - base) << 26;
  w20 = (in[27] - base) >> 38;
  w20 |=  (in[28] - base) << 8;
  w20 |= (in[29] - base) << 54;
  w21 = (in[29] - base) >> 10;
  w21 |= (in[30] - base) << 36;
  w22 = (in[30] - base) >> 28;
  w22 |=  (in[31] - base) << 18;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 184; /* we used up 184 output bytes */ 
}


/* we are going to pack 32 47-bit values, touching 24 64-bit words, using 188 bytes */ 
static void packforblock47_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  24 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 47;
  w1 = (in[1] - base) >> 17;
  w1 |= (in[2] - base) << 30;
  w2 = (in[2] - base) >> 34;
  w2 |=  (in[3] - base) << 13;
  w2 |= (in[4] - base) << 60;
  w3 = (in[4] - base) >> 4;
  w3 |= (in[5] - base) << 43;
  w4 = (in[5] - base) >> 21;
  w4 |= (in[6] - base) << 26;
  w5 = (in[6] - base) >> 38;
  w5 |=  (in[7] - base) << 9;
  w5 |= (in[8] - base) << 56;
  w6 = (in[8] - base) >> 8;
  w6 |= (in[9] - base) << 39;
  w7 = (in[9] - base) >> 25;
  w7 |= (in[10] - base) << 22;
  w8 = (in[10] - base) >> 42;
  w8 |=  (in[11] - base) << 5;
  w8 |= (in[12] - base) << 52;
  w9 = (in[12] - base) >> 12;
  w9 |= (in[13] - base) << 35;
  w10 = (in[13] - base) >> 29;
  w10 |= (in[14] - base) << 18;
  w11 = (in[14] - base) >> 46;
  w11 |=  (in[15] - base) << 1;
  w11 |= (in[16] - base) << 48;
  w12 = (in[16] - base) >> 16;
  w12 |= (in[17] - base) << 31;
  w13 = (in[17] - base) >> 33;
  w13 |=  (in[18] - base) << 14;
  w13 |= (in[19] - base) << 61;
  w14 = (in[19] - base) >> 3;
  w14 |= (in[20] - base) << 44;
  w15 = (in[20] - base) >> 20;
  w15 |= (in[21] - base) << 27;
  w16 = (in[21] - base) >> 37;
  w16 |=  (in[22] - base) << 10;
  w16 |= (in[23] - base) << 57;
  w17 = (in[23] - base) >> 7;
  w17 |= (in[24] - base) << 40;
  w18 = (in[24] - base) >> 24;
  w18 |= (in[25] - base) << 23;
  w19 = (in[25] - base) >> 41;
  w19 |=  (in[26] - base) << 6;
  w19 |= (in[27] - base) << 53;
  w20 = (in[27] - base) >> 11;
  w20 |= (in[28] - base) << 36;
  w21 = (in[28] - base) >> 28;
  w21 |= (in[29] - base) << 19;
  w22 = (in[29] - base) >> 45;
  w22 |=  (in[30] - base) << 2;
  w22 |= (in[31] - base) << 49;
  w23 = (in[31] - base) >> 15;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 188; /* we used up 188 output bytes */ 
}


/* we are going to pack 32 48-bit values, touching 24 64-bit words, using 192 bytes */ 
static void packforblock48_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  24 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 48;
  w1 = (in[1] - base) >> 16;
  w1 |= (in[2] - base) << 32;
  w2 = (in[2] - base) >> 32;
  w2 |=  (in[3] - base) << 16;
  w3 = (in[4] - base);
  w3 |= (in[5] - base) << 48;
  w4 = (in[5] - base) >> 16;
  w4 |= (in[6] - base) << 32;
  w5 = (in[6] - base) >> 32;
  w5 |=  (in[7] - base) << 16;
  w6 = (in[8] - base);
  w6 |= (in[9] - base) << 48;
  w7 = (in[9] - base) >> 16;
  w7 |= (in[10] - base) << 32;
  w8 = (in[10] - base) >> 32;
  w8 |=  (in[11] - base) << 16;
  w9 = (in[12] - base);
  w9 |= (in[13] - base) << 48;
  w10 = (in[13] - base) >> 16;
  w10 |= (in[14] - base) << 32;
  w11 = (in[14] - base) >> 32;
  w11 |=  (in[15] - base) << 16;
  w12 = (in[16] - base);
  w12 |= (in[17] - base) << 48;
  w13 = (in[17] - base) >> 16;
  w13 |= (in[18] - base) << 32;
  w14 = (in[18] - base) >> 32;
  w14 |=  (in[19] - base) << 16;
  w15 = (in[20] - base);
  w15 |= (in[21] - base) << 48;
  w16 = (in[21] - base) >> 16;
  w16 |= (in[22] - base) << 32;
  w17 = (in[22] - base) >> 32;
  w17 |=  (in[23] - base) << 16;
  w18 = (in[24] - base);
  w18 |= (in[25] - base) << 48;
  w19 = (in[25] - base) >> 16;
  w19 |= (in[26] - base) << 32;
  w20 = (in[26] - base) >> 32;
  w20 |=  (in[27] - base) << 16;
  w21 = (in[28] - base);
  w21 |= (in[29] - base) << 48;
  w22 = (in[29] - base) >> 16;
  w22 |= (in[30] - base) << 32;
  w23 = (in[30] - base) >> 32;
  w23 |=  (in[31] - base) << 16;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 192; /* we used up 192 output bytes */ 
}


/* we are going to pack 32 49-bit values, touching 25 64-bit words, using 196 bytes */ 
static void packforblock49_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  25 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 49;
  w1 = (in[1] - base) >> 15;
  w1 |= (in[2] - base) << 34;
  w2 = (in[2] - base) >> 30;
  w2 |= (in[3] - base) << 19;
  w3 = (in[3] - base) >> 45;
  w3 |=  (in[4] - base) << 4;
  w3 |= (in[5] - base) << 53;
  w4 = (in[5] - base) >> 11;
  w4 |= (in[6] - base) << 38;
  w5 = (in[6] - base) >> 26;
  w5 |= (in[7] - base) << 23;
  w6 = (in[7] - base) >> 41;
  w6 |=  (in[8] - base) << 8;
  w6 |= (in[9] - base) << 57;
  w7 = (in[9] - base) >> 7;
  w7 |= (in[10] - base) << 42;
  w8 = (in[10] - base) >> 22;
  w8 |= (in[11] - base) << 27;
  w9 = (in[11] - base) >> 37;
  w9 |=  (in[12] - base) << 12;
  w9 |= (in[13] - base) << 61;
  w10 = (in[13] - base) >> 3;
  w10 |= (in[14] - base) << 46;
  w11 = (in[14] - base) >> 18;
  w11 |= (in[15] - base) << 31;
  w12 = (in[15] - base) >> 33;
  w12 |= (in[16] - base) << 16;
  w13 = (in[16] - base) >> 48;
  w13 |=  (in[17] - base) << 1;
  w13 |= (in[18] - base) << 50;
  w14 = (in[18] - base) >> 14;
  w14 |= (in[19] - base) << 35;
  w15 = (in[19] - base) >> 29;
  w15 |= (in[20] - base) << 20;
  w16 = (in[20] - base) >> 44;
  w16 |=  (in[21] - base) << 5;
  w16 |= (in[22] - base) << 54;
  w17 = (in[22] - base) >> 10;
  w17 |= (in[23] - base) << 39;
  w18 = (in[23] - base) >> 25;
  w18 |= (in[24] - base) << 24;
  w19 = (in[24] - base) >> 40;
  w19 |=  (in[25] - base) << 9;
  w19 |= (in[26] - base) << 58;
  w20 = (in[26] - base) >> 6;
  w20 |= (in[27] - base) << 43;
  w21 = (in[27] - base) >> 21;
  w21 |= (in[28] - base) << 28;
  w22 = (in[28] - base) >> 36;
  w22 |=  (in[29] - base) << 13;
  w22 |= (in[30] - base) << 62;
  w23 = (in[30] - base) >> 2;
  w23 |= (in[31] - base) << 47;
  w24 = (in[31] - base) >> 17;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 196; /* we used up 196 output bytes */ 
}


/* we are going to pack 32 50-bit values, touching 25 64-bit words, using 200 bytes */ 
static void packforblock50_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  25 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 50;
  w1 = (in[1] - base) >> 14;
  w1 |= (in[2] - base) << 36;
  w2 = (in[2] - base) >> 28;
  w2 |= (in[3] - base) << 22;
  w3 = (in[3] - base) >> 42;
  w3 |=  (in[4] - base) << 8;
  w3 |= (in[5] - base) << 58;
  w4 = (in[5] - base) >> 6;
  w4 |= (in[6] - base) << 44;
  w5 = (in[6] - base) >> 20;
  w5 |= (in[7] - base) << 30;
  w6 = (in[7] - base) >> 34;
  w6 |= (in[8] - base) << 16;
  w7 = (in[8] - base) >> 48;
  w7 |=  (in[9] - base) << 2;
  w7 |= (in[10] - base) << 52;
  w8 = (in[10] - base) >> 12;
  w8 |= (in[11] - base) << 38;
  w9 = (in[11] - base) >> 26;
  w9 |= (in[12] - base) << 24;
  w10 = (in[12] - base) >> 40;
  w10 |=  (in[13] - base) << 10;
  w10 |= (in[14] - base) << 60;
  w11 = (in[14] - base) >> 4;
  w11 |= (in[15] - base) << 46;
  w12 = (in[15] - base) >> 18;
  w12 |= (in[16] - base) << 32;
  w13 = (in[16] - base) >> 32;
  w13 |= (in[17] - base) << 18;
  w14 = (in[17] - base) >> 46;
  w14 |=  (in[18] - base) << 4;
  w14 |= (in[19] - base) << 54;
  w15 = (in[19] - base) >> 10;
  w15 |= (in[20] - base) << 40;
  w16 = (in[20] - base) >> 24;
  w16 |= (in[21] - base) << 26;
  w17 = (in[21] - base) >> 38;
  w17 |=  (in[22] - base) << 12;
  w17 |= (in[23] - base) << 62;
  w18 = (in[23] - base) >> 2;
  w18 |= (in[24] - base) << 48;
  w19 = (in[24] - base) >> 16;
  w19 |= (in[25] - base) << 34;
  w20 = (in[25] - base) >> 30;
  w20 |= (in[26] - base) << 20;
  w21 = (in[26] - base) >> 44;
  w21 |=  (in[27] - base) << 6;
  w21 |= (in[28] - base) << 56;
  w22 = (in[28] - base) >> 8;
  w22 |= (in[29] - base) << 42;
  w23 = (in[29] - base) >> 22;
  w23 |= (in[30] - base) << 28;
  w24 = (in[30] - base) >> 36;
  w24 |=  (in[31] - base) << 14;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 200; /* we used up 200 output bytes */ 
}


/* we are going to pack 32 51-bit values, touching 26 64-bit words, using 204 bytes */ 
static void packforblock51_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  26 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 51;
  w1 = (in[1] - base) >> 13;
  w1 |= (in[2] - base) << 38;
  w2 = (in[2] - base) >> 26;
  w2 |= (in[3] - base) << 25;
  w3 = (in[3] - base) >> 39;
  w3 |=  (in[4] - base) << 12;
  w3 |= (in[5] - base) << 63;
  w4 = (in[5] - base) >> 1;
  w4 |= (in[6] - base) << 50;
  w5 = (in[6] - base) >> 14;
  w5 |= (in[7] - base) << 37;
  w6 = (in[7] - base) >> 27;
  w6 |= (in[8] - base) << 24;
  w7 = (in[8] - base) >> 40;
  w7 |=  (in[9] - base) << 11;
  w7 |= (in[10] - base) << 62;
  w8 = (in[10] - base) >> 2;
  w8 |= (in[11] - base) << 49;
  w9 = (in[11] - base) >> 15;
  w9 |= (in[12] - base) << 36;
  w10 = (in[12] - base) >> 28;
  w10 |= (in[13] - base) << 23;
  w11 = (in[13] - base) >> 41;
  w11 |=  (in[14] - base) << 10;
  w11 |= (in[15] - base) << 61;
  w12 = (in[15] - base) >> 3;
  w12 |= (in[16] - base) << 48;
  w13 = (in[16] - base) >> 16;
  w13 |= (in[17] - base) << 35;
  w14 = (in[17] - base) >> 29;
  w14 |= (in[18] - base) << 22;
  w15 = (in[18] - base) >> 42;
  w15 |=  (in[19] - base) << 9;
  w15 |= (in[20] - base) << 60;
  w16 = (in[20] - base) >> 4;
  w16 |= (in[21] - base) << 47;
  w17 = (in[21] - base) >> 17;
  w17 |= (in[22] - base) << 34;
  w18 = (in[22] - base) >> 30;
  w18 |= (in[23] - base) << 21;
  w19 = (in[23] - base) >> 43;
  w19 |=  (in[24] - base) << 8;
  w19 |= (in[25] - base) << 59;
  w20 = (in[25] - base) >> 5;
  w20 |= (in[26] - base) << 46;
  w21 = (in[26] - base) >> 18;
  w21 |= (in[27] - base) << 33;
  w22 = (in[27] - base) >> 31;
  w22 |= (in[28] - base) << 20;
  w23 = (in[28] - base) >> 44;
  w23 |=  (in[29] - base) << 7;
  w23 |= (in[30] - base) << 58;
  w24 = (in[30] - base) >> 6;
  w24 |= (in[31] - base) << 45;
  w25 = (in[31] - base) >> 19;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 204; /* we used up 204 output bytes */ 
}


/* we are going to pack 32 52-bit values, touching 26 64-bit words, using 208 bytes */ 
static void packforblock52_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  26 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 52;
  w1 = (in[1] - base) >> 12;
  w1 |= (in[2] - base) << 40;
  w2 = (in[2] - base) >> 24;
  w2 |= (in[3] - base) << 28;
  w3 = (in[3] - base) >> 36;
  w3 |= (in[4] - base) << 16;
  w4 = (in[4] - base) >> 48;
  w4 |=  (in[5] - base) << 4;
  w4 |= (in[6] - base) << 56;
  w5 = (in[6] - base) >> 8;
  w5 |= (in[7] - base) << 44;
  w6 = (in[7] - base) >> 20;
  w6 |= (in[8] - base) << 32;
  w7 = (in[8] - base) >> 32;
  w7 |= (in[9] - base) << 20;
  w8 = (in[9] - base) >> 44;
  w8 |=  (in[10] - base) << 8;
  w8 |= (in[11] - base) << 60;
  w9 = (in[11] - base) >> 4;
  w9 |= (in[12] - base) << 48;
  w10 = (in[12] - base) >> 16;
  w10 |= (in[13] - base) << 36;
  w11 = (in[13] - base) >> 28;
  w11 |= (in[14] - base) << 24;
  w12 = (in[14] - base) >> 40;
  w12 |=  (in[15] - base) << 12;
  w13 = (in[16] - base);
  w13 |= (in[17] - base) << 52;
  w14 = (in[17] - base) >> 12;
  w14 |= (in[18] - base) << 40;
  w15 = (in[18] - base) >> 24;
  w15 |= (in[19] - base) << 28;
  w16 = (in[19] - base) >> 36;
  w16 |= (in[20] - base) << 16;
  w17 = (in[20] - base) >> 48;
  w17 |=  (in[21] - base) << 4;
  w17 |= (in[22] - base) << 56;
  w18 = (in[22] - base) >> 8;
  w18 |= (in[23] - base) << 44;
  w19 = (in[23] - base) >> 20;
  w19 |= (in[24] - base) << 32;
  w20 = (in[24] - base) >> 32;
  w20 |= (in[25] - base) << 20;
  w21 = (in[25] - base) >> 44;
  w21 |=  (in[26] - base) << 8;
  w21 |= (in[27] - base) << 60;
  w22 = (in[27] - base) >> 4;
  w22 |= (in[28] - base) << 48;
  w23 = (in[28] - base) >> 16;
  w23 |= (in[29] - base) << 36;
  w24 = (in[29] - base) >> 28;
  w24 |= (in[30] - base) << 24;
  w25 = (in[30] - base) >> 40;
  w25 |=  (in[31] - base) << 12;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 208; /* we used up 208 output bytes */ 
}


/* we are going to pack 32 53-bit values, touching 27 64-bit words, using 212 bytes */ 
static void packforblock53_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  27 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 53;
  w1 = (in[1] - base) >> 11;
  w1 |= (in[2] - base) << 42;
  w2 = (in[2] - base) >> 22;
  w2 |= (in[3] - base) << 31;
  w3 = (in[3] - base) >> 33;
  w3 |= (in[4] - base) << 20;
  w4 = (in[4] - base) >> 44;
  w4 |=  (in[5] - base) << 9;
  w4 |= (in[6] - base) << 62;
  w5 = (in[6] - base) >> 2;
  w5 |= (in[7] - base) << 51;
  w6 = (in[7] - base) >> 13;
  w6 |= (in[8] - base) << 40;
  w7 = (in[8] - base) >> 24;
  w7 |= (in[9] - base) << 29;
  w8 = (in[9] - base) >> 35;
  w8 |= (in[10] - base) << 18;
  w9 = (in[10] - base) >> 46;
  w9 |=  (in[11] - base) << 7;
  w9 |= (in[12] - base) << 60;
  w10 = (in[12] - base) >> 4;
  w10 |= (in[13] - base) << 49;
  w11 = (in[13] - base) >> 15;
  w11 |= (in[14] - base) << 38;
  w12 = (in[14] - base) >> 26;
  w12 |= (in[15] - base) << 27;
  w13 = (in[15] - base) >> 37;
  w13 |= (in[16] - base) << 16;
  w14 = (in[16] - base) >> 48;
  w14 |=  (in[17] - base) << 5;
  w14 |= (in[18] - base) << 58;
  w15 = (in[18] - base) >> 6;
  w15 |= (in[19] - base) << 47;
  w16 = (in[19] - base) >> 17;
  w16 |= (in[20] - base) << 36;
  w17 = (in[20] - base) >> 28;
  w17 |= (in[21] - base) << 25;
  w18 = (in[21] - base) >> 39;
  w18 |= (in[22] - base) << 14;
  w19 = (in[22] - base) >> 50;
  w19 |=  (in[23] - base) << 3;
  w19 |= (in[24] - base) << 56;
  w20 = (in[24] - base) >> 8;
  w20 |= (in[25] - base) << 45;
  w21 = (in[25] - base) >> 19;
  w21 |= (in[26] - base) << 34;
  w22 = (in[26] - base) >> 30;
  w22 |= (in[27] - base) << 23;
  w23 = (in[27] - base) >> 41;
  w23 |= (in[28] - base) << 12;
  w24 = (in[28] - base) >> 52;
  w24 |=  (in[29] - base) << 1;
  w24 |= (in[30] - base) << 54;
  w25 = (in[30] - base) >> 10;
  w25 |= (in[31] - base) << 43;
  w26 = (in[31] - base) >> 21;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 212; /* we used up 212 output bytes */ 
}


/* we are going to pack 32 54-bit values, touching 27 64-bit words, using 216 bytes */ 
static void packforblock54_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  27 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 54;
  w1 = (in[1] - base) >> 10;
  w1 |= (in[2] - base) << 44;
  w2 = (in[2] - base) >> 20;
  w2 |= (in[3] - base) << 34;
  w3 = (in[3] - base) >> 30;
  w3 |= (in[4] - base) << 24;
  w4 = (in[4] - base) >> 40;
  w4 |= (in[5] - base) << 14;
  w5 = (in[5] - base) >> 50;
  w5 |=  (in[6] - base) << 4;
  w5 |= (in[7] - base) << 58;
  w6 = (in[7] - base) >> 6;
  w6 |= (in[8] - base) << 48;
  w7 = (in[8] - base) >> 16;
  w7 |= (in[9] - base) << 38;
  w8 = (in[9] - base) >> 26;
  w8 |= (in[10] - base) << 28;
  w9 = (in[10] - base) >> 36;
  w9 |= (in[11] - base) << 18;
  w10 = (in[11] - base) >> 46;
  w10 |=  (in[12] - base) << 8;
  w10 |= (in[13] - base) << 62;
  w11 = (in[13] - base) >> 2;
  w11 |= (in[14] - base) << 52;
  w12 = (in[14] - base) >> 12;
  w12 |= (in[15] - base) << 42;
  w13 = (in[15] - base) >> 22;
  w13 |= (in[16] - base) << 32;
  w14 = (in[16] - base) >> 32;
  w14 |= (in[17] - base) << 22;
  w15 = (in[17] - base) >> 42;
  w15 |= (in[18] - base) << 12;
  w16 = (in[18] - base) >> 52;
  w16 |=  (in[19] - base) << 2;
  w16 |= (in[20] - base) << 56;
  w17 = (in[20] - base) >> 8;
  w17 |= (in[21] - base) << 46;
  w18 = (in[21] - base) >> 18;
  w18 |= (in[22] - base) << 36;
  w19 = (in[22] - base) >> 28;
  w19 |= (in[23] - base) << 26;
  w20 = (in[23] - base) >> 38;
  w20 |= (in[24] - base) << 16;
  w21 = (in[24] - base) >> 48;
  w21 |=  (in[25] - base) << 6;
  w21 |= (in[26] - base) << 60;
  w22 = (in[26] - base) >> 4;
  w22 |= (in[27] - base) << 50;
  w23 = (in[27] - base) >> 14;
  w23 |= (in[28] - base) << 40;
  w24 = (in[28] - base) >> 24;
  w24 |= (in[29] - base) << 30;
  w25 = (in[29] - base) >> 34;
  w25 |= (in[30] - base) << 20;
  w26 = (in[30] - base) >> 44;
  w26 |=  (in[31] - base) << 10;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 216; /* we used up 216 output bytes */ 
}


/* we are going to pack 32 55-bit values, touching 28 64-bit words, using 220 bytes */ 
static void packforblock55_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  28 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 55;
  w1 = (in[1] - base) >> 9;
  w1 |= (in[2] - base) << 46;
  w2 = (in[2] - base) >> 18;
  w2 |= (in[3] - base) << 37;
  w3 = (in[3] - base) >> 27;
  w3 |= (in[4] - base) << 28;
  w4 = (in[4] - base) >> 36;
  w4 |= (in[5] - base) << 19;
  w5 = (in[5] - base) >> 45;
  w5 |= (in[6] - base) << 10;
  w6 = (in[6] - base) >> 54;
  w6 |=  (in[7] - base) << 1;
  w6 |= (in[8] - base) << 56;
  w7 = (in[8] - base) >> 8;
  w7 |= (in[9] - base) << 47;
  w8 = (in[9] - base) >> 17;
  w8 |= (in[10] - base) << 38;
  w9 = (in[10] - base) >> 26;
  w9 |= (in[11] - base) << 29;
  w10 = (in[11] - base) >> 35;
  w10 |= (in[12] - base) << 20;
  w11 = (in[12] - base) >> 44;
  w11 |= (in[13] - base) << 11;
  w12 = (in[13] - base) >> 53;
  w12 |=  (in[14] - base) << 2;
  w12 |= (in[15] - base) << 57;
  w13 = (in[15] - base) >> 7;
  w13 |= (in[16] - base) << 48;
  w14 = (in[16] - base) >> 16;
  w14 |= (in[17] - base) << 39;
  w15 = (in[17] - base) >> 25;
  w15 |= (in[18] - base) << 30;
  w16 = (in[18] - base) >> 34;
  w16 |= (in[19] - base) << 21;
  w17 = (in[19] - base) >> 43;
  w17 |= (in[20] - base) << 12;
  w18 = (in[20] - base) >> 52;
  w18 |=  (in[21] - base) << 3;
  w18 |= (in[22] - base) << 58;
  w19 = (in[22] - base) >> 6;
  w19 |= (in[23] - base) << 49;
  w20 = (in[23] - base) >> 15;
  w20 |= (in[24] - base) << 40;
  w21 = (in[24] - base) >> 24;
  w21 |= (in[25] - base) << 31;
  w22 = (in[25] - base) >> 33;
  w22 |= (in[26] - base) << 22;
  w23 = (in[26] - base) >> 42;
  w23 |= (in[27] - base) << 13;
  w24 = (in[27] - base) >> 51;
  w24 |=  (in[28] - base) << 4;
  w24 |= (in[29] - base) << 59;
  w25 = (in[29] - base) >> 5;
  w25 |= (in[30] - base) << 50;
  w26 = (in[30] - base) >> 14;
  w26 |= (in[31] - base) << 41;
  w27 = (in[31] - base) >> 23;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 220; /* we used up 220 output bytes */ 
}


/* we are going to pack 32 56-bit values, touching 28 64-bit words, using 224 bytes */ 
static void packforblock56_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  28 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 56;
  w1 = (in[1] - base) >> 8;
  w1 |= (in[2] - base) << 48;
  w2 = (in[2] - base) >> 16;
  w2 |= (in[3] - base) << 40;
  w3 = (in[3] - base) >> 24;
  w3 |= (in[4] - base) << 32;
  w4 = (in[4] - base) >> 32;
  w4 |= (in[5] - base) << 24;
  w5 = (in[5] - base) >> 40;
  w5 |= (in[6] - base) << 16;
  w6 = (in[6] - base) >> 48;
  w6 |=  (in[7] - base) << 8;
  w7 = (in[8] - base);
  w7 |= (in[9] - base) << 56;
  w8 = (in[9] - base) >> 8;
  w8 |= (in[10] - base) << 48;
  w9 = (in[10] - base) >> 16;
  w9 |= (in[11] - base) << 40;
  w10 = (in[11] - base) >> 24;
  w10 |= (in[12] - base) << 32;
  w11 = (in[12] - base) >> 32;
  w11 |= (in[13] - base) << 24;
  w12 = (in[13] - base) >> 40;
  w12 |= (in[14] - base) << 16;
  w13 = (in[14] - base) >> 48;
  w13 |=  (in[15] - base) << 8;
  w14 = (in[16] - base);
  w14 |= (in[17] - base) << 56;
  w15 = (in[17] - base) >> 8;
  w15 |= (in[18] - base) << 48;
  w16 = (in[18] - base) >> 16;
  w16 |= (in[19] - base) << 40;
  w17 = (in[19] - base) >> 24;
  w17 |= (in[20] - base) << 32;
  w18 = (in[20] - base) >> 32;
  w18 |= (in[21] - base) << 24;
  w19 = (in[21] - base) >> 40;
  w19 |= (in[22] - base) << 16;
  w20 = (in[22] - base) >> 48;
  w20 |=  (in[23] - base) << 8;
  w21 = (in[24] - base);
  w21 |= (in[25] - base) << 56;
  w22 = (in[25] - base) >> 8;
  w22 |= (in[26] - base) << 48;
  w23 = (in[26] - base) >> 16;
  w23 |= (in[27] - base) << 40;
  w24 = (in[27] - base) >> 24;
  w24 |= (in[28] - base) << 32;
  w25 = (in[28] - base) >> 32;
  w25 |= (in[29] - base) << 24;
  w26 = (in[29] - base) >> 40;
  w26 |= (in[30] - base) << 16;
  w27 = (in[30] - base) >> 48;
  w27 |=  (in[31] - base) << 8;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 224; /* we used up 224 output bytes */ 
}


/* we are going to pack 32 57-bit values, touching 29 64-bit words, using 228 bytes */ 
static void packforblock57_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  29 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  uint64_t w28;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 57;
  w1 = (in[1] - base) >> 7;
  w1 |= (in[2] - base) << 50;
  w2 = (in[2] - base) >> 14;
  w2 |= (in[3] - base) << 43;
  w3 = (in[3] - base) >> 21;
  w3 |= (in[4] - base) << 36;
  w4 = (in[4] - base) >> 28;
  w4 |= (in[5] - base) << 29;
  w5 = (in[5] - base) >> 35;
  w5 |= (in[6] - base) << 22;
  w6 = (in[6] - base) >> 42;
  w6 |= (in[7] - base) << 15;
  w7 = (in[7] - base) >> 49;
  w7 |= (in[8] - base) << 8;
  w8 = (in[8] - base) >> 56;
  w8 |=  (in[9] - base) << 1;
  w8 |= (in[10] - base) << 58;
  w9 = (in[10] - base) >> 6;
  w9 |= (in[11] - base) << 51;
  w10 = (in[11] - base) >> 13;
  w10 |= (in[12] - base) << 44;
  w11 = (in[12] - base) >> 20;
  w11 |= (in[13] - base) << 37;
  w12 = (in[13] - base) >> 27;
  w12 |= (in[14] - base) << 30;
  w13 = (in[14] - base) >> 34;
  w13 |= (in[15] - base) << 23;
  w14 = (in[15] - base) >> 41;
  w14 |= (in[16] - base) << 16;
  w15 = (in[16] - base) >> 48;
  w15 |= (in[17] - base) << 9;
  w16 = (in[17] - base) >> 55;
  w16 |=  (in[18] - base) << 2;
  w16 |= (in[19] - base) << 59;
  w17 = (in[19] - base) >> 5;
  w17 |= (in[20] - base) << 52;
  w18 = (in[20] - base) >> 12;
  w18 |= (in[21] - base) << 45;
  w19 = (in[21] - base) >> 19;
  w19 |= (in[22] - base) << 38;
  w20 = (in[22] - base) >> 26;
  w20 |= (in[23] - base) << 31;
  w21 = (in[23] - base) >> 33;
  w21 |= (in[24] - base) << 24;
  w22 = (in[24] - base) >> 40;
  w22 |= (in[25] - base) << 17;
  w23 = (in[25] - base) >> 47;
  w23 |= (in[26] - base) << 10;
  w24 = (in[26] - base) >> 54;
  w24 |=  (in[27] - base) << 3;
  w24 |= (in[28] - base) << 60;
  w25 = (in[28] - base) >> 4;
  w25 |= (in[29] - base) << 53;
  w26 = (in[29] - base) >> 11;
  w26 |= (in[30] - base) << 46;
  w27 = (in[30] - base) >> 18;
  w27 |= (in[31] - base) << 39;
  w28 = (in[31] - base) >> 25;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  pw64[28] = w28;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 228; /* we used up 228 output bytes */ 
}


/* we are going to pack 32 58-bit values, touching 29 64-bit words, using 232 bytes */ 
static void packforblock58_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  29 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  uint64_t w28;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 58;
  w1 = (in[1] - base) >> 6;
  w1 |= (in[2] - base) << 52;
  w2 = (in[2] - base) >> 12;
  w2 |= (in[3] - base) << 46;
  w3 = (in[3] - base) >> 18;
  w3 |= (in[4] - base) << 40;
  w4 = (in[4] - base) >> 24;
  w4 |= (in[5] - base) << 34;
  w5 = (in[5] - base) >> 30;
  w5 |= (in[6] - base) << 28;
  w6 = (in[6] - base) >> 36;
  w6 |= (in[7] - base) << 22;
  w7 = (in[7] - base) >> 42;
  w7 |= (in[8] - base) << 16;
  w8 = (in[8] - base) >> 48;
  w8 |= (in[9] - base) << 10;
  w9 = (in[9] - base) >> 54;
  w9 |=  (in[10] - base) << 4;
  w9 |= (in[11] - base) << 62;
  w10 = (in[11] - base) >> 2;
  w10 |= (in[12] - base) << 56;
  w11 = (in[12] - base) >> 8;
  w11 |= (in[13] - base) << 50;
  w12 = (in[13] - base) >> 14;
  w12 |= (in[14] - base) << 44;
  w13 = (in[14] - base) >> 20;
  w13 |= (in[15] - base) << 38;
  w14 = (in[15] - base) >> 26;
  w14 |= (in[16] - base) << 32;
  w15 = (in[16] - base) >> 32;
  w15 |= (in[17] - base) << 26;
  w16 = (in[17] - base) >> 38;
  w16 |= (in[18] - base) << 20;
  w17 = (in[18] - base) >> 44;
  w17 |= (in[19] - base) << 14;
  w18 = (in[19] - base) >> 50;
  w18 |= (in[20] - base) << 8;
  w19 = (in[20] - base) >> 56;
  w19 |=  (in[21] - base) << 2;
  w19 |= (in[22] - base) << 60;
  w20 = (in[22] - base) >> 4;
  w20 |= (in[23] - base) << 54;
  w21 = (in[23] - base) >> 10;
  w21 |= (in[24] - base) << 48;
  w22 = (in[24] - base) >> 16;
  w22 |= (in[25] - base) << 42;
  w23 = (in[25] - base) >> 22;
  w23 |= (in[26] - base) << 36;
  w24 = (in[26] - base) >> 28;
  w24 |= (in[27] - base) << 30;
  w25 = (in[27] - base) >> 34;
  w25 |= (in[28] - base) << 24;
  w26 = (in[28] - base) >> 40;
  w26 |= (in[29] - base) << 18;
  w27 = (in[29] - base) >> 46;
  w27 |= (in[30] - base) << 12;
  w28 = (in[30] - base) >> 52;
  w28 |=  (in[31] - base) << 6;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  pw64[28] = w28;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 232; /* we used up 232 output bytes */ 
}


/* we are going to pack 32 59-bit values, touching 30 64-bit words, using 236 bytes */ 
static void packforblock59_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  30 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  uint64_t w28;
  uint64_t w29;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 59;
  w1 = (in[1] - base) >> 5;
  w1 |= (in[2] - base) << 54;
  w2 = (in[2] - base) >> 10;
  w2 |= (in[3] - base) << 49;
  w3 = (in[3] - base) >> 15;
  w3 |= (in[4] - base) << 44;
  w4 = (in[4] - base) >> 20;
  w4 |= (in[5] - base) << 39;
  w5 = (in[5] - base) >> 25;
  w5 |= (in[6] - base) << 34;
  w6 = (in[6] - base) >> 30;
  w6 |= (in[7] - base) << 29;
  w7 = (in[7] - base) >> 35;
  w7 |= (in[8] - base) << 24;
  w8 = (in[8] - base) >> 40;
  w8 |= (in[9] - base) << 19;
  w9 = (in[9] - base) >> 45;
  w9 |= (in[10] - base) << 14;
  w10 = (in[10] - base) >> 50;
  w10 |= (in[11] - base) << 9;
  w11 = (in[11] - base) >> 55;
  w11 |=  (in[12] - base) << 4;
  w11 |= (in[13] - base) << 63;
  w12 = (in[13] - base) >> 1;
  w12 |= (in[14] - base) << 58;
  w13 = (in[14] - base) >> 6;
  w13 |= (in[15] - base) << 53;
  w14 = (in[15] - base) >> 11;
  w14 |= (in[16] - base) << 48;
  w15 = (in[16] - base) >> 16;
  w15 |= (in[17] - base) << 43;
  w16 = (in[17] - base) >> 21;
  w16 |= (in[18] - base) << 38;
  w17 = (in[18] - base) >> 26;
  w17 |= (in[19] - base) << 33;
  w18 = (in[19] - base) >> 31;
  w18 |= (in[20] - base) << 28;
  w19 = (in[20] - base) >> 36;
  w19 |= (in[21] - base) << 23;
  w20 = (in[21] - base) >> 41;
  w20 |= (in[22] - base) << 18;
  w21 = (in[22] - base) >> 46;
  w21 |= (in[23] - base) << 13;
  w22 = (in[23] - base) >> 51;
  w22 |= (in[24] - base) << 8;
  w23 = (in[24] - base) >> 56;
  w23 |=  (in[25] - base) << 3;
  w23 |= (in[26] - base) << 62;
  w24 = (in[26] - base) >> 2;
  w24 |= (in[27] - base) << 57;
  w25 = (in[27] - base) >> 7;
  w25 |= (in[28] - base) << 52;
  w26 = (in[28] - base) >> 12;
  w26 |= (in[29] - base) << 47;
  w27 = (in[29] - base) >> 17;
  w27 |= (in[30] - base) << 42;
  w28 = (in[30] - base) >> 22;
  w28 |= (in[31] - base) << 37;
  w29 = (in[31] - base) >> 27;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  pw64[28] = w28;
  pw64[29] = w29;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 236; /* we used up 236 output bytes */ 
}


/* we are going to pack 32 60-bit values, touching 30 64-bit words, using 240 bytes */ 
static void packforblock60_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  30 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  uint64_t w28;
  uint64_t w29;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 60;
  w1 = (in[1] - base) >> 4;
  w1 |= (in[2] - base) << 56;
  w2 = (in[2] - base) >> 8;
  w2 |= (in[3] - base) << 52;
  w3 = (in[3] - base) >> 12;
  w3 |= (in[4] - base) << 48;
  w4 = (in[4] - base) >> 16;
  w4 |= (in[5] - base) << 44;
  w5 = (in[5] - base) >> 20;
  w5 |= (in[6] - base) << 40;
  w6 = (in[6] - base) >> 24;
  w6 |= (in[7] - base) << 36;
  w7 = (in[7] - base) >> 28;
  w7 |= (in[8] - base) << 32;
  w8 = (in[8] - base) >> 32;
  w8 |= (in[9] - base) << 28;
  w9 = (in[9] - base) >> 36;
  w9 |= (in[10] - base) << 24;
  w10 = (in[10] - base) >> 40;
  w10 |= (in[11] - base) << 20;
  w11 = (in[11] - base) >> 44;
  w11 |= (in[12] - base) << 16;
  w12 = (in[12] - base) >> 48;
  w12 |= (in[13] - base) << 12;
  w13 = (in[13] - base) >> 52;
  w13 |= (in[14] - base) << 8;
  w14 = (in[14] - base) >> 56;
  w14 |=  (in[15] - base) << 4;
  w15 = (in[16] - base);
  w15 |= (in[17] - base) << 60;
  w16 = (in[17] - base) >> 4;
  w16 |= (in[18] - base) << 56;
  w17 = (in[18] - base) >> 8;
  w17 |= (in[19] - base) << 52;
  w18 = (in[19] - base) >> 12;
  w18 |= (in[20] - base) << 48;
  w19 = (in[20] - base) >> 16;
  w19 |= (in[21] - base) << 44;
  w20 = (in[21] - base) >> 20;
  w20 |= (in[22] - base) << 40;
  w21 = (in[22] - base) >> 24;
  w21 |= (in[23] - base) << 36;
  w22 = (in[23] - base) >> 28;
  w22 |= (in[24] - base) << 32;
  w23 = (in[24] - base) >> 32;
  w23 |= (in[25] - base) << 28;
  w24 = (in[25] - base) >> 36;
  w24 |= (in[26] - base) << 24;
  w25 = (in[26] - base) >> 40;
  w25 |= (in[27] - base) << 20;
  w26 = (in[27] - base) >> 44;
  w26 |= (in[28] - base) << 16;
  w27 = (in[28] - base) >> 48;
  w27 |= (in[29] - base) << 12;
  w28 = (in[29] - base) >> 52;
  w28 |= (in[30] - base) << 8;
  w29 = (in[30] - base) >> 56;
  w29 |=  (in[31] - base) << 4;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  pw64[28] = w28;
  pw64[29] = w29;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 240; /* we used up 240 output bytes */ 
}


/* we are going to pack 32 61-bit values, touching 31 64-bit words, using 244 bytes */ 
static void packforblock61_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  31 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  uint64_t w28;
  uint64_t w29;
  uint64_t w30;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 61;
  w1 = (in[1] - base) >> 3;
  w1 |= (in[2] - base) << 58;
  w2 = (in[2] - base) >> 6;
  w2 |= (in[3] - base) << 55;
  w3 = (in[3] - base) >> 9;
  w3 |= (in[4] - base) << 52;
  w4 = (in[4] - base) >> 12;
  w4 |= (in[5] - base) << 49;
  w5 = (in[5] - base) >> 15;
  w5 |= (in[6] - base) << 46;
  w6 = (in[6] - base) >> 18;
  w6 |= (in[7] - base) << 43;
  w7 = (in[7] - base) >> 21;
  w7 |= (in[8] - base) << 40;
  w8 = (in[8] - base) >> 24;
  w8 |= (in[9] - base) << 37;
  w9 = (in[9] - base) >> 27;
  w9 |= (in[10] - base) << 34;
  w10 = (in[10] - base) >> 30;
  w10 |= (in[11] - base) << 31;
  w11 = (in[11] - base) >> 33;
  w11 |= (in[12] - base) << 28;
  w12 = (in[12] - base) >> 36;
  w12 |= (in[13] - base) << 25;
  w13 = (in[13] - base) >> 39;
  w13 |= (in[14] - base) << 22;
  w14 = (in[14] - base) >> 42;
  w14 |= (in[15] - base) << 19;
  w15 = (in[15] - base) >> 45;
  w15 |= (in[16] - base) << 16;
  w16 = (in[16] - base) >> 48;
  w16 |= (in[17] - base) << 13;
  w17 = (in[17] - base) >> 51;
  w17 |= (in[18] - base) << 10;
  w18 = (in[18] - base) >> 54;
  w18 |= (in[19] - base) << 7;
  w19 = (in[19] - base) >> 57;
  w19 |= (in[20] - base) << 4;
  w20 = (in[20] - base) >> 60;
  w20 |=  (in[21] - base) << 1;
  w20 |= (in[22] - base) << 62;
  w21 = (in[22] - base) >> 2;
  w21 |= (in[23] - base) << 59;
  w22 = (in[23] - base) >> 5;
  w22 |= (in[24] - base) << 56;
  w23 = (in[24] - base) >> 8;
  w23 |= (in[25] - base) << 53;
  w24 = (in[25] - base) >> 11;
  w24 |= (in[26] - base) << 50;
  w25 = (in[26] - base) >> 14;
  w25 |= (in[27] - base) << 47;
  w26 = (in[27] - base) >> 17;
  w26 |= (in[28] - base) << 44;
  w27 = (in[28] - base) >> 20;
  w27 |= (in[29] - base) << 41;
  w28 = (in[29] - base) >> 23;
  w28 |= (in[30] - base) << 38;
  w29 = (in[30] - base) >> 26;
  w29 |= (in[31] - base) << 35;
  w30 = (in[31] - base) >> 29;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  pw64[28] = w28;
  pw64[29] = w29;
  pw64[30] = w30;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 244; /* we used up 244 output bytes */ 
}


/* we are going to pack 32 62-bit values, touching 31 64-bit words, using 248 bytes */ 
static void packforblock62_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  31 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  uint64_t w28;
  uint64_t w29;
  uint64_t w30;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 62;
  w1 = (in[1] - base) >> 2;
  w1 |= (in[2] - base) << 60;
  w2 = (in[2] - base) >> 4;
  w2 |= (in[3] - base) << 58;
  w3 = (in[3] - base) >> 6;
  w3 |= (in[4] - base) << 56;
  w4 = (in[4] - base) >> 8;
  w4 |= (in[5] - base) << 54;
  w5 = (in[5] - base) >> 10;
  w5 |= (in[6] - base) << 52;
  w6 = (in[6] - base) >> 12;
  w6 |= (in[7] - base) << 50;
  w7 = (in[7] - base) >> 14;
  w7 |= (in[8] - base) << 48;
  w8 = (in[8] - base) >> 16;
  w8 |= (in[9] - base) << 46;
  w9 = (in[9] - base) >> 18;
  w9 |= (in[10] - base) << 44;
  w10 = (in[10] - base) >> 20;
  w10 |= (in[11] - base) << 42;
  w11 = (in[11] - base) >> 22;
  w11 |= (in[12] - base) << 40;
  w12 = (in[12] - base) >> 24;
  w12 |= (in[13] - base) << 38;
  w13 = (in[13] - base) >> 26;
  w13 |= (in[14] - base) << 36;
  w14 = (in[14] - base) >> 28;
  w14 |= (in[15] - base) << 34;
  w15 = (in[15] - base) >> 30;
  w15 |= (in[16] - base) << 32;
  w16 = (in[16] - base) >> 32;
  w16 |= (in[17] - base) << 30;
  w17 = (in[17] - base) >> 34;
  w17 |= (in[18] - base) << 28;
  w18 = (in[18] - base) >> 36;
  w18 |= (in[19] - base) << 26;
  w19 = (in[19] - base) >> 38;
  w19 |= (in[20] - base) << 24;
  w20 = (in[20] - base) >> 40;
  w20 |= (in[21] - base) << 22;
  w21 = (in[21] - base) >> 42;
  w21 |= (in[22] - base) << 20;
  w22 = (in[22] - base) >> 44;
  w22 |= (in[23] - base) << 18;
  w23 = (in[23] - base) >> 46;
  w23 |= (in[24] - base) << 16;
  w24 = (in[24] - base) >> 48;
  w24 |= (in[25] - base) << 14;
  w25 = (in[25] - base) >> 50;
  w25 |= (in[26] - base) << 12;
  w26 = (in[26] - base) >> 52;
  w26 |= (in[27] - base) << 10;
  w27 = (in[27] - base) >> 54;
  w27 |= (in[28] - base) << 8;
  w28 = (in[28] - base) >> 56;
  w28 |= (in[29] - base) << 6;
  w29 = (in[29] - base) >> 58;
  w29 |= (in[30] - base) << 4;
  w30 = (in[30] - base) >> 60;
  w30 |=  (in[31] - base) << 2;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  pw64[28] = w28;
  pw64[29] = w29;
  pw64[30] = w30;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 248; /* we used up 248 output bytes */ 
}


/* we are going to pack 32 63-bit values, touching 32 64-bit words, using 252 bytes */ 
static void packforblock63_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  32 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  uint64_t w28;
  uint64_t w29;
  uint64_t w30;
  uint64_t w31;
  w0 = (in[0] - base);
  w0 |= (in[1] - base) << 63;
  w1 = (in[1] - base) >> 1;
  w1 |= (in[2] - base) << 62;
  w2 = (in[2] - base) >> 2;
  w2 |= (in[3] - base) << 61;
  w3 = (in[3] - base) >> 3;
  w3 |= (in[4] - base) << 60;
  w4 = (in[4] - base) >> 4;
  w4 |= (in[5] - base) << 59;
  w5 = (in[5] - base) >> 5;
  w5 |= (in[6] - base) << 58;
  w6 = (in[6] - base) >> 6;
  w6 |= (in[7] - base) << 57;
  w7 = (in[7] - base) >> 7;
  w7 |= (in[8] - base) << 56;
  w8 = (in[8] - base) >> 8;
  w8 |= (in[9] - base) << 55;
  w9 = (in[9] - base) >> 9;
  w9 |= (in[10] - base) << 54;
  w10 = (in[10] - base) >> 10;
  w10 |= (in[11] - base) << 53;
  w11 = (in[11] - base) >> 11;
  w11 |= (in[12] - base) << 52;
  w12 = (in[12] - base) >> 12;
  w12 |= (in[13] - base) << 51;
  w13 = (in[13] - base) >> 13;
  w13 |= (in[14] - base) << 50;
  w14 = (in[14] - base) >> 14;
  w14 |= (in[15] - base) << 49;
  w15 = (in[15] - base) >> 15;
  w15 |= (in[16] - base) << 48;
  w16 = (in[16] - base) >> 16;
  w16 |= (in[17] - base) << 47;
  w17 = (in[17] - base) >> 17;
  w17 |= (in[18] - base) << 46;
  w18 = (in[18] - base) >> 18;
  w18 |= (in[19] - base) << 45;
  w19 = (in[19] - base) >> 19;
  w19 |= (in[20] - base) << 44;
  w20 = (in[20] - base) >> 20;
  w20 |= (in[21] - base) << 43;
  w21 = (in[21] - base) >> 21;
  w21 |= (in[22] - base) << 42;
  w22 = (in[22] - base) >> 22;
  w22 |= (in[23] - base) << 41;
  w23 = (in[23] - base) >> 23;
  w23 |= (in[24] - base) << 40;
  w24 = (in[24] - base) >> 24;
  w24 |= (in[25] - base) << 39;
  w25 = (in[25] - base) >> 25;
  w25 |= (in[26] - base) << 38;
  w26 = (in[26] - base) >> 26;
  w26 |= (in[27] - base) << 37;
  w27 = (in[27] - base) >> 27;
  w27 |= (in[28] - base) << 36;
  w28 = (in[28] - base) >> 28;
  w28 |= (in[29] - base) << 35;
  w29 = (in[29] - base) >> 29;
  w29 |= (in[30] - base) << 34;
  w30 = (in[30] - base) >> 30;
  w30 |= (in[31] - base) << 33;
  w31 = (in[31] - base) >> 31;
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  pw64[28] = w28;
  pw64[29] = w29;
  pw64[30] = w30;
  pw64[31] = w31;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 252; /* we used up 252 output bytes */ 
}


/* we are going to pack 32 64-bit values, touching 32 64-bit words, using 256 bytes */ 
static void packforblock64_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint64_t * in = *pin;
  /* we are going to touch  32 64-bit words */ 
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
  uint64_t w16;
  uint64_t w17;
  uint64_t w18;
  uint64_t w19;
  uint64_t w20;
  uint64_t w21;
  uint64_t w22;
  uint64_t w23;
  uint64_t w24;
  uint64_t w25;
  uint64_t w26;
  uint64_t w27;
  uint64_t w28;
  uint64_t w29;
  uint64_t w30;
  uint64_t w31;
  w0 = (in[0] - base);
  w1 = (in[1] - base);
  w2 = (in[2] - base);
  w3 = (in[3] - base);
  w4 = (in[4] - base);
  w5 = (in[5] - base);
  w6 = (in[6] - base);
  w7 = (in[7] - base);
  w8 = (in[8] - base);
  w9 = (in[9] - base);
  w10 = (in[10] - base);
  w11 = (in[11] - base);
  w12 = (in[12] - base);
  w13 = (in[13] - base);
  w14 = (in[14] - base);
  w15 = (in[15] - base);
  w16 = (in[16] - base);
  w17 = (in[17] - base);
  w18 = (in[18] - base);
  w19 = (in[19] - base);
  w20 = (in[20] - base);
  w21 = (in[21] - base);
  w22 = (in[22] - base);
  w23 = (in[23] - base);
  w24 = (in[24] - base);
  w25 = (in[25] - base);
  w26 = (in[26] - base);
  w27 = (in[27] - base);
  w28 = (in[28] - base);
  w29 = (in[29] - base);
  w30 = (in[30] - base);
  w31 = (in[31] - base);
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
  pw64[16] = w16;
  pw64[17] = w17;
  pw64[18] = w18;
  pw64[19] = w19;
  pw64[20] = w20;
  pw64[21] = w21;
  pw64[22] = w22;
  pw64[23] = w23;
  pw64[24] = w24;
  pw64[25] = w25;
  pw64[26] = w26;
  pw64[27] = w27;
  pw64[28] = w28;
  pw64[29] = w29;
  pw64[30] = w30;
  pw64[31] = w31;
  *pin += 32; /* we consumed 32 64-bit integers */ 
  *pw += 256; /* we used up 256 output bytes */ 
}

static void unpackforblock0_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  (void) pw;
  for(int k = 0; k < 32 ; k+= 1) {
    (*pout) [k] = base;
  }
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 1-bit values, touching 1 64-bit words, using 4 bytes */ 
static void unpackforblock1_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(1);
  /* we are going to access  1 64-bit word */ 
  uint64_t w0 = pw64[0];
  *pw += 4; /* we used up 4 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 1 )  & mask  );
  out[2] = base + ( ( w0 >> 2 )  & mask  );
  out[3] = base + ( ( w0 >> 3 )  & mask  );
  out[4] = base + ( ( w0 >> 4 )  & mask  );
  out[5] = base + ( ( w0 >> 5 )  & mask  );
  out[6] = base + ( ( w0 >> 6 )  & mask  );
  out[7] = base + ( ( w0 >> 7 )  & mask  );
  out[8] = base + ( ( w0 >> 8 )  & mask  );
  out[9] = base + ( ( w0 >> 9 )  & mask  );
  out[10] = base + ( ( w0 >> 10 )  & mask  );
  out[11] = base + ( ( w0 >> 11 )  & mask  );
  out[12] = base + ( ( w0 >> 12 )  & mask  );
  out[13] = base + ( ( w0 >> 13 )  & mask  );
  out[14] = base + ( ( w0 >> 14 )  & mask  );
  out[15] = base + ( ( w0 >> 15 )  & mask  );
  out[16] = base + ( ( w0 >> 16 )  & mask  );
  out[17] = base + ( ( w0 >> 17 )  & mask  );
  out[18] = base + ( ( w0 >> 18 )  & mask  );
  out[19] = base + ( ( w0 >> 19 )  & mask  );
  out[20] = base + ( ( w0 >> 20 )  & mask  );
  out[21] = base + ( ( w0 >> 21 )  & mask  );
  out[22] = base + ( ( w0 >> 22 )  & mask  );
  out[23] = base + ( ( w0 >> 23 )  & mask  );
  out[24] = base + ( ( w0 >> 24 )  & mask  );
  out[25] = base + ( ( w0 >> 25 )  & mask  );
  out[26] = base + ( ( w0 >> 26 )  & mask  );
  out[27] = base + ( ( w0 >> 27 )  & mask  );
  out[28] = base + ( ( w0 >> 28 )  & mask  );
  out[29] = base + ( ( w0 >> 29 )  & mask  );
  out[30] = base + ( ( w0 >> 30 )  & mask  );
  out[31] = base + ( ( w0 >> 31 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 2-bit values, touching 1 64-bit words, using 8 bytes */ 
static void unpackforblock2_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(3);
  /* we are going to access  1 64-bit word */ 
  uint64_t w0 = pw64[0];
  *pw += 8; /* we used up 8 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 2 )  & mask  );
  out[2] = base + ( ( w0 >> 4 )  & mask  );
  out[3] = base + ( ( w0 >> 6 )  & mask  );
  out[4] = base + ( ( w0 >> 8 )  & mask  );
  out[5] = base + ( ( w0 >> 10 )  & mask  );
  out[6] = base + ( ( w0 >> 12 )  & mask  );
  out[7] = base + ( ( w0 >> 14 )  & mask  );
  out[8] = base + ( ( w0 >> 16 )  & mask  );
  out[9] = base + ( ( w0 >> 18 )  & mask  );
  out[10] = base + ( ( w0 >> 20 )  & mask  );
  out[11] = base + ( ( w0 >> 22 )  & mask  );
  out[12] = base + ( ( w0 >> 24 )  & mask  );
  out[13] = base + ( ( w0 >> 26 )  & mask  );
  out[14] = base + ( ( w0 >> 28 )  & mask  );
  out[15] = base + ( ( w0 >> 30 )  & mask  );
  out[16] = base + ( ( w0 >> 32 )  & mask  );
  out[17] = base + ( ( w0 >> 34 )  & mask  );
  out[18] = base + ( ( w0 >> 36 )  & mask  );
  out[19] = base + ( ( w0 >> 38 )  & mask  );
  out[20] = base + ( ( w0 >> 40 )  & mask  );
  out[21] = base + ( ( w0 >> 42 )  & mask  );
  out[22] = base + ( ( w0 >> 44 )  & mask  );
  out[23] = base + ( ( w0 >> 46 )  & mask  );
  out[24] = base + ( ( w0 >> 48 )  & mask  );
  out[25] = base + ( ( w0 >> 50 )  & mask  );
  out[26] = base + ( ( w0 >> 52 )  & mask  );
  out[27] = base + ( ( w0 >> 54 )  & mask  );
  out[28] = base + ( ( w0 >> 56 )  & mask  );
  out[29] = base + ( ( w0 >> 58 )  & mask  );
  out[30] = base + ( ( w0 >> 60 )  & mask  );
  out[31] = base + ( w0  >> 62  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 3-bit values, touching 2 64-bit words, using 12 bytes */ 
static void unpackforblock3_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(7);
  /* we are going to access  2 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  *pw += 12; /* we used up 12 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 3 )  & mask  );
  out[2] = base + ( ( w0 >> 6 )  & mask  );
  out[3] = base + ( ( w0 >> 9 )  & mask  );
  out[4] = base + ( ( w0 >> 12 )  & mask  );
  out[5] = base + ( ( w0 >> 15 )  & mask  );
  out[6] = base + ( ( w0 >> 18 )  & mask  );
  out[7] = base + ( ( w0 >> 21 )  & mask  );
  out[8] = base + ( ( w0 >> 24 )  & mask  );
  out[9] = base + ( ( w0 >> 27 )  & mask  );
  out[10] = base + ( ( w0 >> 30 )  & mask  );
  out[11] = base + ( ( w0 >> 33 )  & mask  );
  out[12] = base + ( ( w0 >> 36 )  & mask  );
  out[13] = base + ( ( w0 >> 39 )  & mask  );
  out[14] = base + ( ( w0 >> 42 )  & mask  );
  out[15] = base + ( ( w0 >> 45 )  & mask  );
  out[16] = base + ( ( w0 >> 48 )  & mask  );
  out[17] = base + ( ( w0 >> 51 )  & mask  );
  out[18] = base + ( ( w0 >> 54 )  & mask  );
  out[19] = base + ( ( w0 >> 57 )  & mask  );
  out[20] = base + ( ( w0 >> 60 )  & mask  );
  out[21] = base + ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
  out[22] = base + ( ( w1 >> 2 )  & mask  );
  out[23] = base + ( ( w1 >> 5 )  & mask  );
  out[24] = base + ( ( w1 >> 8 )  & mask  );
  out[25] = base + ( ( w1 >> 11 )  & mask  );
  out[26] = base + ( ( w1 >> 14 )  & mask  );
  out[27] = base + ( ( w1 >> 17 )  & mask  );
  out[28] = base + ( ( w1 >> 20 )  & mask  );
  out[29] = base + ( ( w1 >> 23 )  & mask  );
  out[30] = base + ( ( w1 >> 26 )  & mask  );
  out[31] = base + ( ( w1 >> 29 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 4-bit values, touching 2 64-bit words, using 16 bytes */ 
static void unpackforblock4_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(15);
  /* we are going to access  2 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  *pw += 16; /* we used up 16 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 4 )  & mask  );
  out[2] = base + ( ( w0 >> 8 )  & mask  );
  out[3] = base + ( ( w0 >> 12 )  & mask  );
  out[4] = base + ( ( w0 >> 16 )  & mask  );
  out[5] = base + ( ( w0 >> 20 )  & mask  );
  out[6] = base + ( ( w0 >> 24 )  & mask  );
  out[7] = base + ( ( w0 >> 28 )  & mask  );
  out[8] = base + ( ( w0 >> 32 )  & mask  );
  out[9] = base + ( ( w0 >> 36 )  & mask  );
  out[10] = base + ( ( w0 >> 40 )  & mask  );
  out[11] = base + ( ( w0 >> 44 )  & mask  );
  out[12] = base + ( ( w0 >> 48 )  & mask  );
  out[13] = base + ( ( w0 >> 52 )  & mask  );
  out[14] = base + ( ( w0 >> 56 )  & mask  );
  out[15] = base + ( w0  >> 60  );
  out[16] = base + ( ( w1 )  & mask  );
  out[17] = base + ( ( w1 >> 4 )  & mask  );
  out[18] = base + ( ( w1 >> 8 )  & mask  );
  out[19] = base + ( ( w1 >> 12 )  & mask  );
  out[20] = base + ( ( w1 >> 16 )  & mask  );
  out[21] = base + ( ( w1 >> 20 )  & mask  );
  out[22] = base + ( ( w1 >> 24 )  & mask  );
  out[23] = base + ( ( w1 >> 28 )  & mask  );
  out[24] = base + ( ( w1 >> 32 )  & mask  );
  out[25] = base + ( ( w1 >> 36 )  & mask  );
  out[26] = base + ( ( w1 >> 40 )  & mask  );
  out[27] = base + ( ( w1 >> 44 )  & mask  );
  out[28] = base + ( ( w1 >> 48 )  & mask  );
  out[29] = base + ( ( w1 >> 52 )  & mask  );
  out[30] = base + ( ( w1 >> 56 )  & mask  );
  out[31] = base + ( w1  >> 60  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 5-bit values, touching 3 64-bit words, using 20 bytes */ 
static void unpackforblock5_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(31);
  /* we are going to access  3 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  *pw += 20; /* we used up 20 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 5 )  & mask  );
  out[2] = base + ( ( w0 >> 10 )  & mask  );
  out[3] = base + ( ( w0 >> 15 )  & mask  );
  out[4] = base + ( ( w0 >> 20 )  & mask  );
  out[5] = base + ( ( w0 >> 25 )  & mask  );
  out[6] = base + ( ( w0 >> 30 )  & mask  );
  out[7] = base + ( ( w0 >> 35 )  & mask  );
  out[8] = base + ( ( w0 >> 40 )  & mask  );
  out[9] = base + ( ( w0 >> 45 )  & mask  );
  out[10] = base + ( ( w0 >> 50 )  & mask  );
  out[11] = base + ( ( w0 >> 55 )  & mask  );
  out[12] = base + ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
  out[13] = base + ( ( w1 >> 1 )  & mask  );
  out[14] = base + ( ( w1 >> 6 )  & mask  );
  out[15] = base + ( ( w1 >> 11 )  & mask  );
  out[16] = base + ( ( w1 >> 16 )  & mask  );
  out[17] = base + ( ( w1 >> 21 )  & mask  );
  out[18] = base + ( ( w1 >> 26 )  & mask  );
  out[19] = base + ( ( w1 >> 31 )  & mask  );
  out[20] = base + ( ( w1 >> 36 )  & mask  );
  out[21] = base + ( ( w1 >> 41 )  & mask  );
  out[22] = base + ( ( w1 >> 46 )  & mask  );
  out[23] = base + ( ( w1 >> 51 )  & mask  );
  out[24] = base + ( ( w1 >> 56 )  & mask  );
  out[25] = base + ( ( ( w1 >> 61  ) | ( w2 << 3 ) )  & mask  );
  out[26] = base + ( ( w2 >> 2 )  & mask  );
  out[27] = base + ( ( w2 >> 7 )  & mask  );
  out[28] = base + ( ( w2 >> 12 )  & mask  );
  out[29] = base + ( ( w2 >> 17 )  & mask  );
  out[30] = base + ( ( w2 >> 22 )  & mask  );
  out[31] = base + ( ( w2 >> 27 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 6-bit values, touching 3 64-bit words, using 24 bytes */ 
static void unpackforblock6_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(63);
  /* we are going to access  3 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  *pw += 24; /* we used up 24 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 6 )  & mask  );
  out[2] = base + ( ( w0 >> 12 )  & mask  );
  out[3] = base + ( ( w0 >> 18 )  & mask  );
  out[4] = base + ( ( w0 >> 24 )  & mask  );
  out[5] = base + ( ( w0 >> 30 )  & mask  );
  out[6] = base + ( ( w0 >> 36 )  & mask  );
  out[7] = base + ( ( w0 >> 42 )  & mask  );
  out[8] = base + ( ( w0 >> 48 )  & mask  );
  out[9] = base + ( ( w0 >> 54 )  & mask  );
  out[10] = base + ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
  out[11] = base + ( ( w1 >> 2 )  & mask  );
  out[12] = base + ( ( w1 >> 8 )  & mask  );
  out[13] = base + ( ( w1 >> 14 )  & mask  );
  out[14] = base + ( ( w1 >> 20 )  & mask  );
  out[15] = base + ( ( w1 >> 26 )  & mask  );
  out[16] = base + ( ( w1 >> 32 )  & mask  );
  out[17] = base + ( ( w1 >> 38 )  & mask  );
  out[18] = base + ( ( w1 >> 44 )  & mask  );
  out[19] = base + ( ( w1 >> 50 )  & mask  );
  out[20] = base + ( ( w1 >> 56 )  & mask  );
  out[21] = base + ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
  out[22] = base + ( ( w2 >> 4 )  & mask  );
  out[23] = base + ( ( w2 >> 10 )  & mask  );
  out[24] = base + ( ( w2 >> 16 )  & mask  );
  out[25] = base + ( ( w2 >> 22 )  & mask  );
  out[26] = base + ( ( w2 >> 28 )  & mask  );
  out[27] = base + ( ( w2 >> 34 )  & mask  );
  out[28] = base + ( ( w2 >> 40 )  & mask  );
  out[29] = base + ( ( w2 >> 46 )  & mask  );
  out[30] = base + ( ( w2 >> 52 )  & mask  );
  out[31] = base + ( w2  >> 58  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 7-bit values, touching 4 64-bit words, using 28 bytes */ 
static void unpackforblock7_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(127);
  /* we are going to access  4 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  *pw += 28; /* we used up 28 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 7 )  & mask  );
  out[2] = base + ( ( w0 >> 14 )  & mask  );
  out[3] = base + ( ( w0 >> 21 )  & mask  );
  out[4] = base + ( ( w0 >> 28 )  & mask  );
  out[5] = base + ( ( w0 >> 35 )  & mask  );
  out[6] = base + ( ( w0 >> 42 )  & mask  );
  out[7] = base + ( ( w0 >> 49 )  & mask  );
  out[8] = base + ( ( w0 >> 56 )  & mask  );
  out[9] = base + ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
  out[10] = base + ( ( w1 >> 6 )  & mask  );
  out[11] = base + ( ( w1 >> 13 )  & mask  );
  out[12] = base + ( ( w1 >> 20 )  & mask  );
  out[13] = base + ( ( w1 >> 27 )  & mask  );
  out[14] = base + ( ( w1 >> 34 )  & mask  );
  out[15] = base + ( ( w1 >> 41 )  & mask  );
  out[16] = base + ( ( w1 >> 48 )  & mask  );
  out[17] = base + ( ( w1 >> 55 )  & mask  );
  out[18] = base + ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
  out[19] = base + ( ( w2 >> 5 )  & mask  );
  out[20] = base + ( ( w2 >> 12 )  & mask  );
  out[21] = base + ( ( w2 >> 19 )  & mask  );
  out[22] = base + ( ( w2 >> 26 )  & mask  );
  out[23] = base + ( ( w2 >> 33 )  & mask  );
  out[24] = base + ( ( w2 >> 40 )  & mask  );
  out[25] = base + ( ( w2 >> 47 )  & mask  );
  out[26] = base + ( ( w2 >> 54 )  & mask  );
  out[27] = base + ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
  out[28] = base + ( ( w3 >> 4 )  & mask  );
  out[29] = base + ( ( w3 >> 11 )  & mask  );
  out[30] = base + ( ( w3 >> 18 )  & mask  );
  out[31] = base + ( ( w3 >> 25 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 8-bit values, touching 4 64-bit words, using 32 bytes */ 
static void unpackforblock8_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(255);
  /* we are going to access  4 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  *pw += 32; /* we used up 32 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 8 )  & mask  );
  out[2] = base + ( ( w0 >> 16 )  & mask  );
  out[3] = base + ( ( w0 >> 24 )  & mask  );
  out[4] = base + ( ( w0 >> 32 )  & mask  );
  out[5] = base + ( ( w0 >> 40 )  & mask  );
  out[6] = base + ( ( w0 >> 48 )  & mask  );
  out[7] = base + ( w0  >> 56  );
  out[8] = base + ( ( w1 )  & mask  );
  out[9] = base + ( ( w1 >> 8 )  & mask  );
  out[10] = base + ( ( w1 >> 16 )  & mask  );
  out[11] = base + ( ( w1 >> 24 )  & mask  );
  out[12] = base + ( ( w1 >> 32 )  & mask  );
  out[13] = base + ( ( w1 >> 40 )  & mask  );
  out[14] = base + ( ( w1 >> 48 )  & mask  );
  out[15] = base + ( w1  >> 56  );
  out[16] = base + ( ( w2 )  & mask  );
  out[17] = base + ( ( w2 >> 8 )  & mask  );
  out[18] = base + ( ( w2 >> 16 )  & mask  );
  out[19] = base + ( ( w2 >> 24 )  & mask  );
  out[20] = base + ( ( w2 >> 32 )  & mask  );
  out[21] = base + ( ( w2 >> 40 )  & mask  );
  out[22] = base + ( ( w2 >> 48 )  & mask  );
  out[23] = base + ( w2  >> 56  );
  out[24] = base + ( ( w3 )  & mask  );
  out[25] = base + ( ( w3 >> 8 )  & mask  );
  out[26] = base + ( ( w3 >> 16 )  & mask  );
  out[27] = base + ( ( w3 >> 24 )  & mask  );
  out[28] = base + ( ( w3 >> 32 )  & mask  );
  out[29] = base + ( ( w3 >> 40 )  & mask  );
  out[30] = base + ( ( w3 >> 48 )  & mask  );
  out[31] = base + ( w3  >> 56  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 9-bit values, touching 5 64-bit words, using 36 bytes */ 
static void unpackforblock9_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(511);
  /* we are going to access  5 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  *pw += 36; /* we used up 36 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 9 )  & mask  );
  out[2] = base + ( ( w0 >> 18 )  & mask  );
  out[3] = base + ( ( w0 >> 27 )  & mask  );
  out[4] = base + ( ( w0 >> 36 )  & mask  );
  out[5] = base + ( ( w0 >> 45 )  & mask  );
  out[6] = base + ( ( w0 >> 54 )  & mask  );
  out[7] = base + ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
  out[8] = base + ( ( w1 >> 8 )  & mask  );
  out[9] = base + ( ( w1 >> 17 )  & mask  );
  out[10] = base + ( ( w1 >> 26 )  & mask  );
  out[11] = base + ( ( w1 >> 35 )  & mask  );
  out[12] = base + ( ( w1 >> 44 )  & mask  );
  out[13] = base + ( ( w1 >> 53 )  & mask  );
  out[14] = base + ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
  out[15] = base + ( ( w2 >> 7 )  & mask  );
  out[16] = base + ( ( w2 >> 16 )  & mask  );
  out[17] = base + ( ( w2 >> 25 )  & mask  );
  out[18] = base + ( ( w2 >> 34 )  & mask  );
  out[19] = base + ( ( w2 >> 43 )  & mask  );
  out[20] = base + ( ( w2 >> 52 )  & mask  );
  out[21] = base + ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
  out[22] = base + ( ( w3 >> 6 )  & mask  );
  out[23] = base + ( ( w3 >> 15 )  & mask  );
  out[24] = base + ( ( w3 >> 24 )  & mask  );
  out[25] = base + ( ( w3 >> 33 )  & mask  );
  out[26] = base + ( ( w3 >> 42 )  & mask  );
  out[27] = base + ( ( w3 >> 51 )  & mask  );
  out[28] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[29] = base + ( ( w4 >> 5 )  & mask  );
  out[30] = base + ( ( w4 >> 14 )  & mask  );
  out[31] = base + ( ( w4 >> 23 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 10-bit values, touching 5 64-bit words, using 40 bytes */ 
static void unpackforblock10_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(1023);
  /* we are going to access  5 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  *pw += 40; /* we used up 40 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 10 )  & mask  );
  out[2] = base + ( ( w0 >> 20 )  & mask  );
  out[3] = base + ( ( w0 >> 30 )  & mask  );
  out[4] = base + ( ( w0 >> 40 )  & mask  );
  out[5] = base + ( ( w0 >> 50 )  & mask  );
  out[6] = base + ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
  out[7] = base + ( ( w1 >> 6 )  & mask  );
  out[8] = base + ( ( w1 >> 16 )  & mask  );
  out[9] = base + ( ( w1 >> 26 )  & mask  );
  out[10] = base + ( ( w1 >> 36 )  & mask  );
  out[11] = base + ( ( w1 >> 46 )  & mask  );
  out[12] = base + ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
  out[13] = base + ( ( w2 >> 2 )  & mask  );
  out[14] = base + ( ( w2 >> 12 )  & mask  );
  out[15] = base + ( ( w2 >> 22 )  & mask  );
  out[16] = base + ( ( w2 >> 32 )  & mask  );
  out[17] = base + ( ( w2 >> 42 )  & mask  );
  out[18] = base + ( ( w2 >> 52 )  & mask  );
  out[19] = base + ( ( ( w2 >> 62  ) | ( w3 << 2 ) )  & mask  );
  out[20] = base + ( ( w3 >> 8 )  & mask  );
  out[21] = base + ( ( w3 >> 18 )  & mask  );
  out[22] = base + ( ( w3 >> 28 )  & mask  );
  out[23] = base + ( ( w3 >> 38 )  & mask  );
  out[24] = base + ( ( w3 >> 48 )  & mask  );
  out[25] = base + ( ( ( w3 >> 58  ) | ( w4 << 6 ) )  & mask  );
  out[26] = base + ( ( w4 >> 4 )  & mask  );
  out[27] = base + ( ( w4 >> 14 )  & mask  );
  out[28] = base + ( ( w4 >> 24 )  & mask  );
  out[29] = base + ( ( w4 >> 34 )  & mask  );
  out[30] = base + ( ( w4 >> 44 )  & mask  );
  out[31] = base + ( w4  >> 54  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 11-bit values, touching 6 64-bit words, using 44 bytes */ 
static void unpackforblock11_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(2047);
  /* we are going to access  6 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  *pw += 44; /* we used up 44 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 11 )  & mask  );
  out[2] = base + ( ( w0 >> 22 )  & mask  );
  out[3] = base + ( ( w0 >> 33 )  & mask  );
  out[4] = base + ( ( w0 >> 44 )  & mask  );
  out[5] = base + ( ( ( w0 >> 55  ) | ( w1 << 9 ) )  & mask  );
  out[6] = base + ( ( w1 >> 2 )  & mask  );
  out[7] = base + ( ( w1 >> 13 )  & mask  );
  out[8] = base + ( ( w1 >> 24 )  & mask  );
  out[9] = base + ( ( w1 >> 35 )  & mask  );
  out[10] = base + ( ( w1 >> 46 )  & mask  );
  out[11] = base + ( ( ( w1 >> 57  ) | ( w2 << 7 ) )  & mask  );
  out[12] = base + ( ( w2 >> 4 )  & mask  );
  out[13] = base + ( ( w2 >> 15 )  & mask  );
  out[14] = base + ( ( w2 >> 26 )  & mask  );
  out[15] = base + ( ( w2 >> 37 )  & mask  );
  out[16] = base + ( ( w2 >> 48 )  & mask  );
  out[17] = base + ( ( ( w2 >> 59  ) | ( w3 << 5 ) )  & mask  );
  out[18] = base + ( ( w3 >> 6 )  & mask  );
  out[19] = base + ( ( w3 >> 17 )  & mask  );
  out[20] = base + ( ( w3 >> 28 )  & mask  );
  out[21] = base + ( ( w3 >> 39 )  & mask  );
  out[22] = base + ( ( w3 >> 50 )  & mask  );
  out[23] = base + ( ( ( w3 >> 61  ) | ( w4 << 3 ) )  & mask  );
  out[24] = base + ( ( w4 >> 8 )  & mask  );
  out[25] = base + ( ( w4 >> 19 )  & mask  );
  out[26] = base + ( ( w4 >> 30 )  & mask  );
  out[27] = base + ( ( w4 >> 41 )  & mask  );
  out[28] = base + ( ( w4 >> 52 )  & mask  );
  out[29] = base + ( ( ( w4 >> 63  ) | ( w5 << 1 ) )  & mask  );
  out[30] = base + ( ( w5 >> 10 )  & mask  );
  out[31] = base + ( ( w5 >> 21 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 12-bit values, touching 6 64-bit words, using 48 bytes */ 
static void unpackforblock12_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(4095);
  /* we are going to access  6 64-bit words */ 
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  uint64_t w4 = pw64[4];
  uint64_t w5 = pw64[5];
  *pw += 48; /* we used up 48 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 12 )  & mask  );
  out[2] = base + ( ( w0 >> 24 )  & mask  );
  out[3] = base + ( ( w0 >> 36 )  & mask  );
  out[4] = base + ( ( w0 >> 48 )  & mask  );
  out[5] = base + ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
  out[6] = base + ( ( w1 >> 8 )  & mask  );
  out[7] = base + ( ( w1 >> 20 )  & mask  );
  out[8] = base + ( ( w1 >> 32 )  & mask  );
  out[9] = base + ( ( w1 >> 44 )  & mask  );
  out[10] = base + ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
  out[11] = base + ( ( w2 >> 4 )  & mask  );
  out[12] = base + ( ( w2 >> 16 )  & mask  );
  out[13] = base + ( ( w2 >> 28 )  & mask  );
  out[14] = base + ( ( w2 >> 40 )  & mask  );
  out[15] = base + ( w2  >> 52  );
  out[16] = base + ( ( w3 )  & mask  );
  out[17] = base + ( ( w3 >> 12 )  & mask  );
  out[18] = base + ( ( w3 >> 24 )  & mask  );
  out[19] = base + ( ( w3 >> 36 )  & mask  );
  out[20] = base + ( ( w3 >> 48 )  & mask  );
  out[21] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[22] = base + ( ( w4 >> 8 )  & mask  );
  out[23] = base + ( ( w4 >> 20 )  & mask  );
  out[24] = base + ( ( w4 >> 32 )  & mask  );
  out[25] = base + ( ( w4 >> 44 )  & mask  );
  out[26] = base + ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
  out[27] = base + ( ( w5 >> 4 )  & mask  );
  out[28] = base + ( ( w5 >> 16 )  & mask  );
  out[29] = base + ( ( w5 >> 28 )  & mask  );
  out[30] = base + ( ( w5 >> 40 )  & mask  );
  out[31] = base + ( w5  >> 52  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 13-bit values, touching 7 64-bit words, using 52 bytes */ 
static void unpackforblock13_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 13 )  & mask  );
  out[2] = base + ( ( w0 >> 26 )  & mask  );
  out[3] = base + ( ( w0 >> 39 )  & mask  );
  out[4] = base + ( ( ( w0 >> 52  ) | ( w1 << 12 ) )  & mask  );
  out[5] = base + ( ( w1 >> 1 )  & mask  );
  out[6] = base + ( ( w1 >> 14 )  & mask  );
  out[7] = base + ( ( w1 >> 27 )  & mask  );
  out[8] = base + ( ( w1 >> 40 )  & mask  );
  out[9] = base + ( ( ( w1 >> 53  ) | ( w2 << 11 ) )  & mask  );
  out[10] = base + ( ( w2 >> 2 )  & mask  );
  out[11] = base + ( ( w2 >> 15 )  & mask  );
  out[12] = base + ( ( w2 >> 28 )  & mask  );
  out[13] = base + ( ( w2 >> 41 )  & mask  );
  out[14] = base + ( ( ( w2 >> 54  ) | ( w3 << 10 ) )  & mask  );
  out[15] = base + ( ( w3 >> 3 )  & mask  );
  out[16] = base + ( ( w3 >> 16 )  & mask  );
  out[17] = base + ( ( w3 >> 29 )  & mask  );
  out[18] = base + ( ( w3 >> 42 )  & mask  );
  out[19] = base + ( ( ( w3 >> 55  ) | ( w4 << 9 ) )  & mask  );
  out[20] = base + ( ( w4 >> 4 )  & mask  );
  out[21] = base + ( ( w4 >> 17 )  & mask  );
  out[22] = base + ( ( w4 >> 30 )  & mask  );
  out[23] = base + ( ( w4 >> 43 )  & mask  );
  out[24] = base + ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
  out[25] = base + ( ( w5 >> 5 )  & mask  );
  out[26] = base + ( ( w5 >> 18 )  & mask  );
  out[27] = base + ( ( w5 >> 31 )  & mask  );
  out[28] = base + ( ( w5 >> 44 )  & mask  );
  out[29] = base + ( ( ( w5 >> 57  ) | ( w6 << 7 ) )  & mask  );
  out[30] = base + ( ( w6 >> 6 )  & mask  );
  out[31] = base + ( ( w6 >> 19 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 14-bit values, touching 7 64-bit words, using 56 bytes */ 
static void unpackforblock14_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 14 )  & mask  );
  out[2] = base + ( ( w0 >> 28 )  & mask  );
  out[3] = base + ( ( w0 >> 42 )  & mask  );
  out[4] = base + ( ( ( w0 >> 56  ) | ( w1 << 8 ) )  & mask  );
  out[5] = base + ( ( w1 >> 6 )  & mask  );
  out[6] = base + ( ( w1 >> 20 )  & mask  );
  out[7] = base + ( ( w1 >> 34 )  & mask  );
  out[8] = base + ( ( w1 >> 48 )  & mask  );
  out[9] = base + ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
  out[10] = base + ( ( w2 >> 12 )  & mask  );
  out[11] = base + ( ( w2 >> 26 )  & mask  );
  out[12] = base + ( ( w2 >> 40 )  & mask  );
  out[13] = base + ( ( ( w2 >> 54  ) | ( w3 << 10 ) )  & mask  );
  out[14] = base + ( ( w3 >> 4 )  & mask  );
  out[15] = base + ( ( w3 >> 18 )  & mask  );
  out[16] = base + ( ( w3 >> 32 )  & mask  );
  out[17] = base + ( ( w3 >> 46 )  & mask  );
  out[18] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[19] = base + ( ( w4 >> 10 )  & mask  );
  out[20] = base + ( ( w4 >> 24 )  & mask  );
  out[21] = base + ( ( w4 >> 38 )  & mask  );
  out[22] = base + ( ( ( w4 >> 52  ) | ( w5 << 12 ) )  & mask  );
  out[23] = base + ( ( w5 >> 2 )  & mask  );
  out[24] = base + ( ( w5 >> 16 )  & mask  );
  out[25] = base + ( ( w5 >> 30 )  & mask  );
  out[26] = base + ( ( w5 >> 44 )  & mask  );
  out[27] = base + ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
  out[28] = base + ( ( w6 >> 8 )  & mask  );
  out[29] = base + ( ( w6 >> 22 )  & mask  );
  out[30] = base + ( ( w6 >> 36 )  & mask  );
  out[31] = base + ( w6  >> 50  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 15-bit values, touching 8 64-bit words, using 60 bytes */ 
static void unpackforblock15_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 15 )  & mask  );
  out[2] = base + ( ( w0 >> 30 )  & mask  );
  out[3] = base + ( ( w0 >> 45 )  & mask  );
  out[4] = base + ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
  out[5] = base + ( ( w1 >> 11 )  & mask  );
  out[6] = base + ( ( w1 >> 26 )  & mask  );
  out[7] = base + ( ( w1 >> 41 )  & mask  );
  out[8] = base + ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
  out[9] = base + ( ( w2 >> 7 )  & mask  );
  out[10] = base + ( ( w2 >> 22 )  & mask  );
  out[11] = base + ( ( w2 >> 37 )  & mask  );
  out[12] = base + ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
  out[13] = base + ( ( w3 >> 3 )  & mask  );
  out[14] = base + ( ( w3 >> 18 )  & mask  );
  out[15] = base + ( ( w3 >> 33 )  & mask  );
  out[16] = base + ( ( w3 >> 48 )  & mask  );
  out[17] = base + ( ( ( w3 >> 63  ) | ( w4 << 1 ) )  & mask  );
  out[18] = base + ( ( w4 >> 14 )  & mask  );
  out[19] = base + ( ( w4 >> 29 )  & mask  );
  out[20] = base + ( ( w4 >> 44 )  & mask  );
  out[21] = base + ( ( ( w4 >> 59  ) | ( w5 << 5 ) )  & mask  );
  out[22] = base + ( ( w5 >> 10 )  & mask  );
  out[23] = base + ( ( w5 >> 25 )  & mask  );
  out[24] = base + ( ( w5 >> 40 )  & mask  );
  out[25] = base + ( ( ( w5 >> 55  ) | ( w6 << 9 ) )  & mask  );
  out[26] = base + ( ( w6 >> 6 )  & mask  );
  out[27] = base + ( ( w6 >> 21 )  & mask  );
  out[28] = base + ( ( w6 >> 36 )  & mask  );
  out[29] = base + ( ( ( w6 >> 51  ) | ( w7 << 13 ) )  & mask  );
  out[30] = base + ( ( w7 >> 2 )  & mask  );
  out[31] = base + ( ( w7 >> 17 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 16-bit values, touching 8 64-bit words, using 64 bytes */ 
static void unpackforblock16_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 16 )  & mask  );
  out[2] = base + ( ( w0 >> 32 )  & mask  );
  out[3] = base + ( w0  >> 48  );
  out[4] = base + ( ( w1 )  & mask  );
  out[5] = base + ( ( w1 >> 16 )  & mask  );
  out[6] = base + ( ( w1 >> 32 )  & mask  );
  out[7] = base + ( w1  >> 48  );
  out[8] = base + ( ( w2 )  & mask  );
  out[9] = base + ( ( w2 >> 16 )  & mask  );
  out[10] = base + ( ( w2 >> 32 )  & mask  );
  out[11] = base + ( w2  >> 48  );
  out[12] = base + ( ( w3 )  & mask  );
  out[13] = base + ( ( w3 >> 16 )  & mask  );
  out[14] = base + ( ( w3 >> 32 )  & mask  );
  out[15] = base + ( w3  >> 48  );
  out[16] = base + ( ( w4 )  & mask  );
  out[17] = base + ( ( w4 >> 16 )  & mask  );
  out[18] = base + ( ( w4 >> 32 )  & mask  );
  out[19] = base + ( w4  >> 48  );
  out[20] = base + ( ( w5 )  & mask  );
  out[21] = base + ( ( w5 >> 16 )  & mask  );
  out[22] = base + ( ( w5 >> 32 )  & mask  );
  out[23] = base + ( w5  >> 48  );
  out[24] = base + ( ( w6 )  & mask  );
  out[25] = base + ( ( w6 >> 16 )  & mask  );
  out[26] = base + ( ( w6 >> 32 )  & mask  );
  out[27] = base + ( w6  >> 48  );
  out[28] = base + ( ( w7 )  & mask  );
  out[29] = base + ( ( w7 >> 16 )  & mask  );
  out[30] = base + ( ( w7 >> 32 )  & mask  );
  out[31] = base + ( w7  >> 48  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 17-bit values, touching 9 64-bit words, using 68 bytes */ 
static void unpackforblock17_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 17 )  & mask  );
  out[2] = base + ( ( w0 >> 34 )  & mask  );
  out[3] = base + ( ( ( w0 >> 51  ) | ( w1 << 13 ) )  & mask  );
  out[4] = base + ( ( w1 >> 4 )  & mask  );
  out[5] = base + ( ( w1 >> 21 )  & mask  );
  out[6] = base + ( ( w1 >> 38 )  & mask  );
  out[7] = base + ( ( ( w1 >> 55  ) | ( w2 << 9 ) )  & mask  );
  out[8] = base + ( ( w2 >> 8 )  & mask  );
  out[9] = base + ( ( w2 >> 25 )  & mask  );
  out[10] = base + ( ( w2 >> 42 )  & mask  );
  out[11] = base + ( ( ( w2 >> 59  ) | ( w3 << 5 ) )  & mask  );
  out[12] = base + ( ( w3 >> 12 )  & mask  );
  out[13] = base + ( ( w3 >> 29 )  & mask  );
  out[14] = base + ( ( w3 >> 46 )  & mask  );
  out[15] = base + ( ( ( w3 >> 63  ) | ( w4 << 1 ) )  & mask  );
  out[16] = base + ( ( w4 >> 16 )  & mask  );
  out[17] = base + ( ( w4 >> 33 )  & mask  );
  out[18] = base + ( ( ( w4 >> 50  ) | ( w5 << 14 ) )  & mask  );
  out[19] = base + ( ( w5 >> 3 )  & mask  );
  out[20] = base + ( ( w5 >> 20 )  & mask  );
  out[21] = base + ( ( w5 >> 37 )  & mask  );
  out[22] = base + ( ( ( w5 >> 54  ) | ( w6 << 10 ) )  & mask  );
  out[23] = base + ( ( w6 >> 7 )  & mask  );
  out[24] = base + ( ( w6 >> 24 )  & mask  );
  out[25] = base + ( ( w6 >> 41 )  & mask  );
  out[26] = base + ( ( ( w6 >> 58  ) | ( w7 << 6 ) )  & mask  );
  out[27] = base + ( ( w7 >> 11 )  & mask  );
  out[28] = base + ( ( w7 >> 28 )  & mask  );
  out[29] = base + ( ( w7 >> 45 )  & mask  );
  out[30] = base + ( ( ( w7 >> 62  ) | ( w8 << 2 ) )  & mask  );
  out[31] = base + ( ( w8 >> 15 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 18-bit values, touching 9 64-bit words, using 72 bytes */ 
static void unpackforblock18_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 18 )  & mask  );
  out[2] = base + ( ( w0 >> 36 )  & mask  );
  out[3] = base + ( ( ( w0 >> 54  ) | ( w1 << 10 ) )  & mask  );
  out[4] = base + ( ( w1 >> 8 )  & mask  );
  out[5] = base + ( ( w1 >> 26 )  & mask  );
  out[6] = base + ( ( w1 >> 44 )  & mask  );
  out[7] = base + ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
  out[8] = base + ( ( w2 >> 16 )  & mask  );
  out[9] = base + ( ( w2 >> 34 )  & mask  );
  out[10] = base + ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
  out[11] = base + ( ( w3 >> 6 )  & mask  );
  out[12] = base + ( ( w3 >> 24 )  & mask  );
  out[13] = base + ( ( w3 >> 42 )  & mask  );
  out[14] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[15] = base + ( ( w4 >> 14 )  & mask  );
  out[16] = base + ( ( w4 >> 32 )  & mask  );
  out[17] = base + ( ( ( w4 >> 50  ) | ( w5 << 14 ) )  & mask  );
  out[18] = base + ( ( w5 >> 4 )  & mask  );
  out[19] = base + ( ( w5 >> 22 )  & mask  );
  out[20] = base + ( ( w5 >> 40 )  & mask  );
  out[21] = base + ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
  out[22] = base + ( ( w6 >> 12 )  & mask  );
  out[23] = base + ( ( w6 >> 30 )  & mask  );
  out[24] = base + ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
  out[25] = base + ( ( w7 >> 2 )  & mask  );
  out[26] = base + ( ( w7 >> 20 )  & mask  );
  out[27] = base + ( ( w7 >> 38 )  & mask  );
  out[28] = base + ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
  out[29] = base + ( ( w8 >> 10 )  & mask  );
  out[30] = base + ( ( w8 >> 28 )  & mask  );
  out[31] = base + ( w8  >> 46  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 19-bit values, touching 10 64-bit words, using 76 bytes */ 
static void unpackforblock19_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 19 )  & mask  );
  out[2] = base + ( ( w0 >> 38 )  & mask  );
  out[3] = base + ( ( ( w0 >> 57  ) | ( w1 << 7 ) )  & mask  );
  out[4] = base + ( ( w1 >> 12 )  & mask  );
  out[5] = base + ( ( w1 >> 31 )  & mask  );
  out[6] = base + ( ( ( w1 >> 50  ) | ( w2 << 14 ) )  & mask  );
  out[7] = base + ( ( w2 >> 5 )  & mask  );
  out[8] = base + ( ( w2 >> 24 )  & mask  );
  out[9] = base + ( ( w2 >> 43 )  & mask  );
  out[10] = base + ( ( ( w2 >> 62  ) | ( w3 << 2 ) )  & mask  );
  out[11] = base + ( ( w3 >> 17 )  & mask  );
  out[12] = base + ( ( w3 >> 36 )  & mask  );
  out[13] = base + ( ( ( w3 >> 55  ) | ( w4 << 9 ) )  & mask  );
  out[14] = base + ( ( w4 >> 10 )  & mask  );
  out[15] = base + ( ( w4 >> 29 )  & mask  );
  out[16] = base + ( ( ( w4 >> 48  ) | ( w5 << 16 ) )  & mask  );
  out[17] = base + ( ( w5 >> 3 )  & mask  );
  out[18] = base + ( ( w5 >> 22 )  & mask  );
  out[19] = base + ( ( w5 >> 41 )  & mask  );
  out[20] = base + ( ( ( w5 >> 60  ) | ( w6 << 4 ) )  & mask  );
  out[21] = base + ( ( w6 >> 15 )  & mask  );
  out[22] = base + ( ( w6 >> 34 )  & mask  );
  out[23] = base + ( ( ( w6 >> 53  ) | ( w7 << 11 ) )  & mask  );
  out[24] = base + ( ( w7 >> 8 )  & mask  );
  out[25] = base + ( ( w7 >> 27 )  & mask  );
  out[26] = base + ( ( ( w7 >> 46  ) | ( w8 << 18 ) )  & mask  );
  out[27] = base + ( ( w8 >> 1 )  & mask  );
  out[28] = base + ( ( w8 >> 20 )  & mask  );
  out[29] = base + ( ( w8 >> 39 )  & mask  );
  out[30] = base + ( ( ( w8 >> 58  ) | ( w9 << 6 ) )  & mask  );
  out[31] = base + ( ( w9 >> 13 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 20-bit values, touching 10 64-bit words, using 80 bytes */ 
static void unpackforblock20_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 20 )  & mask  );
  out[2] = base + ( ( w0 >> 40 )  & mask  );
  out[3] = base + ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
  out[4] = base + ( ( w1 >> 16 )  & mask  );
  out[5] = base + ( ( w1 >> 36 )  & mask  );
  out[6] = base + ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
  out[7] = base + ( ( w2 >> 12 )  & mask  );
  out[8] = base + ( ( w2 >> 32 )  & mask  );
  out[9] = base + ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
  out[10] = base + ( ( w3 >> 8 )  & mask  );
  out[11] = base + ( ( w3 >> 28 )  & mask  );
  out[12] = base + ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
  out[13] = base + ( ( w4 >> 4 )  & mask  );
  out[14] = base + ( ( w4 >> 24 )  & mask  );
  out[15] = base + ( w4  >> 44  );
  out[16] = base + ( ( w5 )  & mask  );
  out[17] = base + ( ( w5 >> 20 )  & mask  );
  out[18] = base + ( ( w5 >> 40 )  & mask  );
  out[19] = base + ( ( ( w5 >> 60  ) | ( w6 << 4 ) )  & mask  );
  out[20] = base + ( ( w6 >> 16 )  & mask  );
  out[21] = base + ( ( w6 >> 36 )  & mask  );
  out[22] = base + ( ( ( w6 >> 56  ) | ( w7 << 8 ) )  & mask  );
  out[23] = base + ( ( w7 >> 12 )  & mask  );
  out[24] = base + ( ( w7 >> 32 )  & mask  );
  out[25] = base + ( ( ( w7 >> 52  ) | ( w8 << 12 ) )  & mask  );
  out[26] = base + ( ( w8 >> 8 )  & mask  );
  out[27] = base + ( ( w8 >> 28 )  & mask  );
  out[28] = base + ( ( ( w8 >> 48  ) | ( w9 << 16 ) )  & mask  );
  out[29] = base + ( ( w9 >> 4 )  & mask  );
  out[30] = base + ( ( w9 >> 24 )  & mask  );
  out[31] = base + ( w9  >> 44  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 21-bit values, touching 11 64-bit words, using 84 bytes */ 
static void unpackforblock21_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 21 )  & mask  );
  out[2] = base + ( ( w0 >> 42 )  & mask  );
  out[3] = base + ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
  out[4] = base + ( ( w1 >> 20 )  & mask  );
  out[5] = base + ( ( w1 >> 41 )  & mask  );
  out[6] = base + ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
  out[7] = base + ( ( w2 >> 19 )  & mask  );
  out[8] = base + ( ( w2 >> 40 )  & mask  );
  out[9] = base + ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
  out[10] = base + ( ( w3 >> 18 )  & mask  );
  out[11] = base + ( ( w3 >> 39 )  & mask  );
  out[12] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[13] = base + ( ( w4 >> 17 )  & mask  );
  out[14] = base + ( ( w4 >> 38 )  & mask  );
  out[15] = base + ( ( ( w4 >> 59  ) | ( w5 << 5 ) )  & mask  );
  out[16] = base + ( ( w5 >> 16 )  & mask  );
  out[17] = base + ( ( w5 >> 37 )  & mask  );
  out[18] = base + ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
  out[19] = base + ( ( w6 >> 15 )  & mask  );
  out[20] = base + ( ( w6 >> 36 )  & mask  );
  out[21] = base + ( ( ( w6 >> 57  ) | ( w7 << 7 ) )  & mask  );
  out[22] = base + ( ( w7 >> 14 )  & mask  );
  out[23] = base + ( ( w7 >> 35 )  & mask  );
  out[24] = base + ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
  out[25] = base + ( ( w8 >> 13 )  & mask  );
  out[26] = base + ( ( w8 >> 34 )  & mask  );
  out[27] = base + ( ( ( w8 >> 55  ) | ( w9 << 9 ) )  & mask  );
  out[28] = base + ( ( w9 >> 12 )  & mask  );
  out[29] = base + ( ( w9 >> 33 )  & mask  );
  out[30] = base + ( ( ( w9 >> 54  ) | ( w10 << 10 ) )  & mask  );
  out[31] = base + ( ( w10 >> 11 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 22-bit values, touching 11 64-bit words, using 88 bytes */ 
static void unpackforblock22_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 22 )  & mask  );
  out[2] = base + ( ( ( w0 >> 44  ) | ( w1 << 20 ) )  & mask  );
  out[3] = base + ( ( w1 >> 2 )  & mask  );
  out[4] = base + ( ( w1 >> 24 )  & mask  );
  out[5] = base + ( ( ( w1 >> 46  ) | ( w2 << 18 ) )  & mask  );
  out[6] = base + ( ( w2 >> 4 )  & mask  );
  out[7] = base + ( ( w2 >> 26 )  & mask  );
  out[8] = base + ( ( ( w2 >> 48  ) | ( w3 << 16 ) )  & mask  );
  out[9] = base + ( ( w3 >> 6 )  & mask  );
  out[10] = base + ( ( w3 >> 28 )  & mask  );
  out[11] = base + ( ( ( w3 >> 50  ) | ( w4 << 14 ) )  & mask  );
  out[12] = base + ( ( w4 >> 8 )  & mask  );
  out[13] = base + ( ( w4 >> 30 )  & mask  );
  out[14] = base + ( ( ( w4 >> 52  ) | ( w5 << 12 ) )  & mask  );
  out[15] = base + ( ( w5 >> 10 )  & mask  );
  out[16] = base + ( ( w5 >> 32 )  & mask  );
  out[17] = base + ( ( ( w5 >> 54  ) | ( w6 << 10 ) )  & mask  );
  out[18] = base + ( ( w6 >> 12 )  & mask  );
  out[19] = base + ( ( w6 >> 34 )  & mask  );
  out[20] = base + ( ( ( w6 >> 56  ) | ( w7 << 8 ) )  & mask  );
  out[21] = base + ( ( w7 >> 14 )  & mask  );
  out[22] = base + ( ( w7 >> 36 )  & mask  );
  out[23] = base + ( ( ( w7 >> 58  ) | ( w8 << 6 ) )  & mask  );
  out[24] = base + ( ( w8 >> 16 )  & mask  );
  out[25] = base + ( ( w8 >> 38 )  & mask  );
  out[26] = base + ( ( ( w8 >> 60  ) | ( w9 << 4 ) )  & mask  );
  out[27] = base + ( ( w9 >> 18 )  & mask  );
  out[28] = base + ( ( w9 >> 40 )  & mask  );
  out[29] = base + ( ( ( w9 >> 62  ) | ( w10 << 2 ) )  & mask  );
  out[30] = base + ( ( w10 >> 20 )  & mask  );
  out[31] = base + ( w10  >> 42  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 23-bit values, touching 12 64-bit words, using 92 bytes */ 
static void unpackforblock23_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 23 )  & mask  );
  out[2] = base + ( ( ( w0 >> 46  ) | ( w1 << 18 ) )  & mask  );
  out[3] = base + ( ( w1 >> 5 )  & mask  );
  out[4] = base + ( ( w1 >> 28 )  & mask  );
  out[5] = base + ( ( ( w1 >> 51  ) | ( w2 << 13 ) )  & mask  );
  out[6] = base + ( ( w2 >> 10 )  & mask  );
  out[7] = base + ( ( w2 >> 33 )  & mask  );
  out[8] = base + ( ( ( w2 >> 56  ) | ( w3 << 8 ) )  & mask  );
  out[9] = base + ( ( w3 >> 15 )  & mask  );
  out[10] = base + ( ( w3 >> 38 )  & mask  );
  out[11] = base + ( ( ( w3 >> 61  ) | ( w4 << 3 ) )  & mask  );
  out[12] = base + ( ( w4 >> 20 )  & mask  );
  out[13] = base + ( ( ( w4 >> 43  ) | ( w5 << 21 ) )  & mask  );
  out[14] = base + ( ( w5 >> 2 )  & mask  );
  out[15] = base + ( ( w5 >> 25 )  & mask  );
  out[16] = base + ( ( ( w5 >> 48  ) | ( w6 << 16 ) )  & mask  );
  out[17] = base + ( ( w6 >> 7 )  & mask  );
  out[18] = base + ( ( w6 >> 30 )  & mask  );
  out[19] = base + ( ( ( w6 >> 53  ) | ( w7 << 11 ) )  & mask  );
  out[20] = base + ( ( w7 >> 12 )  & mask  );
  out[21] = base + ( ( w7 >> 35 )  & mask  );
  out[22] = base + ( ( ( w7 >> 58  ) | ( w8 << 6 ) )  & mask  );
  out[23] = base + ( ( w8 >> 17 )  & mask  );
  out[24] = base + ( ( w8 >> 40 )  & mask  );
  out[25] = base + ( ( ( w8 >> 63  ) | ( w9 << 1 ) )  & mask  );
  out[26] = base + ( ( w9 >> 22 )  & mask  );
  out[27] = base + ( ( ( w9 >> 45  ) | ( w10 << 19 ) )  & mask  );
  out[28] = base + ( ( w10 >> 4 )  & mask  );
  out[29] = base + ( ( w10 >> 27 )  & mask  );
  out[30] = base + ( ( ( w10 >> 50  ) | ( w11 << 14 ) )  & mask  );
  out[31] = base + ( ( w11 >> 9 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 24-bit values, touching 12 64-bit words, using 96 bytes */ 
static void unpackforblock24_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 24 )  & mask  );
  out[2] = base + ( ( ( w0 >> 48  ) | ( w1 << 16 ) )  & mask  );
  out[3] = base + ( ( w1 >> 8 )  & mask  );
  out[4] = base + ( ( w1 >> 32 )  & mask  );
  out[5] = base + ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
  out[6] = base + ( ( w2 >> 16 )  & mask  );
  out[7] = base + ( w2  >> 40  );
  out[8] = base + ( ( w3 )  & mask  );
  out[9] = base + ( ( w3 >> 24 )  & mask  );
  out[10] = base + ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
  out[11] = base + ( ( w4 >> 8 )  & mask  );
  out[12] = base + ( ( w4 >> 32 )  & mask  );
  out[13] = base + ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
  out[14] = base + ( ( w5 >> 16 )  & mask  );
  out[15] = base + ( w5  >> 40  );
  out[16] = base + ( ( w6 )  & mask  );
  out[17] = base + ( ( w6 >> 24 )  & mask  );
  out[18] = base + ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
  out[19] = base + ( ( w7 >> 8 )  & mask  );
  out[20] = base + ( ( w7 >> 32 )  & mask  );
  out[21] = base + ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
  out[22] = base + ( ( w8 >> 16 )  & mask  );
  out[23] = base + ( w8  >> 40  );
  out[24] = base + ( ( w9 )  & mask  );
  out[25] = base + ( ( w9 >> 24 )  & mask  );
  out[26] = base + ( ( ( w9 >> 48  ) | ( w10 << 16 ) )  & mask  );
  out[27] = base + ( ( w10 >> 8 )  & mask  );
  out[28] = base + ( ( w10 >> 32 )  & mask  );
  out[29] = base + ( ( ( w10 >> 56  ) | ( w11 << 8 ) )  & mask  );
  out[30] = base + ( ( w11 >> 16 )  & mask  );
  out[31] = base + ( w11  >> 40  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 25-bit values, touching 13 64-bit words, using 100 bytes */ 
static void unpackforblock25_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 25 )  & mask  );
  out[2] = base + ( ( ( w0 >> 50  ) | ( w1 << 14 ) )  & mask  );
  out[3] = base + ( ( w1 >> 11 )  & mask  );
  out[4] = base + ( ( w1 >> 36 )  & mask  );
  out[5] = base + ( ( ( w1 >> 61  ) | ( w2 << 3 ) )  & mask  );
  out[6] = base + ( ( w2 >> 22 )  & mask  );
  out[7] = base + ( ( ( w2 >> 47  ) | ( w3 << 17 ) )  & mask  );
  out[8] = base + ( ( w3 >> 8 )  & mask  );
  out[9] = base + ( ( w3 >> 33 )  & mask  );
  out[10] = base + ( ( ( w3 >> 58  ) | ( w4 << 6 ) )  & mask  );
  out[11] = base + ( ( w4 >> 19 )  & mask  );
  out[12] = base + ( ( ( w4 >> 44  ) | ( w5 << 20 ) )  & mask  );
  out[13] = base + ( ( w5 >> 5 )  & mask  );
  out[14] = base + ( ( w5 >> 30 )  & mask  );
  out[15] = base + ( ( ( w5 >> 55  ) | ( w6 << 9 ) )  & mask  );
  out[16] = base + ( ( w6 >> 16 )  & mask  );
  out[17] = base + ( ( ( w6 >> 41  ) | ( w7 << 23 ) )  & mask  );
  out[18] = base + ( ( w7 >> 2 )  & mask  );
  out[19] = base + ( ( w7 >> 27 )  & mask  );
  out[20] = base + ( ( ( w7 >> 52  ) | ( w8 << 12 ) )  & mask  );
  out[21] = base + ( ( w8 >> 13 )  & mask  );
  out[22] = base + ( ( w8 >> 38 )  & mask  );
  out[23] = base + ( ( ( w8 >> 63  ) | ( w9 << 1 ) )  & mask  );
  out[24] = base + ( ( w9 >> 24 )  & mask  );
  out[25] = base + ( ( ( w9 >> 49  ) | ( w10 << 15 ) )  & mask  );
  out[26] = base + ( ( w10 >> 10 )  & mask  );
  out[27] = base + ( ( w10 >> 35 )  & mask  );
  out[28] = base + ( ( ( w10 >> 60  ) | ( w11 << 4 ) )  & mask  );
  out[29] = base + ( ( w11 >> 21 )  & mask  );
  out[30] = base + ( ( ( w11 >> 46  ) | ( w12 << 18 ) )  & mask  );
  out[31] = base + ( ( w12 >> 7 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 26-bit values, touching 13 64-bit words, using 104 bytes */ 
static void unpackforblock26_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 26 )  & mask  );
  out[2] = base + ( ( ( w0 >> 52  ) | ( w1 << 12 ) )  & mask  );
  out[3] = base + ( ( w1 >> 14 )  & mask  );
  out[4] = base + ( ( ( w1 >> 40  ) | ( w2 << 24 ) )  & mask  );
  out[5] = base + ( ( w2 >> 2 )  & mask  );
  out[6] = base + ( ( w2 >> 28 )  & mask  );
  out[7] = base + ( ( ( w2 >> 54  ) | ( w3 << 10 ) )  & mask  );
  out[8] = base + ( ( w3 >> 16 )  & mask  );
  out[9] = base + ( ( ( w3 >> 42  ) | ( w4 << 22 ) )  & mask  );
  out[10] = base + ( ( w4 >> 4 )  & mask  );
  out[11] = base + ( ( w4 >> 30 )  & mask  );
  out[12] = base + ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
  out[13] = base + ( ( w5 >> 18 )  & mask  );
  out[14] = base + ( ( ( w5 >> 44  ) | ( w6 << 20 ) )  & mask  );
  out[15] = base + ( ( w6 >> 6 )  & mask  );
  out[16] = base + ( ( w6 >> 32 )  & mask  );
  out[17] = base + ( ( ( w6 >> 58  ) | ( w7 << 6 ) )  & mask  );
  out[18] = base + ( ( w7 >> 20 )  & mask  );
  out[19] = base + ( ( ( w7 >> 46  ) | ( w8 << 18 ) )  & mask  );
  out[20] = base + ( ( w8 >> 8 )  & mask  );
  out[21] = base + ( ( w8 >> 34 )  & mask  );
  out[22] = base + ( ( ( w8 >> 60  ) | ( w9 << 4 ) )  & mask  );
  out[23] = base + ( ( w9 >> 22 )  & mask  );
  out[24] = base + ( ( ( w9 >> 48  ) | ( w10 << 16 ) )  & mask  );
  out[25] = base + ( ( w10 >> 10 )  & mask  );
  out[26] = base + ( ( w10 >> 36 )  & mask  );
  out[27] = base + ( ( ( w10 >> 62  ) | ( w11 << 2 ) )  & mask  );
  out[28] = base + ( ( w11 >> 24 )  & mask  );
  out[29] = base + ( ( ( w11 >> 50  ) | ( w12 << 14 ) )  & mask  );
  out[30] = base + ( ( w12 >> 12 )  & mask  );
  out[31] = base + ( w12  >> 38  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 27-bit values, touching 14 64-bit words, using 108 bytes */ 
static void unpackforblock27_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 27 )  & mask  );
  out[2] = base + ( ( ( w0 >> 54  ) | ( w1 << 10 ) )  & mask  );
  out[3] = base + ( ( w1 >> 17 )  & mask  );
  out[4] = base + ( ( ( w1 >> 44  ) | ( w2 << 20 ) )  & mask  );
  out[5] = base + ( ( w2 >> 7 )  & mask  );
  out[6] = base + ( ( w2 >> 34 )  & mask  );
  out[7] = base + ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
  out[8] = base + ( ( w3 >> 24 )  & mask  );
  out[9] = base + ( ( ( w3 >> 51  ) | ( w4 << 13 ) )  & mask  );
  out[10] = base + ( ( w4 >> 14 )  & mask  );
  out[11] = base + ( ( ( w4 >> 41  ) | ( w5 << 23 ) )  & mask  );
  out[12] = base + ( ( w5 >> 4 )  & mask  );
  out[13] = base + ( ( w5 >> 31 )  & mask  );
  out[14] = base + ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
  out[15] = base + ( ( w6 >> 21 )  & mask  );
  out[16] = base + ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
  out[17] = base + ( ( w7 >> 11 )  & mask  );
  out[18] = base + ( ( ( w7 >> 38  ) | ( w8 << 26 ) )  & mask  );
  out[19] = base + ( ( w8 >> 1 )  & mask  );
  out[20] = base + ( ( w8 >> 28 )  & mask  );
  out[21] = base + ( ( ( w8 >> 55  ) | ( w9 << 9 ) )  & mask  );
  out[22] = base + ( ( w9 >> 18 )  & mask  );
  out[23] = base + ( ( ( w9 >> 45  ) | ( w10 << 19 ) )  & mask  );
  out[24] = base + ( ( w10 >> 8 )  & mask  );
  out[25] = base + ( ( w10 >> 35 )  & mask  );
  out[26] = base + ( ( ( w10 >> 62  ) | ( w11 << 2 ) )  & mask  );
  out[27] = base + ( ( w11 >> 25 )  & mask  );
  out[28] = base + ( ( ( w11 >> 52  ) | ( w12 << 12 ) )  & mask  );
  out[29] = base + ( ( w12 >> 15 )  & mask  );
  out[30] = base + ( ( ( w12 >> 42  ) | ( w13 << 22 ) )  & mask  );
  out[31] = base + ( ( w13 >> 5 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 28-bit values, touching 14 64-bit words, using 112 bytes */ 
static void unpackforblock28_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 28 )  & mask  );
  out[2] = base + ( ( ( w0 >> 56  ) | ( w1 << 8 ) )  & mask  );
  out[3] = base + ( ( w1 >> 20 )  & mask  );
  out[4] = base + ( ( ( w1 >> 48  ) | ( w2 << 16 ) )  & mask  );
  out[5] = base + ( ( w2 >> 12 )  & mask  );
  out[6] = base + ( ( ( w2 >> 40  ) | ( w3 << 24 ) )  & mask  );
  out[7] = base + ( ( w3 >> 4 )  & mask  );
  out[8] = base + ( ( w3 >> 32 )  & mask  );
  out[9] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[10] = base + ( ( w4 >> 24 )  & mask  );
  out[11] = base + ( ( ( w4 >> 52  ) | ( w5 << 12 ) )  & mask  );
  out[12] = base + ( ( w5 >> 16 )  & mask  );
  out[13] = base + ( ( ( w5 >> 44  ) | ( w6 << 20 ) )  & mask  );
  out[14] = base + ( ( w6 >> 8 )  & mask  );
  out[15] = base + ( w6  >> 36  );
  out[16] = base + ( ( w7 )  & mask  );
  out[17] = base + ( ( w7 >> 28 )  & mask  );
  out[18] = base + ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
  out[19] = base + ( ( w8 >> 20 )  & mask  );
  out[20] = base + ( ( ( w8 >> 48  ) | ( w9 << 16 ) )  & mask  );
  out[21] = base + ( ( w9 >> 12 )  & mask  );
  out[22] = base + ( ( ( w9 >> 40  ) | ( w10 << 24 ) )  & mask  );
  out[23] = base + ( ( w10 >> 4 )  & mask  );
  out[24] = base + ( ( w10 >> 32 )  & mask  );
  out[25] = base + ( ( ( w10 >> 60  ) | ( w11 << 4 ) )  & mask  );
  out[26] = base + ( ( w11 >> 24 )  & mask  );
  out[27] = base + ( ( ( w11 >> 52  ) | ( w12 << 12 ) )  & mask  );
  out[28] = base + ( ( w12 >> 16 )  & mask  );
  out[29] = base + ( ( ( w12 >> 44  ) | ( w13 << 20 ) )  & mask  );
  out[30] = base + ( ( w13 >> 8 )  & mask  );
  out[31] = base + ( w13  >> 36  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 29-bit values, touching 15 64-bit words, using 116 bytes */ 
static void unpackforblock29_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 29 )  & mask  );
  out[2] = base + ( ( ( w0 >> 58  ) | ( w1 << 6 ) )  & mask  );
  out[3] = base + ( ( w1 >> 23 )  & mask  );
  out[4] = base + ( ( ( w1 >> 52  ) | ( w2 << 12 ) )  & mask  );
  out[5] = base + ( ( w2 >> 17 )  & mask  );
  out[6] = base + ( ( ( w2 >> 46  ) | ( w3 << 18 ) )  & mask  );
  out[7] = base + ( ( w3 >> 11 )  & mask  );
  out[8] = base + ( ( ( w3 >> 40  ) | ( w4 << 24 ) )  & mask  );
  out[9] = base + ( ( w4 >> 5 )  & mask  );
  out[10] = base + ( ( w4 >> 34 )  & mask  );
  out[11] = base + ( ( ( w4 >> 63  ) | ( w5 << 1 ) )  & mask  );
  out[12] = base + ( ( w5 >> 28 )  & mask  );
  out[13] = base + ( ( ( w5 >> 57  ) | ( w6 << 7 ) )  & mask  );
  out[14] = base + ( ( w6 >> 22 )  & mask  );
  out[15] = base + ( ( ( w6 >> 51  ) | ( w7 << 13 ) )  & mask  );
  out[16] = base + ( ( w7 >> 16 )  & mask  );
  out[17] = base + ( ( ( w7 >> 45  ) | ( w8 << 19 ) )  & mask  );
  out[18] = base + ( ( w8 >> 10 )  & mask  );
  out[19] = base + ( ( ( w8 >> 39  ) | ( w9 << 25 ) )  & mask  );
  out[20] = base + ( ( w9 >> 4 )  & mask  );
  out[21] = base + ( ( w9 >> 33 )  & mask  );
  out[22] = base + ( ( ( w9 >> 62  ) | ( w10 << 2 ) )  & mask  );
  out[23] = base + ( ( w10 >> 27 )  & mask  );
  out[24] = base + ( ( ( w10 >> 56  ) | ( w11 << 8 ) )  & mask  );
  out[25] = base + ( ( w11 >> 21 )  & mask  );
  out[26] = base + ( ( ( w11 >> 50  ) | ( w12 << 14 ) )  & mask  );
  out[27] = base + ( ( w12 >> 15 )  & mask  );
  out[28] = base + ( ( ( w12 >> 44  ) | ( w13 << 20 ) )  & mask  );
  out[29] = base + ( ( w13 >> 9 )  & mask  );
  out[30] = base + ( ( ( w13 >> 38  ) | ( w14 << 26 ) )  & mask  );
  out[31] = base + ( ( w14 >> 3 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 30-bit values, touching 15 64-bit words, using 120 bytes */ 
static void unpackforblock30_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 30 )  & mask  );
  out[2] = base + ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
  out[3] = base + ( ( w1 >> 26 )  & mask  );
  out[4] = base + ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
  out[5] = base + ( ( w2 >> 22 )  & mask  );
  out[6] = base + ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
  out[7] = base + ( ( w3 >> 18 )  & mask  );
  out[8] = base + ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
  out[9] = base + ( ( w4 >> 14 )  & mask  );
  out[10] = base + ( ( ( w4 >> 44  ) | ( w5 << 20 ) )  & mask  );
  out[11] = base + ( ( w5 >> 10 )  & mask  );
  out[12] = base + ( ( ( w5 >> 40  ) | ( w6 << 24 ) )  & mask  );
  out[13] = base + ( ( w6 >> 6 )  & mask  );
  out[14] = base + ( ( ( w6 >> 36  ) | ( w7 << 28 ) )  & mask  );
  out[15] = base + ( ( w7 >> 2 )  & mask  );
  out[16] = base + ( ( w7 >> 32 )  & mask  );
  out[17] = base + ( ( ( w7 >> 62  ) | ( w8 << 2 ) )  & mask  );
  out[18] = base + ( ( w8 >> 28 )  & mask  );
  out[19] = base + ( ( ( w8 >> 58  ) | ( w9 << 6 ) )  & mask  );
  out[20] = base + ( ( w9 >> 24 )  & mask  );
  out[21] = base + ( ( ( w9 >> 54  ) | ( w10 << 10 ) )  & mask  );
  out[22] = base + ( ( w10 >> 20 )  & mask  );
  out[23] = base + ( ( ( w10 >> 50  ) | ( w11 << 14 ) )  & mask  );
  out[24] = base + ( ( w11 >> 16 )  & mask  );
  out[25] = base + ( ( ( w11 >> 46  ) | ( w12 << 18 ) )  & mask  );
  out[26] = base + ( ( w12 >> 12 )  & mask  );
  out[27] = base + ( ( ( w12 >> 42  ) | ( w13 << 22 ) )  & mask  );
  out[28] = base + ( ( w13 >> 8 )  & mask  );
  out[29] = base + ( ( ( w13 >> 38  ) | ( w14 << 26 ) )  & mask  );
  out[30] = base + ( ( w14 >> 4 )  & mask  );
  out[31] = base + ( w14  >> 34  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 31-bit values, touching 16 64-bit words, using 124 bytes */ 
static void unpackforblock31_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( w0 >> 31 )  & mask  );
  out[2] = base + ( ( ( w0 >> 62  ) | ( w1 << 2 ) )  & mask  );
  out[3] = base + ( ( w1 >> 29 )  & mask  );
  out[4] = base + ( ( ( w1 >> 60  ) | ( w2 << 4 ) )  & mask  );
  out[5] = base + ( ( w2 >> 27 )  & mask  );
  out[6] = base + ( ( ( w2 >> 58  ) | ( w3 << 6 ) )  & mask  );
  out[7] = base + ( ( w3 >> 25 )  & mask  );
  out[8] = base + ( ( ( w3 >> 56  ) | ( w4 << 8 ) )  & mask  );
  out[9] = base + ( ( w4 >> 23 )  & mask  );
  out[10] = base + ( ( ( w4 >> 54  ) | ( w5 << 10 ) )  & mask  );
  out[11] = base + ( ( w5 >> 21 )  & mask  );
  out[12] = base + ( ( ( w5 >> 52  ) | ( w6 << 12 ) )  & mask  );
  out[13] = base + ( ( w6 >> 19 )  & mask  );
  out[14] = base + ( ( ( w6 >> 50  ) | ( w7 << 14 ) )  & mask  );
  out[15] = base + ( ( w7 >> 17 )  & mask  );
  out[16] = base + ( ( ( w7 >> 48  ) | ( w8 << 16 ) )  & mask  );
  out[17] = base + ( ( w8 >> 15 )  & mask  );
  out[18] = base + ( ( ( w8 >> 46  ) | ( w9 << 18 ) )  & mask  );
  out[19] = base + ( ( w9 >> 13 )  & mask  );
  out[20] = base + ( ( ( w9 >> 44  ) | ( w10 << 20 ) )  & mask  );
  out[21] = base + ( ( w10 >> 11 )  & mask  );
  out[22] = base + ( ( ( w10 >> 42  ) | ( w11 << 22 ) )  & mask  );
  out[23] = base + ( ( w11 >> 9 )  & mask  );
  out[24] = base + ( ( ( w11 >> 40  ) | ( w12 << 24 ) )  & mask  );
  out[25] = base + ( ( w12 >> 7 )  & mask  );
  out[26] = base + ( ( ( w12 >> 38  ) | ( w13 << 26 ) )  & mask  );
  out[27] = base + ( ( w13 >> 5 )  & mask  );
  out[28] = base + ( ( ( w13 >> 36  ) | ( w14 << 28 ) )  & mask  );
  out[29] = base + ( ( w14 >> 3 )  & mask  );
  out[30] = base + ( ( ( w14 >> 34  ) | ( w15 << 30 ) )  & mask  );
  out[31] = base + ( ( w15 >> 1 )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 32-bit values, touching 16 64-bit words, using 128 bytes */ 
static void unpackforblock32_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(4294967295);
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
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( w0  >> 32  );
  out[2] = base + ( ( w1 )  & mask  );
  out[3] = base + ( w1  >> 32  );
  out[4] = base + ( ( w2 )  & mask  );
  out[5] = base + ( w2  >> 32  );
  out[6] = base + ( ( w3 )  & mask  );
  out[7] = base + ( w3  >> 32  );
  out[8] = base + ( ( w4 )  & mask  );
  out[9] = base + ( w4  >> 32  );
  out[10] = base + ( ( w5 )  & mask  );
  out[11] = base + ( w5  >> 32  );
  out[12] = base + ( ( w6 )  & mask  );
  out[13] = base + ( w6  >> 32  );
  out[14] = base + ( ( w7 )  & mask  );
  out[15] = base + ( w7  >> 32  );
  out[16] = base + ( ( w8 )  & mask  );
  out[17] = base + ( w8  >> 32  );
  out[18] = base + ( ( w9 )  & mask  );
  out[19] = base + ( w9  >> 32  );
  out[20] = base + ( ( w10 )  & mask  );
  out[21] = base + ( w10  >> 32  );
  out[22] = base + ( ( w11 )  & mask  );
  out[23] = base + ( w11  >> 32  );
  out[24] = base + ( ( w12 )  & mask  );
  out[25] = base + ( w12  >> 32  );
  out[26] = base + ( ( w13 )  & mask  );
  out[27] = base + ( w13  >> 32  );
  out[28] = base + ( ( w14 )  & mask  );
  out[29] = base + ( w14  >> 32  );
  out[30] = base + ( ( w15 )  & mask  );
  out[31] = base + ( w15  >> 32  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 33-bit values, touching 17 64-bit words, using 132 bytes */ 
static void unpackforblock33_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(8589934591);
  /* we are going to access  17 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  *pw += 132; /* we used up 132 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 33  ) | ( w1 << 31 ) )  & mask  );
  out[2] = base + ( ( w1 >> 2 )  & mask  );
  out[3] = base + ( ( ( w1 >> 35  ) | ( w2 << 29 ) )  & mask  );
  out[4] = base + ( ( w2 >> 4 )  & mask  );
  out[5] = base + ( ( ( w2 >> 37  ) | ( w3 << 27 ) )  & mask  );
  out[6] = base + ( ( w3 >> 6 )  & mask  );
  out[7] = base + ( ( ( w3 >> 39  ) | ( w4 << 25 ) )  & mask  );
  out[8] = base + ( ( w4 >> 8 )  & mask  );
  out[9] = base + ( ( ( w4 >> 41  ) | ( w5 << 23 ) )  & mask  );
  out[10] = base + ( ( w5 >> 10 )  & mask  );
  out[11] = base + ( ( ( w5 >> 43  ) | ( w6 << 21 ) )  & mask  );
  out[12] = base + ( ( w6 >> 12 )  & mask  );
  out[13] = base + ( ( ( w6 >> 45  ) | ( w7 << 19 ) )  & mask  );
  out[14] = base + ( ( w7 >> 14 )  & mask  );
  out[15] = base + ( ( ( w7 >> 47  ) | ( w8 << 17 ) )  & mask  );
  out[16] = base + ( ( w8 >> 16 )  & mask  );
  out[17] = base + ( ( ( w8 >> 49  ) | ( w9 << 15 ) )  & mask  );
  out[18] = base + ( ( w9 >> 18 )  & mask  );
  out[19] = base + ( ( ( w9 >> 51  ) | ( w10 << 13 ) )  & mask  );
  out[20] = base + ( ( w10 >> 20 )  & mask  );
  out[21] = base + ( ( ( w10 >> 53  ) | ( w11 << 11 ) )  & mask  );
  out[22] = base + ( ( w11 >> 22 )  & mask  );
  out[23] = base + ( ( ( w11 >> 55  ) | ( w12 << 9 ) )  & mask  );
  out[24] = base + ( ( w12 >> 24 )  & mask  );
  out[25] = base + ( ( ( w12 >> 57  ) | ( w13 << 7 ) )  & mask  );
  out[26] = base + ( ( w13 >> 26 )  & mask  );
  out[27] = base + ( ( ( w13 >> 59  ) | ( w14 << 5 ) )  & mask  );
  out[28] = base + ( ( w14 >> 28 )  & mask  );
  out[29] = base + ( ( ( w14 >> 61  ) | ( w15 << 3 ) )  & mask  );
  out[30] = base + ( ( w15 >> 30 )  & mask  );
  out[31] = base + ( ( ( w15 >> 63  ) | ( w16 << 1 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 34-bit values, touching 17 64-bit words, using 136 bytes */ 
static void unpackforblock34_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(17179869183);
  /* we are going to access  17 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  *pw += 136; /* we used up 136 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 34  ) | ( w1 << 30 ) )  & mask  );
  out[2] = base + ( ( w1 >> 4 )  & mask  );
  out[3] = base + ( ( ( w1 >> 38  ) | ( w2 << 26 ) )  & mask  );
  out[4] = base + ( ( w2 >> 8 )  & mask  );
  out[5] = base + ( ( ( w2 >> 42  ) | ( w3 << 22 ) )  & mask  );
  out[6] = base + ( ( w3 >> 12 )  & mask  );
  out[7] = base + ( ( ( w3 >> 46  ) | ( w4 << 18 ) )  & mask  );
  out[8] = base + ( ( w4 >> 16 )  & mask  );
  out[9] = base + ( ( ( w4 >> 50  ) | ( w5 << 14 ) )  & mask  );
  out[10] = base + ( ( w5 >> 20 )  & mask  );
  out[11] = base + ( ( ( w5 >> 54  ) | ( w6 << 10 ) )  & mask  );
  out[12] = base + ( ( w6 >> 24 )  & mask  );
  out[13] = base + ( ( ( w6 >> 58  ) | ( w7 << 6 ) )  & mask  );
  out[14] = base + ( ( w7 >> 28 )  & mask  );
  out[15] = base + ( ( ( w7 >> 62  ) | ( w8 << 2 ) )  & mask  );
  out[16] = base + ( ( ( w8 >> 32  ) | ( w9 << 32 ) )  & mask  );
  out[17] = base + ( ( w9 >> 2 )  & mask  );
  out[18] = base + ( ( ( w9 >> 36  ) | ( w10 << 28 ) )  & mask  );
  out[19] = base + ( ( w10 >> 6 )  & mask  );
  out[20] = base + ( ( ( w10 >> 40  ) | ( w11 << 24 ) )  & mask  );
  out[21] = base + ( ( w11 >> 10 )  & mask  );
  out[22] = base + ( ( ( w11 >> 44  ) | ( w12 << 20 ) )  & mask  );
  out[23] = base + ( ( w12 >> 14 )  & mask  );
  out[24] = base + ( ( ( w12 >> 48  ) | ( w13 << 16 ) )  & mask  );
  out[25] = base + ( ( w13 >> 18 )  & mask  );
  out[26] = base + ( ( ( w13 >> 52  ) | ( w14 << 12 ) )  & mask  );
  out[27] = base + ( ( w14 >> 22 )  & mask  );
  out[28] = base + ( ( ( w14 >> 56  ) | ( w15 << 8 ) )  & mask  );
  out[29] = base + ( ( w15 >> 26 )  & mask  );
  out[30] = base + ( ( ( w15 >> 60  ) | ( w16 << 4 ) )  & mask  );
  out[31] = base + ( w16  >> 30  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 35-bit values, touching 18 64-bit words, using 140 bytes */ 
static void unpackforblock35_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(34359738367);
  /* we are going to access  18 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  *pw += 140; /* we used up 140 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 35  ) | ( w1 << 29 ) )  & mask  );
  out[2] = base + ( ( w1 >> 6 )  & mask  );
  out[3] = base + ( ( ( w1 >> 41  ) | ( w2 << 23 ) )  & mask  );
  out[4] = base + ( ( w2 >> 12 )  & mask  );
  out[5] = base + ( ( ( w2 >> 47  ) | ( w3 << 17 ) )  & mask  );
  out[6] = base + ( ( w3 >> 18 )  & mask  );
  out[7] = base + ( ( ( w3 >> 53  ) | ( w4 << 11 ) )  & mask  );
  out[8] = base + ( ( w4 >> 24 )  & mask  );
  out[9] = base + ( ( ( w4 >> 59  ) | ( w5 << 5 ) )  & mask  );
  out[10] = base + ( ( ( w5 >> 30  ) | ( w6 << 34 ) )  & mask  );
  out[11] = base + ( ( w6 >> 1 )  & mask  );
  out[12] = base + ( ( ( w6 >> 36  ) | ( w7 << 28 ) )  & mask  );
  out[13] = base + ( ( w7 >> 7 )  & mask  );
  out[14] = base + ( ( ( w7 >> 42  ) | ( w8 << 22 ) )  & mask  );
  out[15] = base + ( ( w8 >> 13 )  & mask  );
  out[16] = base + ( ( ( w8 >> 48  ) | ( w9 << 16 ) )  & mask  );
  out[17] = base + ( ( w9 >> 19 )  & mask  );
  out[18] = base + ( ( ( w9 >> 54  ) | ( w10 << 10 ) )  & mask  );
  out[19] = base + ( ( w10 >> 25 )  & mask  );
  out[20] = base + ( ( ( w10 >> 60  ) | ( w11 << 4 ) )  & mask  );
  out[21] = base + ( ( ( w11 >> 31  ) | ( w12 << 33 ) )  & mask  );
  out[22] = base + ( ( w12 >> 2 )  & mask  );
  out[23] = base + ( ( ( w12 >> 37  ) | ( w13 << 27 ) )  & mask  );
  out[24] = base + ( ( w13 >> 8 )  & mask  );
  out[25] = base + ( ( ( w13 >> 43  ) | ( w14 << 21 ) )  & mask  );
  out[26] = base + ( ( w14 >> 14 )  & mask  );
  out[27] = base + ( ( ( w14 >> 49  ) | ( w15 << 15 ) )  & mask  );
  out[28] = base + ( ( w15 >> 20 )  & mask  );
  out[29] = base + ( ( ( w15 >> 55  ) | ( w16 << 9 ) )  & mask  );
  out[30] = base + ( ( w16 >> 26 )  & mask  );
  out[31] = base + ( ( ( w16 >> 61  ) | ( w17 << 3 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 36-bit values, touching 18 64-bit words, using 144 bytes */ 
static void unpackforblock36_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(68719476735);
  /* we are going to access  18 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  *pw += 144; /* we used up 144 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 36  ) | ( w1 << 28 ) )  & mask  );
  out[2] = base + ( ( w1 >> 8 )  & mask  );
  out[3] = base + ( ( ( w1 >> 44  ) | ( w2 << 20 ) )  & mask  );
  out[4] = base + ( ( w2 >> 16 )  & mask  );
  out[5] = base + ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
  out[6] = base + ( ( w3 >> 24 )  & mask  );
  out[7] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[8] = base + ( ( ( w4 >> 32  ) | ( w5 << 32 ) )  & mask  );
  out[9] = base + ( ( w5 >> 4 )  & mask  );
  out[10] = base + ( ( ( w5 >> 40  ) | ( w6 << 24 ) )  & mask  );
  out[11] = base + ( ( w6 >> 12 )  & mask  );
  out[12] = base + ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
  out[13] = base + ( ( w7 >> 20 )  & mask  );
  out[14] = base + ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
  out[15] = base + ( w8  >> 28  );
  out[16] = base + ( ( w9 )  & mask  );
  out[17] = base + ( ( ( w9 >> 36  ) | ( w10 << 28 ) )  & mask  );
  out[18] = base + ( ( w10 >> 8 )  & mask  );
  out[19] = base + ( ( ( w10 >> 44  ) | ( w11 << 20 ) )  & mask  );
  out[20] = base + ( ( w11 >> 16 )  & mask  );
  out[21] = base + ( ( ( w11 >> 52  ) | ( w12 << 12 ) )  & mask  );
  out[22] = base + ( ( w12 >> 24 )  & mask  );
  out[23] = base + ( ( ( w12 >> 60  ) | ( w13 << 4 ) )  & mask  );
  out[24] = base + ( ( ( w13 >> 32  ) | ( w14 << 32 ) )  & mask  );
  out[25] = base + ( ( w14 >> 4 )  & mask  );
  out[26] = base + ( ( ( w14 >> 40  ) | ( w15 << 24 ) )  & mask  );
  out[27] = base + ( ( w15 >> 12 )  & mask  );
  out[28] = base + ( ( ( w15 >> 48  ) | ( w16 << 16 ) )  & mask  );
  out[29] = base + ( ( w16 >> 20 )  & mask  );
  out[30] = base + ( ( ( w16 >> 56  ) | ( w17 << 8 ) )  & mask  );
  out[31] = base + ( w17  >> 28  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 37-bit values, touching 19 64-bit words, using 148 bytes */ 
static void unpackforblock37_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(137438953471);
  /* we are going to access  19 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  *pw += 148; /* we used up 148 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 37  ) | ( w1 << 27 ) )  & mask  );
  out[2] = base + ( ( w1 >> 10 )  & mask  );
  out[3] = base + ( ( ( w1 >> 47  ) | ( w2 << 17 ) )  & mask  );
  out[4] = base + ( ( w2 >> 20 )  & mask  );
  out[5] = base + ( ( ( w2 >> 57  ) | ( w3 << 7 ) )  & mask  );
  out[6] = base + ( ( ( w3 >> 30  ) | ( w4 << 34 ) )  & mask  );
  out[7] = base + ( ( w4 >> 3 )  & mask  );
  out[8] = base + ( ( ( w4 >> 40  ) | ( w5 << 24 ) )  & mask  );
  out[9] = base + ( ( w5 >> 13 )  & mask  );
  out[10] = base + ( ( ( w5 >> 50  ) | ( w6 << 14 ) )  & mask  );
  out[11] = base + ( ( w6 >> 23 )  & mask  );
  out[12] = base + ( ( ( w6 >> 60  ) | ( w7 << 4 ) )  & mask  );
  out[13] = base + ( ( ( w7 >> 33  ) | ( w8 << 31 ) )  & mask  );
  out[14] = base + ( ( w8 >> 6 )  & mask  );
  out[15] = base + ( ( ( w8 >> 43  ) | ( w9 << 21 ) )  & mask  );
  out[16] = base + ( ( w9 >> 16 )  & mask  );
  out[17] = base + ( ( ( w9 >> 53  ) | ( w10 << 11 ) )  & mask  );
  out[18] = base + ( ( w10 >> 26 )  & mask  );
  out[19] = base + ( ( ( w10 >> 63  ) | ( w11 << 1 ) )  & mask  );
  out[20] = base + ( ( ( w11 >> 36  ) | ( w12 << 28 ) )  & mask  );
  out[21] = base + ( ( w12 >> 9 )  & mask  );
  out[22] = base + ( ( ( w12 >> 46  ) | ( w13 << 18 ) )  & mask  );
  out[23] = base + ( ( w13 >> 19 )  & mask  );
  out[24] = base + ( ( ( w13 >> 56  ) | ( w14 << 8 ) )  & mask  );
  out[25] = base + ( ( ( w14 >> 29  ) | ( w15 << 35 ) )  & mask  );
  out[26] = base + ( ( w15 >> 2 )  & mask  );
  out[27] = base + ( ( ( w15 >> 39  ) | ( w16 << 25 ) )  & mask  );
  out[28] = base + ( ( w16 >> 12 )  & mask  );
  out[29] = base + ( ( ( w16 >> 49  ) | ( w17 << 15 ) )  & mask  );
  out[30] = base + ( ( w17 >> 22 )  & mask  );
  out[31] = base + ( ( ( w17 >> 59  ) | ( w18 << 5 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 38-bit values, touching 19 64-bit words, using 152 bytes */ 
static void unpackforblock38_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(274877906943);
  /* we are going to access  19 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  *pw += 152; /* we used up 152 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 38  ) | ( w1 << 26 ) )  & mask  );
  out[2] = base + ( ( w1 >> 12 )  & mask  );
  out[3] = base + ( ( ( w1 >> 50  ) | ( w2 << 14 ) )  & mask  );
  out[4] = base + ( ( w2 >> 24 )  & mask  );
  out[5] = base + ( ( ( w2 >> 62  ) | ( w3 << 2 ) )  & mask  );
  out[6] = base + ( ( ( w3 >> 36  ) | ( w4 << 28 ) )  & mask  );
  out[7] = base + ( ( w4 >> 10 )  & mask  );
  out[8] = base + ( ( ( w4 >> 48  ) | ( w5 << 16 ) )  & mask  );
  out[9] = base + ( ( w5 >> 22 )  & mask  );
  out[10] = base + ( ( ( w5 >> 60  ) | ( w6 << 4 ) )  & mask  );
  out[11] = base + ( ( ( w6 >> 34  ) | ( w7 << 30 ) )  & mask  );
  out[12] = base + ( ( w7 >> 8 )  & mask  );
  out[13] = base + ( ( ( w7 >> 46  ) | ( w8 << 18 ) )  & mask  );
  out[14] = base + ( ( w8 >> 20 )  & mask  );
  out[15] = base + ( ( ( w8 >> 58  ) | ( w9 << 6 ) )  & mask  );
  out[16] = base + ( ( ( w9 >> 32  ) | ( w10 << 32 ) )  & mask  );
  out[17] = base + ( ( w10 >> 6 )  & mask  );
  out[18] = base + ( ( ( w10 >> 44  ) | ( w11 << 20 ) )  & mask  );
  out[19] = base + ( ( w11 >> 18 )  & mask  );
  out[20] = base + ( ( ( w11 >> 56  ) | ( w12 << 8 ) )  & mask  );
  out[21] = base + ( ( ( w12 >> 30  ) | ( w13 << 34 ) )  & mask  );
  out[22] = base + ( ( w13 >> 4 )  & mask  );
  out[23] = base + ( ( ( w13 >> 42  ) | ( w14 << 22 ) )  & mask  );
  out[24] = base + ( ( w14 >> 16 )  & mask  );
  out[25] = base + ( ( ( w14 >> 54  ) | ( w15 << 10 ) )  & mask  );
  out[26] = base + ( ( ( w15 >> 28  ) | ( w16 << 36 ) )  & mask  );
  out[27] = base + ( ( w16 >> 2 )  & mask  );
  out[28] = base + ( ( ( w16 >> 40  ) | ( w17 << 24 ) )  & mask  );
  out[29] = base + ( ( w17 >> 14 )  & mask  );
  out[30] = base + ( ( ( w17 >> 52  ) | ( w18 << 12 ) )  & mask  );
  out[31] = base + ( w18  >> 26  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 39-bit values, touching 20 64-bit words, using 156 bytes */ 
static void unpackforblock39_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(549755813887);
  /* we are going to access  20 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  *pw += 156; /* we used up 156 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 39  ) | ( w1 << 25 ) )  & mask  );
  out[2] = base + ( ( w1 >> 14 )  & mask  );
  out[3] = base + ( ( ( w1 >> 53  ) | ( w2 << 11 ) )  & mask  );
  out[4] = base + ( ( ( w2 >> 28  ) | ( w3 << 36 ) )  & mask  );
  out[5] = base + ( ( w3 >> 3 )  & mask  );
  out[6] = base + ( ( ( w3 >> 42  ) | ( w4 << 22 ) )  & mask  );
  out[7] = base + ( ( w4 >> 17 )  & mask  );
  out[8] = base + ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
  out[9] = base + ( ( ( w5 >> 31  ) | ( w6 << 33 ) )  & mask  );
  out[10] = base + ( ( w6 >> 6 )  & mask  );
  out[11] = base + ( ( ( w6 >> 45  ) | ( w7 << 19 ) )  & mask  );
  out[12] = base + ( ( w7 >> 20 )  & mask  );
  out[13] = base + ( ( ( w7 >> 59  ) | ( w8 << 5 ) )  & mask  );
  out[14] = base + ( ( ( w8 >> 34  ) | ( w9 << 30 ) )  & mask  );
  out[15] = base + ( ( w9 >> 9 )  & mask  );
  out[16] = base + ( ( ( w9 >> 48  ) | ( w10 << 16 ) )  & mask  );
  out[17] = base + ( ( w10 >> 23 )  & mask  );
  out[18] = base + ( ( ( w10 >> 62  ) | ( w11 << 2 ) )  & mask  );
  out[19] = base + ( ( ( w11 >> 37  ) | ( w12 << 27 ) )  & mask  );
  out[20] = base + ( ( w12 >> 12 )  & mask  );
  out[21] = base + ( ( ( w12 >> 51  ) | ( w13 << 13 ) )  & mask  );
  out[22] = base + ( ( ( w13 >> 26  ) | ( w14 << 38 ) )  & mask  );
  out[23] = base + ( ( w14 >> 1 )  & mask  );
  out[24] = base + ( ( ( w14 >> 40  ) | ( w15 << 24 ) )  & mask  );
  out[25] = base + ( ( w15 >> 15 )  & mask  );
  out[26] = base + ( ( ( w15 >> 54  ) | ( w16 << 10 ) )  & mask  );
  out[27] = base + ( ( ( w16 >> 29  ) | ( w17 << 35 ) )  & mask  );
  out[28] = base + ( ( w17 >> 4 )  & mask  );
  out[29] = base + ( ( ( w17 >> 43  ) | ( w18 << 21 ) )  & mask  );
  out[30] = base + ( ( w18 >> 18 )  & mask  );
  out[31] = base + ( ( ( w18 >> 57  ) | ( w19 << 7 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 40-bit values, touching 20 64-bit words, using 160 bytes */ 
static void unpackforblock40_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(1099511627775);
  /* we are going to access  20 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  *pw += 160; /* we used up 160 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 40  ) | ( w1 << 24 ) )  & mask  );
  out[2] = base + ( ( w1 >> 16 )  & mask  );
  out[3] = base + ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
  out[4] = base + ( ( ( w2 >> 32  ) | ( w3 << 32 ) )  & mask  );
  out[5] = base + ( ( w3 >> 8 )  & mask  );
  out[6] = base + ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
  out[7] = base + ( w4  >> 24  );
  out[8] = base + ( ( w5 )  & mask  );
  out[9] = base + ( ( ( w5 >> 40  ) | ( w6 << 24 ) )  & mask  );
  out[10] = base + ( ( w6 >> 16 )  & mask  );
  out[11] = base + ( ( ( w6 >> 56  ) | ( w7 << 8 ) )  & mask  );
  out[12] = base + ( ( ( w7 >> 32  ) | ( w8 << 32 ) )  & mask  );
  out[13] = base + ( ( w8 >> 8 )  & mask  );
  out[14] = base + ( ( ( w8 >> 48  ) | ( w9 << 16 ) )  & mask  );
  out[15] = base + ( w9  >> 24  );
  out[16] = base + ( ( w10 )  & mask  );
  out[17] = base + ( ( ( w10 >> 40  ) | ( w11 << 24 ) )  & mask  );
  out[18] = base + ( ( w11 >> 16 )  & mask  );
  out[19] = base + ( ( ( w11 >> 56  ) | ( w12 << 8 ) )  & mask  );
  out[20] = base + ( ( ( w12 >> 32  ) | ( w13 << 32 ) )  & mask  );
  out[21] = base + ( ( w13 >> 8 )  & mask  );
  out[22] = base + ( ( ( w13 >> 48  ) | ( w14 << 16 ) )  & mask  );
  out[23] = base + ( w14  >> 24  );
  out[24] = base + ( ( w15 )  & mask  );
  out[25] = base + ( ( ( w15 >> 40  ) | ( w16 << 24 ) )  & mask  );
  out[26] = base + ( ( w16 >> 16 )  & mask  );
  out[27] = base + ( ( ( w16 >> 56  ) | ( w17 << 8 ) )  & mask  );
  out[28] = base + ( ( ( w17 >> 32  ) | ( w18 << 32 ) )  & mask  );
  out[29] = base + ( ( w18 >> 8 )  & mask  );
  out[30] = base + ( ( ( w18 >> 48  ) | ( w19 << 16 ) )  & mask  );
  out[31] = base + ( w19  >> 24  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 41-bit values, touching 21 64-bit words, using 164 bytes */ 
static void unpackforblock41_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(2199023255551);
  /* we are going to access  21 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  *pw += 164; /* we used up 164 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 41  ) | ( w1 << 23 ) )  & mask  );
  out[2] = base + ( ( w1 >> 18 )  & mask  );
  out[3] = base + ( ( ( w1 >> 59  ) | ( w2 << 5 ) )  & mask  );
  out[4] = base + ( ( ( w2 >> 36  ) | ( w3 << 28 ) )  & mask  );
  out[5] = base + ( ( w3 >> 13 )  & mask  );
  out[6] = base + ( ( ( w3 >> 54  ) | ( w4 << 10 ) )  & mask  );
  out[7] = base + ( ( ( w4 >> 31  ) | ( w5 << 33 ) )  & mask  );
  out[8] = base + ( ( w5 >> 8 )  & mask  );
  out[9] = base + ( ( ( w5 >> 49  ) | ( w6 << 15 ) )  & mask  );
  out[10] = base + ( ( ( w6 >> 26  ) | ( w7 << 38 ) )  & mask  );
  out[11] = base + ( ( w7 >> 3 )  & mask  );
  out[12] = base + ( ( ( w7 >> 44  ) | ( w8 << 20 ) )  & mask  );
  out[13] = base + ( ( w8 >> 21 )  & mask  );
  out[14] = base + ( ( ( w8 >> 62  ) | ( w9 << 2 ) )  & mask  );
  out[15] = base + ( ( ( w9 >> 39  ) | ( w10 << 25 ) )  & mask  );
  out[16] = base + ( ( w10 >> 16 )  & mask  );
  out[17] = base + ( ( ( w10 >> 57  ) | ( w11 << 7 ) )  & mask  );
  out[18] = base + ( ( ( w11 >> 34  ) | ( w12 << 30 ) )  & mask  );
  out[19] = base + ( ( w12 >> 11 )  & mask  );
  out[20] = base + ( ( ( w12 >> 52  ) | ( w13 << 12 ) )  & mask  );
  out[21] = base + ( ( ( w13 >> 29  ) | ( w14 << 35 ) )  & mask  );
  out[22] = base + ( ( w14 >> 6 )  & mask  );
  out[23] = base + ( ( ( w14 >> 47  ) | ( w15 << 17 ) )  & mask  );
  out[24] = base + ( ( ( w15 >> 24  ) | ( w16 << 40 ) )  & mask  );
  out[25] = base + ( ( w16 >> 1 )  & mask  );
  out[26] = base + ( ( ( w16 >> 42  ) | ( w17 << 22 ) )  & mask  );
  out[27] = base + ( ( w17 >> 19 )  & mask  );
  out[28] = base + ( ( ( w17 >> 60  ) | ( w18 << 4 ) )  & mask  );
  out[29] = base + ( ( ( w18 >> 37  ) | ( w19 << 27 ) )  & mask  );
  out[30] = base + ( ( w19 >> 14 )  & mask  );
  out[31] = base + ( ( ( w19 >> 55  ) | ( w20 << 9 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 42-bit values, touching 21 64-bit words, using 168 bytes */ 
static void unpackforblock42_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(4398046511103);
  /* we are going to access  21 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  *pw += 168; /* we used up 168 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 42  ) | ( w1 << 22 ) )  & mask  );
  out[2] = base + ( ( w1 >> 20 )  & mask  );
  out[3] = base + ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
  out[4] = base + ( ( ( w2 >> 40  ) | ( w3 << 24 ) )  & mask  );
  out[5] = base + ( ( w3 >> 18 )  & mask  );
  out[6] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[7] = base + ( ( ( w4 >> 38  ) | ( w5 << 26 ) )  & mask  );
  out[8] = base + ( ( w5 >> 16 )  & mask  );
  out[9] = base + ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
  out[10] = base + ( ( ( w6 >> 36  ) | ( w7 << 28 ) )  & mask  );
  out[11] = base + ( ( w7 >> 14 )  & mask  );
  out[12] = base + ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
  out[13] = base + ( ( ( w8 >> 34  ) | ( w9 << 30 ) )  & mask  );
  out[14] = base + ( ( w9 >> 12 )  & mask  );
  out[15] = base + ( ( ( w9 >> 54  ) | ( w10 << 10 ) )  & mask  );
  out[16] = base + ( ( ( w10 >> 32  ) | ( w11 << 32 ) )  & mask  );
  out[17] = base + ( ( w11 >> 10 )  & mask  );
  out[18] = base + ( ( ( w11 >> 52  ) | ( w12 << 12 ) )  & mask  );
  out[19] = base + ( ( ( w12 >> 30  ) | ( w13 << 34 ) )  & mask  );
  out[20] = base + ( ( w13 >> 8 )  & mask  );
  out[21] = base + ( ( ( w13 >> 50  ) | ( w14 << 14 ) )  & mask  );
  out[22] = base + ( ( ( w14 >> 28  ) | ( w15 << 36 ) )  & mask  );
  out[23] = base + ( ( w15 >> 6 )  & mask  );
  out[24] = base + ( ( ( w15 >> 48  ) | ( w16 << 16 ) )  & mask  );
  out[25] = base + ( ( ( w16 >> 26  ) | ( w17 << 38 ) )  & mask  );
  out[26] = base + ( ( w17 >> 4 )  & mask  );
  out[27] = base + ( ( ( w17 >> 46  ) | ( w18 << 18 ) )  & mask  );
  out[28] = base + ( ( ( w18 >> 24  ) | ( w19 << 40 ) )  & mask  );
  out[29] = base + ( ( w19 >> 2 )  & mask  );
  out[30] = base + ( ( ( w19 >> 44  ) | ( w20 << 20 ) )  & mask  );
  out[31] = base + ( w20  >> 22  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 43-bit values, touching 22 64-bit words, using 172 bytes */ 
static void unpackforblock43_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(8796093022207);
  /* we are going to access  22 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  *pw += 172; /* we used up 172 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 43  ) | ( w1 << 21 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 22  ) | ( w2 << 42 ) )  & mask  );
  out[3] = base + ( ( w2 >> 1 )  & mask  );
  out[4] = base + ( ( ( w2 >> 44  ) | ( w3 << 20 ) )  & mask  );
  out[5] = base + ( ( ( w3 >> 23  ) | ( w4 << 41 ) )  & mask  );
  out[6] = base + ( ( w4 >> 2 )  & mask  );
  out[7] = base + ( ( ( w4 >> 45  ) | ( w5 << 19 ) )  & mask  );
  out[8] = base + ( ( ( w5 >> 24  ) | ( w6 << 40 ) )  & mask  );
  out[9] = base + ( ( w6 >> 3 )  & mask  );
  out[10] = base + ( ( ( w6 >> 46  ) | ( w7 << 18 ) )  & mask  );
  out[11] = base + ( ( ( w7 >> 25  ) | ( w8 << 39 ) )  & mask  );
  out[12] = base + ( ( w8 >> 4 )  & mask  );
  out[13] = base + ( ( ( w8 >> 47  ) | ( w9 << 17 ) )  & mask  );
  out[14] = base + ( ( ( w9 >> 26  ) | ( w10 << 38 ) )  & mask  );
  out[15] = base + ( ( w10 >> 5 )  & mask  );
  out[16] = base + ( ( ( w10 >> 48  ) | ( w11 << 16 ) )  & mask  );
  out[17] = base + ( ( ( w11 >> 27  ) | ( w12 << 37 ) )  & mask  );
  out[18] = base + ( ( w12 >> 6 )  & mask  );
  out[19] = base + ( ( ( w12 >> 49  ) | ( w13 << 15 ) )  & mask  );
  out[20] = base + ( ( ( w13 >> 28  ) | ( w14 << 36 ) )  & mask  );
  out[21] = base + ( ( w14 >> 7 )  & mask  );
  out[22] = base + ( ( ( w14 >> 50  ) | ( w15 << 14 ) )  & mask  );
  out[23] = base + ( ( ( w15 >> 29  ) | ( w16 << 35 ) )  & mask  );
  out[24] = base + ( ( w16 >> 8 )  & mask  );
  out[25] = base + ( ( ( w16 >> 51  ) | ( w17 << 13 ) )  & mask  );
  out[26] = base + ( ( ( w17 >> 30  ) | ( w18 << 34 ) )  & mask  );
  out[27] = base + ( ( w18 >> 9 )  & mask  );
  out[28] = base + ( ( ( w18 >> 52  ) | ( w19 << 12 ) )  & mask  );
  out[29] = base + ( ( ( w19 >> 31  ) | ( w20 << 33 ) )  & mask  );
  out[30] = base + ( ( w20 >> 10 )  & mask  );
  out[31] = base + ( ( ( w20 >> 53  ) | ( w21 << 11 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 44-bit values, touching 22 64-bit words, using 176 bytes */ 
static void unpackforblock44_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(17592186044415);
  /* we are going to access  22 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  *pw += 176; /* we used up 176 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 44  ) | ( w1 << 20 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 24  ) | ( w2 << 40 ) )  & mask  );
  out[3] = base + ( ( w2 >> 4 )  & mask  );
  out[4] = base + ( ( ( w2 >> 48  ) | ( w3 << 16 ) )  & mask  );
  out[5] = base + ( ( ( w3 >> 28  ) | ( w4 << 36 ) )  & mask  );
  out[6] = base + ( ( w4 >> 8 )  & mask  );
  out[7] = base + ( ( ( w4 >> 52  ) | ( w5 << 12 ) )  & mask  );
  out[8] = base + ( ( ( w5 >> 32  ) | ( w6 << 32 ) )  & mask  );
  out[9] = base + ( ( w6 >> 12 )  & mask  );
  out[10] = base + ( ( ( w6 >> 56  ) | ( w7 << 8 ) )  & mask  );
  out[11] = base + ( ( ( w7 >> 36  ) | ( w8 << 28 ) )  & mask  );
  out[12] = base + ( ( w8 >> 16 )  & mask  );
  out[13] = base + ( ( ( w8 >> 60  ) | ( w9 << 4 ) )  & mask  );
  out[14] = base + ( ( ( w9 >> 40  ) | ( w10 << 24 ) )  & mask  );
  out[15] = base + ( w10  >> 20  );
  out[16] = base + ( ( w11 )  & mask  );
  out[17] = base + ( ( ( w11 >> 44  ) | ( w12 << 20 ) )  & mask  );
  out[18] = base + ( ( ( w12 >> 24  ) | ( w13 << 40 ) )  & mask  );
  out[19] = base + ( ( w13 >> 4 )  & mask  );
  out[20] = base + ( ( ( w13 >> 48  ) | ( w14 << 16 ) )  & mask  );
  out[21] = base + ( ( ( w14 >> 28  ) | ( w15 << 36 ) )  & mask  );
  out[22] = base + ( ( w15 >> 8 )  & mask  );
  out[23] = base + ( ( ( w15 >> 52  ) | ( w16 << 12 ) )  & mask  );
  out[24] = base + ( ( ( w16 >> 32  ) | ( w17 << 32 ) )  & mask  );
  out[25] = base + ( ( w17 >> 12 )  & mask  );
  out[26] = base + ( ( ( w17 >> 56  ) | ( w18 << 8 ) )  & mask  );
  out[27] = base + ( ( ( w18 >> 36  ) | ( w19 << 28 ) )  & mask  );
  out[28] = base + ( ( w19 >> 16 )  & mask  );
  out[29] = base + ( ( ( w19 >> 60  ) | ( w20 << 4 ) )  & mask  );
  out[30] = base + ( ( ( w20 >> 40  ) | ( w21 << 24 ) )  & mask  );
  out[31] = base + ( w21  >> 20  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 45-bit values, touching 23 64-bit words, using 180 bytes */ 
static void unpackforblock45_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(35184372088831);
  /* we are going to access  23 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  *pw += 180; /* we used up 180 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 45  ) | ( w1 << 19 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 26  ) | ( w2 << 38 ) )  & mask  );
  out[3] = base + ( ( w2 >> 7 )  & mask  );
  out[4] = base + ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
  out[5] = base + ( ( ( w3 >> 33  ) | ( w4 << 31 ) )  & mask  );
  out[6] = base + ( ( w4 >> 14 )  & mask  );
  out[7] = base + ( ( ( w4 >> 59  ) | ( w5 << 5 ) )  & mask  );
  out[8] = base + ( ( ( w5 >> 40  ) | ( w6 << 24 ) )  & mask  );
  out[9] = base + ( ( ( w6 >> 21  ) | ( w7 << 43 ) )  & mask  );
  out[10] = base + ( ( w7 >> 2 )  & mask  );
  out[11] = base + ( ( ( w7 >> 47  ) | ( w8 << 17 ) )  & mask  );
  out[12] = base + ( ( ( w8 >> 28  ) | ( w9 << 36 ) )  & mask  );
  out[13] = base + ( ( w9 >> 9 )  & mask  );
  out[14] = base + ( ( ( w9 >> 54  ) | ( w10 << 10 ) )  & mask  );
  out[15] = base + ( ( ( w10 >> 35  ) | ( w11 << 29 ) )  & mask  );
  out[16] = base + ( ( w11 >> 16 )  & mask  );
  out[17] = base + ( ( ( w11 >> 61  ) | ( w12 << 3 ) )  & mask  );
  out[18] = base + ( ( ( w12 >> 42  ) | ( w13 << 22 ) )  & mask  );
  out[19] = base + ( ( ( w13 >> 23  ) | ( w14 << 41 ) )  & mask  );
  out[20] = base + ( ( w14 >> 4 )  & mask  );
  out[21] = base + ( ( ( w14 >> 49  ) | ( w15 << 15 ) )  & mask  );
  out[22] = base + ( ( ( w15 >> 30  ) | ( w16 << 34 ) )  & mask  );
  out[23] = base + ( ( w16 >> 11 )  & mask  );
  out[24] = base + ( ( ( w16 >> 56  ) | ( w17 << 8 ) )  & mask  );
  out[25] = base + ( ( ( w17 >> 37  ) | ( w18 << 27 ) )  & mask  );
  out[26] = base + ( ( w18 >> 18 )  & mask  );
  out[27] = base + ( ( ( w18 >> 63  ) | ( w19 << 1 ) )  & mask  );
  out[28] = base + ( ( ( w19 >> 44  ) | ( w20 << 20 ) )  & mask  );
  out[29] = base + ( ( ( w20 >> 25  ) | ( w21 << 39 ) )  & mask  );
  out[30] = base + ( ( w21 >> 6 )  & mask  );
  out[31] = base + ( ( ( w21 >> 51  ) | ( w22 << 13 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 46-bit values, touching 23 64-bit words, using 184 bytes */ 
static void unpackforblock46_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(70368744177663);
  /* we are going to access  23 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  *pw += 184; /* we used up 184 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 46  ) | ( w1 << 18 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 28  ) | ( w2 << 36 ) )  & mask  );
  out[3] = base + ( ( w2 >> 10 )  & mask  );
  out[4] = base + ( ( ( w2 >> 56  ) | ( w3 << 8 ) )  & mask  );
  out[5] = base + ( ( ( w3 >> 38  ) | ( w4 << 26 ) )  & mask  );
  out[6] = base + ( ( ( w4 >> 20  ) | ( w5 << 44 ) )  & mask  );
  out[7] = base + ( ( w5 >> 2 )  & mask  );
  out[8] = base + ( ( ( w5 >> 48  ) | ( w6 << 16 ) )  & mask  );
  out[9] = base + ( ( ( w6 >> 30  ) | ( w7 << 34 ) )  & mask  );
  out[10] = base + ( ( w7 >> 12 )  & mask  );
  out[11] = base + ( ( ( w7 >> 58  ) | ( w8 << 6 ) )  & mask  );
  out[12] = base + ( ( ( w8 >> 40  ) | ( w9 << 24 ) )  & mask  );
  out[13] = base + ( ( ( w9 >> 22  ) | ( w10 << 42 ) )  & mask  );
  out[14] = base + ( ( w10 >> 4 )  & mask  );
  out[15] = base + ( ( ( w10 >> 50  ) | ( w11 << 14 ) )  & mask  );
  out[16] = base + ( ( ( w11 >> 32  ) | ( w12 << 32 ) )  & mask  );
  out[17] = base + ( ( w12 >> 14 )  & mask  );
  out[18] = base + ( ( ( w12 >> 60  ) | ( w13 << 4 ) )  & mask  );
  out[19] = base + ( ( ( w13 >> 42  ) | ( w14 << 22 ) )  & mask  );
  out[20] = base + ( ( ( w14 >> 24  ) | ( w15 << 40 ) )  & mask  );
  out[21] = base + ( ( w15 >> 6 )  & mask  );
  out[22] = base + ( ( ( w15 >> 52  ) | ( w16 << 12 ) )  & mask  );
  out[23] = base + ( ( ( w16 >> 34  ) | ( w17 << 30 ) )  & mask  );
  out[24] = base + ( ( w17 >> 16 )  & mask  );
  out[25] = base + ( ( ( w17 >> 62  ) | ( w18 << 2 ) )  & mask  );
  out[26] = base + ( ( ( w18 >> 44  ) | ( w19 << 20 ) )  & mask  );
  out[27] = base + ( ( ( w19 >> 26  ) | ( w20 << 38 ) )  & mask  );
  out[28] = base + ( ( w20 >> 8 )  & mask  );
  out[29] = base + ( ( ( w20 >> 54  ) | ( w21 << 10 ) )  & mask  );
  out[30] = base + ( ( ( w21 >> 36  ) | ( w22 << 28 ) )  & mask  );
  out[31] = base + ( w22  >> 18  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 47-bit values, touching 24 64-bit words, using 188 bytes */ 
static void unpackforblock47_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(140737488355327);
  /* we are going to access  24 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  *pw += 188; /* we used up 188 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 47  ) | ( w1 << 17 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 30  ) | ( w2 << 34 ) )  & mask  );
  out[3] = base + ( ( w2 >> 13 )  & mask  );
  out[4] = base + ( ( ( w2 >> 60  ) | ( w3 << 4 ) )  & mask  );
  out[5] = base + ( ( ( w3 >> 43  ) | ( w4 << 21 ) )  & mask  );
  out[6] = base + ( ( ( w4 >> 26  ) | ( w5 << 38 ) )  & mask  );
  out[7] = base + ( ( w5 >> 9 )  & mask  );
  out[8] = base + ( ( ( w5 >> 56  ) | ( w6 << 8 ) )  & mask  );
  out[9] = base + ( ( ( w6 >> 39  ) | ( w7 << 25 ) )  & mask  );
  out[10] = base + ( ( ( w7 >> 22  ) | ( w8 << 42 ) )  & mask  );
  out[11] = base + ( ( w8 >> 5 )  & mask  );
  out[12] = base + ( ( ( w8 >> 52  ) | ( w9 << 12 ) )  & mask  );
  out[13] = base + ( ( ( w9 >> 35  ) | ( w10 << 29 ) )  & mask  );
  out[14] = base + ( ( ( w10 >> 18  ) | ( w11 << 46 ) )  & mask  );
  out[15] = base + ( ( w11 >> 1 )  & mask  );
  out[16] = base + ( ( ( w11 >> 48  ) | ( w12 << 16 ) )  & mask  );
  out[17] = base + ( ( ( w12 >> 31  ) | ( w13 << 33 ) )  & mask  );
  out[18] = base + ( ( w13 >> 14 )  & mask  );
  out[19] = base + ( ( ( w13 >> 61  ) | ( w14 << 3 ) )  & mask  );
  out[20] = base + ( ( ( w14 >> 44  ) | ( w15 << 20 ) )  & mask  );
  out[21] = base + ( ( ( w15 >> 27  ) | ( w16 << 37 ) )  & mask  );
  out[22] = base + ( ( w16 >> 10 )  & mask  );
  out[23] = base + ( ( ( w16 >> 57  ) | ( w17 << 7 ) )  & mask  );
  out[24] = base + ( ( ( w17 >> 40  ) | ( w18 << 24 ) )  & mask  );
  out[25] = base + ( ( ( w18 >> 23  ) | ( w19 << 41 ) )  & mask  );
  out[26] = base + ( ( w19 >> 6 )  & mask  );
  out[27] = base + ( ( ( w19 >> 53  ) | ( w20 << 11 ) )  & mask  );
  out[28] = base + ( ( ( w20 >> 36  ) | ( w21 << 28 ) )  & mask  );
  out[29] = base + ( ( ( w21 >> 19  ) | ( w22 << 45 ) )  & mask  );
  out[30] = base + ( ( w22 >> 2 )  & mask  );
  out[31] = base + ( ( ( w22 >> 49  ) | ( w23 << 15 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 48-bit values, touching 24 64-bit words, using 192 bytes */ 
static void unpackforblock48_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(281474976710655);
  /* we are going to access  24 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  *pw += 192; /* we used up 192 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 48  ) | ( w1 << 16 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 32  ) | ( w2 << 32 ) )  & mask  );
  out[3] = base + ( w2  >> 16  );
  out[4] = base + ( ( w3 )  & mask  );
  out[5] = base + ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
  out[6] = base + ( ( ( w4 >> 32  ) | ( w5 << 32 ) )  & mask  );
  out[7] = base + ( w5  >> 16  );
  out[8] = base + ( ( w6 )  & mask  );
  out[9] = base + ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
  out[10] = base + ( ( ( w7 >> 32  ) | ( w8 << 32 ) )  & mask  );
  out[11] = base + ( w8  >> 16  );
  out[12] = base + ( ( w9 )  & mask  );
  out[13] = base + ( ( ( w9 >> 48  ) | ( w10 << 16 ) )  & mask  );
  out[14] = base + ( ( ( w10 >> 32  ) | ( w11 << 32 ) )  & mask  );
  out[15] = base + ( w11  >> 16  );
  out[16] = base + ( ( w12 )  & mask  );
  out[17] = base + ( ( ( w12 >> 48  ) | ( w13 << 16 ) )  & mask  );
  out[18] = base + ( ( ( w13 >> 32  ) | ( w14 << 32 ) )  & mask  );
  out[19] = base + ( w14  >> 16  );
  out[20] = base + ( ( w15 )  & mask  );
  out[21] = base + ( ( ( w15 >> 48  ) | ( w16 << 16 ) )  & mask  );
  out[22] = base + ( ( ( w16 >> 32  ) | ( w17 << 32 ) )  & mask  );
  out[23] = base + ( w17  >> 16  );
  out[24] = base + ( ( w18 )  & mask  );
  out[25] = base + ( ( ( w18 >> 48  ) | ( w19 << 16 ) )  & mask  );
  out[26] = base + ( ( ( w19 >> 32  ) | ( w20 << 32 ) )  & mask  );
  out[27] = base + ( w20  >> 16  );
  out[28] = base + ( ( w21 )  & mask  );
  out[29] = base + ( ( ( w21 >> 48  ) | ( w22 << 16 ) )  & mask  );
  out[30] = base + ( ( ( w22 >> 32  ) | ( w23 << 32 ) )  & mask  );
  out[31] = base + ( w23  >> 16  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 49-bit values, touching 25 64-bit words, using 196 bytes */ 
static void unpackforblock49_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(562949953421311);
  /* we are going to access  25 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  *pw += 196; /* we used up 196 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 49  ) | ( w1 << 15 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 34  ) | ( w2 << 30 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 19  ) | ( w3 << 45 ) )  & mask  );
  out[4] = base + ( ( w3 >> 4 )  & mask  );
  out[5] = base + ( ( ( w3 >> 53  ) | ( w4 << 11 ) )  & mask  );
  out[6] = base + ( ( ( w4 >> 38  ) | ( w5 << 26 ) )  & mask  );
  out[7] = base + ( ( ( w5 >> 23  ) | ( w6 << 41 ) )  & mask  );
  out[8] = base + ( ( w6 >> 8 )  & mask  );
  out[9] = base + ( ( ( w6 >> 57  ) | ( w7 << 7 ) )  & mask  );
  out[10] = base + ( ( ( w7 >> 42  ) | ( w8 << 22 ) )  & mask  );
  out[11] = base + ( ( ( w8 >> 27  ) | ( w9 << 37 ) )  & mask  );
  out[12] = base + ( ( w9 >> 12 )  & mask  );
  out[13] = base + ( ( ( w9 >> 61  ) | ( w10 << 3 ) )  & mask  );
  out[14] = base + ( ( ( w10 >> 46  ) | ( w11 << 18 ) )  & mask  );
  out[15] = base + ( ( ( w11 >> 31  ) | ( w12 << 33 ) )  & mask  );
  out[16] = base + ( ( ( w12 >> 16  ) | ( w13 << 48 ) )  & mask  );
  out[17] = base + ( ( w13 >> 1 )  & mask  );
  out[18] = base + ( ( ( w13 >> 50  ) | ( w14 << 14 ) )  & mask  );
  out[19] = base + ( ( ( w14 >> 35  ) | ( w15 << 29 ) )  & mask  );
  out[20] = base + ( ( ( w15 >> 20  ) | ( w16 << 44 ) )  & mask  );
  out[21] = base + ( ( w16 >> 5 )  & mask  );
  out[22] = base + ( ( ( w16 >> 54  ) | ( w17 << 10 ) )  & mask  );
  out[23] = base + ( ( ( w17 >> 39  ) | ( w18 << 25 ) )  & mask  );
  out[24] = base + ( ( ( w18 >> 24  ) | ( w19 << 40 ) )  & mask  );
  out[25] = base + ( ( w19 >> 9 )  & mask  );
  out[26] = base + ( ( ( w19 >> 58  ) | ( w20 << 6 ) )  & mask  );
  out[27] = base + ( ( ( w20 >> 43  ) | ( w21 << 21 ) )  & mask  );
  out[28] = base + ( ( ( w21 >> 28  ) | ( w22 << 36 ) )  & mask  );
  out[29] = base + ( ( w22 >> 13 )  & mask  );
  out[30] = base + ( ( ( w22 >> 62  ) | ( w23 << 2 ) )  & mask  );
  out[31] = base + ( ( ( w23 >> 47  ) | ( w24 << 17 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 50-bit values, touching 25 64-bit words, using 200 bytes */ 
static void unpackforblock50_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(1125899906842623);
  /* we are going to access  25 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  *pw += 200; /* we used up 200 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 50  ) | ( w1 << 14 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 36  ) | ( w2 << 28 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 22  ) | ( w3 << 42 ) )  & mask  );
  out[4] = base + ( ( w3 >> 8 )  & mask  );
  out[5] = base + ( ( ( w3 >> 58  ) | ( w4 << 6 ) )  & mask  );
  out[6] = base + ( ( ( w4 >> 44  ) | ( w5 << 20 ) )  & mask  );
  out[7] = base + ( ( ( w5 >> 30  ) | ( w6 << 34 ) )  & mask  );
  out[8] = base + ( ( ( w6 >> 16  ) | ( w7 << 48 ) )  & mask  );
  out[9] = base + ( ( w7 >> 2 )  & mask  );
  out[10] = base + ( ( ( w7 >> 52  ) | ( w8 << 12 ) )  & mask  );
  out[11] = base + ( ( ( w8 >> 38  ) | ( w9 << 26 ) )  & mask  );
  out[12] = base + ( ( ( w9 >> 24  ) | ( w10 << 40 ) )  & mask  );
  out[13] = base + ( ( w10 >> 10 )  & mask  );
  out[14] = base + ( ( ( w10 >> 60  ) | ( w11 << 4 ) )  & mask  );
  out[15] = base + ( ( ( w11 >> 46  ) | ( w12 << 18 ) )  & mask  );
  out[16] = base + ( ( ( w12 >> 32  ) | ( w13 << 32 ) )  & mask  );
  out[17] = base + ( ( ( w13 >> 18  ) | ( w14 << 46 ) )  & mask  );
  out[18] = base + ( ( w14 >> 4 )  & mask  );
  out[19] = base + ( ( ( w14 >> 54  ) | ( w15 << 10 ) )  & mask  );
  out[20] = base + ( ( ( w15 >> 40  ) | ( w16 << 24 ) )  & mask  );
  out[21] = base + ( ( ( w16 >> 26  ) | ( w17 << 38 ) )  & mask  );
  out[22] = base + ( ( w17 >> 12 )  & mask  );
  out[23] = base + ( ( ( w17 >> 62  ) | ( w18 << 2 ) )  & mask  );
  out[24] = base + ( ( ( w18 >> 48  ) | ( w19 << 16 ) )  & mask  );
  out[25] = base + ( ( ( w19 >> 34  ) | ( w20 << 30 ) )  & mask  );
  out[26] = base + ( ( ( w20 >> 20  ) | ( w21 << 44 ) )  & mask  );
  out[27] = base + ( ( w21 >> 6 )  & mask  );
  out[28] = base + ( ( ( w21 >> 56  ) | ( w22 << 8 ) )  & mask  );
  out[29] = base + ( ( ( w22 >> 42  ) | ( w23 << 22 ) )  & mask  );
  out[30] = base + ( ( ( w23 >> 28  ) | ( w24 << 36 ) )  & mask  );
  out[31] = base + ( w24  >> 14  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 51-bit values, touching 26 64-bit words, using 204 bytes */ 
static void unpackforblock51_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(2251799813685247);
  /* we are going to access  26 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  *pw += 204; /* we used up 204 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 51  ) | ( w1 << 13 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 38  ) | ( w2 << 26 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 25  ) | ( w3 << 39 ) )  & mask  );
  out[4] = base + ( ( w3 >> 12 )  & mask  );
  out[5] = base + ( ( ( w3 >> 63  ) | ( w4 << 1 ) )  & mask  );
  out[6] = base + ( ( ( w4 >> 50  ) | ( w5 << 14 ) )  & mask  );
  out[7] = base + ( ( ( w5 >> 37  ) | ( w6 << 27 ) )  & mask  );
  out[8] = base + ( ( ( w6 >> 24  ) | ( w7 << 40 ) )  & mask  );
  out[9] = base + ( ( w7 >> 11 )  & mask  );
  out[10] = base + ( ( ( w7 >> 62  ) | ( w8 << 2 ) )  & mask  );
  out[11] = base + ( ( ( w8 >> 49  ) | ( w9 << 15 ) )  & mask  );
  out[12] = base + ( ( ( w9 >> 36  ) | ( w10 << 28 ) )  & mask  );
  out[13] = base + ( ( ( w10 >> 23  ) | ( w11 << 41 ) )  & mask  );
  out[14] = base + ( ( w11 >> 10 )  & mask  );
  out[15] = base + ( ( ( w11 >> 61  ) | ( w12 << 3 ) )  & mask  );
  out[16] = base + ( ( ( w12 >> 48  ) | ( w13 << 16 ) )  & mask  );
  out[17] = base + ( ( ( w13 >> 35  ) | ( w14 << 29 ) )  & mask  );
  out[18] = base + ( ( ( w14 >> 22  ) | ( w15 << 42 ) )  & mask  );
  out[19] = base + ( ( w15 >> 9 )  & mask  );
  out[20] = base + ( ( ( w15 >> 60  ) | ( w16 << 4 ) )  & mask  );
  out[21] = base + ( ( ( w16 >> 47  ) | ( w17 << 17 ) )  & mask  );
  out[22] = base + ( ( ( w17 >> 34  ) | ( w18 << 30 ) )  & mask  );
  out[23] = base + ( ( ( w18 >> 21  ) | ( w19 << 43 ) )  & mask  );
  out[24] = base + ( ( w19 >> 8 )  & mask  );
  out[25] = base + ( ( ( w19 >> 59  ) | ( w20 << 5 ) )  & mask  );
  out[26] = base + ( ( ( w20 >> 46  ) | ( w21 << 18 ) )  & mask  );
  out[27] = base + ( ( ( w21 >> 33  ) | ( w22 << 31 ) )  & mask  );
  out[28] = base + ( ( ( w22 >> 20  ) | ( w23 << 44 ) )  & mask  );
  out[29] = base + ( ( w23 >> 7 )  & mask  );
  out[30] = base + ( ( ( w23 >> 58  ) | ( w24 << 6 ) )  & mask  );
  out[31] = base + ( ( ( w24 >> 45  ) | ( w25 << 19 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 52-bit values, touching 26 64-bit words, using 208 bytes */ 
static void unpackforblock52_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(4503599627370495);
  /* we are going to access  26 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  *pw += 208; /* we used up 208 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 52  ) | ( w1 << 12 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 40  ) | ( w2 << 24 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 28  ) | ( w3 << 36 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 16  ) | ( w4 << 48 ) )  & mask  );
  out[5] = base + ( ( w4 >> 4 )  & mask  );
  out[6] = base + ( ( ( w4 >> 56  ) | ( w5 << 8 ) )  & mask  );
  out[7] = base + ( ( ( w5 >> 44  ) | ( w6 << 20 ) )  & mask  );
  out[8] = base + ( ( ( w6 >> 32  ) | ( w7 << 32 ) )  & mask  );
  out[9] = base + ( ( ( w7 >> 20  ) | ( w8 << 44 ) )  & mask  );
  out[10] = base + ( ( w8 >> 8 )  & mask  );
  out[11] = base + ( ( ( w8 >> 60  ) | ( w9 << 4 ) )  & mask  );
  out[12] = base + ( ( ( w9 >> 48  ) | ( w10 << 16 ) )  & mask  );
  out[13] = base + ( ( ( w10 >> 36  ) | ( w11 << 28 ) )  & mask  );
  out[14] = base + ( ( ( w11 >> 24  ) | ( w12 << 40 ) )  & mask  );
  out[15] = base + ( w12  >> 12  );
  out[16] = base + ( ( w13 )  & mask  );
  out[17] = base + ( ( ( w13 >> 52  ) | ( w14 << 12 ) )  & mask  );
  out[18] = base + ( ( ( w14 >> 40  ) | ( w15 << 24 ) )  & mask  );
  out[19] = base + ( ( ( w15 >> 28  ) | ( w16 << 36 ) )  & mask  );
  out[20] = base + ( ( ( w16 >> 16  ) | ( w17 << 48 ) )  & mask  );
  out[21] = base + ( ( w17 >> 4 )  & mask  );
  out[22] = base + ( ( ( w17 >> 56  ) | ( w18 << 8 ) )  & mask  );
  out[23] = base + ( ( ( w18 >> 44  ) | ( w19 << 20 ) )  & mask  );
  out[24] = base + ( ( ( w19 >> 32  ) | ( w20 << 32 ) )  & mask  );
  out[25] = base + ( ( ( w20 >> 20  ) | ( w21 << 44 ) )  & mask  );
  out[26] = base + ( ( w21 >> 8 )  & mask  );
  out[27] = base + ( ( ( w21 >> 60  ) | ( w22 << 4 ) )  & mask  );
  out[28] = base + ( ( ( w22 >> 48  ) | ( w23 << 16 ) )  & mask  );
  out[29] = base + ( ( ( w23 >> 36  ) | ( w24 << 28 ) )  & mask  );
  out[30] = base + ( ( ( w24 >> 24  ) | ( w25 << 40 ) )  & mask  );
  out[31] = base + ( w25  >> 12  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 53-bit values, touching 27 64-bit words, using 212 bytes */ 
static void unpackforblock53_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(9007199254740991);
  /* we are going to access  27 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  *pw += 212; /* we used up 212 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 53  ) | ( w1 << 11 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 42  ) | ( w2 << 22 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 31  ) | ( w3 << 33 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 20  ) | ( w4 << 44 ) )  & mask  );
  out[5] = base + ( ( w4 >> 9 )  & mask  );
  out[6] = base + ( ( ( w4 >> 62  ) | ( w5 << 2 ) )  & mask  );
  out[7] = base + ( ( ( w5 >> 51  ) | ( w6 << 13 ) )  & mask  );
  out[8] = base + ( ( ( w6 >> 40  ) | ( w7 << 24 ) )  & mask  );
  out[9] = base + ( ( ( w7 >> 29  ) | ( w8 << 35 ) )  & mask  );
  out[10] = base + ( ( ( w8 >> 18  ) | ( w9 << 46 ) )  & mask  );
  out[11] = base + ( ( w9 >> 7 )  & mask  );
  out[12] = base + ( ( ( w9 >> 60  ) | ( w10 << 4 ) )  & mask  );
  out[13] = base + ( ( ( w10 >> 49  ) | ( w11 << 15 ) )  & mask  );
  out[14] = base + ( ( ( w11 >> 38  ) | ( w12 << 26 ) )  & mask  );
  out[15] = base + ( ( ( w12 >> 27  ) | ( w13 << 37 ) )  & mask  );
  out[16] = base + ( ( ( w13 >> 16  ) | ( w14 << 48 ) )  & mask  );
  out[17] = base + ( ( w14 >> 5 )  & mask  );
  out[18] = base + ( ( ( w14 >> 58  ) | ( w15 << 6 ) )  & mask  );
  out[19] = base + ( ( ( w15 >> 47  ) | ( w16 << 17 ) )  & mask  );
  out[20] = base + ( ( ( w16 >> 36  ) | ( w17 << 28 ) )  & mask  );
  out[21] = base + ( ( ( w17 >> 25  ) | ( w18 << 39 ) )  & mask  );
  out[22] = base + ( ( ( w18 >> 14  ) | ( w19 << 50 ) )  & mask  );
  out[23] = base + ( ( w19 >> 3 )  & mask  );
  out[24] = base + ( ( ( w19 >> 56  ) | ( w20 << 8 ) )  & mask  );
  out[25] = base + ( ( ( w20 >> 45  ) | ( w21 << 19 ) )  & mask  );
  out[26] = base + ( ( ( w21 >> 34  ) | ( w22 << 30 ) )  & mask  );
  out[27] = base + ( ( ( w22 >> 23  ) | ( w23 << 41 ) )  & mask  );
  out[28] = base + ( ( ( w23 >> 12  ) | ( w24 << 52 ) )  & mask  );
  out[29] = base + ( ( w24 >> 1 )  & mask  );
  out[30] = base + ( ( ( w24 >> 54  ) | ( w25 << 10 ) )  & mask  );
  out[31] = base + ( ( ( w25 >> 43  ) | ( w26 << 21 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 54-bit values, touching 27 64-bit words, using 216 bytes */ 
static void unpackforblock54_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(18014398509481983);
  /* we are going to access  27 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  *pw += 216; /* we used up 216 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 54  ) | ( w1 << 10 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 44  ) | ( w2 << 20 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 34  ) | ( w3 << 30 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 24  ) | ( w4 << 40 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 14  ) | ( w5 << 50 ) )  & mask  );
  out[6] = base + ( ( w5 >> 4 )  & mask  );
  out[7] = base + ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
  out[8] = base + ( ( ( w6 >> 48  ) | ( w7 << 16 ) )  & mask  );
  out[9] = base + ( ( ( w7 >> 38  ) | ( w8 << 26 ) )  & mask  );
  out[10] = base + ( ( ( w8 >> 28  ) | ( w9 << 36 ) )  & mask  );
  out[11] = base + ( ( ( w9 >> 18  ) | ( w10 << 46 ) )  & mask  );
  out[12] = base + ( ( w10 >> 8 )  & mask  );
  out[13] = base + ( ( ( w10 >> 62  ) | ( w11 << 2 ) )  & mask  );
  out[14] = base + ( ( ( w11 >> 52  ) | ( w12 << 12 ) )  & mask  );
  out[15] = base + ( ( ( w12 >> 42  ) | ( w13 << 22 ) )  & mask  );
  out[16] = base + ( ( ( w13 >> 32  ) | ( w14 << 32 ) )  & mask  );
  out[17] = base + ( ( ( w14 >> 22  ) | ( w15 << 42 ) )  & mask  );
  out[18] = base + ( ( ( w15 >> 12  ) | ( w16 << 52 ) )  & mask  );
  out[19] = base + ( ( w16 >> 2 )  & mask  );
  out[20] = base + ( ( ( w16 >> 56  ) | ( w17 << 8 ) )  & mask  );
  out[21] = base + ( ( ( w17 >> 46  ) | ( w18 << 18 ) )  & mask  );
  out[22] = base + ( ( ( w18 >> 36  ) | ( w19 << 28 ) )  & mask  );
  out[23] = base + ( ( ( w19 >> 26  ) | ( w20 << 38 ) )  & mask  );
  out[24] = base + ( ( ( w20 >> 16  ) | ( w21 << 48 ) )  & mask  );
  out[25] = base + ( ( w21 >> 6 )  & mask  );
  out[26] = base + ( ( ( w21 >> 60  ) | ( w22 << 4 ) )  & mask  );
  out[27] = base + ( ( ( w22 >> 50  ) | ( w23 << 14 ) )  & mask  );
  out[28] = base + ( ( ( w23 >> 40  ) | ( w24 << 24 ) )  & mask  );
  out[29] = base + ( ( ( w24 >> 30  ) | ( w25 << 34 ) )  & mask  );
  out[30] = base + ( ( ( w25 >> 20  ) | ( w26 << 44 ) )  & mask  );
  out[31] = base + ( w26  >> 10  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 55-bit values, touching 28 64-bit words, using 220 bytes */ 
static void unpackforblock55_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(36028797018963967);
  /* we are going to access  28 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  *pw += 220; /* we used up 220 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 55  ) | ( w1 << 9 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 46  ) | ( w2 << 18 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 37  ) | ( w3 << 27 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 28  ) | ( w4 << 36 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 19  ) | ( w5 << 45 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 10  ) | ( w6 << 54 ) )  & mask  );
  out[7] = base + ( ( w6 >> 1 )  & mask  );
  out[8] = base + ( ( ( w6 >> 56  ) | ( w7 << 8 ) )  & mask  );
  out[9] = base + ( ( ( w7 >> 47  ) | ( w8 << 17 ) )  & mask  );
  out[10] = base + ( ( ( w8 >> 38  ) | ( w9 << 26 ) )  & mask  );
  out[11] = base + ( ( ( w9 >> 29  ) | ( w10 << 35 ) )  & mask  );
  out[12] = base + ( ( ( w10 >> 20  ) | ( w11 << 44 ) )  & mask  );
  out[13] = base + ( ( ( w11 >> 11  ) | ( w12 << 53 ) )  & mask  );
  out[14] = base + ( ( w12 >> 2 )  & mask  );
  out[15] = base + ( ( ( w12 >> 57  ) | ( w13 << 7 ) )  & mask  );
  out[16] = base + ( ( ( w13 >> 48  ) | ( w14 << 16 ) )  & mask  );
  out[17] = base + ( ( ( w14 >> 39  ) | ( w15 << 25 ) )  & mask  );
  out[18] = base + ( ( ( w15 >> 30  ) | ( w16 << 34 ) )  & mask  );
  out[19] = base + ( ( ( w16 >> 21  ) | ( w17 << 43 ) )  & mask  );
  out[20] = base + ( ( ( w17 >> 12  ) | ( w18 << 52 ) )  & mask  );
  out[21] = base + ( ( w18 >> 3 )  & mask  );
  out[22] = base + ( ( ( w18 >> 58  ) | ( w19 << 6 ) )  & mask  );
  out[23] = base + ( ( ( w19 >> 49  ) | ( w20 << 15 ) )  & mask  );
  out[24] = base + ( ( ( w20 >> 40  ) | ( w21 << 24 ) )  & mask  );
  out[25] = base + ( ( ( w21 >> 31  ) | ( w22 << 33 ) )  & mask  );
  out[26] = base + ( ( ( w22 >> 22  ) | ( w23 << 42 ) )  & mask  );
  out[27] = base + ( ( ( w23 >> 13  ) | ( w24 << 51 ) )  & mask  );
  out[28] = base + ( ( w24 >> 4 )  & mask  );
  out[29] = base + ( ( ( w24 >> 59  ) | ( w25 << 5 ) )  & mask  );
  out[30] = base + ( ( ( w25 >> 50  ) | ( w26 << 14 ) )  & mask  );
  out[31] = base + ( ( ( w26 >> 41  ) | ( w27 << 23 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 56-bit values, touching 28 64-bit words, using 224 bytes */ 
static void unpackforblock56_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(72057594037927935);
  /* we are going to access  28 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  *pw += 224; /* we used up 224 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 56  ) | ( w1 << 8 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 48  ) | ( w2 << 16 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 40  ) | ( w3 << 24 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 32  ) | ( w4 << 32 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 24  ) | ( w5 << 40 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 16  ) | ( w6 << 48 ) )  & mask  );
  out[7] = base + ( w6  >> 8  );
  out[8] = base + ( ( w7 )  & mask  );
  out[9] = base + ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
  out[10] = base + ( ( ( w8 >> 48  ) | ( w9 << 16 ) )  & mask  );
  out[11] = base + ( ( ( w9 >> 40  ) | ( w10 << 24 ) )  & mask  );
  out[12] = base + ( ( ( w10 >> 32  ) | ( w11 << 32 ) )  & mask  );
  out[13] = base + ( ( ( w11 >> 24  ) | ( w12 << 40 ) )  & mask  );
  out[14] = base + ( ( ( w12 >> 16  ) | ( w13 << 48 ) )  & mask  );
  out[15] = base + ( w13  >> 8  );
  out[16] = base + ( ( w14 )  & mask  );
  out[17] = base + ( ( ( w14 >> 56  ) | ( w15 << 8 ) )  & mask  );
  out[18] = base + ( ( ( w15 >> 48  ) | ( w16 << 16 ) )  & mask  );
  out[19] = base + ( ( ( w16 >> 40  ) | ( w17 << 24 ) )  & mask  );
  out[20] = base + ( ( ( w17 >> 32  ) | ( w18 << 32 ) )  & mask  );
  out[21] = base + ( ( ( w18 >> 24  ) | ( w19 << 40 ) )  & mask  );
  out[22] = base + ( ( ( w19 >> 16  ) | ( w20 << 48 ) )  & mask  );
  out[23] = base + ( w20  >> 8  );
  out[24] = base + ( ( w21 )  & mask  );
  out[25] = base + ( ( ( w21 >> 56  ) | ( w22 << 8 ) )  & mask  );
  out[26] = base + ( ( ( w22 >> 48  ) | ( w23 << 16 ) )  & mask  );
  out[27] = base + ( ( ( w23 >> 40  ) | ( w24 << 24 ) )  & mask  );
  out[28] = base + ( ( ( w24 >> 32  ) | ( w25 << 32 ) )  & mask  );
  out[29] = base + ( ( ( w25 >> 24  ) | ( w26 << 40 ) )  & mask  );
  out[30] = base + ( ( ( w26 >> 16  ) | ( w27 << 48 ) )  & mask  );
  out[31] = base + ( w27  >> 8  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 57-bit values, touching 29 64-bit words, using 228 bytes */ 
static void unpackforblock57_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(144115188075855871);
  /* we are going to access  29 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  uint64_t w28 = pw64[28];
  *pw += 228; /* we used up 228 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 57  ) | ( w1 << 7 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 50  ) | ( w2 << 14 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 43  ) | ( w3 << 21 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 36  ) | ( w4 << 28 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 29  ) | ( w5 << 35 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 22  ) | ( w6 << 42 ) )  & mask  );
  out[7] = base + ( ( ( w6 >> 15  ) | ( w7 << 49 ) )  & mask  );
  out[8] = base + ( ( ( w7 >> 8  ) | ( w8 << 56 ) )  & mask  );
  out[9] = base + ( ( w8 >> 1 )  & mask  );
  out[10] = base + ( ( ( w8 >> 58  ) | ( w9 << 6 ) )  & mask  );
  out[11] = base + ( ( ( w9 >> 51  ) | ( w10 << 13 ) )  & mask  );
  out[12] = base + ( ( ( w10 >> 44  ) | ( w11 << 20 ) )  & mask  );
  out[13] = base + ( ( ( w11 >> 37  ) | ( w12 << 27 ) )  & mask  );
  out[14] = base + ( ( ( w12 >> 30  ) | ( w13 << 34 ) )  & mask  );
  out[15] = base + ( ( ( w13 >> 23  ) | ( w14 << 41 ) )  & mask  );
  out[16] = base + ( ( ( w14 >> 16  ) | ( w15 << 48 ) )  & mask  );
  out[17] = base + ( ( ( w15 >> 9  ) | ( w16 << 55 ) )  & mask  );
  out[18] = base + ( ( w16 >> 2 )  & mask  );
  out[19] = base + ( ( ( w16 >> 59  ) | ( w17 << 5 ) )  & mask  );
  out[20] = base + ( ( ( w17 >> 52  ) | ( w18 << 12 ) )  & mask  );
  out[21] = base + ( ( ( w18 >> 45  ) | ( w19 << 19 ) )  & mask  );
  out[22] = base + ( ( ( w19 >> 38  ) | ( w20 << 26 ) )  & mask  );
  out[23] = base + ( ( ( w20 >> 31  ) | ( w21 << 33 ) )  & mask  );
  out[24] = base + ( ( ( w21 >> 24  ) | ( w22 << 40 ) )  & mask  );
  out[25] = base + ( ( ( w22 >> 17  ) | ( w23 << 47 ) )  & mask  );
  out[26] = base + ( ( ( w23 >> 10  ) | ( w24 << 54 ) )  & mask  );
  out[27] = base + ( ( w24 >> 3 )  & mask  );
  out[28] = base + ( ( ( w24 >> 60  ) | ( w25 << 4 ) )  & mask  );
  out[29] = base + ( ( ( w25 >> 53  ) | ( w26 << 11 ) )  & mask  );
  out[30] = base + ( ( ( w26 >> 46  ) | ( w27 << 18 ) )  & mask  );
  out[31] = base + ( ( ( w27 >> 39  ) | ( w28 << 25 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 58-bit values, touching 29 64-bit words, using 232 bytes */ 
static void unpackforblock58_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(288230376151711743);
  /* we are going to access  29 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  uint64_t w28 = pw64[28];
  *pw += 232; /* we used up 232 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 58  ) | ( w1 << 6 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 52  ) | ( w2 << 12 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 46  ) | ( w3 << 18 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 40  ) | ( w4 << 24 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 34  ) | ( w5 << 30 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 28  ) | ( w6 << 36 ) )  & mask  );
  out[7] = base + ( ( ( w6 >> 22  ) | ( w7 << 42 ) )  & mask  );
  out[8] = base + ( ( ( w7 >> 16  ) | ( w8 << 48 ) )  & mask  );
  out[9] = base + ( ( ( w8 >> 10  ) | ( w9 << 54 ) )  & mask  );
  out[10] = base + ( ( w9 >> 4 )  & mask  );
  out[11] = base + ( ( ( w9 >> 62  ) | ( w10 << 2 ) )  & mask  );
  out[12] = base + ( ( ( w10 >> 56  ) | ( w11 << 8 ) )  & mask  );
  out[13] = base + ( ( ( w11 >> 50  ) | ( w12 << 14 ) )  & mask  );
  out[14] = base + ( ( ( w12 >> 44  ) | ( w13 << 20 ) )  & mask  );
  out[15] = base + ( ( ( w13 >> 38  ) | ( w14 << 26 ) )  & mask  );
  out[16] = base + ( ( ( w14 >> 32  ) | ( w15 << 32 ) )  & mask  );
  out[17] = base + ( ( ( w15 >> 26  ) | ( w16 << 38 ) )  & mask  );
  out[18] = base + ( ( ( w16 >> 20  ) | ( w17 << 44 ) )  & mask  );
  out[19] = base + ( ( ( w17 >> 14  ) | ( w18 << 50 ) )  & mask  );
  out[20] = base + ( ( ( w18 >> 8  ) | ( w19 << 56 ) )  & mask  );
  out[21] = base + ( ( w19 >> 2 )  & mask  );
  out[22] = base + ( ( ( w19 >> 60  ) | ( w20 << 4 ) )  & mask  );
  out[23] = base + ( ( ( w20 >> 54  ) | ( w21 << 10 ) )  & mask  );
  out[24] = base + ( ( ( w21 >> 48  ) | ( w22 << 16 ) )  & mask  );
  out[25] = base + ( ( ( w22 >> 42  ) | ( w23 << 22 ) )  & mask  );
  out[26] = base + ( ( ( w23 >> 36  ) | ( w24 << 28 ) )  & mask  );
  out[27] = base + ( ( ( w24 >> 30  ) | ( w25 << 34 ) )  & mask  );
  out[28] = base + ( ( ( w25 >> 24  ) | ( w26 << 40 ) )  & mask  );
  out[29] = base + ( ( ( w26 >> 18  ) | ( w27 << 46 ) )  & mask  );
  out[30] = base + ( ( ( w27 >> 12  ) | ( w28 << 52 ) )  & mask  );
  out[31] = base + ( w28  >> 6  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 59-bit values, touching 30 64-bit words, using 236 bytes */ 
static void unpackforblock59_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(576460752303423487);
  /* we are going to access  30 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  uint64_t w28 = pw64[28];
  uint64_t w29 = pw64[29];
  *pw += 236; /* we used up 236 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 59  ) | ( w1 << 5 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 54  ) | ( w2 << 10 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 49  ) | ( w3 << 15 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 44  ) | ( w4 << 20 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 39  ) | ( w5 << 25 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 34  ) | ( w6 << 30 ) )  & mask  );
  out[7] = base + ( ( ( w6 >> 29  ) | ( w7 << 35 ) )  & mask  );
  out[8] = base + ( ( ( w7 >> 24  ) | ( w8 << 40 ) )  & mask  );
  out[9] = base + ( ( ( w8 >> 19  ) | ( w9 << 45 ) )  & mask  );
  out[10] = base + ( ( ( w9 >> 14  ) | ( w10 << 50 ) )  & mask  );
  out[11] = base + ( ( ( w10 >> 9  ) | ( w11 << 55 ) )  & mask  );
  out[12] = base + ( ( w11 >> 4 )  & mask  );
  out[13] = base + ( ( ( w11 >> 63  ) | ( w12 << 1 ) )  & mask  );
  out[14] = base + ( ( ( w12 >> 58  ) | ( w13 << 6 ) )  & mask  );
  out[15] = base + ( ( ( w13 >> 53  ) | ( w14 << 11 ) )  & mask  );
  out[16] = base + ( ( ( w14 >> 48  ) | ( w15 << 16 ) )  & mask  );
  out[17] = base + ( ( ( w15 >> 43  ) | ( w16 << 21 ) )  & mask  );
  out[18] = base + ( ( ( w16 >> 38  ) | ( w17 << 26 ) )  & mask  );
  out[19] = base + ( ( ( w17 >> 33  ) | ( w18 << 31 ) )  & mask  );
  out[20] = base + ( ( ( w18 >> 28  ) | ( w19 << 36 ) )  & mask  );
  out[21] = base + ( ( ( w19 >> 23  ) | ( w20 << 41 ) )  & mask  );
  out[22] = base + ( ( ( w20 >> 18  ) | ( w21 << 46 ) )  & mask  );
  out[23] = base + ( ( ( w21 >> 13  ) | ( w22 << 51 ) )  & mask  );
  out[24] = base + ( ( ( w22 >> 8  ) | ( w23 << 56 ) )  & mask  );
  out[25] = base + ( ( w23 >> 3 )  & mask  );
  out[26] = base + ( ( ( w23 >> 62  ) | ( w24 << 2 ) )  & mask  );
  out[27] = base + ( ( ( w24 >> 57  ) | ( w25 << 7 ) )  & mask  );
  out[28] = base + ( ( ( w25 >> 52  ) | ( w26 << 12 ) )  & mask  );
  out[29] = base + ( ( ( w26 >> 47  ) | ( w27 << 17 ) )  & mask  );
  out[30] = base + ( ( ( w27 >> 42  ) | ( w28 << 22 ) )  & mask  );
  out[31] = base + ( ( ( w28 >> 37  ) | ( w29 << 27 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 60-bit values, touching 30 64-bit words, using 240 bytes */ 
static void unpackforblock60_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(1152921504606846975);
  /* we are going to access  30 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  uint64_t w28 = pw64[28];
  uint64_t w29 = pw64[29];
  *pw += 240; /* we used up 240 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 60  ) | ( w1 << 4 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 56  ) | ( w2 << 8 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 52  ) | ( w3 << 12 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 48  ) | ( w4 << 16 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 44  ) | ( w5 << 20 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 40  ) | ( w6 << 24 ) )  & mask  );
  out[7] = base + ( ( ( w6 >> 36  ) | ( w7 << 28 ) )  & mask  );
  out[8] = base + ( ( ( w7 >> 32  ) | ( w8 << 32 ) )  & mask  );
  out[9] = base + ( ( ( w8 >> 28  ) | ( w9 << 36 ) )  & mask  );
  out[10] = base + ( ( ( w9 >> 24  ) | ( w10 << 40 ) )  & mask  );
  out[11] = base + ( ( ( w10 >> 20  ) | ( w11 << 44 ) )  & mask  );
  out[12] = base + ( ( ( w11 >> 16  ) | ( w12 << 48 ) )  & mask  );
  out[13] = base + ( ( ( w12 >> 12  ) | ( w13 << 52 ) )  & mask  );
  out[14] = base + ( ( ( w13 >> 8  ) | ( w14 << 56 ) )  & mask  );
  out[15] = base + ( w14  >> 4  );
  out[16] = base + ( ( w15 )  & mask  );
  out[17] = base + ( ( ( w15 >> 60  ) | ( w16 << 4 ) )  & mask  );
  out[18] = base + ( ( ( w16 >> 56  ) | ( w17 << 8 ) )  & mask  );
  out[19] = base + ( ( ( w17 >> 52  ) | ( w18 << 12 ) )  & mask  );
  out[20] = base + ( ( ( w18 >> 48  ) | ( w19 << 16 ) )  & mask  );
  out[21] = base + ( ( ( w19 >> 44  ) | ( w20 << 20 ) )  & mask  );
  out[22] = base + ( ( ( w20 >> 40  ) | ( w21 << 24 ) )  & mask  );
  out[23] = base + ( ( ( w21 >> 36  ) | ( w22 << 28 ) )  & mask  );
  out[24] = base + ( ( ( w22 >> 32  ) | ( w23 << 32 ) )  & mask  );
  out[25] = base + ( ( ( w23 >> 28  ) | ( w24 << 36 ) )  & mask  );
  out[26] = base + ( ( ( w24 >> 24  ) | ( w25 << 40 ) )  & mask  );
  out[27] = base + ( ( ( w25 >> 20  ) | ( w26 << 44 ) )  & mask  );
  out[28] = base + ( ( ( w26 >> 16  ) | ( w27 << 48 ) )  & mask  );
  out[29] = base + ( ( ( w27 >> 12  ) | ( w28 << 52 ) )  & mask  );
  out[30] = base + ( ( ( w28 >> 8  ) | ( w29 << 56 ) )  & mask  );
  out[31] = base + ( w29  >> 4  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 61-bit values, touching 31 64-bit words, using 244 bytes */ 
static void unpackforblock61_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(2305843009213693951);
  /* we are going to access  31 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  uint64_t w28 = pw64[28];
  uint64_t w29 = pw64[29];
  uint64_t w30 = pw64[30];
  *pw += 244; /* we used up 244 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 61  ) | ( w1 << 3 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 58  ) | ( w2 << 6 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 55  ) | ( w3 << 9 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 52  ) | ( w4 << 12 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 49  ) | ( w5 << 15 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 46  ) | ( w6 << 18 ) )  & mask  );
  out[7] = base + ( ( ( w6 >> 43  ) | ( w7 << 21 ) )  & mask  );
  out[8] = base + ( ( ( w7 >> 40  ) | ( w8 << 24 ) )  & mask  );
  out[9] = base + ( ( ( w8 >> 37  ) | ( w9 << 27 ) )  & mask  );
  out[10] = base + ( ( ( w9 >> 34  ) | ( w10 << 30 ) )  & mask  );
  out[11] = base + ( ( ( w10 >> 31  ) | ( w11 << 33 ) )  & mask  );
  out[12] = base + ( ( ( w11 >> 28  ) | ( w12 << 36 ) )  & mask  );
  out[13] = base + ( ( ( w12 >> 25  ) | ( w13 << 39 ) )  & mask  );
  out[14] = base + ( ( ( w13 >> 22  ) | ( w14 << 42 ) )  & mask  );
  out[15] = base + ( ( ( w14 >> 19  ) | ( w15 << 45 ) )  & mask  );
  out[16] = base + ( ( ( w15 >> 16  ) | ( w16 << 48 ) )  & mask  );
  out[17] = base + ( ( ( w16 >> 13  ) | ( w17 << 51 ) )  & mask  );
  out[18] = base + ( ( ( w17 >> 10  ) | ( w18 << 54 ) )  & mask  );
  out[19] = base + ( ( ( w18 >> 7  ) | ( w19 << 57 ) )  & mask  );
  out[20] = base + ( ( ( w19 >> 4  ) | ( w20 << 60 ) )  & mask  );
  out[21] = base + ( ( w20 >> 1 )  & mask  );
  out[22] = base + ( ( ( w20 >> 62  ) | ( w21 << 2 ) )  & mask  );
  out[23] = base + ( ( ( w21 >> 59  ) | ( w22 << 5 ) )  & mask  );
  out[24] = base + ( ( ( w22 >> 56  ) | ( w23 << 8 ) )  & mask  );
  out[25] = base + ( ( ( w23 >> 53  ) | ( w24 << 11 ) )  & mask  );
  out[26] = base + ( ( ( w24 >> 50  ) | ( w25 << 14 ) )  & mask  );
  out[27] = base + ( ( ( w25 >> 47  ) | ( w26 << 17 ) )  & mask  );
  out[28] = base + ( ( ( w26 >> 44  ) | ( w27 << 20 ) )  & mask  );
  out[29] = base + ( ( ( w27 >> 41  ) | ( w28 << 23 ) )  & mask  );
  out[30] = base + ( ( ( w28 >> 38  ) | ( w29 << 26 ) )  & mask  );
  out[31] = base + ( ( ( w29 >> 35  ) | ( w30 << 29 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 62-bit values, touching 31 64-bit words, using 248 bytes */ 
static void unpackforblock62_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(4611686018427387903);
  /* we are going to access  31 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  uint64_t w28 = pw64[28];
  uint64_t w29 = pw64[29];
  uint64_t w30 = pw64[30];
  *pw += 248; /* we used up 248 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 62  ) | ( w1 << 2 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 60  ) | ( w2 << 4 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 58  ) | ( w3 << 6 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 56  ) | ( w4 << 8 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 54  ) | ( w5 << 10 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 52  ) | ( w6 << 12 ) )  & mask  );
  out[7] = base + ( ( ( w6 >> 50  ) | ( w7 << 14 ) )  & mask  );
  out[8] = base + ( ( ( w7 >> 48  ) | ( w8 << 16 ) )  & mask  );
  out[9] = base + ( ( ( w8 >> 46  ) | ( w9 << 18 ) )  & mask  );
  out[10] = base + ( ( ( w9 >> 44  ) | ( w10 << 20 ) )  & mask  );
  out[11] = base + ( ( ( w10 >> 42  ) | ( w11 << 22 ) )  & mask  );
  out[12] = base + ( ( ( w11 >> 40  ) | ( w12 << 24 ) )  & mask  );
  out[13] = base + ( ( ( w12 >> 38  ) | ( w13 << 26 ) )  & mask  );
  out[14] = base + ( ( ( w13 >> 36  ) | ( w14 << 28 ) )  & mask  );
  out[15] = base + ( ( ( w14 >> 34  ) | ( w15 << 30 ) )  & mask  );
  out[16] = base + ( ( ( w15 >> 32  ) | ( w16 << 32 ) )  & mask  );
  out[17] = base + ( ( ( w16 >> 30  ) | ( w17 << 34 ) )  & mask  );
  out[18] = base + ( ( ( w17 >> 28  ) | ( w18 << 36 ) )  & mask  );
  out[19] = base + ( ( ( w18 >> 26  ) | ( w19 << 38 ) )  & mask  );
  out[20] = base + ( ( ( w19 >> 24  ) | ( w20 << 40 ) )  & mask  );
  out[21] = base + ( ( ( w20 >> 22  ) | ( w21 << 42 ) )  & mask  );
  out[22] = base + ( ( ( w21 >> 20  ) | ( w22 << 44 ) )  & mask  );
  out[23] = base + ( ( ( w22 >> 18  ) | ( w23 << 46 ) )  & mask  );
  out[24] = base + ( ( ( w23 >> 16  ) | ( w24 << 48 ) )  & mask  );
  out[25] = base + ( ( ( w24 >> 14  ) | ( w25 << 50 ) )  & mask  );
  out[26] = base + ( ( ( w25 >> 12  ) | ( w26 << 52 ) )  & mask  );
  out[27] = base + ( ( ( w26 >> 10  ) | ( w27 << 54 ) )  & mask  );
  out[28] = base + ( ( ( w27 >> 8  ) | ( w28 << 56 ) )  & mask  );
  out[29] = base + ( ( ( w28 >> 6  ) | ( w29 << 58 ) )  & mask  );
  out[30] = base + ( ( ( w29 >> 4  ) | ( w30 << 60 ) )  & mask  );
  out[31] = base + ( w30  >> 2  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 63-bit values, touching 32 64-bit words, using 252 bytes */ 
static void unpackforblock63_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  const uint64_t mask = UINT64_C(9223372036854775807);
  /* we are going to access  32 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  uint64_t w28 = pw64[28];
  uint64_t w29 = pw64[29];
  uint64_t w30 = pw64[30];
  uint64_t w31 = pw64[31];
  *pw += 252; /* we used up 252 input bytes */ 
  out[0] = base + ( ( w0 )  & mask  );
  out[1] = base + ( ( ( w0 >> 63  ) | ( w1 << 1 ) )  & mask  );
  out[2] = base + ( ( ( w1 >> 62  ) | ( w2 << 2 ) )  & mask  );
  out[3] = base + ( ( ( w2 >> 61  ) | ( w3 << 3 ) )  & mask  );
  out[4] = base + ( ( ( w3 >> 60  ) | ( w4 << 4 ) )  & mask  );
  out[5] = base + ( ( ( w4 >> 59  ) | ( w5 << 5 ) )  & mask  );
  out[6] = base + ( ( ( w5 >> 58  ) | ( w6 << 6 ) )  & mask  );
  out[7] = base + ( ( ( w6 >> 57  ) | ( w7 << 7 ) )  & mask  );
  out[8] = base + ( ( ( w7 >> 56  ) | ( w8 << 8 ) )  & mask  );
  out[9] = base + ( ( ( w8 >> 55  ) | ( w9 << 9 ) )  & mask  );
  out[10] = base + ( ( ( w9 >> 54  ) | ( w10 << 10 ) )  & mask  );
  out[11] = base + ( ( ( w10 >> 53  ) | ( w11 << 11 ) )  & mask  );
  out[12] = base + ( ( ( w11 >> 52  ) | ( w12 << 12 ) )  & mask  );
  out[13] = base + ( ( ( w12 >> 51  ) | ( w13 << 13 ) )  & mask  );
  out[14] = base + ( ( ( w13 >> 50  ) | ( w14 << 14 ) )  & mask  );
  out[15] = base + ( ( ( w14 >> 49  ) | ( w15 << 15 ) )  & mask  );
  out[16] = base + ( ( ( w15 >> 48  ) | ( w16 << 16 ) )  & mask  );
  out[17] = base + ( ( ( w16 >> 47  ) | ( w17 << 17 ) )  & mask  );
  out[18] = base + ( ( ( w17 >> 46  ) | ( w18 << 18 ) )  & mask  );
  out[19] = base + ( ( ( w18 >> 45  ) | ( w19 << 19 ) )  & mask  );
  out[20] = base + ( ( ( w19 >> 44  ) | ( w20 << 20 ) )  & mask  );
  out[21] = base + ( ( ( w20 >> 43  ) | ( w21 << 21 ) )  & mask  );
  out[22] = base + ( ( ( w21 >> 42  ) | ( w22 << 22 ) )  & mask  );
  out[23] = base + ( ( ( w22 >> 41  ) | ( w23 << 23 ) )  & mask  );
  out[24] = base + ( ( ( w23 >> 40  ) | ( w24 << 24 ) )  & mask  );
  out[25] = base + ( ( ( w24 >> 39  ) | ( w25 << 25 ) )  & mask  );
  out[26] = base + ( ( ( w25 >> 38  ) | ( w26 << 26 ) )  & mask  );
  out[27] = base + ( ( ( w26 >> 37  ) | ( w27 << 27 ) )  & mask  );
  out[28] = base + ( ( ( w27 >> 36  ) | ( w28 << 28 ) )  & mask  );
  out[29] = base + ( ( ( w28 >> 35  ) | ( w29 << 29 ) )  & mask  );
  out[30] = base + ( ( ( w29 >> 34  ) | ( w30 << 30 ) )  & mask  );
  out[31] = base + ( ( ( w30 >> 33  ) | ( w31 << 31 ) )  & mask  );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}


/* we packed 32 64-bit values, touching 32 64-bit words, using 256 bytes */ 
static void unpackforblock64_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint64_t * out = *pout;
  /* we are going to access  32 64-bit words */ 
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
  uint64_t w16 = pw64[16];
  uint64_t w17 = pw64[17];
  uint64_t w18 = pw64[18];
  uint64_t w19 = pw64[19];
  uint64_t w20 = pw64[20];
  uint64_t w21 = pw64[21];
  uint64_t w22 = pw64[22];
  uint64_t w23 = pw64[23];
  uint64_t w24 = pw64[24];
  uint64_t w25 = pw64[25];
  uint64_t w26 = pw64[26];
  uint64_t w27 = pw64[27];
  uint64_t w28 = pw64[28];
  uint64_t w29 = pw64[29];
  uint64_t w30 = pw64[30];
  uint64_t w31 = pw64[31];
  *pw += 256; /* we used up 256 input bytes */ 
  out[0] = base + ( w0   );
  out[1] = base + ( w1   );
  out[2] = base + ( w2   );
  out[3] = base + ( w3   );
  out[4] = base + ( w4   );
  out[5] = base + ( w5   );
  out[6] = base + ( w6   );
  out[7] = base + ( w7   );
  out[8] = base + ( w8   );
  out[9] = base + ( w9   );
  out[10] = base + ( w10   );
  out[11] = base + ( w11   );
  out[12] = base + ( w12   );
  out[13] = base + ( w13   );
  out[14] = base + ( w14   );
  out[15] = base + ( w15   );
  out[16] = base + ( w16   );
  out[17] = base + ( w17   );
  out[18] = base + ( w18   );
  out[19] = base + ( w19   );
  out[20] = base + ( w20   );
  out[21] = base + ( w21   );
  out[22] = base + ( w22   );
  out[23] = base + ( w23   );
  out[24] = base + ( w24   );
  out[25] = base + ( w25   );
  out[26] = base + ( w26   );
  out[27] = base + ( w27   );
  out[28] = base + ( w28   );
  out[29] = base + ( w29   );
  out[30] = base + ( w30   );
  out[31] = base + ( w31   );
  *pout += 32; /* we wrote 32 64-bit integers */ 
}

static packforblockfnc_64 funcForPackArr64[] = {
&packforblock0_64,
&packforblock1_64,
&packforblock2_64,
&packforblock3_64,
&packforblock4_64,
&packforblock5_64,
&packforblock6_64,
&packforblock7_64,
&packforblock8_64,
&packforblock9_64,
&packforblock10_64,
&packforblock11_64,
&packforblock12_64,
&packforblock13_64,
&packforblock14_64,
&packforblock15_64,
&packforblock16_64,
&packforblock17_64,
&packforblock18_64,
&packforblock19_64,
&packforblock20_64,
&packforblock21_64,
&packforblock22_64,
&packforblock23_64,
&packforblock24_64,
&packforblock25_64,
&packforblock26_64,
&packforblock27_64,
&packforblock28_64,
&packforblock29_64,
&packforblock30_64,
&packforblock31_64,
&packforblock32_64,
&packforblock33_64,
&packforblock34_64,
&packforblock35_64,
&packforblock36_64,
&packforblock37_64,
&packforblock38_64,
&packforblock39_64,
&packforblock40_64,
&packforblock41_64,
&packforblock42_64,
&packforblock43_64,
&packforblock44_64,
&packforblock45_64,
&packforblock46_64,
&packforblock47_64,
&packforblock48_64,
&packforblock49_64,
&packforblock50_64,
&packforblock51_64,
&packforblock52_64,
&packforblock53_64,
&packforblock54_64,
&packforblock55_64,
&packforblock56_64,
&packforblock57_64,
&packforblock58_64,
&packforblock59_64,
&packforblock60_64,
&packforblock61_64,
&packforblock62_64,
&packforblock63_64,
&packforblock64_64
};
static unpackforblockfnc_64 funcForUnpackArr64[] = {
&unpackforblock0_64,
&unpackforblock1_64,
&unpackforblock2_64,
&unpackforblock3_64,
&unpackforblock4_64,
&unpackforblock5_64,
&unpackforblock6_64,
&unpackforblock7_64,
&unpackforblock8_64,
&unpackforblock9_64,
&unpackforblock10_64,
&unpackforblock11_64,
&unpackforblock12_64,
&unpackforblock13_64,
&unpackforblock14_64,
&unpackforblock15_64,
&unpackforblock16_64,
&unpackforblock17_64,
&unpackforblock18_64,
&unpackforblock19_64,
&unpackforblock20_64,
&unpackforblock21_64,
&unpackforblock22_64,
&unpackforblock23_64,
&unpackforblock24_64,
&unpackforblock25_64,
&unpackforblock26_64,
&unpackforblock27_64,
&unpackforblock28_64,
&unpackforblock29_64,
&unpackforblock30_64,
&unpackforblock31_64,
&unpackforblock32_64,
&unpackforblock33_64,
&unpackforblock34_64,
&unpackforblock35_64,
&unpackforblock36_64,
&unpackforblock37_64,
&unpackforblock38_64,
&unpackforblock39_64,
&unpackforblock40_64,
&unpackforblock41_64,
&unpackforblock42_64,
&unpackforblock43_64,
&unpackforblock44_64,
&unpackforblock45_64,
&unpackforblock46_64,
&unpackforblock47_64,
&unpackforblock48_64,
&unpackforblock49_64,
&unpackforblock50_64,
&unpackforblock51_64,
&unpackforblock52_64,
&unpackforblock53_64,
&unpackforblock54_64,
&unpackforblock55_64,
&unpackforblock56_64,
&unpackforblock57_64,
&unpackforblock58_64,
&unpackforblock59_64,
&unpackforblock60_64,
&unpackforblock61_64,
&unpackforblock62_64,
&unpackforblock63_64,
&unpackforblock64_64
};
/**  turbopacking64.py ends here **/

#endif //INCLUDE_TURBOPACKING64_H

