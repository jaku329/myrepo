// https://leetcode.com/problems/ransom-note/

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> m;
    for (int i = 0; i < magazine.size(); ++i) {
      if (m.count(magazine[i]))
        m[magazine[i]]++;
      else
        m[magazine[i]] = 1;
    }

    for (int i = 0; i < ransomNote.size(); ++i) {
      if (m.count(ransomNote[i]) && m[ransomNote[i]] > 0)
        m[ransomNote[i]]--;
      else
        return false;
    }
    return true;
  }
};
