// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* n = q.front();
        q.pop();

        if (i == size - 1)
          result.push_back(n->val);

        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
    }
    return result;
  }
};
