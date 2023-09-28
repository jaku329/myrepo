// https://leetcode.com/problems/flood-fill/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int sColor = image[sr][sc];
    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        pair<int, int> rc= q.front();
        int r = rc.first;
        int c = rc.second;
        q.pop();
        image[r][c] = color;
        if (r > 0 && image[r - 1][c] == sColor) q.push({r - 1, c});
        if (c > 0 && image[r][c - 1] == sColor) q.push({r, c - 1});
        if (r < image.size() - 1 && image[r + 1][c] == sColor) q.push({r + 1, c});
        if (c < image[r].size() - 1 && image[r][c + 1] == sColor) q.push({r, c + 1});
      }
    }
    return image;
  }
};

class Solution2 {
public:
  void dfs(vector<vector<int>>& image, int sr, int sc, int color, int sColor) {
    if (image[sr][sc] != sColor) return;
    image[sr][sc] = color;
    if (sr > 0) dfs(image, sr - 1, sc, color, sColor);
    if (sc > 0) dfs(image, sr, sc - 1, color, sColor);
    if (sr < image.size() - 1) dfs(image, sr + 1, sc, color, sColor);
    if (sc < image[sr].size() - 1) dfs(image, sr, sc + 1, color, sColor);
  }
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    dfs(image, sr, sc, color, image[sr][sc]);
    return image;
  }
};

int main() {
  vector<vector<int>> image = {
    {1,1,1},
    {1,1,0},
    {1,0,1}
  };
  Solution2 s;
  vector<vector<int>> res = s.floodFill(image,1,1,2);

  for (auto it = res.begin(); it != res.end(); it++) {
    for (auto it2 = it->begin(); it2 != it->end(); it2++)
      cout << *it2 << " ";
    cout << endl;
  }
  return 0;
}
