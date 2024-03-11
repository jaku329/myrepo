// 128. Longest Consecutive Sequence

// brute force: O(n^2):O(1)

// hashmap: O(n):O(n)
int longestConsecutive(vector<int>& nums) {
  int maxWidth = 0;
  unordered_set<int> uset;
  for (auto n : nums)
    uset.insert(n);
  while (!uset.empty()) {
    auto it = uset.begin();
    int n1 = *it;
    int n2 = *it;
    uset.erase(*it);
    int width = 1;
    while (uset.count(--n1)) {
      uset.erase(n1);
      width++;
    }
    while (uset.count(++n2)) {
      uset.erase(n2);
      width++;
    }
    maxWidth = max(width, maxWidth);
  }
  return maxWidth;
}
