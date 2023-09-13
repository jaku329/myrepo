// https://leetcode.com/problems/counting-bits

class Solution {
public:
  vector<int> countBits(int n) {
    int msb = 2;
    int ls = 1;
    vector<int> dp(n + 1, 0);
    if (n == 0) return dp;
    dp[1] = 1;
    if (n == 1) return dp;
    dp[2] = 1;

    for (int i = 3; i <= n; ++i) {
      if (msb == ls) {
        dp[i] = 1;
        msb = i;
        ls = 1;
      }
      else {
        dp[i] = dp[msb] + dp[ls++];
      }
    }
    return dp;
  }
};
