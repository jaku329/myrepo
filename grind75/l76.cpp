// https://leetcode.com/problems/minimum-window-substring/

string minWindow(string s, string t) {
  vector<int> tMap(128, 0);
  vector<int> sMap(128, 0);
  int needed = t.size();
  for (int i = 0; i < t.size(); ++i) {
    tMap[t[i]]++;
  }

  int l = 0, r = 0;
  int len = s.size() + 1;
  int minL = -1;
  while (r < s.size()) {
    if (tMap[s[r]] > 0) {
      sMap[s[r]]++;
      if (tMap[s[r]] >= sMap[s[r]]) {
        needed--;
      }
      if (needed == 0) {
        if ((r - l + 1) < len) {
          len = r - l + 1;
          minL = l;
        }
      }
  
      while (l < r && needed == 0) {
        if (tMap[s[l]] > 0) {
          if (sMap[s[l]] <= tMap[s[l]])
            needed++;
          sMap[s[l]]--;
        }
        l++;
        if (needed == 0) {
          if ((r - l + 1) < len) {
            len = r - l + 1;
            minL = l;
          }
        }
      }
    }
    r++;
  }

  if (minL < 0) return "";

  return s.substr(minL, len);
}
