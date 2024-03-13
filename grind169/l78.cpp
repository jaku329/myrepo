// 78. Subset

void dfs(vector<int>& nums, int start, vector<vector<int>>& result, vector<int>& path) {
  result.push_back(path);
  
  for (int i = start; i < nums.size(); ++i) {
    path.push_back(nums[i]);
    dfs(nums, i + 1, result, path);
    path.pop_back();
  }
}
vector<vector<int>> subset(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> path;
  dfs(nums, 0, result, path);
  return result;
}
