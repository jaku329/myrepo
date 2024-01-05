// 211. Design Add and Search Words Data Structure

class TrieNode {
public:
  unordered_map<char, TrieNode*> children;
  bool isWord = false;
};

class WordDictionary {
private:
  TrieNode* root;
public:
  WordDictionary() {
    root = new TrieNode();
  }

  void addWord(string word) {
    TrieNode* tmp = root;
    for (auto c : word) {
      if (tmp->children.count(c) == 0)
        tmp->children[c] = new TrieNode();
      tmp = tmp->children[c];
    }
    tmp->isWord = true;
  }

  bool search(string& word, int pos, TrieNode* node) {
    if (pos == word.size())
      return node->isWord;
 
    if (word[pos] == '.') {
      for (auto it = node->children.begin(); it != node->children.end(); ++it) {
        if (search(word, pos + 1, it->second)) return true;
      }
      return false;
    }
    else if (node->children.count(word[pos]) == 0)
      return false;
    return search(word, pos + 1, node->children[word[pos]]);
  }

  bool search(string word) {
    return search(word, 0, root);
  }
};
