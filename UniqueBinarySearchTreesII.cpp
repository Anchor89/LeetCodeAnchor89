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
  typedef vector<int>::iterator ite;
  void generateTrees(ite begin, ite end, vector<TreeNode*>& ret) {
    ret.clear();
    if (begin >= end) {
      ret.push_back(NULL);
      return;
    }
    vector<TreeNode*> lt, rht;
    for(ite cur=begin; cur!=end; cur++) {
      generateTrees(begin, cur, lt);
      generateTrees(cur+1, end, rht);
      for (int i=0; i<lt.size(); i++) {
	for (int j=0; j<rht.size(); j++) {
	  TreeNode* rt = new TreeNode(*cur);
	  rt->left = lt[i];
	  rt->right = rht[j];
	  ret.push_back(rt);
	}
      }
    }
  }
  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode*> ret;
    vector<int> nums(n);
    int i = 1;
    generate_n(nums.begin(), n, [&]() {return i++;});
    generateTrees(nums.begin(), nums.end(), ret);    
    return ret;
  }
};
