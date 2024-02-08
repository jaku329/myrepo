// 560. Subarray Sum Equals K

// 1. brute force: O(n^2);O(1)

// 2. prefix sum: O(n);O(n)
int subarraySum(vector<int>& nums, int k) {
  int cnt = 0;
  unordered_set<int> prefixSum;
  prefixSum.insert(0);
  int sum = 0;
  for (int i = 0; i < nums.size(); ++i) {
    sum += nums[i];
    if (prefixSum.count(sum - k) > 0)
      cnt++;
    prefixSum.insert(sum);
  }
  return cnt;
}
