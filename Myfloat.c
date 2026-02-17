#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   unsigned int sign_part;
   unsigned int exponent_part;
   unsigned int fraction_part;

   sign_part = (unsigned int)sign_bit;
   sign_part = sign_part & 1U;      
   sign_part = sign_part << 31;


   exponent_part = (unsigned int)exponent;
   exponent_part = exponent_part & 0xFFU;  
   exponent_part = exponent_part << 23;

   fraction_part = fraction & 0x7FFFFFU;

   f = sign_part;
   f = f | exponent_part;
   f = f | fraction_part;

   return *(float *)&f;
}
