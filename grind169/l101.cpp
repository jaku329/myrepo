// 101. Symmetric Tree

bool isSymmetric(TreeNode* left, TreeNode* right) {
  if (left == NULL && right == NULL) return true;
  else if (left && right == NULL) return false;
  else if (right && left == NULL) return false;
  else if (left->val != right->val) return false;

  return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
  if (root == NULL) return true;
  return isSymmetric(root->left, root->right);
}

// 1,2,2,null,3,null,3
