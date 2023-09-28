// https://leetcode.com/problems/implement-queue-using-stacks/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
  stack<int> st;
  stack<int> rSt;
public:
  void push(int x) {
    while (!rSt.empty()) {
      st.push(rSt.top());
      rSt.pop();
    }
    st.push(x);
  }

  int pop() {
    int x;
    while (!st.empty()) {
      rSt.push(st.top());
      st.pop();
    }

    x = rSt.top();
    rSt.pop();
    return x;
  }
  
  int peek() {
    while (!st.empty()) {
      rSt.push(st.top());
      st.pop();
    }
    return rSt.top();
  }

  bool empty() {
    return st.empty() & rSt.empty();
  }
};

int main() {
  MyQueue q;

  q.push(1);
  q.push(2);
  cout << q.peak() << endl;
  cout << q.pop() << endl;
  cout << q.empty() << endl;
  return 0;
}
