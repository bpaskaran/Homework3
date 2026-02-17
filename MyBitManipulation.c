
#include "MyBitManipulation.h"
#include <stdio.h>

int ToggleBit(int num, int pos) {

   if (pos < 0 || pos > 31) {
      return num;
   }

   unsigned int mask = 1U;
   mask = mask << pos;

   num = num ^ mask;

   return num;
}


int GetMSB(int num) {

   unsigned int value = (unsigned int)num;
   int i;

   if (value == 0U) {
      return -1;
   }

   for (i = 31; i >= 0; i--) {
      if (((value >> i) & 1U) == 1U) {
         return i;
      }
   }

   return -1;
}


int ClearBitRange(int num, int start, int end) {

   if (start < 0 || end > 31 || start > end) {
      return num;
   }

   unsigned int value = (unsigned int)num;
   unsigned int left_mask;
   unsigned int right_mask;
   unsigned int final_mask;

 
   if (end == 31) {
      left_mask = 0U;
   } else {
      left_mask = ~0U;
      left_mask = left_mask << (end + 1);
   }

   if (start == 0) {
      right_mask = 0U;
   } else {
      right_mask = (1U << start) - 1U;
   }

   final_mask = left_mask | right_mask;

   value = value & final_mask;

   return (int)value;
}


int RotateLeft(int num, int d) {

   unsigned int value = (unsigned int)num;
   unsigned int left_part;
   unsigned int right_part;
   unsigned int result;

   d = d % 32;

   if (d < 0) {
      d = d + 32;
   }

   if (d == 0) {
      return num;
   }

   left_part = value << d;
   right_part = value >> (32 - d);

   result = left_part | right_part;

   return (int)result;
}




int SwapOddEvenBits(int num) {

   unsigned int value = (unsigned int)num;

   unsigned int even_bits;
   unsigned int odd_bits;
   unsigned int result;

 
   even_bits = value & 0xAAAAAAAAU;
   odd_bits  = value & 0x55555555U;

   even_bits = even_bits >> 1;
   odd_bits  = odd_bits << 1;

   result = even_bits | odd_bits;

   return (int)result;
}
