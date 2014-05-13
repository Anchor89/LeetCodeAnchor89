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
  int minDepth(TreeNode *root) {
    if (root && root->left && root->right) {
      return min(minDepth(root->left), minDepth(root->right))+1;
    } else if (root && (root->left || root->right)) {
      return max(minDepth(root->left), minDepth(root->right))+1;
    } else {
      return root?1:0;
    }
  }
};
