// 240. Search a 2D Matrix II

#include <iostream>
#include <vector>
using namespace std;
// search matrix[c1][r1 ~ r2]
bool searchRow(vector<vector<int>>& matrix, int& r1, int& r2, int c1, int c2, int target) {
  int l = r1, r = r2;
  while (l <= r) {
    int m = l + ((r - l) >> 1);
    if (matrix[c1][m] == target)
      return true;
    else if (matrix[c1][m] > target)
      r = m - 1;
    else
      l = m + 1;
  }
  r2 = r;
  return false;
}

// search matrix[c1 ~ c2][r1]
bool searchCol(vector<vector<int>>& matrix, int r1, int r2, int& c1, int& c2, int target) {
  int l = c1, r = c2;
  while (l <= r) {
    int m = l + ((r - l) >> 1);
    if (matrix[m][r1] == target)
      return true;
    else if (matrix[m][r1] > target)
      r = m - 1;
    else
      l = m + 1;
  }
  c2 = r;
  return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int r1 = 0, r2 = matrix[0].size() - 1;
  int c1 = 0, c2 = matrix.size() - 1;
  while (r1 <= r2 && c1 <= c2) {
    if (searchRow(matrix, r1, r2, c1, c2, target))
      return true;
    else
      c1++;
    if (searchCol(matrix, r1, r2, c1, c2, target))
      return true;
    else
      r1++;
  }
  return false;
}

int main() {
  vector<vector<int>> matrix = {
    {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}
  };
  cout << searchMatrix(matrix, 20);

  return 0;
}
