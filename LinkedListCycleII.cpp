#include "LeetCode.h"

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head) return NULL;
    ListNode *fast=head, *slow=head;
    while(fast && fast->next) {
      slow=slow->next;
      fast = fast->next->next;
      if (slow == fast) break;
    }
    if (!fast || !fast->next) return NULL;
    fast = head;
    while(fast!=slow) {
      fast=fast->next;
      slow=slow->next;
    }
    return fast;
  }
};
