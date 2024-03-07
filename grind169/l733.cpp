// 733. Flood Fill

void dfs(vector<vector<int>>& image, int sr, int sc, int oriColor, int color) {
  if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[sr].size()) return;
  else if (image[sr][sc] == color || image[sr][sc] != oriColor) return;

  image[sr][sc] = color;
  dfs(image, sr - 1, sc, oriColor, color);
  dfs(image, sr + 1, sc, oriColor, color);
  dfs(image, sr, sc - 1, oriColor, color);
  dfs(image, sr, sc + 1, oriColor, color);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
  vector<vector<int>> result;
  for (auto row : image)
    result.push_back(row);
  dfs(result, sr, sc, result[sr][sc], color);
  return result;
}
