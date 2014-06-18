#include "LeetCode.h"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
  // 4:37
  void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
        
    queue<TreeLinkNode*> lvl[2];
    int cur = 0;
    lvl[0].push(root);
    while(!lvl[cur].empty()) {
      TreeLinkNode* now = lvl[cur].front();
      lvl[cur].pop();
      now->next = lvl[cur].empty()? NULL:lvl[cur].front();
      if(now->left) lvl[cur^1].push(now->left);
      if(now->right) lvl[cur^1].push(now->right);
      if (lvl[cur].empty()) cur^=1;
    }
  }
};
