#include "LeetCode.h"

class Solution {
public:
  pair<bool, int> testBalance(TreeNode* root) {
    if (root == NULL) return make_pair(true, 0);
    pair<bool, int> left = testBalance(root->left);
    pair<bool, int> right = testBalance(root->right);
    if (left.first && right.first && abs(left.second-right.second) < 2) {
      return make_pair(true, max(left.second, right.second)+1);
    }
    return make_pair(false, 0);
  }
  bool isBalanced(TreeNode *root) {
    return testBalance(root).first;
  }
};
