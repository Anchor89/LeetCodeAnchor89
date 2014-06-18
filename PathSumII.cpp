#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> result;
  void dfs(vector<int>& path, TreeNode* root, int sum) {
    if (root == nullptr) return;
    if (sum == root->val && !root->left && !root->right) {
      path.push_back(sum);
      result.push_back(path);
      path.pop_back();
      return;
    }
    path.push_back(root->val);
    dfs(path, root->left, sum-root->val);
    dfs(path, root->right, sum-root->val);
    path.pop_back();
  }
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    result.clear();
    vector<int> path;
    dfs(path, root, sum);
    return result;
  }
};
