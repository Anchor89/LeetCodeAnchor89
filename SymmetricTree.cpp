#include "LeetCode.h"

class Solution {
public:
  bool is(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    return left && right && left->val == right->val && is(left->right, right->left) && is(left->left, right->right);
  }
  bool isSymmetric(TreeNode *root) {
    return !root || is(root->left, root->right);
  }
};
