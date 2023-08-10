#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size() / 2; ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        matrix[i][j] ^= matrix[matrix.size() - i - 1][j];
        matrix[matrix.size() - i - 1][j] ^= matrix[i][j];
        matrix[i][j] ^= matrix[matrix.size() - i - 1][j];
      }
    }
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = i + 1; j < matrix[i].size(); ++j) {
        matrix[i][j] ^= matrix[j][i];
        matrix[j][i] ^= matrix[i][j];
        matrix[i][j] ^= matrix[j][i];
      }
    }
  }
};
