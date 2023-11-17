// https://leetcode.com/problems/word-search/

class Solution {
public:
  bool dfs(vector<vector<char>>& board, string word, int pos, int i, int j, vector<vector<bool>>& visited) {
    if (visited[i][j]) return false;
    else if (board[i][j] != word[pos]) return false;
    else if (pos == word.size() - 1) return true;

    visited[i][j] = true;
    if (i > 0)
      if (dfs(board, word, pos + 1, i - 1, j, visited)) return true;
    if (i < board.size() - 1)
      if (dfs(board, word, pos + 1, i + 1, j, visited)) return true;
    if (j > 0)
      if (dfs(board, word, pos + 1, i, j - 1, visited)) return true;
    if (j < board[i].size() - 1)
      if (dfs(board, word, pos + 1, i, j + 1, visited)) return true;
    visited[i][j] = false;

    return false;
  }
  
  bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[i].size(); ++j)
        if (board[i][j] == word[0])
          if (dfs(board, word, 0, i, j, visited))
            return true;
    return false;
  }
};
