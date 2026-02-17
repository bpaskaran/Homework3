#include "MyBitManipulation.h"

int ToggleBit(int num, int pos) {
    if (pos < 0 || pos > 31) return num;
    return num ^ (1U << pos);
}

int GetMSB(int num) {
    unsigned int u = (unsigned int)num;
    if (u == 0U) return -1;

    for (int p = 31; p >= 0; --p) {
        if ((u >> p) & 1U) return p;
    }
    return -1; 
}

int ClearBitRange(int num, int start, int end) {
    if (start < 0 || end > 31 || start > end) return num;

    unsigned int u = (unsigned int)num;

    unsigned int left;
    if (end == 31) {
        left = 0U; 
    } else {
        left = ~0U << (end + 1);
    }

    unsigned int right;
    if (start == 0) {
        right = 0U; 
    } else {
        right = (1U << start) - 1U;
    }

    unsigned int mask = left | right;
    return (int)(u & mask);
}

int RotateLeft(int num, int d) {
    unsigned int u = (unsigned int)num;


    d %= 32;
    if (d < 0) d += 32; 

    if (d == 0) return num;

    unsigned int res = (u << d) | (u >> (32 - d));
    return (int)res;
}

int SwapOddEvenBits(int num) {
    unsigned int u = (unsigned int)num;

    unsigned int even = u & 0xAAAAAAAAU; // bits 1,3,5,...
    unsigned int odd  = u & 0x55555555U; // bits 0,2,4,...

    even >>= 1;
    odd <<= 1;

    return (int)(even | odd);
}
