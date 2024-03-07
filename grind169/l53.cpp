// 53. Maximum Subarray

// 1. brute force: O(n^2):O(1)

// 2. DP: O(n):O(n)

// 3. DP+optimal: O(n):O(1)
int maxSubArray(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  else (nums.size() == 1) return nums[0];
  int dp = nums[0];
  int maxSum = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    dp = max(dp + nums[i], nums[i]);
    maxSum = max(maxSum, dp);
  }
  return maxSum;
}
