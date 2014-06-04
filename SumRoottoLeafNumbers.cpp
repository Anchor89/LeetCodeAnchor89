#include "LeetCode.h"

class Solution {
public:
  int result;
  void dfs(TreeNode* root, int cur) {
    if (root->left == NULL && root->right == NULL) {
      result+=cur*10+root->val;
    }
    if (root->left) dfs(root->left, cur*10+root->val);
    if (root->right) dfs(root->right, cur*10+root->val);
  }
  int sumNumbers(TreeNode *root) {
    result = 0;
    if (root) dfs(root, 0);
    return result;
  }
};
