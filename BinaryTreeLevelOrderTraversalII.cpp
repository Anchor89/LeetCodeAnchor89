#include "LeetCode.h"

class Solution {
public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> lvl[2];
    int depth = 0;
    lvl[depth].push(root);
    result.push_back(vector<int>());
    while(!lvl[depth].empty()) {
      auto cur = lvl[depth].front();
      lvl[depth].pop();
      result.back().push_back(cur->val);
      if (cur->left) {
        lvl[depth^1].push(cur->left);
      }
      if (cur->right) {
        lvl[depth^1].push(cur->right);
      }
      if (lvl[depth].empty()) {
        depth^=1;
        if (!lvl[depth].empty()) result.push_back(vector<int>());
      }
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
