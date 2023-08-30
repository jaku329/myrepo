// https://leetcode.com/problems/maximum-product-subarray/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// TODO: space complexity can be reduced.
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    vector<int> dpP(nums.size(), -1);
    vector<int> dpN(nums.size(), 0);
    int product = INT_MIN;

    product = nums[0];
    if (nums[0] < 0)
      dpN[0] = nums[0]; // 0 -14 -4
    else
      dpP[0] = nums[0]; // 7 -1 56

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < 0) {
        if (dpP[i - 1] >= 0) {
          dpN[i] = min(nums[i], dpP[i - 1] * nums[i]);
        }
        else
          dpN[i] = nums[i];

        if (dpN[i - 1] < 0)
          dpP[i] = dpN[i - 1] * nums[i];
      }
      else {
        if (dpP[i - 1] < 0)
          dpP[i] = nums[i];
        else 
          dpP[i] = max(nums[i], dpP[i - 1] * nums[i]);
   
        if (dpN[i - 1] < 0)
          dpN[i] = dpN[i - 1] * nums[i];
      }

      if (dpP[i] < 0)
        product = max(product, dpN[i]);
      else
        product = max(product, dpP[i]);
    }

    for (auto it = dpP.begin(); it != dpP.end(); it++)
      cout << *it << " ";
    cout << endl;
    for (auto it = dpN.begin(); it != dpN.end(); it++)
      cout << *it << " ";
    cout << endl;
    return product;
  }
};

int main() {
  vector<int> nums = {7, -2, -4};
  Solution s;

  cout << s.maxProduct(nums);
  return 0;
}
