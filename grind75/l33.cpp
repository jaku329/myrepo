// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) return m;
      else if (nums[r] > nums[l]) { // supposed the nums are distinct, so no need '='
        if (nums[m] > target) r = m - 1;
        else if (nums[m] < target) l = m + 1;
      }
      else { // else if (nums[r] < nums[l])
        if (nums[m] > target) {
          if (target > nums[l])
              r = m - 1;
          else
              l = m + 1;
        }
        else {
          if (nums[m] > nums[l]) 
            l = m + 1;
          else 
            r = m - 1;
        }
      }
    }
    return -1;
  }
};
