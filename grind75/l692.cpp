// https://leetcode.com/problems/top-k-frequent-words/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Compare {
public:
bool operator() (const pair<int, string>& below, const pair<int, string>& above) {
    // to be max heap
    if (below.first < above.first) return true;
    else if (below.first == above.first && below.second > above.second) return true;
    return false;
}
};

vector<string> topKFrequent(vector<string>& words, int k) {
  unordered_map<string, int> umap;
  for (auto word : words) {
    if (umap.count(word)) umap[word]++;
    else umap[word] = 1;
  }

  priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
  for (auto it = umap.begin(); it != umap.end(); ++it)
    pq.push({it->second, it->first});

  vector<string> result;
  for (int i = 0; i < k; ++i) {
    result.push_back(pq.top().second);
    pq.pop();
  }

  return result;
}

int main() {

  return 0;
}
