// 98. Validate Binary Search Tree

#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left = NULL;
  TreeNode* right = NULL;
};
// dfs
// close condition of range
bool isValidBST(TreeNode* root, int min, int max) {
  if (root == NULL) return true;
  else if (root->val < min || root->val > max) return false;

  if ((root->val == INT_MIN) && root->left) return false;
  else if ((root->val == INT_MAX) && (root->right)) return false;

  return isValidBST(root->left, min, root->val - 1) & isValidBST(root->right, root->val + 1, max);
}

bool isValidBST(TreeNode* root) {
  return isValidBST(root, INT_MIN, INT_MAX);
}

int main() {
  TreeNode n;
  n.val = 2147483647;//INT_MAX;
  cout << isValidBST(&n) << endl;
  return 0;
}
