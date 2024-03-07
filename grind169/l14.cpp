// 14. Longest Common Prefix

string longestCommonPrefix(vector<string>& strs) {
  if (strs.size() == 0) return "";
  else if (strs.size() == 1) return strs[0];

  int i = 0;
  for (; i < strs[0].size(); ++i)
    for (int j = 1; j < strs.size(); ++j) {
      if (i >= strs[j].size() || strs[j][i] != strs[0][i])
        return strs[0].substr(0, i);
    }

  return strs[0];
}
