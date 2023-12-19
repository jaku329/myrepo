// 53. Maximum Subarray

// 1. brute force: O(n^2);O(1)

// 2. DP
int maxSubArray(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  else if (nums.size() == 1) return nums[0];

  int maxSum;
  vector<int> dp(nums.size(), 0)
  dp[0] = nums[0];
  maxSum = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    dp[i] = max(nums[i], dp[i - 1] + num[i]);
    maxSum = max(maxSum, dp[i]);
  }
  return maxSum;
}

// 3. DP optimal
int maxSubArray(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  else if (nums.size() == 1) return nums[0];

  int preSum = nums[0];
  int maxSum = preSum;
  for (int i = 1; i < nums.size(); ++i) {
    preSum = max(preSum + nums[i], nums[i]);
    maxSum = max(maxSum, preSum);
  }
  return maxSum;
}
