// https://leetcode.com/problems/decode-ways

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left = NULL;
  TreeNode* right = NULL;
};

class Solution {
public:
  void inorder(TreeNode* r, vector<int>& vals) {
    if (r == NULL) return;

    if (r->left) inorder(r->left, vals);
    vals.push_back(r->val);
    if (r->right) inorder(r->right, vals);
  }

  bool isValidBST(TreeNode* root) {
    vector<int> vals;
    inorder(root, vals);
    if (vals.size() <= 1) return true;
    for (int i = 1; i < vals.size(); ++i)
      if (vals[i] <= vals[i - 1]) return false;
    return true;
  }
};

class Solution2 {
public:
  long prev = LONG_MIN;
  bool inorder(TreeNode* r) {
    if (r == NULL) return true;

    if (r->left) if (!inorder(r->left)) return false;
    if (prev >= r->val) return false;
    prev = r->val;
    if (r->right) if (!inorder(r->right)) return false;
    return true;
  }

  bool isValidBST(TreeNode* root) {
    return inorder(root);
  }
};

int main() {
  TreeNode a;
  a.val = 0;
  Solution2 s;
  cout << s.isValidBST(&a) << endl;
  return 0;
}

