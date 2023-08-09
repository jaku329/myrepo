#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    int m, pivot = -1;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (nums[m] == target) return m;
      else if (m + 1 < nums.size() &&  nums[m + 1] < nums[m]) {
        pivot = m + 1;
        break;
      }
      else if (m > 0 && nums[m - 1] > nums[m]) {
        pivot = m;
        break;
      }
      else if (nums[m] > nums[l]) {
        l = m + 1;
      } 
      else if (nums[m] <= nums[l]) {
        r = m - 1;
      }
    }
    cout << pivot << endl;

    if (pivot < 0) {
      l = 0;
      r = nums.size() - 1;
    }
    else if (target >= nums[0]) {
      l = 0;
      r = pivot - 1;
    }
    else {
      l = pivot;
      r = nums.size() - 1;
    }
    cout << l << ", " << r << endl;
    while (l <= r) {
      m = l + (r - l) / 2;
      if (nums[m] == target) return m;
      else if (nums[m] > target) r = m - 1;
      else l = m + 1;
    }
    return -1;
  }
};

int main() {
  vector<int> nums = {3, 5, 1};//{4,5,6,7,0,1,2};
  Solution s;
  cout << s.search(nums, 3) << endl;
  return 0;
}
