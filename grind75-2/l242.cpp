// 242. Valid Anagram

// sort, O(nlog(n));O(1)

// hash, O(n);O(1)
bool isAnagram(string s, string t) {
  if (s.size() != t.size()) return false;
  vector<int> cSet(26, 0);
  for (auto c : s)
    cSet[c - 'a']++;
  for (auto c : t)
    if (cSet[c - 'a'] <= 0) 
      return false;
    else 
      cSet[c - 'a']--;
  return true;
}
