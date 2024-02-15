// 863. All Nodes Distance K in Binary Tree

// 1. build up undirected graph + BFS
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  vector<int> result;
  if (k == 0) {
    result.push_back(target->val);
    return result;
  }
  else if (root == target) {
    // just BFS, no need to build up graph
  }

  unordered_map<int, vector<int>> graph;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* n = q.front();
    q.pop();
    if (graph.count(n->val) == 0)
      graph[n->val] = vector<int>();
    if (n->left) {
      q.push(n->left);
      graph[n->val].push_back(n->left->val);
      graph[n->left->val].push_back(n->val);
    }
    if (n->right) {
      q.push(n->right);
      graph[n->val].push_back(n->right->val);
      graph[n->right->val].push_back(n->val);
    }
  }

  queue<int> que;
  que.push(target->val);
  unordered_set<int> visited;
  visited.insert(target->val);
  while (!que.empty()) {
    int size = que.size();
    for (int i = 0; i < size; ++i) {
      int n = que.front();
      que.pop();
      if (k == 0)
        result.push_back(n);
      else
        for (auto child : graph[n])
          if (visited.count(child) == 0) {
            que.push(child);
            visited.insert(child);
          }
    }
    k--;
  }

  return result;
}

// 2. my solution
void levelK(TreeNode* target, int k, vector<int>& result) {
  queue<TreeNode*> q;
  q.push(target);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* n = q.front();
      q.pop();
      if (k == 0)
        result.push_back(n->val);
      else {
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
    }
    k--;
  }
}
int dfs(TreeNode* root, TreeNode* target, int k, vector<int>& result) {
  if (root == target) return -k;
  else if (root == NULL) return 0;

  int depthL = dfs(root->left, target, k, result);
  int depthR = dfs(root->right, target, k, result);

  if (depthL == -1 || depthR == -1) {
    result.push_back(root->val);
    return max(depthL, depthR) + 1;
  }
  else if (depthL >= 0 && depthR >= 0)
    return max(depthL, depthR) + 1;

  if (depthR + depthL >= -1) {
    if (depthL < 0)
      levelK(root->right, abs(depthL) - 2, result);
    else if (depthR < 0)
      levelK(root->left, abs(depthR) - 2, result);
  }

  return (depthL < 0 ? depthL : depthR) + 1;
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
  vector<int> result;
  if (k == 0) {
    result.push_back(target->val);
    return result;
  }
  else if (root != target) {
    // collect from parent node
    dfs(root, target, k, result);
  }

  // collect from children node
  levelK(target, k, result);

  return result;
}
