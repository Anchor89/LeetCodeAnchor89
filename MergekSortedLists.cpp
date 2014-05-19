#include "LeetCode.h"

class Solution {
public:
    struct cmp {
        bool operator()(const ListNode* a, const ListNode* b) { return a->val > b->val; }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode h(0), *t=&h;
        for (auto& list : lists) {
            if (list) q.push(list);
        }
        while(!q.empty()) {
            ListNode* cur = q.top();
            q.pop();
            if (cur->next) q.push(cur->next);
            t = t->next = cur;
        }
        t->next = NULL;
        return h.next;
    }
};