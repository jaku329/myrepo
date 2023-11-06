// https://leetcode.com/problems/permutations/

class Solution {
public:
  vector<vector<int>> result;
  void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& visited) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (!visited[i]) {
        path.push_back(nums[i]);
        visited[i] = true;
        backtrack(nums, path, visited);
        visited[i] = false;
        path.pop_back();
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path;
    vector<bool> visited(nums.size(), false);
    backtrack(nums, path, visited);
    return result;
  }
};

class Solution2 {
  vector<vector<int>> result;
  void backtrack(vector<int>& nums, vector<int>& path, int start) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = start; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        swap(nums[i], nums[start]);
        backtrack(nums, path, start + 1);
        swap(nums[i], nums[start]);
        path.pop_back();
      }
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<int> path;
    backtrack(nums, path, 0);
    return result;
  }

};
