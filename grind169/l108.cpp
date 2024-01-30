// 108. Convert Sorted Array to Binary Search Tree

TreeNode* buildBST(vector<int>& nums, int start, int end) {
  if (start > end) return NULL;

  int m = start + ((end - start) >> 1);
  TreeNode* root = new TreeNode();
  root->val = nums[m];
  root->right = buildBST(nums, m + 1, end);
  root->left = buildBST(nums, start, m - 1);
  return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  if (nums.size() == 0) return NULL;
  return buildBST(nums, 0, nums.size() - 1);
}

// 0,-3,9,-10,null,5
// 0,-10,5,null,-3,null,9
