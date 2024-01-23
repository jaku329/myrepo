// 213. House Robber II

int rob(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  else if (nums.size() == 1) return nums[0];
  else if (nums.size() == 2) return max(nums[0], nums[1]);

  int pp = 0;
  int p = nums[0];
  for (int i = 1; i < nums.size() - 1; ++i) {
    pp = max(pp + nums[i], p);
    swap(pp, p);
  }
  int maxAmount = max(pp, p);
  pp = 0;
  p = nums[1];
  for (int i = 2; i < nums.size(); ++i) {
    pp = max(pp + nums[i], p);
    swap(pp, p);
  }
  maxAmount = max(maxAmount, max(pp, p));
  return maxAmount;
}
