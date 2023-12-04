// https://leetcode.com/problems/rotate-array/

// time limit exceeded
void rotate(vector<int>& nums, int k) {
  if (nums.size() <= 1 || k == 0) return;
  k %= nums.size();
  while (k-- > 0) {
    swap(nums[0], nums[nums.size() - 1]);
    int i = nums.size() - 1;
    while (i > 1) {
      swap(nums[i], nums[i - 1]);
      i--;
    }
  }
}

void reverse(vector<int>& nums, int l, int r) {
  while (l < r) {
    swap(nums[l], nums[r]);
    l++;
    r--;
  }
}

void rotate(vector<int>& nums, int k) {
  k %= nums.size();
  if (k == 0) return;
  reverse(nums, 0, nums.size() - 1);
  reverse(nums, 0, k - 1);
  reverse(nums, k, nums.size() - 1);
}
