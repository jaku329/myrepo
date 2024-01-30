// 977. Squares of a Sorted Array

// 1. BS to find the min value near to zero. O(log(n)) 2. two pointer to extend the sqaure; O(n):O(n)
vector<int> sortedSquares(vector<int>& nums) {
  vector<int> result;
  if (nums.size() == 0) return result;
  int l = 0, r = nums.size() - 1;
  int m = 0;
  while (l < r) {
    int m = l + ((r - l) >> 1);
    if (nums[m] == 0) { 
      l = m;
      r = m;
    }
    else if (nums[m] < 0)
      l = m + 1;
    else
      r = m;
  }

  if (nums[r] >= 0)
    l = r - 1; // nums[r - 1] is negative

  while (l >= 0 && r < nums.size()) {
    if (abs(nums[l]) < abs(nums[r]))
      result.push_back(nums[l] * nums[l--]);
    else
      result.push_back(nums[r] * nums[r++]);
  }
  while (l >= 0)
    result.push_back(nums[l] * nums[l--]);
  while (r < nums.size())
    result.push_back(nums[r] * nums[r++]);
  return result;
}
