#include "LeetCode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode h(0), *t1=&h,*t2,*t3;
    h.next = head;
    n-=m;
    while(--m) t1=t1->next;
    t2 = t1->next;
    t3 = t2->next;
    while(n--) {
      ListNode* tmp = t3->next;
      t3->next = t1->next;
      t1->next = t3;
      t3 = tmp;
    }
    t2->next = t3;
    return h.next;
  }
};
