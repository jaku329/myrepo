// 1004. Max Consecutive Ones III

int longestOnes(vector<int>& nums, int k) {
  int maxOnes = 0;
  int l = 0, r = 0;
  int zeros = 0;
  while (r < nums.size()) {
    if (nums[r] == 1)
      maxOnes = max(maxOnes, r - l + 1);
    else if (zeros < k) {
      maxOnes = max(maxOnes, r - l + 1);
      zeros++;
    }
    else {
      while (l < r && nums[l] == 1) 
        l++;
      if (l <= r && nums[l] == 0) 
        l++;
    }
    r++;
  }
  return maxOnes;
}

// [1,1,1,0,0,0,1,1,1,1,0], k = 2
// [0,0,1,1,1,0,0], k = 0
