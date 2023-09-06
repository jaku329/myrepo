// https://leetcode.com/problems/kth-smallest-element-in-a-bst

#include <iostream>

class Solution {
public:
  void inorder(TreeNode* root, vector<int>& bst) {

    if (root->left) {
      inorder(root->left, bst);
    }
    
    bst.push_back(root->val);
     
    if (root->right) {
      inorder(root->right, bst);
    }
  }

  int kthSmallest(TreeNode* root, int k) {
    vector<int> bst;
    inorder(root, bst);
    return bst[k - 1];
  }
};

class Solution2 {
public:
  void inorder(TreeNode* root, int& k, int& val) {

    if (root->left) {
      inorder(root->left, k, val);
    }

    k--;
    if (k == 0) val = root->val;

    if (root->right) {
      inorder(root->right, k, val);
    }
  }

  int kthSmallest(TreeNode* root, int k) {
    int val;
    inorder(root, k, val); 
    return val;
  }
};
