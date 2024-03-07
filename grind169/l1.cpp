// 1. Two Sum

// brute force: O(n^2):O(1)
// sort + two pointer: O(nlogn):O(1)
// hash: O(n):O(n)
vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> result;
  unordered_map<int, int> umap;
  for (int i = 0; i < nums.size(); ++i) {
    if (umap.count(target - nums[i]) > 0) {
      result.push_back(umap[target - nums[i]]);
      result.push_back(i);
    }
    umap[nums[i]] = i;
  }
  return result;
}
