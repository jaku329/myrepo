// https://leetcode.com/problems/climbing-stairs

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int recursive(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    return recursive(n - 1) + recursive(n - 2);
  }
  int dp1(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
  int dp2(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    vector<int> dp(3, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
      dp[2] = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = dp[2];
    }
    return dp[3];
  }
  int climbStairs(int n) {
    return dp[n];
  }
};


