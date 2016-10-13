#!/usr/bin/env python3

def howmany(bit):
    """ how many values are we going to pack? """
    return 32

def howmanywords(bit):
    return (howmany(bit) * bit + 63)//64

def howmanybytes(bit):
    return (howmany(bit) * bit + 7)//8
print("""
#ifndef INCLUDE_TURBOPACKING64_H
#define INCLUDE_TURBOPACKING64_H
#include <iso646.h> // mostly for Microsoft compilers
#include <stdint.h> // part of Visual Studio 2010 and better
""")
print("""
#ifndef UINT64_C
#define UINT64_C(c) (c ## ULL)
#endif
""")
print("""
/**
* (c) Daniel Lemire
* Apache License 2.0
*/
/** turbopacking64 starts here **/
/**
* this code mimics the way TurboPFor packs short arrays of integers.
* We pack and unpack always at least a full 64-bit word, plus whatever
* is necessary to get to an even number of bytes.
*/""")

print("""typedef void (*packforblockfnc_64)(const uint64_t base, const uint64_t ** pin, uint8_t ** pw);""")
print("""typedef void (*unpackforblockfnc_64)(const uint64_t base, const uint8_t ** pw, uint64_t ** pout);""")



def plurial(number):
    if(number > 1):
        return "s"
    else :
        return ""

print("")
print("static void packforblock0_64(const uint64_t , const uint64_t ** pin, uint8_t ** pw) {");
print("  (void)pw;");
print("  *pin += {0}; /* we consumed {0} 64-bit integer{1} */ ".format(howmany(0),plurial(howmany(0))));
print("}");
print("")

for bit in range(1,65):
    print("")
    print("/* we are going to pack {0} {1}-bit values, touching {2} 64-bit words, using {3} bytes */ ".format(howmany(bit),bit,howmanywords(bit),howmanybytes(bit)))
    print("static void packforblock{0}_64(const uint64_t base, const uint64_t ** pin, uint8_t ** pw) {{".format(bit));
    print("  uint64_t * pw64 = *(uint64_t **) pw;");
    print("  const uint64_t * in = *pin;");
    print("  /* we are going to touch  {0} 64-bit word{1} */ ".format(howmanywords(bit),plurial(howmanywords(bit))));
    for k in range(howmanywords(bit)) :
      print("  uint64_t w{0};".format(k))
    for j in range(howmany(bit)):
      firstword = j * bit // 64
      secondword = (j * bit + bit - 1)//64
      firstshift = (j*bit) % 64
      if( firstword == secondword):
          if(firstshift == 0):
            print("  w{0} = (in[{1}] - base);".format(firstword,j))
          else:
            print("  w{0} |=  (in[{1}] - base) << {2};".format(firstword,j,firstshift))
      else:
          print("  w{0} |= (in[{1}] - base) << {2};".format(firstword,j,firstshift))
          secondshift = 64-firstshift
          print("  w{0} = (in[{1}] - base) >> {2};".format(secondword,j,secondshift))
    for k in range(howmanywords(bit)) :
      print("  pw64[{0}] = w{0};".format(k))
    print("  *pin += {0}; /* we consumed {0} 64-bit integer{1} */ ".format(howmany(bit),plurial(howmany(bit))));
    print("  *pw += {0}; /* we used up {0} output bytes */ ".format(howmanybytes(bit)));
    print("}");
    print("")

print("static void unpackforblock0_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {");
print("  (void) pw;");
print("  for(int k = 0; k < {0} ; k+= 1) {{".format(howmany(0)))
print("    (*pout) [k] = base;")
print("  }")
print("  *pout += {0}; /* we wrote {0} 64-bit integer{1} */ ".format(howmany(0),plurial(howmany(0))));
print("}");
print("")

for bit in range(1,65):
    print("")
    print("/* we packed {0} {1}-bit values, touching {2} 64-bit words, using {3} bytes */ ".format(howmany(bit),bit,howmanywords(bit),howmanybytes(bit)))
    print("static void unpackforblock{0}_64(const uint64_t base, const uint8_t ** pw, uint64_t ** pout) {{".format(bit));
    print("  const uint64_t * pw64 = *(const uint64_t **) pw;");
    print("  uint64_t * out = *pout;");
    if(bit < 64): print("  const uint64_t mask = UINT64_C({0});".format((1<<bit)-1));
    maskstr = " & mask "
    if (bit == 64) : maskstr = "" # no need
    print("  /* we are going to access  {0} 64-bit word{1} */ ".format(howmanywords(bit),plurial(howmanywords(bit))));
    for k in range(howmanywords(bit)) :
      print("  uint64_t w{0} = pw64[{0}];".format(k))
    print("  *pw += {0}; /* we used up {0} input bytes */ ".format(howmanybytes(bit)));
    for j in range(howmany(bit)):
      firstword = j * bit // 64
      secondword = (j * bit + bit - 1)//64
      firstshift = (j*bit) % 64
      firstshiftstr = ">> {0} ".format(firstshift)
      if(firstshift == 0):
          firstshiftstr ="" # no need
      if( firstword == secondword):
          if(firstshift + bit == 64):
            print("  out[{0}] = base + ( w{1}  {2} );".format(j,firstword,firstshiftstr,firstshift))
          else:
            print("  out[{0}] = base + ( ( w{1} {2}) {3} );".format(j,firstword,firstshiftstr,maskstr))
      else:
          secondshift = (64-firstshift)
          print("  out[{0}] = base + ( ( ( w{1} {2} ) | ( w{3} << {4} ) ) {5} );".format(j,firstword,firstshiftstr, firstword+1,secondshift,maskstr))
    print("  *pout += {0}; /* we wrote {0} 64-bit integer{1} */ ".format(howmany(bit),plurial(howmany(bit))));
    print("}");
    print("")

print("static packforblockfnc_64 funcForPackArr64[] = {")
for bit in range(0,64):
  print("&packforblock{0}_64,".format(bit))
print("&packforblock64_64")
print("};")

print("static unpackforblockfnc_64 funcForUnpackArr64[] = {")
for bit in range(0,64):
  print("&unpackforblock{0}_64,".format(bit))
print("&unpackforblock64_64")
print("};")
print("/**  turbopacking64.py ends here **/")
print("""
#endif //INCLUDE_TURBOPACKING64_H
""")
