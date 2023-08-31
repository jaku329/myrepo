// https://leetcode.com/problems/reverse-bits

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    ret |= n & 0x01;
    for (int i = 1; i < 32; ++i) {
      ret = ret << 1;
      n = n >> 1;
      ret |= n & 0x01;
    }
    return ret;
  }
};

