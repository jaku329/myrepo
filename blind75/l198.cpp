// https://leetcode.com/problems/house-robber

class Solution {
  int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0) dp[i] = nums[0];
      else if (i == 1) dp[i] = max(dp[i - 1], nums[i]);
      else {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
      }
    }
    return dp[nums.size() - 1];
  }
};

class Solution2 {
  int rob(vector<int>& nums) {
    int dp1 = 0;
    int dp2 = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0) dp2 = nums[0];
      else if (i == 1) {
        dp1 = dp2;
        dp2 = max(dp2, nums[1]);
      }
      else {
        int tmp = dp2;
        dp2 = max(dp1 + nums[i], dp2);
        dp1 = tmp;
      }
      
    }
    return dp2;
  }
};

// Wrong answer, because robber can skip two houses, but not odd or even house.
class Solution3 {
public:
  int rob(vector<int>& nums) {
    int maxOdd = 0, maxEven = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i & 0x1) maxEven += nums[i];
      else maxOdd += nums[i];
    }
    return max(maxOdd, maxEven);
  }
};
