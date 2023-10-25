// https://leetcode.com/problems/3sum/

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i - 1] == nums[i])
        continue;
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        if (nums[i] + nums[l] + nums[r] == 0) {
          vector<int> v = {nums[i], nums[l], nums[r]};
          result.push_back(v);
          while (l < r && nums[l] == nums[l + 1]) l++;
          while (l < r && nums[r] == nums[r - 1]) r--;
        }
        else if (nums[i] + nums[l] + nums[r] > 0)
          r--;
        else
          l++;
      }
    }
    return result;
  }
};
