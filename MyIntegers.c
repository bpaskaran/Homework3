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

   long long value = 0;

   if (source_repr == '2') {
     
      if ((repr & 0x80000000U) != 0U) {
      
         value = (long long)repr;
         value = value - (1LL << 32);
      } else {
       
         value = (long long)repr;
      }
   } else {
     
      unsigned int sign = (repr >> 31) & 1U;
      unsigned int mag  = repr & 0x7FFFFFFFU;

    
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



   if (target_repr == '2') {
    
      long long min = -(1LL << 31);
      long long max = (1LL << 31) - 1;

      if (value < min || value > max) {
         printf("undefined\n");
         return;
      }

    
      printf("%08x\n", (unsigned int)value);
      return;
   }


   {
    
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

    
      unsigned int sign_bit = 0U;
      unsigned int mag = 0U;

      if (value < 0) {
         sign_bit = 1U;
         mag = (unsigned int)(-value);
      } else {
         sign_bit = 0U;
         mag = (unsigned int)value;
      }

      unsigned int out = 0U;
      out = sign_bit << 31;
      out = out | (mag & 0x7FFFFFFFU);

      printf("%08x\n", out);
      return;
   }
}
