// 15. 3Sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// sort + two pointers
vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> result;
  for (int i = 0; i < nums.size() - 2; ++i) {
    if (i > 0 && nums[i] == nums[i - 1]) continue;
    int l = i + 1;
    int r = nums.size() - 1;
    while (l < r) {
  cout << l << ", " << r << endl;
      if (l - 1 > i && nums[l] == nums[l - 1]) {
        l++;
        continue;
      }
      if (nums[i] + nums[l] + nums[r] == 0) {
        vector<int> sol({nums[i], nums[l], nums[r]});
        result.push_back(sol);
        l++;
        r--;
      }
      else if (nums[i] + nums[l] + nums[r] > 0)
        r--;
      else
        l++;
    }
  }
  return result;
}

int main() {
  vector<int> nums = {
    -1,0,1,2,-1,-4
  };
  threeSum(nums);
  return 0;
}
