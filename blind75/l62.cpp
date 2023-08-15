// https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>
using namespace std;

// time limit exceed
class Solution {
public:
  void dfs(int m, int n, int y, int x, int& sum) {
    if (y == m - 1 && x == n - 1) {
      sum++;
      return;
    }
    
    if (y + 1 < m) dfs(m, n, y + 1, x, sum);
    if (x + 1 < n) dfs(m, n, y, x + 1, sum);
  }

  int uniquePaths(int m, int n) {
    int sum = 0;
    dfs(m, n, 0, 0, sum);
    return sum;
  }
};

// DP
class Solution2 {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0) dp[i][j] = 1;
        else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m - 1][n - 1];
  }
};

// DP + reduce space complexity
class Solution3 {
public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0) dp[j] = 1;
        else dp[j] = dp[j] + dp[j - 1];
      }
    }
    return dp[n - 1];
  }
};

int main() {
  Solution3 s;
  cout << s.uniquePaths(3, 7) << endl;
}
