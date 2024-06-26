// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    int profit = 0;
    int min = prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > min) 
        profit = profit > prices[i] - min ? profit : prices[i] - min;
      else
        min = prices[i];
    }
    return profit;
  }
};

// DP
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
  }
};
