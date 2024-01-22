// 55. Jump Game

// 1. dfs+memorize: O(n);O(n)

// 2. recursive: O(n);O(1)
bool canJump(vector<int>& nums, int end) {
  if (end == 0) return true;
  int i = end - 1;
  while (i >= 0)
    if (i + nums[i] >= end)
      return canJump(nums, i);
    else
      i--;
  return false;
}

bool canJump(vector<int>& nums) {
  return canJump(nums, nums.size() - 1);
}
