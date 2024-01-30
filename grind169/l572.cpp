// 572. Subtree of Another Tree

bool dfs(TreeNode* t1, TreeNode* t2) {
  if (t1 == NULL && t2 == NULL) return true;
  if (t1 == NULL || t2 == NULL) return false;
  else if (t1->val != t2->val) return false;
  return dfs(t1->left, t2->left) && dfs(t1->right, t2->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  if (root == NULL || subRoot == NULL) return false;

  if (root->val == subRoot->val) {
    if (dfs(root, subRoot)) return true;
  }

  return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
