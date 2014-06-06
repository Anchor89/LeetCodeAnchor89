#include "LeetCode.h"

class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    int at = m-1, bt = n-1, put = m+n-1;
    while(put>=0) {
      A[put--] = at>=0 && (bt<0 || A[at]>B[bt])? A[at--]:B[bt--];
    }
  }
};
