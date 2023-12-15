// 543. Diameter of Binary Tree

int dfs(TreeNode* root, int& diameter) {
  if (root == NULL) return 0;
  int distL = dfs(root->left, diameter);
  int distR = dfs(root->right, diameter);

  diameter = max(diameter, distL + distR);
  
  return max(distL, distR) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
  int diameter = 0;
  dfs(root, diameter);
  return diameter;
}
