#include "LeetCode.h"

/**
 * The inorder of the tree should be in acsending order a1,a2,a3....an.
 * After swap two of them, there will be only two cases:
 * 1. a1,a2,a3,....a(i+1), ai.....an
 * 2. a1,a2....aj,a(i+1).....a(j-1),ai...n
 * In both cases, a(i+1) > ai, aj>a(i+1), a(j-1)>ai
 * So find all pair(a,b) that a>b.
 * Then swap the wrong element.
 */
class Solution {
public:
  TreeNode* pre;
  vector<TreeNode*> reverse;
  void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    if (pre && pre->val > root->val) {
      reverse.push_back(pre);
      reverse.push_back(root);
    }
    pre = root;
    inorder(root->right);
  }
  void recoverTree(TreeNode *root) {
    pre == NULL;
    reverse.clear();
    inorder(root);
    if (reverse.size() > 0) {
      swap(reverse.back()->val, reverse.front()->val);
    } 
  }
};
