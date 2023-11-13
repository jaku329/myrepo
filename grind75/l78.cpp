// https://leetcode.com/problems/subsets/

class Solution {
public:
  void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int pos) {
    if (pos >= nums.size()) return;

    result.push_back(path);

    for (int i = pos; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      dfs(nums, result, path, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> subset(vector<int>& nums) {
    vector<int> path;
    vector<vector<int>> result;
    dfs(nums, result, path, 0);
    return result;
  }
};
