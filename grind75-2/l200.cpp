// 200. Number of Islands

void dfs(vector<vector<char>>& grid, int i, int j) {
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return;
  else if (grid[i][j] == '0') return;

  grid[i][j] = '0';
  dfs(grid, i - 1, j);
  dfs(grid, i + 1, j);
  dfs(grid, i, j - 1);
  dfs(grid, i, j + 1);
}

int numIslands(vector<vector<char>>& grid) {
  int num = 0;
  for (int i = 0; i < grid.size(); ++i)
    for (int j = 0; j < grid[i].size(); ++j)
      if (grid[i][j] != '0') {
        num++;
        dfs(grid, i, j);
      }
  return num;
}
