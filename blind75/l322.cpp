// https://leetcode.com/problems/coin-change

class Solution {
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < coins.size(); ++j) {
        if (coins[j] <= i)
          dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
      }
    }
    if (dp[amount] == amount + 1) return -1;
    return dp[amount];
  }
};
