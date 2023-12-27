// 75. Sort Colors

#include <vector>
#include <iostream>
using namespace std;

// 1. sort: O(nlog(n)):O(1)

// 2. two pinters: O(n)
void sortColors(vector<int>& nums) {
  int i0 = -1;
  int i2 = nums.size();
  int i = 0;
  while (i < i2) {
    if (i == i0)
      i++;
    else if (nums[i] == 2) {
      i2--;
      swap(nums[i], nums[i2]);
    }
    else if (nums[i] == 0) {
      i0++;
      swap(nums[i], nums[i0]);
    }
    else
      i++;
  }
}

int main() {
  vector<int> nums = {
    2,0,2,1,1,0
  };
  sortColors(nums);
  return 0;
}
