#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>

static bool is_valid_repr(char r) {
    return (r == '2' || r == 'S');
}

void repr_convert(char source_repr, char target_repr, unsigned int repr) {
    if (!is_valid_repr(source_repr) || !is_valid_repr(target_repr)) {
        printf("error\n");
        return;
    }

    long long value = 0;

    if (source_repr == '2') {
    
        if (repr & 0x80000000U) {
            value = (long long)repr - (1LL << 32); 
        } else {
            value = (long long)repr;
        }
    } else { 
        unsigned int sign = (repr >> 31) & 1U;
        unsigned int mag  = repr & 0x7FFFFFFFU;

        if (mag == 0U) {
            value = 0; 
        } else {
            value = sign ? -(long long)mag : (long long)mag;
        }
    }

    
    if (target_repr == '2') {
        
        const long long MIN_TWOS = -(1LL << 31);
        const long long MAX_TWOS =  (1LL << 31) - 1;

        if (value < MIN_TWOS || value > MAX_TWOS) {
            printf("undefined\n");
            return;
        }

        unsigned int out = (unsigned int)(value & 0xFFFFFFFFULL);
        printf("%08x\n", out);
        return;
    } else { 
        
        const long long MIN_SM = -((1LL << 31) - 1);
        const long long MAX_SM =  ((1LL << 31) - 1);

        if (value == 0) {
            
            printf("%08x\n", 0U);
            return;
        }

        if (value < MIN_SM || value > MAX_SM) {
            
            printf("undefined\n");
            return;
        }

        unsigned int sign = (value < 0) ? 1U : 0U;
        unsigned int mag  = (unsigned int)((value < 0) ? -value : value);

        unsigned int out = (sign << 31) | (mag & 0x7FFFFFFFU);
        printf("%08x\n", out);
        return;
    }
}
