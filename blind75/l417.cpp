// https://leetcode.com/problems/pacific-atlantic-water-flow

class Solution {
public:
  void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<int>>& visited) {
    if (visited[i][j]) return;

    visited[i][j] = true;
    if (i > 0 && heights[i - 1][j] >= heights[i][j]) dfs(heights, i - 1, j, visited);
    if (j > 0 && heights[i][j - 1] >= heights[i][j]) dfs(heights, i, j - 1, visited);
    if (i < heights.size() - 1 && heights[i + 1][j] >= heights[i][j]) dfs(heights, i + 1, j, visited);
    if (j < heights[i].size() - 1 && heights[i][j + 1] >= heights[i][j]) dfs(heights, i, j + 1, visited);
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    vector<vector<int>> pacific(heights.size(), vector<int>(heights[0].size(), false));
    vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), false));
    vector<vector<int>> res;

    for (int i = 0; i < heights.size(); i++)
      dfs(heights, i, 0, pacific);
    for (int j = 1; j < heights[0].size(); j++)
      dfs(heights, 0, j, pacific);

    for (int i = 0; i < heights.size(); i++)
      dfs(heights, i, heights[i].size() - 1, atlantic);
    for (int j = 0; j < heights[0].size() - 1; j++)
      dfs(heights, heights.size() - 1, j, atlantic);

    for (int i = 0; i < pacific.size(); ++i)
      for (int j = 0; j < pacific[i].size(); ++j) {
        if (pacific[i][j] && atlantic[i][j]) 
          res.push_back({i, j});
    }

    return res;
  }
};
