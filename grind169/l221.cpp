// 221. Maximal Square

int maximalSquares(vector<vector<char>>& matrix) {
  int edge = 0;
  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
  for (int j = 0; j < matrix[0].size(); ++j) {
    dp[0][j] = matrix[0][j] - '0';
    if (edge == 0 && matrix[0][j] == '1')
      edge = 1;
  }
  for (int i = 0; i < matrix.size(); ++i) {
    dp[i][0] = matrix[i][0] - '0';
    if (edge == 0 && matrix[i][0] == '1')
      edge = 1;
  }

  for (int i = 1; i < matrix.size(); ++i) {
    for (int j = 1; j < matrix[i].size(); ++j) {
      if (matrix[i][j] == '0')
        dp[i][j] = 0;
      else if (dp[i - 1][j - 1] == 0 || dp[i - 1][j] == 0 || dp[i][j - 1] == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      edge = max(edge, dp[i][j]);
    }
  }
  return edge * edge;
}
