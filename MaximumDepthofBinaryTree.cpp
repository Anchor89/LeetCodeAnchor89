#include "LeetCode.h"

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return max(maxDepth(root->left), maxDepth(root->right))+1;
  }
};
