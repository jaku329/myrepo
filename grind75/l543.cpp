// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution {
public:
  int diameter = 0;

  int postOrder(TreeNode* root) {
    if (root == NULL) return 0;
    int dl = postOrder(root->left);
    int dr = postOrder(root->right);
    diameter = dl + dr > diameter ? dl + dr : diameter;
    if (dl > dr) return dl + 1;
    return dr + 1;
  }
  
  int diameterOfBinaryTree(TreeNode* root) {
    postOrder(root);
    return diameter;
  }
};
