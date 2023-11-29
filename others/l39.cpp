// 

void dfs(vector<int>& candidates, int target, int start, vector<vector<int>>& result, vector<int>& picked) {
  if (target == 0) {
    result.push_back(picked);
    return;
  }
  else if (target < 0) return;

  for (int i = start; i < candidates.size(); ++i) {
    picked.push_back(candidates[i]);
    dfs(candidates, target - candidates[i], i, result, picked);
    picked.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> result;
  vector<int> picked;
  dfs(candidates, target, 0, result, picked);
  return result;
}
