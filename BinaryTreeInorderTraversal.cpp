#include "LeetCode.h"

/**
 * Recursive
 */
class Solution {
public:
  vector<int> result;
  void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    result.push_back(root->val);
    inorder(root->right);
  }
  vector<int> inorderTraversal(TreeNode *root) {
    result.clear();
    inorder(root);
    return result;
  }
};

/* Morris inorder traversal */
class Solution {
public:
  TreeNode* getPre(TreeNode* root) {
    TreeNode* cur = root->left;
    while(cur && cur->right && cur->right != root) cur=cur->right;
    return cur;
  }
  
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    TreeNode* cur = root;
    while(cur) {
      TreeNode* pre = getPre(cur);
      if (!pre) {
        result.push_back(cur->val);
        cur = cur->right;
      } else {
        if (pre->right == cur) {
          result.push_back(cur->val);
          pre->right = NULL;
          cur = cur->right;
        } else {
          pre->right = cur;
          cur = cur->left;    
        }
      }
    }
    return result;
  }
};
