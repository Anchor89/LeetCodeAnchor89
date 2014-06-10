#include "LeetCode.h"

class Solution {
public:
  double kth(int A[], int m, int B[], int n, int k) {
    if (m>n) return kth(B,n,A,m,k);
    if (m == 0) return B[k-1];
    if (k == 1) return min(A[0], B[0]);
    int half = min(k >> 1, m);
    if (A[half-1] < B[half-1]) return kth(A+half, m-half, B, n, k-half);
    else return kth(A, m, B+half, n-half, k-half);
  }
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if((m+n)&1) {
      return kth(A,m,B,n,((m+n)>>1)+1);
    } else {
      return (kth(A,m,B,n,(m+n)>>1)+kth(A,m,B,n,((m+n)>>1)+1)) /2.0;
    }
  }
};
