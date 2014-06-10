#include "LeetCode.h"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode h(0), *t1=&h, *t2=&h;
    h.next = head;
    while(n-- && t2) t2 = t2->next;
    if (!t2) return h.next;
    while(t2 && t2->next) {
      t1 = t1->next;
      t2 = t2->next;
    }
    t1->next = t1->next->next;
    return h.next;
  }
};
