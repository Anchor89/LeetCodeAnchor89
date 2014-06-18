#include "LeetCode.h"

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode h1(0), *t1=&h1, h2(0), *t2=&h2;
    for(;head; head=head->next) {
      if (head->val < x) {
        t1 = t1->next = head;
      } else {
        t2 = t2->next = head;
      }
    }
    t2->next = NULL;
    t1->next = h2.next;
    return h1.next;
  }
};
