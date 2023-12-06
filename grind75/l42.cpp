// https://leetcode.com/problems/trapping-rain-water/

int trap(vector<int>& height) {
  stack<int> st;
  int r = 0;
  int area = 0;
  while (r < height.size()) {
    if (height[r] > 0) {
      if (st.empty())
        st.push(r);
      else {
        if (height[r] < height[st.top()]) {
          area += height[r] * (r - st.top() - 1);
          st.push(r);
        }
        else {
          int h = height[st.top()];
          area += height[st.top()] * (r - st.top() - 1);
          st.pop();
          while (!st.empty()) {
            if (height[st.top()] > height[r]) {
              area += (height[r] - h) * (r - st.top() - 1);
              break;
            }
            else {
              area += (height[st.top()] - h) * (r - st.top() - 1);
              h = height[st.top()];
              st.pop();
            }
          }
          st.push(r);
        }
      }
    }
    r++;
  }

  return area;
}
