// 15. 3Sum

//  sort + two pointers, O(N^2);O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> result;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 2; ++i) {
    if (i > 0 && nums[i - 1] == nums[i])
      continue;
    int j = i + 1;
    int k = nums.size() - 1;
    while (j < k) {
      if (nums[j] + nums[k] + nums[i] == 0) {
        result.push_back({nums[i], nums[j], nums[k]});
        j++;
        k--;
        while (j < k && nums[j] == nums[j - 1]) j++;
      }
      else if (nums[j] + nums[k] + nums[i] > 0)
        k--;
      else
        j++;
    }
  }
  return result; 
}

