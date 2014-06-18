#include "LeetCode.h"

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (k == 1) return head;
    ListNode h(0), *t=&h, *sub, *next;
    h.next = head;
    while(t) {
      next = t;
      for (int i=0; i<k && next; i++) next = next->next;
      if (next) {
        sub = t->next->next;
        t->next->next = next->next;
        next->next = NULL;
        next = t->next;
        while(sub) {
          ListNode* tmp = sub;
          sub = sub->next;
          tmp->next = t->next;
          t->next = tmp;
        }
      }
      t = next;
    }
    return h.next;
  }
};
