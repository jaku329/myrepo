// https://leetcode.com/problems/longest-increasing-subsequence
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 1) return 1;
    int len = 1;
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
          len = max(dp[i], len);
        }
      }
    }
    return len;
  }
};


int main() {
  vector<int> nums = {10,9,2,5,3,7,101,18};
  for (auto it = nums.begin(); it != nums.end(); it++) cout << *it << " "; cout << endl;
  Solution s;
  cout << s.lengthOfLIS(nums);
  return 0;
}
