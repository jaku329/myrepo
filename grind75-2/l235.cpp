// 235. Lowest Common Ancestor of a Binary Search Tree

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

// 1. pure dfs
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == NULL) return NULL;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);
  if (left && right)
    return root;
  else if ((root == p) || (root == q))
    return root;

  if (left)
    return left;
  return right;
}

// 2. BST
TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == NULL || root == p || root == q) return root;

  TreeNode* left = NULL;
  TreeNode* right = NULL;

  if (root->val > p->val)
    left = dfs(root->left, p, q);
  if (root->val < q->val)
    right = dfs(root->right, p, q);

  if (left && right)
    return root;

  if (left)
    return left;
  return right;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (p->val < q->val)
    return dfs(root, p, q);
  return dfs(root, q, p);
}

// 3. BST 2
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (root == NULL || root == p || root == q) return root;

  if (p->val > q->val)
    return lowestCommonAncestor(root, q, p);

  if (root->val > q->val)
    return lowestCommonAncestor(root->left, p, q);
  else if (root->val < p->val)
    return lowestCommonAncestor(root->right, p, q);
  return root;
}

int main() {
  return 0;
}

