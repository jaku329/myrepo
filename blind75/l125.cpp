// https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.size() <= 1) return true;
    int l = 0, r = s.size() - 1;

    char caseBit = 'a' - 'A';
    while (l < r) {
      while (l < r && ((s[l] | caseBit) < 'a' || (s[l] | caseBit) > 'z') && (s[l] < '0' || s[l] > '9'))
        l++;
      while (l < r && ((s[r] | caseBit) < 'a' || (s[r] | caseBit) > 'z') && (s[r] < '0' || s[r] > '9')) {
        r--;
      }
      if ((s[l] | caseBit) != (s[r] | caseBit)) return false;
 
      l++;
      r--;
    }
    return true;
  }
};

int main() {
  string str = "0P";
  Solution s;
  cout << str << endl;
  cout << s.isPalindrome(str) << endl;
}
