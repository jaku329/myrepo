// https://leetcode.com/problems/combination-sum-ii/

void dfs(vector<int>& nums, int target, int start, vector<vector<int>>& result, vector<int>& picked) {
  if (target == 0) {
    result.push_back(picked);
    return;
  }
  else if (target < 0) return;

  for (int i = start; i < nums.size(); ++i) {
    if (i > start && nums[i] == nums[i - 1]) continue; // for optimizing

    picked.push_back(nums[i]);
    dfs(nums, target - nums[i], i + 1, result, picked);
    picked.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  vector<vector<int>> result;
  vector<int> picked;
  sort(candidates.begin(), candidates.end()); // for optimizing
  dfs(candidates, target, 0, result, picked);
  return result;
}
