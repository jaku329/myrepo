// https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  vector<int> dp(nums.size(), 1);
  int len = 1;
  for (int i = 1; i < nums.size(); ++i)
    for (int j = i - 1; j >= 0; --j) {
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1)
        len = max(len, dp[i]);
      }
    }
  return len;
}

int main() {
  vector<int> nums = {
    0,1,0,3,2,3
  };
  return 0;
}
