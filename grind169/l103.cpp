// 103. Binary Tree Zigzag Level Order Traversal

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  queue<TreeNode*> q;
  vector<vector<int>> result;
  if (root)
    q.push(root);
  int level = 0;
  while (!q.empty()) {
    level++;
    int size = q.size();
    vector<int> zigzag;
    for (int i = 0; i < size; ++i) {
      TreeNode* n = q.front();
      q.pop();
      zigzag.push_back(n->val);
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
    if ((level & 0x1) == 0) 
      reverse(zigzag.begin(), zigzag.end());
    result.push_back(zigzag);
  }
  return result;
}
