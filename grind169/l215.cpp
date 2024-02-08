// 215. Kth Largest Element in an Array

#include <iostream>
#include <vector>
using namespace std;

// quicksort: TLE
int partition(vector<int>& nums, int l, int r) {
  if (l > r) return -1;
  else if (l == r) return r;
  
  int i = l, j = l - 1;
  // use r as the pivot
  while (i < r) {
    if (nums[i] < nums[r])
      swap(nums[++j], nums[i]);
    i++;
  }
  swap(nums[++j], nums[r]);
  cout << "[debug]" << j << endl;
  return j;
}

int findKthLargest(vector<int>& nums, int l, int r, int k) {
  if (l > r) return -1;

  int pivot = partition(nums, l, r);
  if (pivot == nums.size() - k)
    return pivot;
  else if (pivot > nums.size() - k)
    return findKthLargest(nums, l, pivot - 1, k);
  return findKthLargest(nums, pivot + 1, r, k);
}

int findKthLargest(vector<int>& nums, int k) {
  return nums[findKthLargest(nums, 0, nums.size() - 1, k)];
}

int main() {
  vector<int> nums = {
    3,2,1,5,6,4

  };
  int k = 2;

  cout << findKthLargest(nums, k) << endl << endl;;
  
  for (auto n : nums)
    cout << n << " ";
  cout << endl << endl;

  return 0;
}
