// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      if (m.count(nums[i]))
        m[nums[i]] += 1;
      else
        m[nums[i]] = 1;
    }
    priority_queue<pair<int, int>> pq;
    for (auto it = m.begin(); it != m.end(); it++) {
      pq.push({it->second, it->first});
    }
    vector<int> res;
    for (int i = 0; i < k; ++i) {
      res.push_back((pq.top()).second);
      pq.pop();
    }
    return res;
  }
};
