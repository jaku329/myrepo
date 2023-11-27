// https://leetcode.com/problems/maximum-product-subarray/

int maxProduct(vector<int>& nums) {
  vector<int> dpMax(nums.size(), 0);
  vector<int> dpMin(nums.size(), 0);

  if (nums.size() == 1) return nums[0];

  dpMax[0] = nums[0];
  dpMin[0] = nums[0];

  int product = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    dpMax[i] = max(nums[i], max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
    dpMin[i] = min(nums[i], min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]));
    product = max(product, dpMax[i]);
  }
  return product;
}
