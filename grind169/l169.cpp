// 169. Majority Element

int majorityElement(vector<int>& nums) {
  if (nums.size() == 0) return -1;
  int winner = nums[0];
  int cnt = 1;
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] == winner)
      cnt++;
    else
      cnt--;
    if (cnt == 0) {
      winner = nums[i];
      cnt = 1;
    }
    else if (nums.size() - i < cnt)
      return winner;
  }
  return winner;
}
