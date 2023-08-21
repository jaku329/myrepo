#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

class Solution {
  int dfs(TreeNode* root, int depth) {
    if (root->left == NULL && root->right == NULL) return depth;

    int depthL = 1, depthR = 1;
    if (root->left) depthL = dfs(root->left, depth + 1);
    if (root->right) depthR = dfs(root->right, depth + 1);

    return depthL > depthR ? depthL : depthR;
  }
 

  int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
//    return dfs(root, 1);
    int mDepth = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      mDepth++;
      for (int i = 0; i < size; ++i) {
        TreeNode* n = q.front();
        q.pop();
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
    }
    return mDepth;
  }
};
