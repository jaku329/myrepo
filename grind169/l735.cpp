// 735. Asteroid Collision

vector<int> asteroidCollision(vector<int>& asteroids) {
  stack<int> st;
  for (auto asteroid : asteroids) {
    if (st.empty() || asteroid > 0)
      st.push(asteroid);
    else { // asteroid is negative
      while (!st.empty() && st.top() > 0 && st.top() < abs(asteroid))
        st.pop();
      if (st.empty() || st.top() < 0)
        st.push(asteroid);
      else if (st.top() == abs(asteroid))
        st.pop();
    }
  }
  vector<int> result;
  while (!st.empty()) {
    result.push_back(st.top());
    st.pop();
  }
  reverse(result.begin(), result.end());
  return result;
}
