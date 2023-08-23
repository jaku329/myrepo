#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    vector<int> sum;
    sum.push_back(nums[0]);
    int max = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (sum[sum.size() - 1] < 0) {
        sum.push_back(nums[i]);
      }
      else {
        sum.push_back(sum[sum.size() - 1] + nums[i]);
      }
      max = max > sum[sum.size() - 1] ? max : sum[sum.size() - 1];
    }
    return max;
  }
};

class Solution2 {
  int maxSubArray(vector<int>& nums) {
    int prevSum = nums[0];
    int max = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (prevSum <= 0) prevSum = nums[i];
      else prevSum += nums[i];
      max = max > prevSum ? max : prevSum;
    }
    return max;
  }
}

int main() {
  return 0;
}
