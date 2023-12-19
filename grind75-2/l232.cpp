// 232. Implement Queue using Stacks

class MyQueue {
private:
  stack<int> oldStack;
  stack<int> newStack;
public:
  MyQueue() {}
  
  void push(int x) {
    while (!newStack.empty()) {
	  oldStack.push(newStack.top());
	  newStack.pop();
	}
	oldStack.push(x);
  }
  
  int pop() {
    int result = peek();
	newStack.pop();
	return result;
  }
  
  int peek() {
    while (!oldStack.empty()) {
	  newStack.push(oldStack.top());
	  oldStack.pop();
	}
	return newStack.top();
  }
  
  bool empty() {
    return oldStack.empty() && newStack.empty();
  }
};
