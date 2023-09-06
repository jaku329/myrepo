// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

class Solution {
  TreeNode* dfs(TreeNode* root, TreeNode* left, TreeNode* right) {
    if (root == NULL) return NULL;

    if (root->val >= left->val && root->val <= right->val) return root;

    TreeNode* tmp = NULL;
    if (root->val > right->val) tmp = lowestCommonAncestor(root->left, left, right);
    else if (root->val < left->val) tmp = lowestCommonAncestor(root->right, left, right);

    return tmp;
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < q->val) return dfs(root, p, q);
    return dfs(root, q, p);
  }
};
