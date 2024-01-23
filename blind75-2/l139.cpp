// 139. Word Break

// 1. dfs

// 2. dp
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<string> wordSet;
  for (auto word : wordDict) {
    wordSet.insert(word);
  }
  vector<bool> dp(s.size(), false);
  for (int i = 0; i < s.size(); ++i) {
    for (auto word : wordSet) {
      int len = word.size();
      if (i - len + 1 < 0)
        dp[i] = 0;
      else {
        if ((i - len + 1 == 0 || dp[i - len - 1]) && wordSet.count(s.substr(i - len + 1, len)) > 0)
          dp[i] = true;
        else
          dp[i] = false;
      }
    }
  }
  return dp[s.size() - 1];
}
