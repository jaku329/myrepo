// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (p.size() > s.size()) return result;

    unordered_map<char, int> umap;
    unordered_map<char, int> umapWin;
    for (auto c : p) {
      if (umap.find(c) != umap.end())
        umap[c]++;
      else {
        umap[c] = 1;
      }
    }
    int l = 0, r = 0;
    while (r < s.size()) {
      if (umap.find(s[r]) == umap.end()) {
        if (umapWin.size() > 0)
          umapWin.clear();
        l = r;
      }
      else {
        if (umapWin.size() == 0)
          l = r;

        if (umapWin.find(s[r]) != umapWin.end())
          umapWin[s[r]]++;
        else
          umapWin[s[r]] = 1;

        while (umapWin[s[r]] > umap[s[r]]) {
          umapWin[s[l]]--;
          l++;
        }

        if (r - l + 1 == p.size()) {
          result.push_back(l);
          umapWin[s[l]]--;
          l++;
        }
      }
      r++;
    }
    return result;
  }
};

class Solution2 {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    if (p.size() > s.size()) return result;

    vector<int> pv(26, 0);
    vector<int> sv(26, 0);
    for (auto c : p) {
      pv[c - 'a'] += 1;
    }

    int l = 0, r = 0;
    bool start = false;
    while (r < s.size()) {
      int c = s[r] - 'a';
      if (pv[c] == 0) {
        while (l < r)
          sv[s[l++] - 'a'] = 0;
        start = false;
      }
      else {
        if (!start) {
          l = r;
          start = true;
        }

        sv[c]++;

        while (sv[c] > pv[c]) {
          sv[s[l] - 'a']--;
          l++;
        }

        if (r - l + 1 == p.size()) {
          result.push_back(l);
          sv[s[l] - 'a']--;
          l++;
        }
      }
      r++;
    }
    return result;
  }
};
