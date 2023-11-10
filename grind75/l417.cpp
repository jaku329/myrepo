// https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>

using namespace std;

// 1.backtrack

// 2. DP
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int halfSum = 0;
    for (int i = 0; i < nums.size(); ++i)
      halfSum += nums[i];
    if (halfSum & 0x1) return false;
    halfSum /= 2;
  
    vector<bool> dp(halfSum + 1, false);
    dp[0] = false;
    if (nums[0] > halfSum) return false;
    dp[nums[0]] = true;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = halfSum; j > nums[i]; --j) {
        dp[j] = dp[j - nums[i]] | dp[j];
        if (dp[halfSum]) return true;
      }
      if (dp[halfSum]) return true;
    }
    return false;
  }
};

int main() {
  vector<int> nums = {
    2,2,3,5
  };
  Solution s;
  
  cout << s.canPartition(nums) << endl;
  return 0;
}
