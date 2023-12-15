// 104. Maximum Depth of Binary Tree

// 1.DFS
int maxDepth(TreeNode* root) {
  if (root == NULL) return 0;
  return max(maxDepth(root->left), maxDepth(root->right)) + 1; 
}

// 2.BFS
int maxDepth(TreeNode* root) {
  if (root == NULL) return 0;
  int depth = 0;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    depth++;
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* n = q.front();
      q.pop();
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
  }
  return depth;
}
