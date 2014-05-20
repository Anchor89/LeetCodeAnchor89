#include "LeetCode.h"

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return NULL;
    RandomListNode *cur1, h(0), *t=&h;
    for(cur1=head; cur1; cur1=cur1->next->next) {
      RandomListNode* tmp = new RandomListNode(cur1->label);
      tmp->next = cur1->next;
      cur1->next = tmp;
    }
    for(cur1=head; cur1; cur1=cur1->next->next) {
      cur1->next->random = cur1->random? cur1->random->next:NULL;
    }
    for(cur1=head; cur1; cur1=cur1->next) {
      t = t->next = cur1->next;
      cur1->next = t->next;
    }
    return h.next;
  }
};
