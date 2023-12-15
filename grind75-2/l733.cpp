// 733. Flood Fill

#include <iostream>
#include <vector>
using namespace std;

// dfs, O(mn);O(1)
void dfs(vector<vector<int>>& image, int sr, int sc, int color) {
  if (image[sr][sc] == color) return;
  int origColor = image[sr][sc];
  image[sr][sc] = color;
  if (sr > 0 && image[sr - 1][sc] == origColor)
    dfs(image, sr - 1, sc, color);
  if (sr < image.size() - 1 && image[sr + 1][sc] == origColor)
    dfs(image, sr + 1, sc, color);
  if (sc > 0 && image[sr][sc - 1] == origColor)
    dfs(image, sr, sc - 1, color);
  if (sc < image[sr].size() - 1 && image[sr][sc + 1] == origColor)
    dfs(image, sr, sc + 1, color);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
  vector<vector<int>> result;
  for (auto v : image)
    result.push_back(v);
  dfs(result, sr, sc, color);
  return result;
}

int main() {
  vector<vector<int>> image = {
//    {1,1,1},{1,1,0},{1,0,1}
    {0,0,0},{0,0,0}
  };
  auto r = floodFill(image, 0, 0, 0);

  for (auto v : r) {
    for (auto i : v)
      cout << i << " ";
    cout << endl;
  }
}
