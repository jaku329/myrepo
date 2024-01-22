// 124. Binary Tree Maximum Path Sum

int dfs(TreeNode* root, int& sum) {
  int sumL = -1001, sumR = -1001;
  if (root->left) sumL = dfs(root->left, sum);
  if (root->right) sumR = dfs(root->right, sum);
  int sumOfReturn = max(root->val, max(root->val + sumL, root->val + sumR));
  sum = max(sum, max(root->val + sumL + sumR, sumOfReturn));
  return sumOfReturn;
}

int maxPathSum(TreeNode* root) {
  int sum = -1001;
  if (root)
    dfs(root, sum);
  else
    return 0;
  return sum;
}
