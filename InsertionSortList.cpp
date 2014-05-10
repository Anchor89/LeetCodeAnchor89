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
  ListNode *insertionSortList(ListNode *head) {
    ListNode h(0), *t=&h, *n;
    while(head != NULL) {
      for(t=&h; t->next != NULL && t->next->val < head->val; t=t->next);
      n = head; head=head->next;
      n->next = t->next;
      t->next = n;
    }
    return h.next;
  }
};
