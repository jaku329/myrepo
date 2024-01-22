// 39. Combination Sum

void dfs(vector<int>& candidates, int pos, int target, vector<vector<int>>& result, vector<int>& path) {
  if (target == 0) {
    result.push_back(path);
    return;
  }
  else if (target < 0) 
    return;

  for (int i = pos; i < candidates.size(); ++i) {
    path.push_back(candidates[i]);
    dfs(candidates, i, target - candidates[i], result, path);
    path.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> result;
  vector<int> path;
  dfs(candidates, 0, target, result, path);
  return result;
}
