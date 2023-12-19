// 973. K Closest Points to Origin

struct Cmp {
  bool operator() (const pair<double, int>& bottom, const pair<double, int>& top) {
    return top.first < bottom.first;
  }
};

vector<vector<int>> kCloest(vector<vector<int>>& points, int k) {
  priority_queue<pair<double, int>, vector<pair<double, int>>, Cmp> pq; // dist, idx of points
  for (int i = 0; i < points.size(); ++i) {
    double dist = sqrt(((long)points[i][0] * (long)points[i][0]) + ((long)points[i][1] * (long)points[i][1]));
    pq.push({dist, i});
  }
  vector<vector<int>> result;
  while (k-- > 0) {
    result.push_back(points[(pq.top()).second]);
    pq.pop();
  }
  return result;
}
