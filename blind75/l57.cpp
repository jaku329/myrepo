// https://leetcode.com/problems/insert-interval

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int l, r;
    if (intervals.empty()) {
      res.push_back(newInterval);
      return res;
    }

    l = newInterval[0];
    r = newInterval[1];
    for (int i = 0; i < intervals.size(); ++i) {
      if (r < intervals[i][0]) {
        res.push_back({l, r});
        l = intervals[i][0];
        r = intervals[i][1];
       
      }
      else if (l > intervals[i][1]) {
        res.push_back(intervals[i]);
      }
      else {
        l = min(l, intervals[i][0]);
        r = max(r, intervals[i][1]);
      }
    }
    res.push_back({l, r});

    return res;
  }
};

int main() {
  vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};//{{1,5}};//{{1,3}, {6,9}};
  vector<int> n = {4, 8};
  Solution s;
  auto res = s.insert(intervals, n);
  for (auto it = res.begin(); it != res.end(); ++it) {
    for (auto it2 = it->begin(); it2 != it->end(); ++it2)
      cout << *it2 << " ";
    cout << endl;
  }
  return 0;
}
