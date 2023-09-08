// https://leetcode.com/problems/missing-number

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int tmp1 = nums.size();
    int tmp2 = 0;
    for (int i = 0; i < nums.size(); ++i) {
      tmp1 ^= i;
      tmp2 ^= nums[i];
    }
    return tmp1 ^= tmp2;
  }
};

int main() {
  vector<int> nums = {0,3,5,8,4,6,1,9,7};
  Solution s;
  cout << s.missingNumber(nums);

  for (auto it = nums.begin(); it != nums.end(); ++it) cout << *it << " "; cout << endl;
  return 0;
}
