// https://leetcode.com/problems/path-sum-ii/

void dfs(TreeNode* root, int targetSum, vector<vector<int>>& result, vector<int>& path) {
  if (root->left == NULL && root->right ==NULL) {
    if (targetSum == 0) {
      result.push_back(path);
    }
    return;
  }

  if (root->left) {
    path.push_back(root->left->val);
    dfs(root->left, targetSum - root->left->val, result, path);
    path.pop_back();
  }

  if (root->right) {
    path.push_back(root->right->val);
    dfs(root->right, targetSum - root->right->val, result, path);
    path.pop_back();
  }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
  vector<vector<int>> result;
  if (root == NULL) return result;

  vector<int> path;
  path.push_back(root->val);
  dfs(root, targetSum - root->val, result, path);
  return result;
}
