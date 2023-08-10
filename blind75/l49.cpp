#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      vector<unordered_map<char, int>> maps;
      vector<bool> groupDone(strs.size(), false);
      for (int i = 0; i < strs.size(); ++i) {
        unordered_map<char, int> map;
        for (int j = 0; j < strs[i].size(); ++j) {
          if(map.count(strs[i][j]) == 0)
            map[strs[i][j]] = 1;
          else
            map[strs[i][j]] += 1;
        }
        maps.push_back(map);
      }
  
      for (int i = 0; i < strs.size(); ++i) {
        if (groupDone[i]) continue;
        vector<string> r;
        r.push_back(strs[i]);
        for (int j = i + 1; j < strs.size(); ++j) {
          if (groupDone[j]) continue;
          if (strs[i].size() != strs[j].size()) continue;
          groupDone[j] = true;
          for (auto it = maps[j].begin(); it != maps[j].end(); it++) {
            //if (maps[i].count(it->first) == 0 || maps[i][it->first] != it->second) {
            if (maps[i][it->first] != it->second) {
              groupDone[j] = false;
              break;
            }
          }
          if (groupDone[j]) r.push_back(strs[j]);
        }
        res.push_back(r);
      }

      return res;
    }
};

class Solution2 {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> maps;
    for (auto it = strs.begin(); it != strs.end(); it++) {
      string s = *it;
      sort(s.begin(), s.end());
      maps[s].push_back(*it);
    }
    for (auto it = maps.begin(); it != maps.end(); it++)
      res.push_back(it->second);
    return res;
  }
};

int main() {
  vector<string> strs = {"hhhhu","tttti","tttit","hhhuh","hhuhh","tittt"};//{"eat", "ate"};
//  Solution s;
//  vector<vector<string> res = s.groupAnagrams(strs);
  Solution2 s;
  auto res = s.groupAnagrams(strs);  

  for (auto it = res.begin(); it != res.end(); it++) {
    for (auto it2 = it->begin(); it2 != it->end(); it2++)
      cout << *it2 << " ";
    cout << endl;
  }

  return 0;
}
