// 1. Two Sum

// 1. sort + two pointers: O(nlong(n));O(1)

// 2. hashmap: O(n);O(n)
vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> result;
  unordered_map<int> umap;
  for (int i = 0; i < nums.size(); ++i)
    if (uset.count(target - nums[i]) > 0) {
      result.push_back(umap[target - nums[i]]);
      result.push_back(i);
      break;
    }
    else {
      umap[nums[i]] = i;
    }
  return result;
}
