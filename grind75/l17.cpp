// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  void dfs(vector<string>& strMap, string digits, int pos, vector<string>& result, string picks) {
    if (pos == digits.size()) {
      result.push_back(picks);
    }
    else {
      if (digits[pos] == '0' || digits[pos] == '1') 
        dfs(strMap, digits, pos + 1, result, picks);
      else
        for (int i = 0; i < strMap[digits[pos] - '0'].size(); ++i) {
          dfs(strMap, digits, pos + 1, result, picks + strMap[digits[pos] - '0'][i]);
        }
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> strMap = {
      "",
      "",
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz"
    };
    vector<string> result;
    if (digits.size() == 0) return result;
    string s;
    dfs(strMap, digits, 0, result, s);
    return result;
  }
};

int main() {
  Solution sol;
  auto v = sol.letterCombinations("23");
  cout << v.size() << endl;
  for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << endl;
  return 0;
}
