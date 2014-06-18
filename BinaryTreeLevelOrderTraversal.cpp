#include "LeetCode.h"

class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode*> q[2];
    int depth = 0;
    q[0].push(root);
    result.push_back(vector<int>());
    while(!q[depth].empty()) {
      TreeNode* cur = q[depth].front();
      q[depth].pop();
      result.back().push_back(cur->val);
      if (cur->left) q[depth^1].push(cur->left);
      if (cur->right) q[depth^1].push(cur->right);
      if (q[depth].empty()) {
	depth^=1;
	if (!q[depth].empty()) result.push_back(vector<int>());
      }
    }
    return result;
  }
};
