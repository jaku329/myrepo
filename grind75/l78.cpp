// https://leetcode.com/problems/subsets/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int pos) {
    if (pos >= nums.size()) return;

    result.push_back(path);

    for (int i = pos + 1; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      dfs(nums, result, path, i);
      path.pop_back();
    }
  }

  vector<vector<int>> subset(vector<int>& nums) {
    vector<int> path;
    vector<vector<int>> result;
    result.push_back(path);
    for (int i = 0; i < nums.size(); ++i)
    {
      path.push_back(nums[i]);
      dfs(nums, result, path, i);
      path.pop_back();
    }
    return result;
  }
};

class Solution2 {
public:
  void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int pos) {
    result.push_back(path);

    for (int i = pos; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      dfs(nums, result, path, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> subset(vector<int>& nums) {
    vector<int> path;
    vector<vector<int>> result;
    dfs(nums, result, path, 0);
    return result;
  }

};

int main() {
  vector<int> nums = {
    1,2,3
  };

  Solution2 s;

  auto r = s.subset(nums);
 
  for (auto it = r.begin(); it != r.end(); it++) {
    for (auto it2 = it->begin(); it2 != it->end(); it2++)
      cout << *it2 << " ";
    cout << endl;
  }
 
  return 0;
}
