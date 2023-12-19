// 542. 01 Matrix
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS: O((MN)^2);O(MN)
// Memory Limit Exceeded
int bfs(vector<vector<int>>& mat, int i, int j) {
  int steps = 0;
  queue<pair<int, int>> q;
  q.push({i, j});
  while (!q.empty()) {
    steps++;
    int size = q.size();
    for (int k = 0; k < size; ++k) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      if (y > 0) {
        if (mat[y - 1][x] == 0)
          return steps;
        q.push({y - 1, x});
      }
      if (y < mat.size() - 1) {
        if (mat[y + 1][x] == 0) 
          return steps;
        q.push({y + 1, x});
      }
      if (x > 0) {
        if (mat[y][x - 1] == 0)
          return steps;
        q.push({y, x - 1});
      }
      if (x < mat[y].size() - 1) {
        if (mat[y][x + 1] == 0)
          return steps;
        q.push({y, x + 1});
      }
    }
  }
  return -1;
}
vector<vector<int>> updateMatrix1(vector<vector<int>>& mat) {
  vector<vector<int>> result(mat.size(), vector<int>(mat[0].size(), 0));
  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[i].size(); ++j) {
      if (mat[i][j] != 0)
        result[i][j] = bfs(mat, i, j);
    }
  }
  return result;
}


// DP: O(MN);O(MN)
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), mat.size() * mat[0].size()));
  for (int i = 0; i < mat.size(); ++i) {
    for (int j = 0; j < mat[i].size(); ++j) {
      if (mat[i][j] == 0)
        dp[i][j] = 0;
      else {
        if (i == 0 && j == 0) {
          continue;
        }
        else if (i == 0)
          dp[i][j] = dp[i][j - 1] + 1;
        else if (j == 0)
          dp[i][j] = dp[i - 1][j] + 1;
        else
          dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
      }
    }
  }
  for (int i = mat.size() - 1; i >= 0; --i) {
    for (int j = mat[i].size() - 1; j >= 0; --j) {
      if (i == mat.size() - 1 && j == mat[i].size() - 1) 
        continue;
      if (i == mat.size() - 1)
        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
      else if (j == mat[i].size() - 1)
        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
      else
        dp[i][j] = min(dp[i][j], min(dp[i][j + 1], dp[i + 1][j]) + 1);
    }
  }
  return dp;
}

int main() {
  vector<vector<int>> mat = {
    {0,0,1,0,1,1,1,0,1,1},
    {1,1,1,1,0,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,1,1},
    {1,0,1,0,1,1,1,0,1,1},
    {0,0,1,1,1,0,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,0,1,0,1,0,1},
    {0,1,0,0,0,1,0,0,1,1},
    {1,1,1,0,1,1,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,0}
  };

  auto r = updateMatrix(mat);
  for (auto v : r) {
    for (auto c : v)
      cout << c << " ";
    cout << endl;
  }
  return 0;
}

