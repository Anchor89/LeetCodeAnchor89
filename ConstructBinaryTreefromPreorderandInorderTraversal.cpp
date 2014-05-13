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
  typedef vector<int>::iterator vite;
  TreeNode* build(vite ph, vite pt, vite ih, vite it) {
    if (ph == pt) return NULL;
    TreeNode* ret = new TreeNode(*ph);
    vite rt = find(ih, it, *ph);
    ret->left = build(ph+1, ph+1+(rt-ih), ih, rt);
    ret->right = build(ph+1+(rt-ih), pt, rt+1, it);
    return ret;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
  }
};
