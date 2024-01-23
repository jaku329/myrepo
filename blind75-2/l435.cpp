// 435. Non-overlapping Intervals

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  int eraseNum = 0;
  sort(intervals.begin(), intervals.end(), [] (const vector<int>& first, const vector<int>& second) {
    if (first[1] < second[1]) return true;
    else if (first[1] > second[1]) return false;
    return first[0] <= second[0];
  });
  int prev = 0;
  for (int i = 1; i < intervals.size(); ++i) {
    if (intervals[i][0] < intervals[prev][1])
      eraseNum++;
    else
      prev = i;
  }
  return eraseNum;
}
