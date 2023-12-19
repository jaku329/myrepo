// 150. Evaluate Reverse Polish Notation

#include <vector>
#include <iostream>
#include <stack>
#include <string>

using namespace std;
int myStoi(string s) {
  int i = 0;
  int result = 0;
  bool negative = false;
  if (s[i] == '-') {
    negative = true;
    i++;
  }
  while (i < s.size())
    result = result * 10 + (s[i++] - '0');
  return negative ? -result: result;
}

int evalRPN(vector<string>& tokens) {
  stack<int> st;
  for (auto n : tokens) {
    if (n == "+") {
      int v2 = st.top();
      st.pop();
      int v1 = st.top();
      st.pop();
      st.push(v1 + v2);
    }
    else if (n == "-") {
      int v2 = st.top();
      st.pop();
      int v1 = st.top();
      st.pop();
      st.push(v1 - v2);
    }
    else if (n == "*") {
      int v2 = st.top();
      st.pop();
      int v1 = st.top();
      st.pop();
      st.push(v1 * v2);
    }
    else if(n == "/") {
      int v2 = st.top();
      st.pop();
      int v1 = st.top();
      st.pop();
      st.push(v1 / v2);
    }
    else {
      st.push(myStoi(n)); 
    }
  }
  return st.top();
}

int main() {
  vector<string> tokens = {
   "2","1","+","3","*"
  };
  cout << evalRPN(tokens);
  return 0;
}
