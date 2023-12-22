// 994. Rotting Oranges

int organgeRotting(vector<vector<int>>& grid) {
  int min = 0;
  queue<pair<int, int>> q;
  for (int i = 0; i < grid.size(); ++i) 
    for (int j = 0; j < grid[i].size(); ++j)
	  if (grid[i][j] == 2)
	    q.push({i, j});

  while (!q.empty()) {
    min++;
    int size = q.size();
	for (int i = 0; i < size; ++i) {
	  int y = q.front().first;
	  int x = q.front().second;
	  q.pop();
	  if (y > 0 && grid[y - 1][x] == 1) {
	    grid[y - 1][x] = 2;
		q.push({y - 1, x});
	  }
	  if (y < grid.size() - 1 && grid[y + 1][x] == 1) {
	    grid[y + 1][x] = 2;
		q.push({y + 1, x});
	  }
	  if (x > 0 && grid[y][x - 1] == 1) {
	    grid[y][x - 1] = 2;
		q.push({y, x - 1});
	  }
	  if (x < grid[y].size() - 1 && grid[y][x + 1] == 1) {
	    grid[y][x + 1] = 2;
		q.push({y, x + 1});
	  }
	}
  }
  for (int i = 0; i < grid.size(); ++i) 
    for (int j = 0; j < grid[i].size(); ++j)
	  if (grid[i][j] == 1)
	    return -1;
  if (min == 0) return 0;
  return min - 1;
}

