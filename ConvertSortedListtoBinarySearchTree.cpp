#include "LeetCode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) return NULL;
    ListNode h(0), *s0, *s1, *s2;
    s0 = s1 = s2 = &h;
    h.next = head;
    for(;s2->next; s0=s1, s1=s1->next) {
      s2 = s2->next->next == NULL? s2->next:s2->next->next;
    }
    TreeNode* ret = new TreeNode(s1->val);
    s0->next = NULL;
    ret->left = s0 != &h? sortedListToBST(head):NULL;
    ret->right = sortedListToBST(s1->next);
    return ret;
  }
};
