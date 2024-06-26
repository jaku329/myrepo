// 226. Invert Binary Tree

// DFS
TreeNode* invertTree(TreeNode* root) {
  if (root == NULL) return root;
  TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  invertTree(root->left);
  invertTree(root->right);
  return root;
}
