// 662. Maximum Width of Binary Tree

// [1] should be 1
int maxWidthBT(TreeNode* root) {
  int width = 0;
  queue<pair<TreeNode*, int>> q;
  if (root)
    q.push({root, 1});
  while (!q.empty()) {
    int size = q.size();
    int lId;
    for (int i = 0; i < size; ++i) {
      int id = q.front().second;
      TreeNode* n = q.front().first;
      q.pop();
      if (n->left) q.push({n->left, id * 2});
      if (n->right) q.push({n->right, id * 2 + 1});

      if (i == 0) lId = id;
      if (i == size - 1) {
        width = max(width, id - lId + 1);
      }
    }
  }
  return width;
}
