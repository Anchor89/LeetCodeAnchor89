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
  ListNode *sortList(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode h1(0), h2(0), h3(0), *t1=&h1, *t2=&h2, *t3=&h3;
    int val = head->val;
    while(head != NULL) {
      if (head->val < val) {
        t1 = t1->next = head;
      } else if (head->val == val) {
        t2 = t2->next = head;
      } else {
        t3 = t3->next = head;
      }
      head = head->next;
    }
    t1->next = t2->next = t3->next = NULL;
    h1.next = sortList(h1.next);
    for(t1=&h1; t1->next; t1=t1->next);
    t1->next = h2.next;
    t2->next = sortList(h3.next);
    return h1.next;
  }
};
