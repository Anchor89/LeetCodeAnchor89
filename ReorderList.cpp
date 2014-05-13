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
  void reorderList(ListNode *head) {
    ListNode h(0), *s1=&h, *s2=&h;
    h.next = head;
    if (head == NULL || head->next == NULL) return;
    while(s2->next != NULL) {
      s1 = s1->next;
      s2 = s2->next->next == NULL? s2->next:s2->next->next; // WA: s2->next == NULL?
    }
    s2 = s1->next;
    s1 = s1->next = NULL;
    while(s2) {
      ListNode *tmp = s2->next;
      s2->next = s1;
      s1 = s2;
      s2 = tmp;
    }
    s2 = h.next; // First half
    while(s1) {
      ListNode *tmp = s1->next;
      s1->next = s2->next;
      s2->next = s1;
      s2 = s1->next;
      s1 = tmp;
    }
  }
};
