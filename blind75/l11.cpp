/* 
  Container With Most Water
  https://leetcode.com/problems/container-with-most-water
*/
#include<iostream>
#include<vector>
#include<stack>
//#include<math>
using namespace std;

// brute force
class Solution {
public:
  int maxArea(vector<int>& height) {
    int max = 0;
    if (height.size() == 0) return 0;
    for (int i = 1; i < height.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        int lower = height[j] < height[i] ? height[j] : height[i];
        max = max > (lower * (i - j)) ? max : (lower * (i - j));
      }
    }
    return max;
  }
};

// enhance brute force
class Solution2 {
public:
  int maxArea(vector<int>& height) {
    vector<int> s;
    int max = 0;
    if (height.size() == 0) return 0;
    s.push_back(0);
    for (int i = 1; i < height.size(); ++i) {
      for (int j = 0; j < s.size(); ++j) {
        int lower = height[s[j]] < height[i] ? height[s[j]] : height[i];
        max = max > (lower * (i - s[j])) ? max : (lower * (i - s[j]));
      }
      if (height[s.size() - 1] < height[i]) {
        s.push_back(i);
      }
    }
    return max;
  }
};

// greedy + two pointer
class Solution3 {
public:
  int maxArea(vector<int>& height) {
    int area = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
      area = max(area, min(height[l], height[r]) * (r - l));
      if (height[l] < height[r])
        l++;
      else
        r--;
    }
    return area;
  }
};

int main() {
  vector<int> h = {1,8,6,2,5,4,8,3,7};
  Solution s;
  Solution3 s3;
//  cout << s.maxArea(h) << endl;
  cout << s3.maxArea(h) << endl;
  return 0;
}
