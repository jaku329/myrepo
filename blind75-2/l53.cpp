// 53. Maximum Subarray

int maxSubArray(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int prev = nums[0];
  int sum = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    prev = max(prev + nums[i], nums[i]);
    sum = max(sum, prev);
  }
  return sum;
}
