// 658. Find K Closest Elements
#include <iostream>
#include <vector>
using namespace std;
int helper(vector<int>& arr, int x, int l, int r) {
  int distR = abs(arr[r] - x);
  int distL = abs(x - arr[l]);
  if (distL == distR)
    return l < r ? l : r;
  else if (distL < distR)
    return l;
  return r;
}

vector<int> findCloestElements(vector<int>& arr, int k, int x) {
  int l = 0, r = arr.size() - 1;
  int m;
  while (l <= r) {
    m = l + ((r - l) >> 1);
    if (arr[m] == x)
      break;
    else if (arr[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  if (arr[m] == x) {
    l = m;
    r = m;
  }
  else {
    if (l > arr.size() - 1)
      l = r;
    else if (r < 0)
      r = l;
    else { 
      l = helper(arr, x, r, l);
      r = l;
    }
  }

  vector<int> result;
  while (--k > 0) {
    if (l <= 0)
      r++;
    else if (r >= arr.size() - 1)
      l--;
    else {
      int choice = helper(arr, x, l - 1, r + 1);
      if (choice == l - 1)
        l--;
      else
        r++;
    }
  }
  while (l <= r)
    result.push_back(arr[l++]);
  return result;
}

// {1,2,3,4,5}
// {1,1,1,10,10,10} // x = 9, k = 1

int main() {
  vector<int> arr = {
    1,1,1,10,10,10
  };
  auto r = findCloestElements(arr, 1, 9);
  for (auto i : r)
    cout << i << " ";
  cout << endl;
  return 0;
}
