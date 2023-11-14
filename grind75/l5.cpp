// https://leetcode.com/problems/longest-palindromic-substring/description/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lenOfPalindrome(string s, int l, int r) {
    int len = r - l + 1;
    int start, end;
    for (int i = l; i < r; ++i) {
      start = i;
      end = r;
      while (start < end && s[start] == s[end]) {
        start++;
        end--;
      }
      if (start >= end) return len;
      len--;
    }
    return 1;
  }

  string longestPalindrome(string s) {
    if (s.size() <= 1) return s;
    int maxLen = 1;
    int maxL = 0;
    vector<int> dp(s.size(), 1);
    for (int i = 1; i < s.size(); ++i) {
      cout << i << ": " ;
      dp[i] = lenOfPalindrome(s, 0, i);
      cout << dp[i] << endl;
      if (dp[i] > maxLen) {
        maxLen = dp[i];
        maxL = i + 1 - maxLen;
      }
    }
    return s.substr(maxL, maxLen);
  }
};

// optimizing Solution1
class Solution2 {
public:
  int lenOfPalindrome(string s, int l, int r) {
    int len = r - l + 1;
    int start, end;
    for (int i = l; i < r; ++i) {
      start = i;
      end = r;
      while (start < end && s[start] == s[end]) {
        start++;
        end--;
      }
      if (start >= end) return len;
      len--;
    }
    return 1;
  }

  string longestPalindrome(string s) {
    if (s.size() <= 1) return s;
    int maxLen = 1;
    int maxL = 0;
    vector<int> dp(s.size(), 1);
    for (int i = 1; i < s.size(); ++i) {
      if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == s[i])
        dp[i] = dp[i - 1] + 2;
      else
        dp[i] = lenOfPalindrome(s, i - dp[i - 1], i);
      if (dp[i] > maxLen) {
        maxLen = dp[i];
        maxL = i + 1 - maxLen;
      }
    }
    return s.substr(maxL, maxLen);
  }

};

int main() {
  Solution2 s;
  cout << s.longestPalindrome("babad") << endl;
  return 0;
}
