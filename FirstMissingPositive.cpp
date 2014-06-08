#include "LeetCode.h"

class Solution {
public:
  /* switch A[i] to position A[i]-1; */
  int firstMissingPositive(int A[], int n) {
    for (int i=0; i<n; i++) {
      for (int j=i; A[j] > 0 && A[j] <=n && A[j]-1 != j && A[A[j]-1] != A[j]; ) {
	swap(A[j], A[A[j]-1]);
      }
    }
    for (int i=0; i<n; i++) {
      if (A[i] - 1 != i) return i+1;
    }
    return n+1;
  }
};
