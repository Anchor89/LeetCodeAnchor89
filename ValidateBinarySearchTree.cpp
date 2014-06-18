#include "LeetCode.h"

class Solution {
public:
  // Subtree has a range [low, up]
  bool is(TreeNode* root, int low, int up) {
    if (root == nullptr) return true;
    return is(root->left, low, root->val-1) && is(root->right, root->val+1, up) && root->val >= low && root->val <= up;
  }
  bool isValidBST(TreeNode *root) {
    return is(root, INT_MIN, INT_MAX);
  }
};
