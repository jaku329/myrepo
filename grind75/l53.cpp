// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int prev = nums[0];
    int max = prev;
    for (int i = 1; i < nums.size(); ++i) {
      if (prev <= 0) prev = nums[i];
      else prev += nums[i];
      max = prev > max ? prev : max; 
    }
    return max;
  }
};
