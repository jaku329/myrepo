// 210. Course Schedule II

// 1. backtrack: faster than topology sort.
bool dfs(vector<vector<int>>& graph, int i, vector<int>& path, unordered_set<int>& finished, vector<bool>& visited) {
  if (visited[i]) // has cycle
    return false;

  if (finished.count(i) > 0)
    return true;

  visited[i] = true;
  for (int j = 0; j < graph[i].size(); ++j) {
    if (!dfs(graph, graph[i][j], path, finished, visited))
      return false;
  }
  visited[i] = false;
  path.push_back(i);
  finished.insert(i);
  if (finished.size() == graph.size()) {
    return true;
  }
  return true;
}

// 
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> graph(numCourses, vector<int>());
  for (int i = 0; i < prerequisites.size(); ++i)
    graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
  unordered_set<int> finished;
  vector<bool> visited(graph.size(), false);
  vector<int> path;
  for (int i = 0; i < graph.size(); ++i) {
    if (!dfs(graph, i, path, finished, visited))
      return vector<int>();
  }
  return path;
}

// 2. topology sort, slow 125ms
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
  for (int i = 0; i < prerequisites.size(); ++i)
    graph[prerequisites[i][0]].insert(prerequisites[i][1]);

  vector<int> counts(graph.size(), 0);
  queue<int> zeroQ;
  for (int i = 0; i < graph.size(); ++i) {
    counts[i] = graph[i].size();
    if (counts[i] == 0)
      zeroQ.push(i);
  }

  vector<int> path;
  while (!zeroQ.empty()) {
    int i = zeroQ.front();
    zeroQ.pop();
    path.push_back(i);
    for (int j = 0; j < graph.size(); ++j)
      if (graph[j].count(i) > 0) {
        counts[j]--;
        if (counts[j] == 0) 
          zeroQ.push(j);
      }
  }
  for (int j = 0; j < counts.size(); ++j)
    if (counts[j] > 0)
      return vector<int>();
  return path;
}
