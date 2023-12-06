// https://leetcode.com/problems/find-k-closest-elements/

#include <iostream>
#include <vector>
using namespace std;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  vector<int> result;
  if (k == 0) return result;
  int l = 0, r = arr.size() - 1;
  int m;
  while (l < r) {
    m = l + ((r - l) >> 2);
    if (arr[m] == x) break;
    else if (arr[m] < x) l = m + 1;
    else r = m - 1;
  }

  if (l == r) m = l;
  if (arr[m] > x && m > 0)
    m = arr[m] - x < x - arr[m - 1] ? m : m - 1;
  else if (arr[m] < x && m < arr.size() - 1)
    m = x - arr[m] < arr[m + 1] - x ? m : m + 1;

  l = m - 1, r = m + 1;
  while (r - l <= k) {
    if (l < 0)
      r++;
    else if (r >= arr.size())
      l--;
    else {
      if (x - arr[l] <= arr[r] - x)
        l--;
      else
        r++;
    }
  }

  l += 1;
  for (int i = 0; i < k; ++i) {
    result.push_back(arr[l + i]);
  }

  return result;
}  

int main() {
  vector<int> arr = {
    1,1,1,9,9,9
  };

  auto r = findClosestElements(arr, 1, 8);

  for (auto e : r)
   cout << e << " ";
  cout << endl;
  return 0;
}
