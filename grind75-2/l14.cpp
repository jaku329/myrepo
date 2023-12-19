// 14. Longest Common Prefix

string longestCommonPrefix(vector<string>& strs) {
  if (strs.size() == 0) return "";
  else if (strs.size() == 1) return strs[0];

  string s = strs[0];
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 1; j < strs.size(); ++j) {
      if ((i > strs[j].size() - 1) || s[i] != strs[j][i])
        return s.substr(0, i);
    }
  }
  return strs[0];
}
