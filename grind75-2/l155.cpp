// 155. Min Stack

// 1. only stack: 2 stack + 1 tmp stack
class MinStack {
private:
  stack<int> st1;
  stack<int> st2;
public:
  MinStack() {}
  void push(int val) {
    stack<int> tmp;
    st1.push(val);
    while (!st2.empty() && st2.top() < val) {
      tmp.push(st2.top());
      st2.pop();
    }
    st2.push(val);
    while (!tmp.empty()) {
      st2.push(tmp.top());
      tmp.pop();
    }
  }
  void pop() {
    stack<int> tmp;
    while (!st2.empty() && st2.top() != st1.top()) {
      tmp.push(st2.top());
      st2.pop();
    }
    st2.pop();
    st1.pop();
    while (!tmp.empty()) {
      st2.push(tmp.top());
      tmp.pop();
    }
  }
  int top() {
    return st1.top();
  }
  int getMin() {
    return st2.top();
  }
}

// 2. one stack: 2 stacks
class MinStack {
private:
  stack<int> st1;
  stack<int> st2;
public:
  MinStack() {}
  void push(int val) {
    st1.push(val);
    if (st2.empty() || val <= st2.top())
      st2.push(val);
  }
  void pop() {
    if (!st2.empty() && st2.top() == st1.top())
      st2.pop();
    st1.pop();
  }
  int top() {
    return st1.top();
  }
  int getMin() {
    if (!st2.empty())
      return st2.top();
    return st1.top();
  }
}

// 3. stack + priority queue + hash table(or hash set for all distinct numbers)
class MinStack {
private:
  stack<int> st;
  priority_queue<int, vector<int>, greater<>> pq;
  unordered_map<int, int> umap;
public:
  MinStack() {}
  void push(int val) {
    st.push(val);
    pq.push(val);
    umap[val]++;
  }
  void pop() {
    umap[st.top()]--;
    st.pop();
  }
  int top() {
    return st.top();
  }
  int getMin() {
    while (umap[pq.top()] == 0) pq.pop();
    return pq.top();
  }
}
