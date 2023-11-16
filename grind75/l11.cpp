// https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
  int maxArea(vector<int>& height) {
    int area = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
      area = max(area, (r - l) * min(height[l], height[r]));
      if (height[l] > height[r]) r--;
      else l++;
    }
    return area;
  }
};
