// 136. Single Number

int singleNumber(vector<int>& nums) {
  int single = nums[0];
  for (int i = 1; i < nums.size(); ++i)
    single ^= nums[i];
  return single;
}
