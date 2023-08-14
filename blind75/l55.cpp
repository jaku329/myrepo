/*
  https://leetcode.com/problems/jump-game
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS: time limit exceeded
class Solution {
public:
  bool dfs(vector<int>& nums, int pos, vector<bool>& visited) {
    if (pos >= nums.size() - 1) return true;
//    if (visited[pos]) return false; 
    visited[pos] = true;
    if (nums[pos] == 0) return false;
    
    for (int i = pos + 1; i < nums.size() && i <= pos + nums[pos]; ++i) {
      if (i == nums.size() - 1) return true;
      if (visited[i]) continue;
      if(dfs(nums, i, visited)) return true;
    }

    return false;
  }

  bool dfs(vector<int>& nums, int pos) {
    if (pos >= nums.size() - 1) return true;
    if (nums[pos] == 0) return false;

    for (int i = pos + 1; i < nums.size() && i <= pos + nums[pos]; ++i) {
      if (i == nums.size() - 1) return true;
      if(dfs(nums, i)) return true;
    }

    return false;
  }
  bool canJump(vector<int>& nums) {
    vector<bool> visited(nums.size(), false);
    return dfs(nums, 0, visited);
  }
};

// dp 
class Solution2 {
public:
//  bool dfs(vector<int>&)
  bool canJump(vector<int>& nums) {
    int max;
    if (nums.size() == 0) return false;
    if (nums.size() == 1) return true;

    max = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (max < i) return false;
      max = max > nums[i] + i ? max : nums[i] + i;
    }
    if (max >= nums[nums.size() - 1]) return true;
    return true;
  }
};

int main() {
  vector<int> nums = {2,3,1,1,4};
  Solution2 s;
  cout << s.canJump(nums) << endl;
  return 0;
}
