#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;


   unsigned int sign = ((unsigned int)sign_bit & 1U) << 31;   
   unsigned int exp  = ((unsigned int)exponent & 0xFFU) << 23; 
   unsigned int frac = fraction & 0x7FFFFFU;                   

   f = sign | exp | frac;

   return *(float *)&f;
}
