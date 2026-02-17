#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>

void repr_convert(char source_repr, char target_repr, unsigned int repr) {


   if (source_repr != '2' && source_repr != 'S') {
      printf("error\n");
      return;
   }
   if (target_repr != '2' && target_repr != 'S') {
      printf("error\n");
      return;
   }

   /* 2) Decode (turn the input bits into a signed number in 'value') */
   long long value = 0;

   if (source_repr == '2') {
      /* two's complement: check sign bit (bit 31) */
      if ((repr & 0x80000000U) != 0U) {
         /* negative: value = repr - 2^32 */
         value = (long long)repr;
         value = value - (1LL << 32);
      } else {
         /* positive */
         value = (long long)repr;
      }
   } else {
      /* sign/magnitude: top bit is sign, rest is magnitude */
      unsigned int sign = (repr >> 31) & 1U;
      unsigned int mag  = repr & 0x7FFFFFFFU;

      /* treat both +0 and -0 as 0 */
      if (mag == 0U) {
         value = 0;
      } else {
         if (sign == 1U) {
            value = -(long long)mag;
         } else {
            value = (long long)mag;
         }
      }
   }

   /* 3) Convert to target and 4) print */

   if (target_repr == '2') {
      /* must fit in signed 32-bit */
      long long min = -(1LL << 31);
      long long max = (1LL << 31) - 1;

      if (value < min || value > max) {
         printf("undefined\n");
         return;
      }

      /* printing as 8 hex digits */
      printf("%08x\n", (unsigned int)value);
      return;
   }

   /* target is 'S' (sign/magnitude) */
   {
      /* sign/magnitude cannot represent -2^31 */
      long long min = -((1LL << 31) - 1);
      long long max =  ((1LL << 31) - 1);

      if (value == 0) {
         printf("%08x\n", 0U);
         return;
      }

      if (value < min || value > max) {
         printf("undefined\n");
         return;
      }

      /* build sign/magnitude bits */
      unsigned int sign_bit = 0U;
      unsigned int mag = 0U;

      if (value < 0) {
         sign_bit = 1U;
         mag = (unsigned int)(-value);
      } else {
         sign_bit = 0U;
         mag = (unsigned int)value;
      }

      /* put sign in bit 31, magnitude in bits 30..0 */
      unsigned int out = 0U;
      out = sign_bit << 31;
      out = out | (mag & 0x7FFFFFFFU);

      printf("%08x\n", out);
      return;
   }
}
