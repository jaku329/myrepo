// 787. Cheapest Flights Within K Stops

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <queue>
using namespace std;

// BFS + priority queue (Dijkstra): TLE
class Compare {
public:
  bool operator () (const vector<int>& down, const vector<int>& top) {
    return top[0] < down[0];
  }
};
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
  vector<unordered_map<int, int>> graph(n, unordered_map<int, int>());
  for (int i = 0; i < flights.size(); ++i) {
    graph[flights[i][0]][flights[i][1]] = flights[i][2];
  }
  priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
  pq.push({0, src, k});
  while (!pq.empty()) {
    vector<int> triple = pq.top();
    pq.pop();
    if (triple[1] == dst)
      return triple[0];
    else if (triple[2] < 0)
      continue;
    for (auto it = graph[triple[1]].begin(); it != graph[triple[1]].end(); ++it) {
      pq.push({triple[0] + graph[triple[1]][it->first], it->first, triple[2] - 1});
    }
  }
  return -1;
}

// dfs: TLE
void dfs(vector<unordered_map<int, int>>& graph, int src, int dst, int k, vector<bool>& visited, int price, int& minPrice) {
  if (src == dst) {
    minPrice = min(minPrice, price);
    return;
  }
  else if (k < 0) {
    return;
  }
  else if (visited[src])
    return;

  visited[src] = true;
  for (auto it = graph[src].begin(); it != graph[src].end(); ++it) {
    dfs(graph, it->first, dst, k - 1, visited, price + it->second, minPrice);
  }
  visited[src] = false;
}

int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k) {
  vector<unordered_map<int, int>> graph(n, unordered_map<int, int>());
  for (int i = 0; i < flights.size(); ++i) {
    graph[flights[i][0]][flights[i][1]] = flights[i][2];
  }
  vector<bool> visited(graph.size(), false);
  int price = 0;
  int minPrice = INT_MAX;
  dfs(graph, src, dst, k, visited, price, minPrice);
  if (minPrice == INT_MAX) return -1;
  return minPrice;
}

int main() {
  vector<vector<int>> flights = {
//    {0,1,100},{1,2,100},{0,2,500}
//    {0,1,2},{1,2,1},{2,0,10}
    {0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}
  };
  int n = 5;
  int src = 0;
  int dst = 2;
  int k = 2;
  cout << findCheapestPrice(n, flights, src, dst, k) << endl;
  return 0;
}
