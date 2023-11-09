// https://leetcode.com/problems/word-break/description/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// backtrack + hashmap
class Solution {
public:
  bool backtrack(string s, unordered_map<int, unordered_set<string>>& umap, vector<int>& lens, int pos) {
    if (pos == s.size()) return true;
    else if (pos > s.size()) return false;

    for (int i = 0; i < lens.size(); ++i) {
      if (i > 0 && lens[i - 1] == lens[i]) continue;

      if ((pos + lens[i] <= s.size()) && umap[lens[i]].count(s.substr(pos, lens[i])) > 0)
        if (backtrack(s, umap, lens, pos + lens[i])) return true;
    }

    return false;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<int, unordered_set<string>> umap;
    vector<int> lens;
    for (int i = 0; i < wordDict.size(); ++i) {
      lens.push_back(wordDict[i].size());
      if (umap.count(wordDict[i].size())) {
        umap[wordDict[i].size()].insert(wordDict[i]);
      }
      else {
        unordered_set<string> uset;
        uset.insert(wordDict[i]);
        umap[wordDict[i].size()] = uset;
      }
    }
    sort(lens.begin(), lens.end(), greater<int>());
    
    return backtrack(s, umap, lens, 0);
  }
};

// DP + hashmap (using last word as key)
class Solution2 {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<char, vector<string>> umap;
    for (int i = 0; i < wordDict.size(); ++i) {
      if (umap.count(wordDict[i][wordDict[i].size() - 1]))
        umap[wordDict[i][wordDict[i].size() - 1]].push_back(wordDict[i]);
      else
        umap[wordDict[i][wordDict[i].size() - 1]] = vector<string> (1, wordDict[i]);
    }
    vector<bool> dp(s.size(), false);
    for (int i = 0; i < s.size(); ++i) {
      if (umap.count(s[i])) {
        for (int j = 0; j < umap[s[i]].size(); ++j) {
          if ((i - (int)umap[s[i]][j].size()) == -1) {
            dp[i] = (s.substr(i - (int)umap[s[i]][j].size() + 1, umap[s[i]][j].size()) == umap[s[i]][j]);
          }
          else if ((i - (int)umap[s[i]][j].size()) >= 0) {
            dp[i] = dp[i - umap[s[i]][j].size()] && (s.substr(i - (int)umap[s[i]][j].size() + 1, umap[s[i]][j].size()) == umap[s[i]][j]);
          }
          
          if (dp[i]) break;
        }
      }
      else
        dp[i] = false;
    }
    return dp[s.size() - 1];
  }
};



int main() {
  string s = "leetcode";//"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";//"leetcode";
  vector<string> wordDict = {"leet", "code"};//{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  Solution2 sol;
  cout << sol.wordBreak(s, wordDict) << endl;
  return 0;
}
