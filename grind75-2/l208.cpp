// 208. Implement Trie (Prefix Tree)

#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode*> children;
  bool isWord = false;
};

class Trie {
private:
  TrieNode* root;
public:
  Trie() {
    root = new TrieNode();
  }

  void insert(string word) {
    TrieNode* tmp = root;
    for (auto c : word) {
      if (tmp->children.count(c) == 0)
        tmp->children[c] = new TrieNode();
      tmp = tmp->children[c];
    }
    tmp->isWord = true;
  }

  bool search(string word, int i, TrieNode* root) {
    if (i == word.size() && root->isWord)
      return true;

    if (root->children.count(word[i]) == 0)
      return false;
    return search(word, i + 1, root->children[word[i]]);
  }

  bool search(string word) {
    return search(word, 0, root);
  }

  bool startsWith(string prefix) {
    TrieNode* tmp = root;
    for (auto c : prefix) {
      if (tmp->children.count(c) == 0)
        return false;
      tmp = tmp->children[c];
    }
    return true;
  }
};

int main() {
  Trie t;
  t.
}
