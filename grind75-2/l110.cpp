// 110. Balanced Binary Tree

int dfs(TreeNode* root) {
  if (root == NULL) return 0;
  
  int lHeight = dfs(root->left);
  int rHeight = dfs(root->right);

  if (lHeight < 0 || rHeight < 0) return -1;
  
  if (abs(lHeight - rHeight) > 1) return -1;

  return 1 + (lHeight > rHeight ? lHeight : rHeight);
}

bool isBalanced(TreeNode* root) {
  if (dfs(root) < 0) return false;
  return true;
}
