#include "LeetCode.h"

class Solution {
public:
  int maxArea(vector<int> &height) {
    auto head = height.begin(), tail = height.end()-1;
    int res = 0;
    for (; head<tail; ) {
      res = max(min(*head, *tail)*(tail-head), res);
      if (*head<*tail) {
	for(int t=*head; head<tail && *head<=t; head++);
      } else {
	for(int t=*tail; tail > head && *tail<=t; tail--);
      }
    }
    return res;
  }
};
