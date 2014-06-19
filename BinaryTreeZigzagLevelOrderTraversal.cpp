#include "LeetCode.h"

class Solution {
public:
  // Not good. Should do normal level order traversal and output in different order
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> >  res;
    vector<int> row;
    if (!root) return res;
    vector<TreeNode*> lvl[2];
    int cur = 0;
    lvl[cur].push_back(root);
    res.push_back(vector<int>());
    res.back().push_back(root->val);
    while(!lvl[cur].empty()) {
      lvl[1-cur].clear();
      row.clear();
      for_each(lvl[cur].rbegin(), lvl[cur].rend(), [&](TreeNode* n) {
          if (n->right) {
            lvl[1-cur].push_back(n->right);
            row.push_back(n->right->val);
          }
          if (n->left) {
            lvl[1-cur].push_back(n->left);
            row.push_back(n->left->val);
          }
        });
      if (!row.empty()) res.push_back(row);
      cur = 1-cur;
      lvl[1-cur].clear();
      row.clear();
      for_each(lvl[cur].rbegin(), lvl[cur].rend(), [&](TreeNode* n) {
          if (n->left) {
            lvl[1-cur].push_back(n->left);
            row.push_back(n->left->val);
          }
          if (n->right) {
            lvl[1-cur].push_back(n->right);
            row.push_back(n->right->val);
          }
        });
      if (!row.empty()) res.push_back(row);
      cur = 1-cur;
    }
    return res;
  }
};
