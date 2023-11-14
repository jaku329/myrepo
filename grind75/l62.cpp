// https://leetcode.com/problems/unique-paths/description/

class Solution {
public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 0;

    vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        dp[j] = dp[j] + dp[j - 1];
      }
    }
    
    return dp[n - 1];
  }
};

class Solution2 {
public:
  void dfs(int m, int n, int i, int j, int& sum) {
    if (i == m - 1 && j == n - 1)
      sum += 1;
    else {
      if (i < m) dfs(m, n, i + 1, j, sum);
      if (j < n) dfs(m, n, i, j + 1, sum);
    }
  }

  int uniquePaths(int m, int n) {
    if (m <= 0 || n <= 0) return 0;
    int sum = 0;
    dfs(m, n, 0, 0, sum);
    return sum;
  }
};
