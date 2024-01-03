// 198. House Robber

// DP + optimize: O(n);O(1)
int rob(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int prev = 0;
  int cur = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    prev = max(cur, prev + nums[i]);
    swap(prev, cur);
  }
  return cur;
}
