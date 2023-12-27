// 78. Subsets

void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int start) {
  result.push_back(path);
  for (int i = start; i < nums.size(); ++i) {
    path.push_back(nums[i]);
    dfs(nums, result, path, i + 1);
    path.pop_back();
  }
}

vector<vector<int>> subset(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> path;
  dfs(nums, result, path, 0);
  return result;
}
