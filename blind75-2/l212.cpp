// 212. Word Search II

class TrieNode {
public:
  int wordId = -1;
  unordered_map<char, TrieNode*> children;
};

class Trie {
public:
  TrieNode* root;
  Trie() {
    root = new TrieNode();
  }
  void addWord(string word, int wordId) {
    TrieNode* tmp = root;
    for (auto c : word) {
      if (tmp->children.count(c) == 0)
        tmp->children[c] = new TrieNode();
      tmp = tmp->children[c];
    }
    tmp->wordId = wordId;
  }
};

void dfs(vector<vector<char>>& board, vector<string>& words, int i, int j, TrieNode* tn, vector<vector<bool>>& visited, vector<string>& result) {
  if (visited[i][j]) return;
  else if ((tn->children).count(board[i][j]) == 0) return;
  else if ((tn->children[board[i][j]])->wordId >= 0) {
    result.push_back(words[(tn->children[board[i][j]])->wordId]);
    (tn->children[board[i][j]])->wordId = -1; // return only one in the result
  }

  visited[i][j] = true;
  if (i > 0) dfs(board, words, i - 1, j, (tn->children)[board[i][j]], visited, result);
  if (i < board.size() - 1) dfs(board, words, i + 1, j, (tn->children)[board[i][j]], visited, result);
  if (j > 0) dfs(board, words, i, j - 1, (tn->children)[board[i][j]], visited, result);
  if (j < board[i].size() - 1) dfs(board, words, i, j + 1, (tn->children)[board[i][j]], visited, result);
  visited[i][j] = false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
  vector<string> result;
  Trie t;
  for (int i = 0; i < words.size(); ++i)
    t.addWord(words[i], i);
  vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
  for (int i = 0; i < board.size(); ++i)
    for (int j = 0; j < board[i].size(); ++j)
      dfs(board, words, i, j, t.root, visited, result);
  return result;
}
