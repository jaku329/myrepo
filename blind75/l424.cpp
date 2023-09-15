// https://leetcode.com/problems/longest-repeating-character-replacement

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    int len = 0;
    unordered_map<char, int> m;
    int l = 0, r = 0;
    while (r < s.size()) {
      if (m.count(s[r]))
        m[s[r]] += 1;
      else
        m[s[r]] = 1;
      
      int lenOflongestChar = 0;
      int lenOfallChar = 0;
      for (auto it = m.begin(); it != m.end(); ++it) {
        lenOflongestChar = max(it->second, lenOflongestChar);
        lenOfallChar += it->second;
      }
      
      if (lenOfallChar - lenOflongestChar <= k) {
        len = max(lenOfallChar, len);
      }
      else {
        while (l < r && (lenOfallChar - lenOflongestChar > k)) {
          if (m[s[l]] == 1)
            m.erase(s[l]);
          else
            m[s[l]] -= 1;
          lenOflongestChar = 0;
          lenOfallChar = 0;
          for (auto it = m.begin(); it != m.end(); ++it) {
            lenOflongestChar = max(it->second, lenOflongestChar);
            lenOfallChar = it->second;
          }
          l++;
        }
      }
      r++;
    }
    return len;
  }
};

int main() {
  string s = "EOEMQLLQTRQDDCOERARHGAAARRBKCCMFTDAQOLOKARBIJBISTGNKBQGKKTALSQNFSABASNOPBMMGDIOETPTDICRBOMBAAHINTFLH";
  int k = 7;
  Solution sol;
  cout << s << endl;
  cout << sol.characterReplacement(s, k);
  return 0;
}
