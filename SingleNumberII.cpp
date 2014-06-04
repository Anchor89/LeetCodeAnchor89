#include "LeetCode.h"

class Solution {
public:
  int singleNumber(int A[], int n) {
    int a0 = 0, a1 = 0, t;
    for (int i=0; i<n; i++) {
      t = a1;
      a1 = (~a1 & a0 & A[i]) | (a1 & ~a0 & ~A[i]);
      a0 = (~t & ~a0 & A[i]) | (~t & a0 & ~A[i]);
    }
    return a0;
  }
};
