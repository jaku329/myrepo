// 91. Decode Ways
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// "1123"
//  123
// Wrong!
int numDecodings(string s) {
  if (s.size() == 0) return 0;
  else if (s[0] == '0') return 0;
  else if (s.size() == 1) return 1;
  vector<int> dp(s.size(), 0);
  dp[0] = 1;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] == '0') {
      if (s[i - 1] <= '2' && s[i - 1] > '0') {
        if (i > 1)
          dp[i] = dp[i - 2];
        else
          dp[i] = dp[i - 1];
      }
      else
        return 0;
    }
    else {
      if (s[i - 1] == '0') {
        dp[i] = dp[i - 1];
      }
      else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
        if (i > 1)
          dp[i] = dp[i - 1] + dp[i - 2];
        else 
          dp[i] = dp[i - 1] + 1;
      }
      else {
        dp[i] = dp[i - 1];
      }
    }
  }
  return dp[s.size() - 1];
} 

int main() {
  cout << numDecodings("12") << endl;
  cout << numDecodings("226") << endl;
  cout << numDecodings("1123") << endl;
  return 0;
}
