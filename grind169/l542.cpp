// 542. 01 Matrix
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  vector<vector<int>> result(mat.size(), vector<int>(mat[0].size(), mat.size() * mat[0].size()));
  for (int i = 0; i < mat.size(); ++i)
    for (int j = 0; j < mat[i].size(); ++j)
      if (result[i][j] != 0) {
        if (i == 0 && j > 0) 
          result[i][j] = result[i][j - 1] + 1;
        else if (i > 0 && j == 0)
          result[i][j] = result[i - 1][j] + 1;
        else if (i > 0 && j > 0)
          result[i][j] = min(result[i][j - 1], result[i - 1][j]) + 1;
      }

  for (int i = mat.size() - 1; i >= 0; --i)
    for (int j = mat[i].size() - 1; j >= 0; --j) {
      if (mat[i][j] != 0) {
        if (i == mat.size() - 1 && j < mat[i].size() - 1)
          result[i][j] = min(result[i][j], result[i][j + 1] + 1);
        else if (i < mat.size() - 1 && j == mat[i].size() - 1)
          result[i][j] = min(result[i][j], result[i + 1][j] + 1);
        else if (i < mat.size() - 1 && j < mat[i].size() - 1)
          result[i][j] = min(result[i][j], min(result[i][j + 1], result[i + 1][j]) + 1);
      }
    }
  return result;
}

int main() {
  vector<vector<int>> mat = {
{0,0,1,0,1,1,1,0,1,1}
,{1,1,1,1,0,1,1,1,1,1}
,{1,1,1,1,1,0,0,0,1,1}
,{1,0,1,0,1,1,1,0,1,1}
,{0,0,1,1,1,0,1,1,1,1}
,{1,0,1,1,1,1,1,1,1,1}
,{1,1,1,1,0,1,0,1,0,1}
,{0,1,0,0,0,1,0,0,1,1}
,{1,1,1,0,1,1,0,1,0,1}
,{1,0,1,1,1,0,1,1,1,0}
  };
  auto r = updateMatrix(mat);
  for (auto v : r) {
    for (auto c : v)
      cout << c << " ";
    cout << endl;
  }
  return 0;
}
