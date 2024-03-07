// 191. Number of 1 Bits

int hammingWeight(uint32_t n) {
  int cnt = 0;
  while (n) {
    if (n & 0x1)
      cnt++;
    n = n >> 1;
  }
  return cnt;
}

// tracky
int hammingWeight(uint32_t n) {
  int cnt = 0;
  while (n) {
    cnt++;
    n &= (n - 1);
  }
  return cnt;
}
