// 48. Rotate Image

#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
  for (int i = 0; i < matrix.size(); ++i) {
    int l = 0, r = matrix[i].size() - 1;
    while (l < r) {
      swap(matrix[i][l], matrix[i][r]);
      l++;
      r--;
    }
  }
  for (int i = 0; i < matrix.size(); ++i)
    for (int j = 0; j < i; ++j)
        swap(matrix[i][j], matrix[j][i]);
}

int main() {
  vector<vector<int>> matrix = {
    {1,2,3},{4,5,6},{7,8,9}
  };
  rotate(matrix);

  for (auto r : matrix) {
    for (auto c : r)
      cout << c << " ";
    cout << endl;
  }
  return 0;
}
