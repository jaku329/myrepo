// https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
/*
    sort(intervals.begin(), intervals.end(), [](vector<int> i1, vector<int> i2){
      return i1[0] <= i2[0];
    });
*/
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    int l = -1, r = -1;
    for (int i = 0; i < intervals.size();) {
      l = intervals[i][0];
      r = intervals[i][1];
      i++;
      while (i < intervals.size() && intervals[i][0] <= r) {
        if (intervals[i][1] > r)
          r = intervals[i][1];
        i++;
      }
      res.push_back({l, r});
    }
    return res;
  }
};

int main() {
  vector<vector<int>> intervals = {
    {1,3},{2,6},{8,10},{15,18}
  };
  Solution s;
  auto res = s.mergeIntervals(intervals);
  return 0;
}
