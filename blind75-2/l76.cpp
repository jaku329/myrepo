// 76. Minimum Window Substring

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string minWindow(string s, string t) {
  vector<int> tSet(128, 0);
  vector<int> sSet(128, 0);
  int need = 0;
  for (auto c : t) {
    tSet[c]++;
    need++;
  }
  int l = 0, r = 0;
  int win = s.size() + 1;
  string result = "";
  while (r < s.size()) {
    sSet[s[r]]++;
    if (tSet[s[r]] > 0 && sSet[s[r]] <= tSet[s[r]]) {
      need--;
      while (l <= r && need == 0) {
        if (r - l + 1 < win) {
          win = r - l + 1;
          result = s.substr(l, win);
        }
        sSet[s[l]]--;
        if (tSet[s[l]] > 0 && sSet[s[l]] < tSet[s[l]]) {
          need++;
        }
        l++;
      }
    }
    r++;
  }

  return result;
}

int main() {
  cout << minWindow("a", "a") << endl;
  return 0;
}
