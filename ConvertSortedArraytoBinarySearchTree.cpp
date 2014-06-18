#include "LeetCode.h"

class Solution {
public:
  template<class T>
  TreeNode *convert(T begin, T end) {
    if (begin == end) return NULL;
    T mid = begin+(end-begin)/2;
    TreeNode* root = new TreeNode(*mid);
    root->left = convert(begin, mid);
    root->right = convert(mid+1, end);
    return root;
  }
  TreeNode *sortedArrayToBST(vector<int> &num) {
    return convert(num.begin(), num.end());
  }
};
