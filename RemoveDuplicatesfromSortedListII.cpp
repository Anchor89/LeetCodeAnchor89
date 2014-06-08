#include "LeetCode.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode h(0), *t=&h, *begin = head, *end;
    while(begin) {
      for(end = begin->next; end && end->val == begin->val; end=end->next);
      if (end == begin->next) t=t->next=begin;
      begin = end;
    }
    t->next = NULL;
    return h.next;
  }
};
