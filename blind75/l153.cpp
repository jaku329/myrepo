// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < nums[l]) r = m;
      else if (m < nums.size() - 1 && nums[m] <= nums[m + 1]) l = m + 1;
      else r = m;
    }
    if (l >= nums.size() - 1) return nums[0];
    return nums[l + 1];
  }
};

int main() {
  vector<int> nums = {3,1,2};
  Solution s;
  cout << s.findMin(nums) << endl;
  return 0;
}
