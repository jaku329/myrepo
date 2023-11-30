// 

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// disjoint set
int findRoot(vector<int>& parent, int node) {
  // optimal 1: find root + compress the tree hight
  int c = node;

  while(parent[c] != -1) c = parent[c];
 
  if (parent[node] != -1)
    parent[node] = c;

  return c;
}

bool unionNodes(vector<int>& parent, int x, int y) {
  int rootX = findRoot(parent, x);
  int rootY = findRoot(parent, y);
  if (rootX == rootY) return false; // the same group means circular!

  if (rootX > rootY) parent[x] = rootY;
  else parent[y] = rootX;
  return true;
}

bool validTree2(int n, vector<vector<int>>& edges) {
  // optimal 2: using rank of height
  vector<int> rank(n, 1);

  vector<int> parent(n, -1);
  for (int i = 0; i < edges.size(); ++i) {
    if (!unionNodes(parent, edges[i][0], edges[i][1])) return false;
  }
  return true;
}


// dfs
// true means circular
bool dfs(vector<unordered_set<int>>& graph, vector<bool>& visited, int vertex, unordered_set<int>& path) {
  if (path.count(vertex) > 0) return true;

  cout << vertex << endl;
  path.insert(vertex);
  for (auto it = graph[vertex].begin(); it != graph[vertex].end(); it++) {
    if (visited[*it]) continue;
    visited[*it] = true;
    if (dfs(graph, visited, *it, path)) return true;
    visited[*it] = false;
  }

  return false;
}

bool validTree(int n, vector<vector<int>>& edges) {
  vector<unordered_set<int>> graph(n, unordered_set<int>());
  for (int i = 0; i < edges.size(); ++i) {
    graph[edges[i][0]].insert(edges[i][1]);
    graph[edges[i][1]].insert(edges[i][0]);
  }

  vector<bool> visited(n, false);
  unordered_set<int> path;
  visited[0] = true;
  if (dfs(graph, visited, 0, path)) return false;

  return true;
}

int main() {
  vector<vector<int>> edges = {
//   {0, 1}, {0, 2}, {0, 3}, {1, 4}
   {0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}
  };

  cout << validTree(5, edges) << endl;

  cout << validTree2(5, edges) << endl;

  return 0;
}
