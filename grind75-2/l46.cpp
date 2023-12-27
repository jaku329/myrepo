// 46. Permutations

void dfs(vector<int>& nums, int pos, vector<vector<int>>& result) {
  if (pos == nums.size())
    result.push_back(nums);
  
  for (int i = pos; i < nums.size(); ++i) {
    swap(nums[i], nums[pos]);
    dfs(nums, pos + 1, result);
    swap(nums[i], nums[pos]);
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> result;
  dfs(nums, 0, result);
  return result;
}
