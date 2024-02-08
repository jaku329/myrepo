// 179. Largest Number

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Compare {
public:
  bool operator () (const string& bottom, const string& top) {
    int i = 0;
    
    if (bottom.size() == top.size())
      while (i < bottom.size()) {
        if (top[i] > bottom[i])
          return true;
        else if (top[i] < bottom[i])
          return false;
        i++;
      }
    else {
      string s1 = top + bottom;
      string s2 = bottom + top;
      i = 0;
      while (i < s1.size()) {
        if (s1[i] > s2[i])
          return true;
        else if (s1[i] < s2[i])
          return false;
        i++;
      }
    }
    return true;
  }
};

string toString(int num) {
  if (num == 0) return "0";

  string s;
  while (num > 0) {
    s += (num % 10) + '0';
    num /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
string largestNumber(vector<int>& nums) {
  priority_queue<string, vector<string>, Compare> pq;
  for (auto n : nums)
    pq.push(toString(n));
  string result;
  while (!pq.empty()) {
    if (result == "0" && pq.top() == "0") {
      pq.pop();
      continue;
    }
    result += pq.top();
    pq.pop();
  }
  return result;
}

int main() {
  return 0;
}
