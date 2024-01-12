// 261

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 1. dfs
bool dfs(vector<vector<int>>& graph, int i, vector<bool>& visited, unordered_set<int>& finished) {
  if (finished.count(i) > 0) { 
    cout << "loop!" << endl;
    return false;
  }

  finished.insert(i);

  visited[i] = true;
  for (int j = 0; j < graph[i].size(); ++j) {
    if (!visited[graph[i][j]])
      if (!dfs(graph, graph[i][j], visited, finished))
        return false;
  }
  visited[i] = false;

  return true;
}

bool validTree(int n, vector<vector<int>>& edges) {
  vector<vector<int>> graph(n, vector<int>());
  for (auto e : edges) {
    graph[e[0]].push_back(e[1]);
    graph[e[1]].push_back(e[0]);
  }
  vector<bool> visited(n, false);
  unordered_set<int> finished;
  if (!dfs(graph, 0, visited, finished))
    return false;
  if (finished.size() < n )
    return false;
  return true;
}

// 2. disjoint set (DA)
int findRoot(vector<int>& parent, int child) {
  int c = child;
  while (parent[c] >= 0) 
    c = parent[c];
  if (child != c)
    parent[child] = c;
  return c;
}
bool unite(vector<int>& parent, int x, int y) {
  int rX = findRoot(parent, x);
  int rY = findRoot(parent, y);
  if (rX == rY) return false;
  if (rX > rY)
    parent[x] = rY;
  else
    parent[y] = rX;
  return true;
}
bool validTree2(int n, vector<vector<int>>& edges) {
  vector<int> parent(n, -1);
  for (auto edge : edges) {
    if (!unite(parent, edge[0], edge[1]))
      return false;
  }
  return true;
}

int main() {
  vector<vector<int>> edges = {
   {0, 1}, {0, 2}, {0, 3}, {1, 4}
//   {0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}
  };

  cout << validTree(5, edges) << endl;

  cout << validTree2(5, edges) << endl;

  return 0;
}
