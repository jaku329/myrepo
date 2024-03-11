// 48. Rotate Image

void rotate(vector<vector<int>>& matrix) {
  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      if (j > i) {
        matrix[i][j] ^= matrix[j][i];
        matrix[j][i] ^= matrix[i][j];
        matrix[i][j] ^= matrix[j][i];
      }
    }
  }
  for (int i = 0; i < matrix.size(); ++i)
    reverse(matrix.begin(), matrix.end());
}
