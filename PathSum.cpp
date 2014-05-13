#include "LeetCode.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    return !root->right&&!root->left? root->val==sum:hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
  }
};
