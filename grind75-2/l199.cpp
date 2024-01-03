// 199. Binary Tree Right Side View

vector<int> rightSideView(TreeNode* root) {
  vector<int> result;
  queue<TreeNode*> q;
  if (root) q.push(root);
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* n = q.front();
      q.pop();
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
      if (i == size - 1)
        result.push_back(n->val);
    }
  }
  return result;
}
