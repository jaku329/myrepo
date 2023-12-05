// https://leetcode.com/problems/maximum-width-of-binary-tree/


int widthOfBinaryTree(TreeNode* root) {
  queue<pair<TreeNode*, unsigned int>> q;
  int maxWidth = 1;
  if (root == NULL) return 0;
  q.push({root, 1});
  while(!q.empty()) {
    int size = q.size();
    unsigned int l = 0, r = 0;
    for (int i = 0; i < size; ++i) {
      TreeNode* n = q.front().first;
      unsigned int id = q.front().second;
      q.pop();
      if (i == 0) l = id;
      if (i == size - 1) r = id;

      if (n->left) {
        q.push({n->left, id * 2});
      }
      
      if (n->right) {
        q.push({n->right, id * 2 + 1});
      }
    }
    maxWidth = max(maxWidth, (int)(r - l + 1));
  }
  return maxWidth;
}
