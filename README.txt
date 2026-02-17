HW3 Practice Solution

Build:
  make

Run:
  ./hw3

Part 1:
  - ToggleBit: tested valid positions (0,3) and invalid (32).
  - GetMSB: tested 18,0,1.
  - ClearBitRange: tested normal range, full range, invalid range.
  - RotateLeft: tested d=1,2,31.
  - SwapOddEvenBits: tested 23->43 and 0->0.

Part 2:
  - Verified against provided examples (5.5, -5.5, 1.25, -1.25, 0.002588).

Part 3:
  - Verified the exact example conversions:
    S->2 0x80000001 => ffffffff
    S->2 0x80000000 => 00000000
    2->2 0x59f2ca50 => 59f2ca50
    invalid repr => error
    2->S 0x80000000 => undefined
