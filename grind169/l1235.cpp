// 1235. Maximum Profit in Job Scheduling

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DFS: TLE
void dfs(vector<int>& start, vector<pair<int, int>>& sortedEnd, vector<int>& profit, int picked, int curProfit, int& maxProfit) {
  maxProfit = max(maxProfit, curProfit);
  
  for (int i = picked + 1; i < sortedEnd.size(); ++i) {
    if (start[sortedEnd[i].second] >= sortedEnd[picked].first)
      dfs(start, sortedEnd, profit, i, curProfit + profit[sortedEnd[i].second], maxProfit);
  }
}

int jobScheduling2(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
  vector<pair<int, int>> sortedEnd;
  for (int i = 0; i < endTime.size(); ++i)
    sortedEnd.push_back({endTime[i], i});
  sort(sortedEnd.begin(), sortedEnd.end());
  int maxProfit = 0, curProfit = 0;
  for (int i = 0; i < sortedEnd.size(); ++i) {
    dfs(startTime, sortedEnd, profit, i, curProfit + profit[sortedEnd[i].second], maxProfit);
  }
  return maxProfit;
}

// DP
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
  vector<pair<int, int>> sortedEnd;
  for (int i = 0; i < endTime.size(); ++i)
    sortedEnd.push_back({endTime[i], i});
  sort(sortedEnd.begin(), sortedEnd.end());

  vector<int> nearestNonConflict(sortedEnd.size(), 0);
  for (int i = sortedEnd.size(); i > 0; --i) {
    nearestNonConflict[i] = i;
    for (int j = i - 1; j >= 0; --j) {
      if (sortedEnd[j].first <= startTime[sortedEnd[i].second])
        nearestNonConflict[i] = j;
    }
  }

  vector<int> dp(sortedEnd.size(), 0);
  dp[0] = profit[sortedEnd[0].second];
  for (int i = 1; i < sortedEnd.size(); ++i) {
    int curIdx = sortedEnd[i].second;
    dp[i] = dp[nearestNonConflict[i]] + profit[curIdx];
  }

  return dp[sortedEnd.size() - 1];
}

int main() {
  vector<int> startTime = {
    1,2,3,3
  };
  vector<int> endTime = {
    3,4,5,6
  };
  vector<int> profit = {
    50,10,40,70
  };

  cout << jobScheduling(startTime, endTime, profit) << endl;
}
