#include<cstdlib>
#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
