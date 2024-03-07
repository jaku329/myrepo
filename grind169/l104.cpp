// 104. Maximum Depth of Binary Tree

// 1. BFS

// 2. DFS
int maxDepth(TreeNode* root) {
  if (root == NULL) return 0;
  return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
