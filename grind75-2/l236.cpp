// 236. Lowest Common Ancestor of a Binary Tree

//
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode q) {
  if (root == NULL) return NULL;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);
  
  if (left && right) return root;
  else if (root == p || root == q) return root;
  else if (left) return left;
  else if (right) return right;
  return NULL;
}

