// https://leetcode.com/problems/word-search

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j, int pos) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) return false;
    if (visited[i][j]) return false;
    if (board[i][j] != word[pos]) return false;
    else if (pos == word.size() - 1) return true;

    visited[i][j] = true;
    if (dfs(board, word, visited, i - 1, j, pos + 1)) return true;
    if (dfs(board, word, visited, i + 1, j, pos + 1)) return true;
    if (dfs(board, word, visited, i, j - 1, pos + 1)) return true;
    if (dfs(board, word, visited, i, j + 1, pos + 1)) return true;
    visited[i][j] = false;

    return false;
  }
  bool exist(vector<vector<char>>& board, string word) {
    bool found;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[i].size(); ++j) {
        if (dfs(board, word, visited, i, j, 0)) return true;
      }
    return false;
  }
};

int main() {
  vector<vector<char>> board = {
    {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}
  };
  Solution s;

  cout << s.exist(board, "SEE") << endl;
  return 0;
}
