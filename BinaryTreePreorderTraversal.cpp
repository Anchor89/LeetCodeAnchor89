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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    if (!root) return result;
    stack<TreeNode*> nodes;
    stack<int> ops;
    nodes.push(root);
    ops.push(0);
    while(!nodes.empty()) {
      TreeNode* cur = nodes.top();
      int& op = ops.top();
      op++;
      if (op == 1) {
        result.push_back(cur->val);
      } else if (op == 2) {
        if (cur->left) {
          nodes.push(cur->left);
          ops.push(0);
        }
      } else if (op == 3) {
        if (cur->right) {
          nodes.push(cur->right);
          ops.push(0);
        }
      } else {
        nodes.pop();
        ops.pop();
      }
    }
    return result;
  }
};
