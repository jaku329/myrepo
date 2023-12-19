// 57. Insert Interval

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  vector<vector<int>> result;
  bool isInserted = false;
  for (int i = 0; i < intervals.size(); ++i) {
    if (intervals[i][1] < newInterval[0])
      result.push_back(intervals[i]);
    else if (intervals[i][0] > newInterval[1]) {
      if (!isInserted) {
        result.push_back(newInterval);
        isInserted = true;
      }
      result.push_back(intervals[i]);
    }
    else {
      if (intervals[i][0] < newInterval[0])
        newInterval[0] = intervals[i][0];
      if (intervals[i][1] > newInterval[1])
        newInterval[1] = intervals[i][1];
    }
  }

  if (!isInserted)
    result.push_back(newInterval);

  return result;
}

// [1,2],[3,5],[6,7],[8,10],[12,16]
// [4,8]
