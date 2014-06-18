#include "LeetCode.h"

class Solution {
public:
  int searchInsert(int A[], int n, int target) {
    if (n==0 || target > A[n-1]) return n;
    if (n==1 || target <= A[0]) return 0;
    int head = 0, tail=n-1;
    while(tail-head>1) {
      int mid = (head&tail) + ((head^tail) >> 1);
      if (A[mid] >= target) {
        tail = mid;
      } else {
        head = mid;
      }
    }
    return tail;
  }
};
