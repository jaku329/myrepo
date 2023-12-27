// 139. Word Break

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;

// 1. DFS: TLE
bool dfs(string s, unordered_set<string>& wordSet, vector<int>& wordLen, int pos) {
  if (pos == s.size()) return true;
  
  for (int i = 0; i < wordLen.size(); ++i) {
    if (wordLen[i] + pos <= s.size() && wordSet.count(s.substr(pos, wordLen[i])) > 0) {
      if (dfs(s, wordSet, wordLen, pos + wordLen[i])) return true;
    }
  }
  return false;
}
/*
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> wordSet;
  vector<int> wordLen;
  unordered_set<int> lenSet;
  for (auto word : wordDict) {
    wordSet.insert(word);
    lenSet.insert(word.size());
  }
  for (auto it = lenSet.begin(); it != lenSet.end(); ++it)
    wordLen.push_back(*it);
  sort(wordLen.begin(), wordLen.end(), less<int>());
  return dfs(s, wordSet, wordLen, 0);
}
*/
// 2. DP or recursive (w/ memorize)
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> wordSet;
  vector<bool> dp(s.size(), false);
  for (auto word : wordDict) {
    wordSet.insert(word);
  }

  for (int i = 0; i < s.size(); ++i) {
    for (auto word : wordSet) {
      int len = (int)word.size();
      if (dp[i])
        continue;
      else if (i + 1 - len == 0 && wordSet.count(s.substr(i + 1 - len, len)) > 0)
        dp[i] = true;
      else if ((i - len < 0) || !dp[i - len])
        continue;
      else
        dp[i] = wordSet.count(s.substr(i + 1 - len, len)) > 0 ? true: false;
    }
  }
  return dp[s.size() - 1];
} 

int main() {
  vector<string> wordDict = {
    "leet", "code" 
  };
  string s = "leetcode";//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab;
  cout << wordBreak(s, wordDict);
  return 0;
}
