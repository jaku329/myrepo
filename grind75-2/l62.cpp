// 62. Unique Paths

// 1. dfs

// 2. DP
int uniquePath(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 || j == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[m - 1][n - 1];
}

// 3. DP optimize: O(mn);O(n)
int uniquePath(int m, int n) {
  vector<int> dp(n, 0);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 || j == 0)
        dp[j] = 1;
      else
        dp[j] = dp[j] + dp[j - 1];
    }
  }
  return dp[n - 1];
}
