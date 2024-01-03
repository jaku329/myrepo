// 417. Pacific Atlantic Water Flow

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& toX) {
  if (toX[i][j]) return;

  toX[i][j] = true;

  if (i > 0 && heights[i - 1][j] >= heights[i][j]) {
    dfs(heights, i - 1, j, toX);
  }
  if (i < heights.size() - 1 && heights[i + 1][j] >= heights[i][j]) {
    dfs(heights, i + 1, j, toX);
  }
  if (j > 0 && heights[i][j - 1] >= heights[i][j]) {
    dfs(heights, i, j - 1, toX);
  }
  if (j < heights[i].size() - 1 && heights[i][j + 1] >= heights[i][j]) {
    dfs(heights, i, j + 1, toX);
  }

}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  vector<vector<bool>> toP(heights.size(), vector<bool>(heights[0].size(), false));
  vector<vector<bool>> toA(heights.size(), vector<bool>(heights[0].size(), false));

  for (int i = 0; i < heights.size(); ++i) {
    dfs(heights, i, 0, toP);
  }
  for (int j = 1; j < heights[0].size(); ++j) {
    dfs(heights, 0, j, toP);
  }

  for (int i = 0; i < heights.size(); ++i) {
    dfs(heights, i, heights[i].size() - 1, toA);
  }
  for (int j = 0; j < heights[heights.size() - 1].size() - 1; ++j) {
    dfs(heights, heights.size() - 1, j, toA);
  }

  vector<vector<int>> result;
  for (int i = 0; i < heights.size(); ++i)
    for (int j = 0; j < heights[i].size(); ++j)
      if (toP[i][j] && toA[i][j])
        result.push_back({i, j});
  return result;
}

int main() {
  vector<vector<int>> heights = {
    {2,1}, {1,2}
  };
  auto r = pacificAtlantic(heights);
  for (auto v : r) {
    for (auto h : v)
      cout << h << " ";
    cout << endl;
  }
  return 0;
}
