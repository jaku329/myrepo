// 238. Product of Array Except Self

// O(n);O(n)
vector<int> productExeptSelf(vector<int>& nums) {
  vector<int> lToR(nums.size(), 0);
  vector<int> rToL(nums.size(), 0);
  vector<int> result(nums.size(), 0);

  lToR[0] = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    lToR[i] = nums[i] * lToR[i - 1];
  }
  rToL[nums.size() - 1] = nums[nums.size() - 1];
  for (int i = nums.size() - 2; i >= 0; --i) {
    rToL[i] = nums[i] * rToL[i + 1];
  }
  result[0] = rToL[1];
  result[nums.size() - 1] = lToR[nums.size() - 2];
  for (int i = 1; i < nums.size() - 1; ++i) {
    result[i] = lToR[i - 1] * rToL[i + 1];
  }
  return result;
}
