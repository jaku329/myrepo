#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  vector<int> path;
  void backtrace(vector<int>&nums, int target, int pos) {
    if (target == 0) {
      res.push_back(path);
      return;
    }

    for (int i = pos; i < nums.size(); ++i) {
      if (target >= nums[i]) {
        path.push_back(nums[i]);
        backtrace(nums, target - nums[i], i);
        path.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backtrace(candidates, target, 0);
    return res;
  }
};

int main() {
  vector<int> nums = {7,3,2}; //{2,3,6,7};
  Solution s;
  vector<vector<int>> res = s.combinationSum(nums, 18);

  for (auto it = res.begin(); it < res.end(); ++it) {
    for (auto it2 = it->begin(); it2 < it->end(); ++it2)
      cout << *it2 << " ";
    cout << endl;
  }
}
