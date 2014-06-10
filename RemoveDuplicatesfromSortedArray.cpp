#include "LeetCode.h"

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int len = 0;
    for (int i=0; i<n; i++) {
      if (i>0 && A[i]==A[i-1]) continue;
      A[len++] = A[i];
    }
    return len;
  }
};
