// 844. Backspace String Compare

// stack, O(s/t);O(s+t)
bool backspaceCompare(string s, string t) {
  stack<char> st1;
  stack<char> st2;

  for (auto c : s)
    if (c != '#')
      st1.push(c);
    else if (!st1.empty())
      st1.pop();

  for (auto c : t)
    if (c != '#')
      st2.push(c);
    else if (!st2.empty())
      st2.pop();

  if (st1.size() != st2.size()) return false;
  while (!st1.empty()) {
    if (st1.top() != st2.top()) return false;
    st1.pop();
    st2.pop();
  }
  return true;
}

// TODO: below code NG
// two pointer, O(s/t);O(1)
bool backspaceCompare(string s, string t) {
  int i = s.size() - 1;
  int j = t.size() - 1;
  while (i >= 0 && j >= 0) {
    int cnt = 0;
    if (s[i] == '#') cnt++;
    while (i >= 0 && cnt > 0) {
      if (s[i] == '#') cnt++;
      else
        cnt--;
      i--;
    }
    cnt = 0;
    if (t[j] == '#') cnt++;
    while (j >= 0 && cnt > 0) {
      if (s[j] == '#') cnt++;
      else
        cnt--;
      j--;
    }

    if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
    else if (i < 0) return false;
    else if (j < 0) return false;
    else // i < 0 && j < 0
      return true;
    i--;
    j--;
  }
  return true;
}
