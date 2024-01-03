// 152. Maximum Product Subarray

// 1. brute force: O()

// 2. DP: O(n);O(n)
int maxProduct(vector<int>& nums) {
  int product = nums[0];
  vector<int> maxDp(nums.size(), 0);
  vector<int> minDp(nums.size(), 0);
  maxDp[0] = nums[0];
  minDp[0] = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    maxDp[i] = max(nums[i], max(maxDp[i - 1] * nums[i], minDp[i - 1] * nums[i]));
    minDp[i] = min(nums[i], min(minDp[i - 1] * nums[i], maxDp[i - 1] * nums[i]));
    product = max(product, maxDp[i]);
  }
  return product;
}

// 3. DP + optimal: O(n);O(1)
int maxProduct(vector<int>& nums) {
  int product = nums[0];
  int maxP = nums[0];
  int minP = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    int tmp1 = maxP * nums[i];
    int tmp2 = minP * nums[i];
    maxP = max(nums[i], max(tmp1, tmp2));
    minP = min(nums[i], min(tmp1, tmp2));
    product = max(product, maxP);
  }
  return product;
}

// 4. DP optimizing
int maxProduct(vector<int>& nums) {
  int product = nums[0];
  int maxP = nums[0];
  int minP = nums[0];
  for (int i = 1; i < nums.size(); ++i) {
    int tmp1 = maxP * nums[i];
    int tmp2 = minP * nums[i];
    if (tmp1 > tmp2) {
      maxP = max(nums[i], tmp1);
      minP = min(nums[i], tmp2);
    }
    else {
      maxP = max(nums[i], tmp2);
      minP = min(nums[i], tmp1);
    }
    product = max(product, maxP);
  }
  return product;
}
