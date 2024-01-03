// 105. Construct Binary Tree from Preorder and Inorder Traversal

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pL, int pR, int iL, int iR) {
  TreeNode* root = new TreeNode();
  root->val = preorder[pL];
  root->left = NULL;
  root->right = NULL;
  
  int iRoot = iL;
  while (preorder[pL] != inorder[iRoot]) iRoot++;
  if (iRoot > iL)
    root->left = build(preorder, inorder, pL + 1, pL + iRoot - iL, iL, iRoot - 1);
  if (iRoot < iR)
    root->right = build(preorder, inorder, pL + iRoot - iL + 1, pR, iRoot + 1, iR);

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}
