// https://leetcode.com/problems/course-schedule-ii/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
// topology sort
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> path;
  vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
  for (int i = 0; i < prerequisites.size(); ++i) {
    graph[prerequisites[i][0]].insert(prerequisites[i][1]);
  }

  bool HasZero = false;
  vector<int> counts(numCourses, 0);
  for (int i = 0; i < graph.size(); ++i) {
    counts[i] = graph[i].size();
    if (counts[i] == 0) HasZero = true;
  }

  while (HasZero) {
    HasZero = false;
    for (int i = 0; i < counts.size(); ++i) {
      if (counts[i] == 0) {
        path.push_back(i);
        for (int j = 0; j < graph.size(); ++j) {
          if (graph[j].count(i) > 0) {
            graph[j].erase(i);
            counts[j]--;
            if (counts[j] == 0) HasZero = true;
          }
        }
        counts[i] = -1;
      }
    }
  }

  if (path.size() < numCourses) return vector<int>();

  return path;
}

// topology sort 2
vector<int> findOrder2(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> path;
  vector<int> counts(numCourses, 0);
  vector<unordered_set<int>> graph(numCourses, unordered_set<int>());
  for (int i = 0; i < prerequisites.size(); ++i) {
    graph[prerequisites[i][0]].insert(prerequisites[i][1]);
    counts[prerequisites[i][0]]++;
  }

  unordered_set<int> zeroSet;
  for (int i = 0; i < counts.size(); ++i) {
    if (counts[i] == 0) {
      zeroSet.insert(i);
    }
  }

  while (zeroSet.size() > 0) {
    auto it = zeroSet.begin();
    path.push_back(*it);
    for (int i = 0; i < graph.size(); ++i) {
      if (graph[i].count(*it) > 0) {
        counts[i]--;
        if (counts[i] == 0) zeroSet.insert(i);
      }
    }
    zeroSet.erase(*it);
  }

  if (path.size() < numCourses) return vector<int>();
  return path;
}


// DFS (postorder)
bool dfs(vector<vector<int>>& graph, int course, vector<int>& path, vector<bool>& finished, vector<bool>& visited) {
  if (finished[course]) return false;
  finished[course] = true;

//  path.push_back(course);
  for (int i = 0; i < graph[course].size(); ++i) {
    if (!visited[graph[course][i]]) {
      visited[graph[course][i]] = true;
      if (dfs(graph, graph[course][i], path, finished, visited)) return true;
      visited[graph[course][i]] = false;
    }
    else return true;
  }
  path.push_back(course);

  return false;
}

vector<int> findOrder3(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> path;
  vector<vector<int>> graph(numCourses, vector<int>());
  for (int i = 0; i < prerequisites.size(); ++i) {
    graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
  }
  vector<bool> finished(numCourses, false);
  vector<bool> visited(numCourses, false);
  for (int i = 0; i < graph.size(); ++i) {
    if (!finished[i]) {
      visited[i] = true;
      if (dfs(graph, i, path, finished, visited)) return vector<int> ();
      visited[i] = false;
    }
  }
  return path;
}

int main() {
  vector<vector<int>> pre = {
    {0,1}
  };
  auto r = findOrder3(2, pre);
  for (auto c : r)
    cout << c << " " << endl; 
  return 0;
}
