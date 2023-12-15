// 226. Invert Binary Tree

TreeNode* invertTree(TreeNode* root) {
  if (root == NULL) return NULL;
  TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;
  invert(root->left);
  invert(root->right);
  return root;  
}
