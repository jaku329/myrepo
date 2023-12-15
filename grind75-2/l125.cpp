// 125. Valid Palindrome

// two pointers, O(n);O(1)
bool isPalindrome(string s) {
  int l = 0;
  int r = s.size() -1;
  char caseBit = ~('A' ^ 'a');
  while (l < r) {
    while (l < r && !((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9')))
      l++;
    while (l < r && !((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9')))
      r--;
    if (s[l] >= '0'd && s[l] <= '9' && s[l] != s[r])
      return false;
    if ((s[l] & caseBit) != (s[r] & caseBit)) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}
