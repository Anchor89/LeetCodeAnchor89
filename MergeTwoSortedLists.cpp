#include "LeetCode.h"

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode h(0), *t=&h;
    while(l1 || l2) {
      if (l1 && l2 && l1->val < l2->val || !l2) {
        t = t->next = l1;
        l1 = l1->next;
      } else {
        t = t->next = l2;
        l2 = l2->next;
      }
    }
    t->next = NULL;
    return h.next;
  }
};
