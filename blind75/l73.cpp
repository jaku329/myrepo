// https://leetcode.com/problems/set-matrix-zeroes/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void setZeros(vector<vector<int>>& matrix) {
    vector<int> mBits(matrix.size(), 0);
    vector<int> nBits(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == 0) {
          mBits[i] = 1;
          nBits[j] = 1;
        }
      }
    }

    for (int i = 0; i < mBits.size(); ++i) {
      if (mBits[i] > 0) {
        for (int j = 0; j < matrix[i].size(); ++j)
          matrix[i][j] = 0;
      }
    }

    for (int j = 0; j < nBits.size(); ++j) {
      if (nBits[j] > 0) {
        for (int i = 0; i < matrix.size(); ++i)
          matrix[i][j] = 0;
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix = {{0}};
  Solution s;
  s.setZeros(matrix);
  return 0;
}
