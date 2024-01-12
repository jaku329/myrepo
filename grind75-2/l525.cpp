// 525. Contiguous Array

// prefix sum
int findMaxLength(vector<int>& nums) {
  unordered_map<int, int> umap;
  umap[0] = -1;
  int prefixSum = 0;
  int len = 0;
  for (int i = 0; i < nums.size(); ++i) {
    prefixSum += nums[i] == 1 ? 1 : -1;
    if (umap.count(prefixSum) == 0) {
      umap[prefixSum] = i;
    }
    else {
      len = max(len, i - umap[prefixSum]);
    }
  }
  return len;
}
// 0,1,1,0,1,1,1,0
