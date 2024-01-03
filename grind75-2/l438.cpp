// 438. Find All Anagrams in a String

vector<int> findAnagrams(string s, string p) {
  vector<int> result;
  unordered_map<char, int> umap;
  for (auto c : p)
    umap[c]++;
  int l = 0; // close
  int r = 0;
  while (r < s.size() && umap.count(s[r]) == 0)
    r++;
  l = r;
  while (r < s.size()) {
    if (umap.count(s[r]) == 0) {
      while (l < r) {
        if (umap.count(s[l]))
          umap[s[l]]++;
        l++;
      }
    }
    else {
      umap[s[r]]--;
      if (umap.count(s[l]) == 0)
        l++;

      while (l < r && umap[s[r]] < 0) {
        umap[s[l]]++;
        l++;
      }
      if (r - l == p.size() - 1) {
        result.push_back(l);
        umap[s[l]]++;
        l++;
      }
    }
    r++;
  }
  return result;
}
