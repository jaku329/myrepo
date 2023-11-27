// https://leetcode.com/problems/next-permutation/

#include <iostream>
#include <vector>

using namespace std;

// NG
void nextPermutation(vector<int>& nums) {
  if (nums.size() <= 1) return;
  int reversedMax;
  if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
    swap(nums[nums.size() - 1], nums[nums.size() - 2]);
    return;
  }
  reversedMax = nums.size() - 2;
  while (reversedMax > 0) {
    if (nums[reversedMax - 1] >= nums[reversedMax]) reversedMax--;
    else break;
  }

  int l, r;
  if (reversedMax == 0) {
    l = 0;
    r = nums.size() - 1;
  }
  else {
    int swapped = nums.size() - 1;
    while (nums[swapped] <= nums[reversedMax - 1]) {
      swapped--;
    }
    swap(nums[swapped], nums[reversedMax - 1]);
    l = reversedMax;
    r = nums.size() - 1;
  }

  while (l < r) {
      swap(nums[l], nums[r]);
      l++;
      r--;
  }
}

int main() {
  vector<int> nums = {1,5,1};
  nextPermutation(nums);

  for (auto n : nums)
    cout << n << " ";
  cout << endl;
  return 0;
}
