// 33. Search in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

// 4,5,6,7,0,1,2 // t:0
// 4,5,6,7,8,1,2,3 // t:8
int search(vector<int>& nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l <= r) {
    cout << l << ", " << r << endl;
    int m = l + ((r - l) >> 1);
    if (nums[m] == target)
      return m;
    else if (nums[m] > target) {
      if (nums[l] <= target)
        r = m - 1;
      else if (nums[l] > nums[m]) // including nums[l] > target
        r = m - 1;
      else
        l = m + 1;
    }
    else { // nums[m] < target
      if (nums[r] >= target) 
        l = m + 1;
      else if (nums[r] < nums[m])
        l = m + 1;
      else
        r = m - 1;
    }
  }
  return -1; 
}

int main() {
  vector<int> nums = {
//    4,5,6,7,0,1,2
    4,5,6,7,8,1,2,3
  };
  cout << search(nums, 8) << endl;

  return 0;
}
