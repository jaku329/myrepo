// 79. Word Search

bool dfs(vector<vector<char>>& board, string word, int i, int j, int w, vector<vector<bool>>& visited) {
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
    return false;
  else if (w >= word.size())
    return false;
  else if (visited[i][j])
    return false;
  else if (board[i][j] != word[w])
    return false;

  if (w >= word.size() - 1)
    return true;

  visited[i][j] = true;
  if (dfs(board, word, i + 1, j, w + 1, visited))
    return true;
  if (dfs(board, word, i - 1, j, w + 1, visited))
    return true;
  if (dfs(board, word, i, j + 1, w + 1, visited))
    return true;
  if (dfs(board, word, i, j - 1, w + 1, visited))
    return true;
  visited[i][j] = false;
  return false;
}
bool exist(vector<vector<char>>& board, string word) {
  vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
  for (int i = 0; i < board.size(); ++i)
    for (int j = 0; j < board[i].size(); ++j)
      if (dfs(board, word, i, j, 0, visited))
        return true;
  return false;
}
