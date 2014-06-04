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
  TreeNode* flattenWithTail(TreeNode* root) {
    if (root == NULL) return NULL;
    if (root->right == NULL && root->left == NULL) return root;
    TreeNode *lt=flattenWithTail(root->left), *rt = flattenWithTail(root->right);
    if (lt) {
      lt->right = root->right;
      root->right = root->left;
      root->left = NULL;
      return rt? rt:lt;
    } else {
      return rt;
    }
  }
  void flatten(TreeNode *root) {
    if (root) flattenWithTail(root);
  }
};
