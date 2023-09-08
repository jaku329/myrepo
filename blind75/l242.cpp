// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); ++i) {
      if (m.count(s[i]))
        m[s[i]] += 1;
      else
        m[s[i]] = 1;
    }
    for (int i = 0; i < t.size(); ++i) {
      if (m.count(t[i]) && m[t[i]] > 0) {
        m[t[i]] -= 1;
      }
      else return false;
    }
    return true;
  }
};
