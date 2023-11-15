// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, int pL, int pR, vector<int>& inorder, int iL, int iR) {
    if (pL > pR || iL > iR) return NULL;

    TreeNode* root = new TreeNode();
    root->val = preorder[pL];
    if (pL == pR) return root;

    int i;
    for (i = iL; i <= iR; ++i) {
      if (inorder[i] == preorder[pL]) break;
    }
    
    root->left = buildTree(preorder, pL + 1, pL + (i - iL), inorder, iL, i - 1); 
    root->right = buildTree(preorder, pL + (i - iL) + 1, pR, inorder, i + 1, iR);

    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0) return NULL;
   
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
};
