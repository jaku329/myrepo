/*
  https://leetcode.com/problems/spiral-matrix
*/

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int u = 0, d = matrix.size(), l = 0, r = matrix[0].size();
    int i = 0, j = 0;
    int total = matrix.size() * matrix[0].size();
    vector<int> res;
    if (matrix.size() == 0) return res;

    while (total > 0) {
      i = u;
      j = l;
      for (++u; j < r; ++j) {
        res.push_back(matrix[i][j]);
        total--;
      }
      if (total == 0) break;

      i = u;
      j = r - 1;
      for (--r; i < d; ++i) {
        res.push_back(matrix[i][j]);
        total--;
      }
      if (total == 0) break;

      i = d - 1;
      j = r - 1;
      for (--d; j >= l; --j) {
        res.push_back(matrix[i][j]);
        total--;
      }
      if (total == 0) break;

      i = d - 1;
      j = l;
      for (++l; i >= u; --i) {
        res.push_back(matrix[i][j]);
        total--;
      }
      if (total == 0) break;
    }
    return res;
  }
};

int main() {
  vector<vector<int>> m = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};//{{1,2,3}, {4,5,6}, {7,8,9}};
  Solution s;
  auto res = s.spiralOrder(m);
  for (auto it = res.begin(); it != res.end(); it++)
    cout << *it << " ";
  cout << endl;
  return 0;
}
