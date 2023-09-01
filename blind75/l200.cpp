// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
  int dfs(vector<vector<char>>& grid, int i, int j) {
    if (grid[i][j] == '0') return 0;
    
    grid[i][j] = '0';
    if (i > 0) dfs(grid, i - 1, j);
    if (i < grid.size() - 1) dfs(grid, i + 1, j);
    if (j > 0) dfs(grid, i, j - 1);
    if (j < grid[i].size() - 1) dfs(grid, i, j + 1);

    return 1;
  }

  int numOfIslands(vector<vector<char>>& grid) {
    int num = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == '1') {
          num += dfs(grid, i, j);
        }
      }
    }
    return num;
  }
};
