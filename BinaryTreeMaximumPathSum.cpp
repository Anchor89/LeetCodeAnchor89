#include "LeetCode.h"

class Solution {
public:
  int max3(int a, int b, int c) {
    return max<int>(a,max<int>(b,c));
  }
  pair<int, int> maxSum(TreeNode* root) {
    if (!root) return make_pair(0xf3f3f3f3,0);
    pair<int, int> l,r;
    l = maxSum(root->left);
    r = maxSum(root->right);
    return make_pair(max3(l.first, r.first, max(l.second,0)+root->val+max(r.second,0)), max(max(l.second, r.second)+root->val, 0));
  }
  int maxPathSum(TreeNode *root) {
    return maxSum(root).first;
  }
};
