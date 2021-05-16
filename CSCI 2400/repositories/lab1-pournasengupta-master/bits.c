/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/*
 * Total: 25 pts
 */
//De Morgan's Law 
         //A & B = ~(~A | ~B)
         //A | B = ~(~A & ~B)
/* 
 * 1-pt puzzles 
 */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    //using De Morgan's Law 
    return ~(~x | ~y);
}
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    //x ^ y = (x & y) | (~x & ~y)
    //we cannot use | so we must change it to & 
    //using De Morgan's Law 
    //x ^ y = ~(x & y) & ~(~x & ~y)
    return ~(x & y) & ~(~x & ~y);
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
    //if x is 0, it will return 1
    //if x is 1, it will return 0 
    return !x; 
}
/* 
 * fitsShort - return 1 if x can be represented as a 
 *   16-bit, two's complement integer.
 *   Examples: fitsShort(33000) = 0, fitsShort(-32768) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int fitsShort(int x) {
    //shift x right by 16 to fill 16 0's or 1's to the right 
    //shift x left by 16 to fill 16 0's or 1's to the left 
    //if x doesn't change, x can be represented as a 16 bit, 2's complement
    //x' = (x << 16) >> 16 (both shifts of right and left)
    int temp1 = (x << 16) >> 16; 
    //use x' ^ x to see if there is a change
    //if there is, x' ^ x will equal 1. if there isn't, it will equal 0
    //since we want it to return 1 if there is no change, we use !
    //!(x' ^ x) gives us the correct value to return 
    return !(temp1 ^ x);
}
/* 
 * 2-pt puzzles
 */
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    //in this case, we want to shift by 32 + (1 + ~n) instead of 16
    int shiftVal = 32 + (1 + ~n);
    //shift x right by shiftVal to fill shiftVal 0's or 1's to the right 
    //shift x left by shiftVal to fill shiftVal 0's or 1's to the right 
    //if x doesn't change, x can be represented as an n-bit, 2's complement
    //x' = (x << shiftVal) >> shiftVal (both shifts of right and left)
    //use x' ^ x to see if there is a change 
    //if there is, x' ^ x will equal 1. if there isn't, it will equal 0 
    //since we want it to return 1 if there is no change, we use !
    //!(x' ^ x) gies us the correct value to return 
    //!(((x << shiftVal) >> shiftVal)^ x)
    return !(((x << shiftVal) >> shiftVal) ^ x);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    //n is a 2's complement integer
    //to find the MSB, we must shift left by 3, essentially multiplying by 8 
    //n << 3 = 8 * n
    int shiftN = n << 3; 
    //this pushes the MSB to the end of the word 
    //to extract byte n from word x, you must shift x right by n << 3
    //byte = x >> (n << 3)
    //this pushes out everything but n from the word x 
    //0xff is the LSB
    //byte & 0xff compares the two so that the MSB (which is now the byte n) is returned 
    return ((x >> shiftN) & 0xff); 
}
/* 
 * isNotEqual - return 0 if x == y, and 1 otherwise 
 *   Examples: isNotEqual(5,5) = 0, isNotEqual(4,5) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNotEqual(int x, int y) {
    //Xor returns 0 if x == y and 1 otherwise 
    //!! makes sure that it can only return 0 and 1 
    return !!(x ^ y); 
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    //32-bits 
    //shift x right by 31 bits to bring last bit to the front 
    //x >> 31
    int shiftVal = x >> 31; 
    //if the bit is 1, the value is negative 
    //if the bit is 0, the value is zero or negative 
    //non-zero values (both positive and negative) are true
    //zero values are false 
    //compare the value of x with the bit 
    //x >> 31 | !!x
    return (shiftVal | !!x); 
}
/* 
 * 3-pt puzzles 
 */
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    //start with an Xor of x and y, x^y
    //int xorCheck = x^y; 
    //set temp1 to ~ of xorCheck, the opposite of the performed xor 
    //int temp1 = ~xorCheck; 
    //y - x, if this is negative, x > y and we must return 0 
    int diff = y + (~x + 1); 
    //set temp to the ! of the diff, true only if diff is 0 
    //int temp = !diff; 
    //compare xorCheck and x using & 
    //xorCheck = xorCheck & x; 
    //~ of the difference 
    int diffNeg = ~diff; 
    //xor of temp1 and diffNeg 
    //int tempVal = temp1 ^ diffNeg; 
    //compare new tempVal value to xorCheck using | 
    //tempVal = tempVal | xorCheck; 
    //compare new tempVal value to left shift of 1, adds 0's to right and shifts bit 1 to the first bit
    //tempVal = tempVal & (1 << 31); 
    //adding everything together 
    int tempVal = (((~(x^y) & diffNeg) | ((x^y) & x)) & (1 << 31));
    //return !!tempVal | !diff; 
    return (!!tempVal | !diff); 
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    //shift binary 1 left by 31 bits to move 1 bit (last bit) to front 
    int mask = 1 << 31; 
    //shift by n bits to the right (as is done by an arithmetic shift)
    mask = mask >> n; 
    //shift left by 1 bit
    mask = mask << 1; 
    //shift x right by n bits 
    //nor of mask 
    return (x >> n) & ~mask; 
}
/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
    //shift binary 1 left by 31 bits to move 1 bit (last bit) to front 
    int mask = (1 << 31); 
    //shift mask to the left by 31 - n 
    mask = mask >> (31 + (~n + 1)); 
    //compare x shifted right by 32 - n bits with nor of mask using & and compare with x shifted left by n bits using |
    return ((x >> (32 + (~n + 1))) & ~mask) | (x << n); 
    
}
/*
 * 4-pt puzzles
 */
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value (Tmax), and when negative overflow occurs,
 *          it returns minimum negative value (Tmin)
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
    //sum of x and y 
    int sum = x + y; 
    //calculate overflow by xor comparing the sums and integers 
    //then shift right by 31 bits 
    int overflow = ((sum ^ x)&(sum ^ y)) >> 31; 
    //shift sum right by overflow & 31
    //then add overflow shifted left by 31 
    return (sum >> (overflow & 31)) + (overflow << 31); 
}
            
/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
    //unsigned mask -> sign bit (first bit) is 0 
    unsigned mask = 0x7FFFFFFF; 
    //unsigned NaN -> the mininum NaN possible 
    unsigned NaN = 0x7F800001; 
    //new temporary argument or result -> & of uf and mask which creates new arg that is absolute value of floating point arg f 
    unsigned temp = uf & mask; 
    //if result is greater than or equal to minimum NaN 
    if(temp >= NaN){
        //return original argument uf
        return uf; 
    }
    //if the result is not NaN
    else{
        //return the result -> equivalent absolute value of f for floating point argument f 
        return temp; 
    }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  return 2;
}
