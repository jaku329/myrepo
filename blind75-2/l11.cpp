// 11. Container With Most Water

int maxArea(vector<int>& height) {
  int l = 0, r = height.size() - 1;
  int area = 0;
  while (l < r) {
    area = max(area, min(height[l], height[r]) * (r - l));
    if (height[l] < height[r]) l++;
    else r--;
  }
  return area;
}
