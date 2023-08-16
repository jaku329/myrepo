// https://leetcode.com/problems/minimum-window-substring

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> tmap;
    unordered_map<char, int> map;
    int needed = t.size();

    for (int i = 0; i < t.size(); ++i) {
      if(tmap.count(t[i])) tmap[t[i]]++;
      else {
        tmap[t[i]] = 1;
        map[t[i]] = 0;
      }
    }

    int minL = 0, minR = s.size();
    int l = 0, r = 0;
    int minWin = s.size() + 1;
    while (r < s.size()) {
      if (tmap.count(s[r])) {
        map[s[r]]++;
        if (map[s[r]] <= tmap[s[r]]) {
          needed--;
        }
        while (needed <= 0) {
          if (r - l + 1 < minWin) {
            minR = r;
            minL = l;
            minWin = r - l + 1;
          }

          if (tmap.count(s[l])) {
            map[s[l]]--;
            if (map[s[l]] < tmap[s[l]]) {
              needed++;
            }
          }
          l++;
        }
      }
      r++;
    }

    if (minWin > s.size()) return "";
    return s.substr(minL, minWin);
  }
};

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";

  Solution sol;
  cout << sol.minWindow(s, t) << endl;
  return 0;
}
