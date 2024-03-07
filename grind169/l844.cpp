// 844. Backspace String Compare

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// stack: O(n):O(n)
bool backspaceCompare(string s, string t) {
  stack<char> stS;
  stack<char> stT;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '#') {
      if (!stS.empty())
        stS.pop();
    }
    else
      stS.push(s[i]);
  }
  for (int i = 0; i < t.size(); ++i) {
    if (t[i] == '#') {
      if (!stT.empty())
        stT.pop();
    }
    else
      stT.push(t[i]);
  }
  if (stS.size() != stT.size()) return false;
  while (!stS.empty()) {
    if (stS.top() != stT.top()) return false;
    stS.pop();
    stT.pop();
  }
  return true;
}

int main() {
  cout << backspaceCompare("xywrrmp", "xywrrmu#p");
  return 0;
}
