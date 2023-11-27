// https://leetcode.com/problems/house-robber/

class Solution {
public:
  int rob(vector<int>& nums) {
    int prev = 0, pprev = 0, maxAmount = 0;

    if (nums.size() == 0) return 0;

    for (int i = 0; i < nums.size(); ++i) {
      pprev = max(pprev + nums[i], prev);
      maxAmount = max(maxAmount, pprev);
      swap(pprev, prev);
    }
    return maxAmount;
  }
};
