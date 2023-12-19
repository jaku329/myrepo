// 409. Longest Palindrome

int longestPalindrome(string s) {
  unordered_map<char, int> umap;
  for (int i = 1; i < s.size(); ++i) {
    umap[s[i]]++;
  }
  bool hasOdd = false;
  int len = 0;
  for (auto it = umap.begin(); it != umap.end(); ++it) {
    if (!hasOdd && (it->second & 0x1))
	  hasOdd = true;
	len += it->second & (~0x1);
  }
  return hasOdd ? len + 1 : len;
}
