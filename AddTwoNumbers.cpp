#include "LeetCode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
#define next(c) ((c)=(c)?(c)->next:NULL)
#define val(c) ((c)?(c)->val:0)
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *c1,*c2,h3(0),*c3=&h3;
    int carry = 0;
    for (c1 = l1, c2=l2; c1||c2; next(c1), next(c2)) {
      c3 = c3->next = new ListNode(val(c1)+val(c2)+carry);
      carry = c3->val / 10;
      c3->val %= 10;
    }
    if (carry > 0) c3 = c3->next = new ListNode(1);
    return h3.next;
  }
};
