// https://leetcode.com/problems/combination-sum-iii/

void dfs(vector<vector<int>>& result, vector<int>& picked, int k, int n, int start) {
  if (n == 0 && k == 0) {
    result.push_back(picked);
    return;
  }
  else if (n < 0) return;
  else if (k == 0) return;
  

  for (int i = start; i <= 9; ++i) {
    picked.push_back(i);
    dfs(result, picked, k - 1, n - i, i + 1);
    picked.pop_back();
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> result;
  vector<int> picked;
  dfs(result, picked, k, n, 1);
  return result;
}
