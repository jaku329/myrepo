// 217. Contains Duplicate

// hash table, O(n);O(n)
bool containDuplicate(vector<int>& nums) {
  unordered_set<int> uset;
  for (auto n : nums)
    if (uset.count(n) > 0) 
      return true;
    else
      uset.insert(n);
  return false;
}
