#include "LeetCode.h"

class Solution {
public:
  // 3:27
  void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    if (root->left) root->left->next = root->right;
    if (root->right && root->next) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
  }
};
