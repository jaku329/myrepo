// 5. Longest Palindromic Substring

// 1D DP: 26ms
bool isPalindrome(string s, int start, int end) {
  while (start < end) {
    if (s[start] != s[end])
      return false;
    start++;
    end--;
  }
  return true;
}

string longestPalindrome(string s) {
  if (s.size() == 0) return 0;
  int len = 1, maxL = 0;
  vector<int> dp(s.size(), 1);
  for (int i = 1; i < s.size(); ++i) {
    if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == s[i])
      dp[i] = dp[i - 1] + 2;
    else {
      int start = i - dp[i - 1];
      if (start < 0) start = 0;
      while (start < i && !isPalindrome(s, start, i)) 
        start++;
      dp[i] = i - start + 1;
    }
    if (dp[i] > len) {
      maxL = i - dp[i] + 1;
      len = dp[i];
    }
  }
  return s.substr(maxL, len);
}

// extened from center: 53ms
int palindrome(string s, int l, int r) {
  if (l < 0 || r >= s.size()) return 0;
  else if (s[l] != s[r]) return 1;
  int len = 0;
  while (l >= 0 && r < s.size() && s[l] == s[r]) {
    len = r - l + 1;
    l--;
    r++;
  }
  return len;
}
string longestPalindrome(string s) {
  int len = 0, maxLen = 0, maxL = 0;
  for (int i = 0; i < s.size(); ++i) {
    len = palindrome(s, i, i);
    if (len > maxLen) {
      maxLen = len;
      maxL = i - len / 2;
    }
    len = palindrome(s, i, i + 1);
    if (len > maxLen) {
      maxLen = len;
      maxL = i + 1 - len / 2;
    }
  }
  return s.substr(maxL, maxLen);
} 

// Manachar?
