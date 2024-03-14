// 235. Lowest Common Ancestor of a Binary Search Tree

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == NULL || p == NULL || q == NULL) return NULL;
  else if (root == p || root == q) return root;
  
  if (root->val < p->val && root->val < q->val)
    return lowestCommonAncestor(root->right, p, q);
  else if (root->val > p->val && root->val > q->val)
    return lowestCommonAncestor(root->left, p, q);
  return root;
}
