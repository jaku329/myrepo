#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    int i = 0;
    while (i < s.size()) {
      if (st.size() > 0 && s[i] == '}') {
        if (st.top() == '{')
          st.pop();
        else
          return false;
      }
      else if (st.size() > 0 && s[i] == ']') {
        if (st.top() == '[')
          st.pop();
        else
          return false;
      }
      else if (st.size() > 0 && s[i] == ')') {
        if (st.top() == '(') 
          st.pop();
        else
          return false;
      }
      else if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        st.push(s[i]);
      else {
        return false;
      }
      i++;
    }
    if (st.size() > 0) return false;
    return true;
  }
};

int main() {
  return 0;
}
