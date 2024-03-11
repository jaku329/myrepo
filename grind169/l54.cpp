// 54. Spiral Matrix

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> result;
  int direction = 0;
  int boundT = 0, boundB = matrix.size() - 1, boundL = 0, boundR = matrix[0].size() - 1;
  unsigned int total = matrix.size() * matrix[0].size();
  int i = 0, j = 0;
  while (totall-- > 0) {
    result.push_back(matrix[i][j]);
    switch (direction) {
      case 0: // to right
        if (j == boundR) {
          i++;
          boundT++;
          direction++;
        }
        else
          j++;
        break;
      case 1: // to bottom
        if (i == boundB) {
          j--;
          boundR--;
          direction++;
        }
        else
          i++;
        break;
      case 2: // to left
        if (j == boundL) {
          i--;
          boundB--;
          direction++;
        }
        else
          j--;
        break;
      case 3: // to top
        if (i == boundT) {
          j++;
          boundL++;
          direction = 0;
        }
        else
          i--;
        break;
    }
  }
  return result;
}
