// 3. Longest Substring Without Repeating Characters


// two pointers
int lengthOfLongestSubstring(string s) {
  if (s.size() == 0) return 0;
  
  vector<char> charSet(128, 0);
  int l = 0;
  int r = 0;
  int maxLen = 0;
  while (r < s.size()) {
    charSet[s[r]]++;
    if (charSet[s[r]] == 1)
      maxLen = max(maxLen, r - l + 1);
    while (charSet[s[r]] > 1) {
      charSet[s[l]]--;
      l++;
    }
    r++;
  }
  return maxLen;
}

// abcabcbb
