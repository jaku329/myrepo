// 90. Subsets II

void dfs(vector<int>& nums, int start, vector<vector<int>>& result, vector<int>& path) {
  result.push_back(path);
  for (int i = start; i < nums.size(); ++i) {
    if (i > start && nums[i - 1] == nums[i])
      continue;
    path.push_back(nums[i]);
    dfs(nums, i + 1, result, path);
    path.pop_back();
  }
}

vector<vector<int>> subsetWithDup(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> path;
  sort(nums.begin(), nums.end());
  dfs(nums, 0, result, path);
  return result;
}
