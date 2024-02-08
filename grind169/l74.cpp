// 74. Search a 2D Matrix

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int l = 0, r = matrix.size() * matrix[0].size() - 1;
  while (l <= r) {
    int m = l + ((r - l) >> 1);
    int y = m / matrix[0].size();
    int x = m % matrix[0].size();
    if (matrix[y][x] == target)
      return true;
    else if (matrix[y][x] < target)
      l = m + 1;
    else
      r = m - 1;
  }
  return false;
}

int main() {
  vector<vector<int>> matrix = {
    {1, 1}
  };
  cout << searchMatrix(matrix, 2) << endl;
  return 0;
}
