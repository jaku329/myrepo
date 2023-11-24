// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> idxStack;
    vector<int> result(temperatures.size(), 0);

    idxStack.push(temperatures.size() - 1);
    for (int i = temperatures.size() - 2; i >= 0; --i) {
      while (!idxStack.empty() && temperatures[idxStack.top()] < temperatures[i])
        idxStack.pop();

      if (!idxStack.empty())
        result[i] = idxStack.top() - i;
      else 
        result[i] = 0;
      idxStack.push(i);
    }
  
    return result;
  }
};
