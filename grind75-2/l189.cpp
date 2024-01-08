// 189. Rotate Array

void rotate(vector<int>& nums, int k) {
  if (nums.size() <= 1) return ;
  int start = 0;
  int n = nums.size();
  int tmp = nums[start];
  int i = start;
  while (n-- > 0) {
    i = (i + k) % nums.size();
    if (i == start) {
      nums[i] = tmp;
      start = (start + 1) % nums.size();
      tmp = nums[start];
      i = start;
    }
    else
      swap(tmp, nums[i]);
  }
}

// [-1,-100,3,99]
// -1,-100,-1,99 3
// 3,-100,-1,99 -1
