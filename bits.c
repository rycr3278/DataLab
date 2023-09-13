/* 
 * CS:APP Data Lab 
 * 
 * Ryan Cross, rycr3278
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
  2. Performs right shifts arithmetically and a negative shift value results in zero.
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


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
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
   <https://www.gnu.org/licenses/>.  */
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





/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  /* Utilize DeMorgan's Law to return Not (~) Not (~) x AND (&) Not (~) x. 
   */
  return ~(~x & ~y);
}

/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  /* The ! operator returns true (1) if operand is false (0),
   * and false (0) if the operand is true (1).
   */
  return !x;
}

/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  /* Inside parenthesis, left-shift (<<) 1 by 31 to create 
   * 10000000 00000000 00000000 00000000, and then invert 
   * those bits using the complement operator (~). 
   */
  return ~(1 << 31);
}

/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
  /* We create a mask to check if any odd numbered bit in binary word
   * is set to 1. We use 0xAA, which is equal to 10101010 in base2, and 
   * left-shift (<<) by multiples of 8 to make sure we cover every odd bit, and
   * combine with bitwise or (|) operator. Our return statement highlights any
   * odd bits appearing in x and returns 1 if they exist, or 0 if they don't. 
   */
  int mask = 0xAA << 24 | 0xAA << 16 | 0xAA << 8 | 0xAA;
  return !!(x & mask);
}

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
  /* Shift x left by 32-n places, effectively pushing the top n bits of x
   * to the leftmost side of the 32-bit number. Then shift x right by 32 - n,
   * returning it to original position. In return statement, check to see if
   * the original value is equal to the shifted value. If n was big enough, 
   * value of x should be unchanged. If not, n was too small to fit x. 
   */
  int shiftAmount = 32 + (~n + 1);

  return !(x ^ (x << shiftAmount >> shiftAmount));
}

/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  /* We use the AND operator (&) to combine x with the negative
   * counterpart of x. We find the negative counterpart of x by
   * using the complement operator (~) and adding 1. This inverts the
   * bits of x, and by adding 1 we roll the bits over from least to most
   * significant. 
   */
  return x & (~x + 1);
}

/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* We create variables for upper and lower int vals to check against. We check  
   * if x is within the low range by checking the sign of x - lowVal (by using 
   * inverted lowVal + 1). We right-shift by 31 to extract our sign bit. 
   * If the sign is non-negative, then x is greater than or equal to lowVal. 
   * We check if x is less than highVal in the same way. If result is non-negative, 
   * then x is less than or equal to 0x39. We then combine these using AND operator (&)
   * to return 1 or 0 if x is within desired range. 
   */
  int lowVal = 0x30;
  int highVal = 0x3a;

  int lowRange = !((x + (~lowVal + 1)) >> 31);
  int highRange = (x + (~highVal + 1)) >> 31;

  return lowRange & highRange;
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* Isolate the sign bits of x and y with right-shift (>>) and AND (&) ops, 
   * then check to see if signs are different using XOR (^), storing in diff_sgn.
   * Use AND (&) to check if signs are different and x is negative, storing result
   * in a, which will store 1 iff x and y are different signs and x is negative. 
   * Next, calculate y - x and store in same_sgn_diff. If the sign bit of same_sgn_diff 
   * is 0, it means y - x is non-negative, implying x is less than or equal to y. 
   * The !diff_sgn part ensures that this check is only considered when x and y 
   * have the same sign. The result will be 1 (true) if either a is 1 (if x and y have 
   * different signs and x is negative) or b is 1 (i.e., x and y have the same sign and 
   * x <= y). Otherwise, it will be 0.
   */
  int sign_x = x >> 31 & 1;
  int sign_y = y >> 31 & 1;

  int diff_sgn = sign_x ^ sign_y;

  int a = diff_sgn & sign_x;

  int same_sgn_diff = y + ~x + 1;
  int b = !diff_sgn & !(same_sgn_diff >> 31);

  return a | b;
}

/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  /* First we isolate each byte of x using a right shift (>>) and 
   * the 0xff mask in combination with the AND operator (&). 
   * Then we shift each byte to position it in the appropriate place
   * for it to be a reverse from the original x. We combine each byte 
   * back together using the OR operator (|) and return the result. 
   */

  int lsb = x & 0xff;
  int secondByte = (x >> 8) & 0xff;
  int thirdByte = (x >> 16) & 0xff;
  int msb = (x >> 24) & 0xff;

  return lsb << 24 | secondByte << 16 | thirdByte << 8 | msb;
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* We create byte-sized masks of alternating bits that gradually increase in spacing,
   * using a combo of the |= op and the left-shift op (<<) to essentially increase 
   * the size of the masks beyond the 0x0 - 0xFF range limit. We use the masks to count 
   * 1's in gradually increasing groups, right-shifting (>>) x each time to account for
   * mask sizes. After masks have been applied, we return x which is now the sum of 1's
   * in the original x. 
   *  */
  
  int mask1, mask2, mask3, mask4, mask5;

  mask1 = 0x55; // 0101 0101
  mask1 |= (mask1 << 8);
  mask1 |= (mask1 << 16);
   
  mask2 = 0x33; // 0011 0011
  mask2 |= (mask2 << 8);
  mask2 |= (mask2 << 16);
    
  mask3 = 0x0F; // 0000 1111
  mask3 |= (mask3 << 8);
  mask3 |= (mask3 << 16);
    
  mask4 = 0xFF; // 0000 0000 1111 1111
  mask4 |= (mask4 << 16);
    
  mask5 = 0xFF; // 0000 0000 0000 0000 1111 1111 1111 1111
  mask5 |= (mask5 << 8);

  // Count set bits in groups of 2
  x = (x & mask1) + ((x >> 1) & mask1);
  // Count set bits in groups of 4
  x = (x & mask2) + ((x >> 2) & mask2);
  // Count set bits in groups of 8
  x = (x & mask3) + ((x >> 4) & mask3);
  // Count set bits in groups of 16
  x = (x & mask4) + ((x >> 8) & mask4);
  // Count set bits in groups of 32
  x = (x & mask5) + ((x >> 16) & mask5);

  return x;
}

/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /* First, we right-shift (>>) x to read it's sign bit. We do the same
   * with the complement (~) of x after adding 1. One of those two equations
   * must logically have a negative sign. Assuming the right-shift is arithmnatic,
   * this means that either the original value of x or x's compliment will be all 1's
   * after the right-shift (unless x was 0). Taking the OR (|) between the two
   * and adding 1 gives us 0 if x was non-zero, and 1 if it was zero.
   */
  return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}

/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x) {
  /* First assign quotient of x divided by 8 to divByEight, using right shift (>>).
   * Next assign remainder to rem (if x is not divisible by 8) using AND (&) between x and 7 (111).
   * Mulitply divByEight by 5 by using power of 2 and addition. Repeat for rem.
   * We adjust rounding depending on sign of x by using right shift (>>) and AND (&) op
   * to combine with 7 (111). We add the bias to mulRemBy5 and right-shift (>>) 
   * to divide by 8. Finally, return sum of mulWholePartBy5 and Fractional
   *  */
  
  int divByEight = x >> 3;
  int rem = x & 7;

  int mulWholePartBy5 = divByEight + (divByEight << 2);

  int mulRemBy5 = rem + (rem << 2);

  int bias = (x >> 31) & 7;

  int fractional = (mulRemBy5 + bias) >> 3;

  return mulWholePartBy5 + fractional;
}





/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  return 2;
}
