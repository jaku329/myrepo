// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> lProduct(nums.size(), nums[0]);
    vector<int> rProduct(nums.size(), nums[nums.size() - 1]);

    for (int i = 2; i < nums.size(); ++i) {
      lProduct[i] = lProduct[i - 1] * nums[i - 1];
    }
  
    for (int i = rProduct.size() - 3; i >= 0; --i) {
      rProduct[i] = rProduct[i + 1] * nums[i + 1];
    }

    lProduct[0] = rProduct[0];
    for (int i = 1; i < lProduct.size() - 1; ++i)
      lProduct[i] *= rProduct[i];

    return lProduct;
  }
};

