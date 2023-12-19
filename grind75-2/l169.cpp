// 169. Majority Element

// sort, O(nlog(n)); O(1)
int majorElement(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  return nums[nums.size() >> 1];
}

// hash table, O(n);O(n)
int majorElement(vector<int>& nums) {
  unordered_map<int, int> umap;
  for (auto n : nums) {
    umap[n]++;
	if (umap[n] > (nums.size() >> 1))
	  return n;
  }
  return 0;
}

// moore voting, O(n);O(1)
int majorElement(vector<int>& nums) {
  int candidate = nums[0];
  int count = 1;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == candidate) {
	  count++;
	  if (count > (nums.size() - i - 1)) return candidate;
	}
	else {
	  if (count == 1) candidate = nums[i];
	  else count--;
	}
  }
  return candidate;
}
