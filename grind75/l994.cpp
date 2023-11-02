// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
  int orangeRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 2)
          q.push({i, j});
      }
    }

    int minutes = -1;
    if (q.empty()) minutes = 0;
    while (!q.empty()) {
      minutes++;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        pair<int, int> p = q.front();
        q.pop();
        if (p.first > 0 && grid[p.first - 1][p.second] == 1) {
          grid[p.first - 1][p.second] = 2;
          q.push({p.first - 1, p.second});
        }
        if (p.first < grid.size() - 1 && grid[p.first + 1][p.second] == 1) {
          grid[p.first + 1][p.second] = 2;
          q.push({p.first + 1, p.second});
        }
        if (p.second > 0 && grid[p.first][p.second - 1] == 1) {
          grid[p.first][p.second - 1] = 2;
          q.push({p.first, p.second - 1});
        }
        if (p.second < grid[p.first].size() - 1 && grid[p.first][p.second + 1] == 1) {
          grid[p.first][p.second + 1] = 2;
          q.push({p.first, p.second + 1});
        }
      }
    }

    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1)
          return -1;
      }
    }
    return minutes;
  }
};
