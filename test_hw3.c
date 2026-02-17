#include <stdio.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"

static void test_part1(void) {
    printf("=== Part 1 Tests ===\n");

    // ToggleBit
    printf("ToggleBit(9,0) expected 8 got %d\n", ToggleBit(9,0));
    printf("ToggleBit(9,3) expected 1 got %d\n", ToggleBit(9,3));
    printf("ToggleBit(9,32) expected 9 got %d\n", ToggleBit(9,32)); // invalid

    // GetMSB
    printf("GetMSB(18) expected 4 got %d\n", GetMSB(18));
    printf("GetMSB(0) expected -1 got %d\n", GetMSB(0));
    printf("GetMSB(1) expected 0 got %d\n", GetMSB(1));

    // ClearBitRange
    printf("ClearBitRange(73,1,3) expected 65 got %d\n", ClearBitRange(73,1,3));
    printf("ClearBitRange(73,0,31) expected 0 got %d\n", ClearBitRange(73,0,31));
    printf("ClearBitRange(73,5,2) expected 73 got %d\n", ClearBitRange(73,5,2)); // invalid

    // RotateLeft
    printf("RotateLeft(5,1) expected 10 got %d\n", RotateLeft(5,1));
    printf("RotateLeft(5,2) expected 20 got %d\n", RotateLeft(5,2));
    printf("RotateLeft(1,31) expected 0x80000000 got 0x%08x\n", (unsigned)RotateLeft(1,31));

    // SwapOddEvenBits
    printf("SwapOddEvenBits(23) expected 43 got %d\n", SwapOddEvenBits(23));
    printf("SwapOddEvenBits(0) expected 0 got %d\n", SwapOddEvenBits(0));
}

static void test_part2(void) {
    printf("\n=== Part 2 Tests ===\n");
    printf("5.5?  %g\n", construct_float_sf(0x00, 0x81, 0x300000));
    printf("-5.5? %g\n", construct_float_sf(0x01, 0x81, 0x300000));
    printf("1.25? %g\n", construct_float_sf(0x00, 0x7F, 0x200000));
    printf("-1.25? %g\n", construct_float_sf(0x01, 0x7F, 0x200000));
    printf("0.002588? %g\n", construct_float_sf(0x00, 0x76, 0x299B6F));
}

static void test_part3(void) {
    printf("\n=== Part 3 Tests ===\n");
    // expected outputs from pdf examples
    repr_convert('S', '2', 0x80000001U); // ffffffff
    repr_convert('S', '2', 0x80000000U); // 00000000
    repr_convert('2', '2', 0x59f2ca50U); // 59f2ca50
    repr_convert('F', '2', 0x00394812U); // error
    repr_convert('2', 'S', 0x80000000U); // undefined
}

int main(void) {
    test_part1();
    test_part2();
    test_part3();
    return 0;
}
