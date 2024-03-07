// 57. Insert Interval

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  vector<vector<int>> result;
  for (auto interval : intervals) {
    if (interval[1] < newInterval[0])
      result.push_back(interval);
    else if (interval[0] > newInterval[1]) {
      if (newInterval[0] <= newInterval[1]) {
        result.push_back(newInterval);
        newInterval[0] = newInterval[1] + 1; // indicate newInterval is inserted.
      }
      result.push_back(interval);
    }
    else {
      if (interval[0] < newInterval[0])
        newInterval[0] = interval[0];
      if (interval[1] > newInterval[1])
        newInterval[1] = interval[1];
    }
  }
  if (newInterval[0] <= newInterval[1])
    result.push_back(newInterval);
  return result;
}
