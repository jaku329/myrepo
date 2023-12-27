// 39. Combination Sum

void dfs(vector<int>& candidates, int target, int start, vector<vector<int>>& result, vector<int>& nums) {
  if (target == 0) 
    result.push_back(nums);
  else if (target < 0)
    return;

  for (int i = start; i < candidates.size(); ++i) {
    nums.push_back(candidates[i]);
    dfs(candidates, target - candidates[i], i, result, nums);
    nums.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<vector<int>>& candidates, int target) {
  vector<vector<int>> result;
  vector<int> nums;
  dfs(candidates, target, 0, result, nums);
  return result;
}
