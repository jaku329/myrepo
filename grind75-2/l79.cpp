// 79. Word Search

// dfs
bool dfs(vector<vector<char>>& board, int i, int j, string word, int pos, vector<vector<bool>>& visited) {
  if (pos >= word.size()) return true;
  else if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) return false;
  else if (visited[i][j]) return false;
  else if (board[i][j] != word[pos]) return false;

  visited[i][j] = true;
  if (dfs(board, i + 1, j, word, pos + 1, visited)) return true;
  if (dfs(board, i - 1, j, word, pos + 1, visited)) return true;
  if (dfs(board, i, j + 1, word, pos + 1, visited)) return true;
  if (dfs(board, i, j - 1, word, pos + 1, visited)) return true;
  visited[i][j] = false;
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
  for (int i = 0; i < board.size(); ++i)
    for (int j = 0; j < board[i].size(); ++j)
      if (dfs(board, i, j, word, 0, visited))
        return true;
  return false;
}
