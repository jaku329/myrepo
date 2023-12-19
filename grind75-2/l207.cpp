// 207. Course Schedule

// topology sort, O(N)
bool canFinished(int numCourses, vector<vector<int>>& prerequisites) {
  vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
  vector<int> counts(numCourses, 0);
  for (int i = 0; i < prerequisites.size(); ++i) {
    graph[prerequisites[i][1]].insert(prerequisites[i][0]);
  }

  stack<int> zeroCnt;
  for (int i = 0; i < graph.size(); ++i) {
    if (graph[i].size() == 0)
      zeroCnt.push(i);
    else
      counts[i] = graph[i].size();
  }
  while (!zeroCnt.empty()) {
    int course = zeroCnt.top();
    zeroCnt.pop();
    for (int i = 0; i < graph.size(); ++i) {
      if (graph[i].size() == 0)
        continue;
      if (graph[i].count(course) > 0) {
        graph[i].erase(course);
        counts[i]--;
        if (counts[i] == 0)
          zeroCnt.push(i);
      }
    }
  }
  for (auto cnt : counts)
    if (cnt > 0)
      return false;
  return true;
}


// 2. dfs: TLE
bool hasCircle(vector<vector<int>>& graph, int i, vector<bool>& visited) {
  if (visited[i]) return true;

  visited[i] = true;
  for (int j = 0; j < graph[i].size(); ++j) {
    if (visited[graph[i][j]])
      return true;
    if (hasCircle(graph, graph[i][j], visited))
      return true;
  }
  visited[i] = false;
  return false;
}

bool canFinished(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> graph(numCourses, vector<int>());
  for (int i = 0; i < prerequisites.size(); ++i) {
    graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
  }
  vector<bool> visited(numCourses, false);
  for (int i = 0; i < numCourses; ++i) {
    if (hasCircle(graph, i, visited)) return false;
  }
  return true;
}

// 3. DFS optimize
bool hasCircle(vector<vector<int>>& graph, int i, vector<bool>& visited, vector<bool>& finished) {
  if (visited[i]) return true;

  finished[i] = true;

  visited[i] = true;
  for (int j = 0; j < graph[i].size(); ++j) {
    if (visited[graph[i][j]])
      return true;
    if (finished[graph[i][j]])
      continue;
    if (hasCircle(graph, graph[i][j], visited, finished))
      return true;
  }
  visited[i] = false;
  return false;
}

bool canFinished(int numCourses, vector<vector<int>>& prerequisites) {
  vector<vector<int>> graph(numCourses, vector<int>());
  for (int i = 0; i < prerequisites.size(); ++i) {
    graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
  }
  vector<bool> finished(numCourses, false);
  vector<bool> visited(numCourses, false);
  for (int i = 0; i < numCourses; ++i) {
    if (hasCircle(graph, i, visited, finished)) return false;
  }
  return true;
}
