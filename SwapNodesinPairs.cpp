#include "LeetCode.h"

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    ListNode h(0), *t=&h, *tmp;
    h.next = head;
    while(t->next && t->next->next) {
      tmp = t->next->next;
      t->next->next = tmp->next;
      tmp->next = t->next;
      t->next = tmp;
      t = t->next->next;
    }
    return h.next;
  }
};
