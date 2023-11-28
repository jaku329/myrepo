// https://leetcode.ca/2021-03-13-1730-Shortest-Path-to-Get-Food/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getFood(vector<vector<char>>& grid) {
  queue<pair<int, int>> q;

  for (int i = 0; i < grid.size(); ++i)
    for (int j = 0; j < grid[i].size(); ++j)
      if (grid[i][j] == '*')
        q.push({i, j});

  int steps = 0;
  while (!q.empty()) {
    int size = q.size();
    steps++;
    for (int i = 0; i < size; ++i) {
      int m = q.front().first;
      int n = q.front().second;
      q.pop();
      
      grid[m][n] = 'X';
      if (m > 0)
        if (grid[m - 1][n] == '#') return steps;
        else if (grid[m - 1][n] != 'X')
          q.push({m - 1, n});
      if (m < grid.size() - 1)
        if (grid[m + 1][n] == '#') return steps;
        else if (grid[m + 1][n] != 'X')
          q.push({m + 1, n});
      if (n > 0)
        if (grid[m][n - 1] == '#') return steps;
        else if (grid[m][n - 1] != 'X')
          q.push({m, n - 1});
      if (n < grid[m].size() - 1)
        if (grid[m][n + 1] == '#') return steps;
        else if (grid[m][n + 1] != 'X')
          q.push({m, n + 1});
    }
  }
  return -1;
}

int main() {
  vector<vector<char>> grid = {
//    {'X','X','X','X','X','X'},{'X','*','O','O','O','X'},{'X','O','O','#','O','X'},{'X','X','X','X','X','X'} // 3
//    {'X','X','X','X','X'},{'X','*','X','O','X'},{'X','O','X','#','X'},{'X','X','X','X','X'} // -1
//    {'X','X','X','X','X','X','X','X'},{'X','*','O','X','O','#','O','X'},{'X','O','O','X','O','O','X','X'},{'X','O','O','O','O','#','O','X'},{'X','X','X','X','X','X','X','X'} // 6
//    {'O','*'},{'#','O'} // 2
    {'X','*'},{'#','X'} // -1 
  };
  cout << getFood(grid) << endl;
  return 0;
}
