// 134. Gas Station

#include <iostream>
#include <vector>
using namespace std;

// two pointers
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  int l = 0; 
  int r = 0;
  int tank = 0;
  while (l < gas.size()) {
    if (gas[l] - cost[l] >= 0) {
      tank = gas[l] - cost[l];
      r = (l + 1) % gas.size();
      while (r != l && tank >= 0) {
        tank += (gas[r] - cost[r]);
        r = (r + 1) % gas.size();
      }
      if (l == r && tank >= 0)
        return l;
      if (r > l)
        l = r;
      else
        return -1;
    }
    else
      l++;
  }
  return -1;
}

int main() {
  vector<int> gas = {
    5,8,2,8
  };
  vector<int> cost = {
    6,5,6,6
  };
  cout << canCompleteCircuit(gas, cost) << endl;
  return 0;
}
