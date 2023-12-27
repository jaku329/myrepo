// 56. Merge Intervals

// [1,3],[2,6],[8,10],[15,18]
// [1,4][1,4]
// use temp interval
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> result;
  sort(intervals.begin(), intervals.end(), [](const vector<int>& first, const vector<int>& second){ return first[0] < second[0];}); // sorting begin
  vector<int> newIn;
  for (auto in : intervals) {
    if (newIn.size() == 0) {
      newIn = in;
    }
    else {
      if (in[1] <= newIn[1])
        continue;
      else if (in[0] <= newIn[1])
        newIn[1] = in[1];
      else {
        result.push_back(newIn);
        newIn.clear();
        newIn = in;
      }
    }
  }
  if (newIn.size() != 0)
    result.push_back(newIn);
  return result;
}

// no temp interval
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> result;
  sort(intervals.begin(), intervals.end());
  for (auto in : intervals) {
    if (result.size() == 0)
      result.push_back(in);
    else if (in[1] > result[result.size() - 1][1]) {
      if (in[0] <= result[result.size() - 1][1])
        result[result.size() - 1][1] = in[1];
      else
        result.push_back(in);
    }
  }
  return result;
}
