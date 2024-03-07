// 235. Lowest Common Ancestor of a Binary Search Tree

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == NULL) return NULL;
  else if (root == p || root == q) return root;

  TreeNode* lChild = lowestCommonAncestor(root->left, p, q);
  TreeNode* rChild = lowestCommonAncestor(root->right, p, q);
  if (lChild && rChild) return root;
  else if (lChild) return lChild;
  else if (rChild) return rChild;
  return NULL;
}
