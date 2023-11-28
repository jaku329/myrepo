// https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>

using namespace std;

// 1.backtrack

class Solution {
public:
  void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& to) {
    if (to[i][j]) return;

    to[i][j] = true;
    if (i > 0 && heights[i][j] <= heights[i - 1][j]) 
      dfs(heights, i - 1, j, to);
    if (i < heights.size() - 1 && heights[i][j] <= heights[i + 1][j])
      dfs(heights, i + 1, j, to);
    if (j > 0 && heights[i][j] <= heights[i][j - 1])
      dfs(heights, i, j - 1, to);
    if (j < heights[i].size() - 1 && heights[i][j] <= heights[i][j + 1])
      dfs(heights, i, j + 1, to);
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
    for (int j = 0; j < heights[0].size() - 1; ++j) {
      dfs(heights, heights.size() - 1, j, toA);
    }

    vector<vector<int>> result;
    for (int i = 0; i < heights.size(); ++i)
      for (int j = 0; j < heights[i].size(); ++j)
        if (toP[i][j] && toA[i][j])
          result.push_back({i, j});

    return result;
  }
};

// 3. DP optimizing



int main() {
  vector<vector<int>> heights = {
    {1,2,3},
    {8,9,4},
    {7,6,5}
  };
  Solution s;
  
  auto r = s.pacificAtlantic(heights);

  for (auto v : r) {
    for (auto p : v)
      cout << p << " " ;
    cout << endl;
  }

  return 0;
}
