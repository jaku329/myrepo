// 268. Missing Number

int missingNumber(vector<int>& nums) {
  long sum = ((1 + nums.size()) * nums.size()) >> 1;
  for (auto num : nums)
    sum -= num;
  return (int)sum;
}

int missingNumber(vector<int>& nums) {
  int missing = nums[0] ^ 0;
  for (int i = 1; i < nums.size(); ++i)
    missing ^= nums[i] ^ i;
  missing ^= nums.size();
  return missing;
}
