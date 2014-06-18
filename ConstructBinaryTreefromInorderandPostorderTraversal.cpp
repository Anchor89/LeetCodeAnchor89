#include "LeetCode.h"

class Solution {
public:
  template<class T>
  TreeNode* build(T inBegin, T inEnd, T postBegin, T postEnd) {
    if (inBegin == inEnd || postBegin == postEnd) return NULL;
    T inRoot = find(inBegin, inEnd, *(postEnd-1));
    if (inRoot == inEnd) return NULL;
    TreeNode * root = new TreeNode(*inRoot);
    int leftSize = distance(inBegin, inRoot);
    root->left = build(inBegin, inRoot, postBegin, postBegin+leftSize);
    root->right = build(inRoot+1, inEnd, postBegin+leftSize, postEnd-1);
    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.size() != postorder.size()) return nullptr;
    return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
  }
};
