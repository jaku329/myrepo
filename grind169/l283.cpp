// 283. Move Zeroes

void moveZeros(vector<int>& nums) {
  int i = 0, j = -1;
  while (i < nums.size()) {
    if (nums[i] != 0)
      swap(nums[i], nums[++j]);
    i++;
  }
}
