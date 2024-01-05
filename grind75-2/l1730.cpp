// 1730 - Shortest Path to Get Food

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

  vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
  int steps = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int k = 0; k < size; ++k) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      if (grid[i][j] == '#')
        return steps; 
      if (i > 0 && !visited[i - 1][j] && grid[i - 1][j] != 'X') {
        visited[i - 1][j] = true;
        q.push({i - 1, j});
      }
      if (i < grid.size() - 1 && !visited[i + 1][j] && grid[i + 1][j] != 'X') {
        visited[i + 1][j] = true;
        q.push({i + 1, j});
      }
      if (j > 0 && !visited[i][j - 1] && grid[i][j - 1] != 'X') {
        visited[i][j - 1] = true;
        q.push({i, j - 1});
      }
      if (j < grid[i].size() - 1 && !visited[i][j + 1] && grid[i][j + 1] != 'X') {
        visited[i][j + 1] = true;
        q.push({i, j + 1});
      }
    }
    steps++;
  }
  return -1;
}

int main() {
  vector<vector<char>> g1 = {
    {'X','X','X','X','X','X'},{'X','*','O','O','O','X'},{'X','O','O','#','O','X'},{'X','X','X','X','X','X'}
  };
  vector<vector<char>> g2 = {
    {'X','X','X','X','X'},{'X','*','X','O','X'},{'X','O','X','#','X'},{'X','X','X','X','X'}
  };
  vector<vector<char>> g3 = {
    {'X','X','X','X','X','X','X','X'},{'X','*','O','X','O','#','O','X'},{'X','O','O','X','O','O','X','X'},{'X','O','O','O','O','#','O','X'},{'X','X','X','X','X','X','X','X'}
  };
  vector<vector<char>> g4 = {
    {'O','*'},{'#','O'}
  };
  vector<vector<char>> g5 = {
    {'X','*'},{'#','X'}
  };

  cout << getFood(g1);
  cout << getFood(g2);
  cout << getFood(g3);
  cout << getFood(g4);
  cout << getFood(g5);
  return 0;
}
