// 3. Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(string s) {
  vector<int> charSet(128, 0);
  int l = 0, r = 0;
  int len = 0;
  while (r < s.size()) {
    charSet[s[r]]++;
    while (charSet[s[r]] > 1) {
      charSet[s[l]]--;
      l++;
    }
    len = max(len, r - l + 1);
    r++;
  }
  return len;
}
