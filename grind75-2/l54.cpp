// 54. Spiral Matrix

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> result;
  if (matrix.size() == 0) return result;
  int size = matrix.size() * matrix[0].size();
  int i = 0, j = 0;
  int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
  while (i > up || i < down || j > left || j < right) {
    while (j < right) {
      result.push_back(matrix[i][j]);
      j++;
    }
    up++;

    while (i < down) {
      result.push_back(matrix[i][j]);
      i++;
    }
    right--;

    while (j > left) {
      result.push_back(matrix[i][j]);
      j--;
    }
    down--;

    while (i > up) {
      result.push_back(matrix[i][j]);
      i--;
    }
    left++;
  }
  result.push_back(matrix[i][j]);
  return result;
}

int main() {
  vector<vector<int>> matrix = {
   {1,2,3},
   {4,5,6},
   {7,8,9}
  };
  auto r = spiralOrder(matrix);
  for (auto v : r)
    cout << v << " ";
  cout << endl;
  return 0;
}
