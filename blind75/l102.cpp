// https://leetcode.com/problems/binary-tree-level-order-traversal

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left = NULL;;
  TreeNode* right= NULL;
};

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> v;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode* n = q.front();
        q.pop();
        v.push_back(n->val);
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
      }
      res.push_back(v);
    }

    return res;
  }
};

int main() {
  TreeNode n1;
  n1.val = 0;
  Solution s;
  s.levelOrder(&n1);
  return 0;
}
