// https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> umap;
    for (int i = 0; i < s.size(); ++i) {
      if (umap.count(s[i])) umap[s[i]]++;
      else umap[s[i]] = 1;
    }
    int len = 0;
    bool hasOdd = false;
    for (auto it = umap.begin(); it != umap.end(); ++it) {
      len += (it->second & (~0x1));
      if (!hasOdd && it->second & 0x1) {
        len++;
        hasOdd = true;
      }
    }
    return len;
  }
};
