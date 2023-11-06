// https://leetcode.com/problems/combination-sum/

class Solution {
public:
  void backtrack(vector<int>& can, int target, int c, vector<vector<int>>& result, vector<int>& path) {
    if (target == 0) {
      result.push_back(path);
      return;
    }
    else if (target < 0) {
      return;
    }

    for (int i = c; i < can.size(); ++i) {
      path.push_back(can[i]);
      backtrack(can, target - can[i], i, result, path);
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    for (int i = 0; i < candidates.size(); ++i) {
      path.push_back(candidates[i]);
      backtrack(candidates, target - candidates[i], i, result, path);
      path.pop_back();
    }
    return result;
  }
};
