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

/* Recursive solution */
class Solution {
public:
  vector<int> result;
  void pt(TreeNode* root) {
    if (root == NULL) return;
        
    pt(root->left);
    pt(root->right);
    result.push_back(root->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
    result.clear();
    pt(root);
    return result;
  }
};

/* None recursize solution */
class Solution {
public:
  struct Node {
    TreeNode* val;
    int pc;
    Node(TreeNode* v) : val(v), pc(0) {}
  };
    
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<Node> node;
    node.push(Node(root));
    while(!node.empty()) {
      Node& t = node.top();
      if (t.val == NULL) {
	node.pop();
      } else if (t.pc == 0) {
	node.push(Node(t.val->left));
	t.pc++;
      } else if (t.pc == 1) {
	node.push(Node(t.val->right));
	t.pc++;
      } else {
	result.push_back(t.val->val);
	node.pop();
      }
    }
    return result;
  }
};
