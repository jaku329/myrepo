// https://leetcode.com/problems/longest-consecutive-sequence

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    vector<bool> visited(nums.size(), false);
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      m[nums[i]] = i;
    }

    int ret = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i]) continue;
     
      int consecutive = 1;
      int num = nums[i];
      while (m.count(num + 1) > 0) {
        num++;
        consecutive++;
        visited[m[num]] = true;
      }
      num = nums[i];
      while (m.count(num - 1) > 0) {
        num--;
        consecutive++;
        visited[m[num]] = true;
      }

      ret = ret > consecutive ? ret : consecutive;
    }
    return ret;
  }
};
