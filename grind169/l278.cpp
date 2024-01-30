// 278. First Bad Version

#include <iostream>
using namespace std;
bool isBadVersion(int v) {
  if (v >= 4) return true;
  return false;
}
int firstBadVersion(int n) {
  int l = 1, r = n;
  while (l < r) {
    int m = l + ((r - l) >> 1);
    if (isBadVersion(m))
      r = m;
    else
      l = m + 1;
  }
  return l; 
}

int main() {
  cout << firstBadVersion(5);
  return 0;
}
