#include "LeetCode.h"

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    int len = 0;
    ListNode h(0), *t=&h;
    h.next = head;
    for(;t->next;t=t->next, len++);
    if (len == 0) return NULL;
    t->next = h.next;
    k %= len;
    int pre = len - k;
    t = &h;
    for(; pre>0; t=t->next, pre--);
    h.next = t->next;
    t->next = NULL;
    return h.next;
  }
};
