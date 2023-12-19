// 102. Binary Tree Level Order Traversal

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> result;
  queue<TreeNode*> q;
  if (root)
    q.push(root);
  while (!q.empty()) {
    int size = q.size();
    vector<int> level;
    for (int i = 0; i < size; ++i) {
      TreeNode* n = q.front();
      q.pop();
      level.push_back(n->val);
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
    result.push_back(level);
  }
  return result;  
}
