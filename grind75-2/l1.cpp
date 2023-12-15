// 1. Two Sum

// brute force: O(n^2); O(1)

// hashmap: O(n); O(n)
vector<int> twoSum(<vector<int>& nums, int target) {
  unordered_map<int, int> umap;
  vector<int> result;
  for (int i = 0; i < nums.size(); ++i) {
    if (umap.count(target - nums[i]) > 0) {
      result.push_back(i);
      result.push_back(umap[target - nums[i]]);
      break;
    }
    else
      umap[nums[i]] = i;
  }
  return result;
}
