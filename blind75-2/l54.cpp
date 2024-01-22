// 54. Spiral Matrix

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> result;
  if (matrix.size() == 0) return result;
  int u = 0, d = matrix.size() - 1, l = 0, r = matrix[0].size() - 1; // close
  int i = 0, j = 0;
  int dir = 1; // 0:up; 1:right; 2:down; 3:left
  int cnt = matrix.size() * matrix[0].size();
  while (result.size() < cnt - 1) {
    if (dir == 0) {
      if (i > u)
        result.push_back(matrix[i--][j]);
      else {
        dir = 1;
        l++;
      }
    }
    else if (dir == 1) {
      if (j < r)
        result.push_back(matrix[i][j++]);
      else {
        dir = 2;
        u++;
      }
    }
    else if (dir == 2) {
      if (i < d)
        result.push_back(matrix[i++][j]);
      else {
        dir = 3;
        r--;
      }
    }
    else if (dir == 3) {
      if (j > l)
        result.push_back(matrix[i][j--]);
      else {
        dir = 0;
        d--;
      }
    }
  }
  result.push_back(matrix[i][j]);
  return result;
}

int main() {
  vector<vector<int>> matrix = {
//    {1,2,3}, {4,5,6}, {7,8,9}
   {1,2,3,4},{5,6,7,8},{9,10,11,12}
  };
  auto r = spiralOrder(matrix);
  for (auto c : r) 
    cout << c << " ";
  cout << endl;
  return 0;
}
