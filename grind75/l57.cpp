// https://leetcode.com/problems/insert-interval/

class Solution {
public:
  vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int l = newInterval[0], r = newInterval[1];
    bool inserted = false;
    for (int i = 0; i < intervals.size(); ++i) {
      if (inserted) {
        result.push_back(intervals[i]);
      }
      else {
        if (r < intervals[i][0]) {
          result.push_back({l, r});
          result.push_back(intervals[i]);
          inserted = true;
        }
        else if (l > intervals[i][1]) {
          result.push_back(intervals[i]);
        }
        else {
          l = min(l, intervals[i][0]);
          r = max(r, intervals[i][1]);
        }
      }
    }
    if (!inserted) {
      result.push_back({l, r});
    }
    return result;
  }
};
