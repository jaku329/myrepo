// 17. Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// dfs
void dfs(string digits, int pos, vector<string>& charMap, vector<string>& result, string s) {
  if (pos == digits.size()) {
    result.push_back(s);
    return;
  }

  int charIdx = digits[pos] - '0';
  for (int i = 0; i < charMap[charIdx].size(); ++i) {
    dfs(digits, pos + 1, charMap, result, s + charMap[charIdx][i]);
  }
}
vector<string> lettersCombinations(string digits) {
  vector<string> charMap = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
  };
  vector<string> result;
  dfs(digits, 0, charMap, result, "");
  return result;
}

int main() {
  auto r = lettersCombinations("2");
  for (auto s : r)
    cout << s << " ";
  cout << endl;
  return 0;
}
