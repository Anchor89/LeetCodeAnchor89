#include "LeetCode.h"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    for(ListNode *t=head; t&&t->next; t=t->next) {
      while (t->next && t->val == t->next->val) {
        ListNode* tmp = t->next;
        t->next = tmp->next;
        delete tmp;
      }
    }
    return head;
  }
};
