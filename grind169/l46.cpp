// 46. Permutations

void dfs(vector<int>& nums, int start, vector<vector<int>>& result, vector<int>& path) {
  if (start >= nums.size())
    result.push_back(path);
  for (int i = start; i < nums.size(); ++i) {
    path.push_back(nums[i]);
    swap(nums[start], nums[i]);
    dfs(nums, i + 1, result, path);
    swap(nums[start], nums[i]);
    path.pop_back();
  }
}
vector<vector<int>> permutate(vector<int>& nums) {
  vector<vector<int>> result;
  vector<int> path;
  dfs(nums, 0, result, path);
  return result;
}
