// 121. Best Time to Buy and Sell Stock

// 1. brute force, O(n^2), O(1)

// 2. mono stack, O(n), O(n)

// 3. dp, O(n);O(n) -> O(n);O(1)
int maxProfit(vector<int>& prices) {
  if (prices.size() <= 1) return 0;

  int profit = 0;
  int minPrice = prices[0];

  for (int i = 1; i < prices.size(); ++i) {
    profit = max(profit, prices[i] - minPrice);
    minPrice = min(minPrice, prices[i]);
  }

  return profit;
}
