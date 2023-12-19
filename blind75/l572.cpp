// https://leetcode.com/problems/subtree-of-another-tree


// Not optimal solution
class Solution {
public:
  bool sameTree(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return true;
    else if (t1 == NULL) return false;
    else if (t2 == NULL) return false;
    else if (t1->val != t2->val) return false;

    return (sameTree(t1->left, t2->left) & sameTree(t1->right, t2->right));
  }

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (subRoot == NULL) return true;
    if (root == NULL) return false;
    if (root == NULL && subRoot == NULL) return true;
    
    if (root->val == subRoot->val)
      if (sameTree(root, subRoot)) return true;

    if (root->left)
      if (isSubtree(root->left, subRoot)) return true;

    if (root->right)
      if (isSubtree(root->right, subRoot)) return true;

    return false;
  }
};
