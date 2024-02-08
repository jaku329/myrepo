// 437. Path Sum III

// DFS + prefix sum
void dfs(TreeNode* root, int targetSum, unordered_map<long, int>& umap, long sum, int& cnt) {
  if (umap.count(sum - targetSum) > 0) cnt += umap[sum - targetSum];

  umap[sum]++;
  if (root->left) 
    dfs(root->left, targetSum, umap, sum + root->left->val, cnt);
  if (root->right ) 
    dfs(root->right, targetSum, umap, sum + root->right->val, cnt);
  umap[sum]--;
}

int pathSum(TreeNode* root, int targetSum) {
  if (root == NULL) return 0;
  int cnt = 0;
  unordered_map<long, int> umap;
  umap[0] = 1;
  dfs(root, targetSum, umap, root->val, cnt);
  return cnt;
}
