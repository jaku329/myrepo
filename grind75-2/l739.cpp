// 739. Daily Temperatures

vector<int> dailyTemperatures(vector<vector<int>>& temperatures) {
  vector<int> result(temperatures.size(), 0);
  if (temperatures.size() == 0) return result;
  
  stack<int> st;
  result[temperatures.size() - 1] = 0;
  st.push(temperatures.size() - 1);
  for (int i = temperatures.size() - 2; i >= 0; --i) {
    while (!st.empty() && temperatures[st.top()] <= temperatures[i])
      st.pop();

    if (st.empty())
      result[i] = 0;
    else
      result[i] = st.top() - i; 
    st.push(i);
  }
  return result;
}
