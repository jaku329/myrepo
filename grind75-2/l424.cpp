// 424 Longest Repeating Charactor Replacement

// two pointers: O(26*N);O(1)
int charactorReplacement(string s, int k) {
  int l = 0, r = 0;
  vector<int> charCnt(26, 0);
  int maxChar = 0;
  int len = 0;
  while (r < s.size()) {
    int i = s[r] - 'A';
    charCnt[i]++;
    if (charCnt[i] > maxChar)
      maxChar = charCnt[i];
    if (r - l + 1 - maxChar <= k)
      len = max(len, r - l + 1);
    else {
      while (r - l + 1 - maxChar > k) {
        int i = s[l] - 'A';
        charCnt[i]--;
        if (charCnt[i] + 1 == maxChar) {
          for (auto c : charCnt)
            if (c > 0)
              maxChar = max(maxChar, c);
        }
        l++;
      }
    }
    r++;
  }
  return len;
}
