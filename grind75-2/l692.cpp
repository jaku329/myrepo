// 692. Top K Frequent Words

class Compare {
public:
  bool operator() (const pair<int, string>& bottom, const pair<int, string>& top) {
    if (top.first > bottom.first) return true;
    else if (top.first == bottom.first && top.second < bottom.second) return true;
    return false;
  }
};
vector<string> topKFrequent(vector<string>& words, int k) {
  vector<string> result;
  unordered_map<string, int> umap;
  for (auto word : words)
    umap[word]++;
  priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
  for (auto it = umap.begin(); it != umap.end(); ++it) {
    pq.push({it->second, it->first});
  }
  while(k-- > 0) {
    result.push_back(pq.top().second);
    pq.pop();
  }
  return result;
}
