// https://leetcode.com/problems/longest-repeating-character-replacement/

int characterReplacement(string s, int k) {
  if (s.size() == 0) return 0;

  int l = 0, r = 0;
  unordered_map<char, int> umap;
  int maxCnt = 0;
  char maxChar;
  int len = 0;
  while (r < s.size()) {
    if (umap.count(s[r]) > 0)
      umap[s[r]]++;
    else
      umap[s[r]] = 1;
    if (umap[s[r]] > maxCnt) {
      maxCnt = umap[s[r]];
      maxChar = s[r];
    }
    if (r - l + 1 - maxCnt <= k) {
      len = max(len, r - l + 1);
    }
    else {
      while (l < r && r - l + 1 - maxCnt > k) {
        umap[s[l]]--;
        if (maxChar == s[l]) {
          for (auto it = umap.begin(); it != umap.end(); ++it) {
            if (it->first != s[l] && it->second >= maxCnt) {
              maxCnt = it->second;
              maxChar = it->first;
              break;
            }
          }
        }
        l++;
      }
    }

    r++;
  }
  return len;
}

