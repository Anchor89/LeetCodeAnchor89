#include "LeetCode.h"

class Solution {
public:
  int bs(int A[], int begin, int end, int target) {
    if (begin == end) return -1;
    if (begin == end-1) return A[begin]==target? begin:-1;
        
    int mid = (begin&end) + ((begin^end)>>1);
    if (A[mid] == target) return mid;
    if (A[mid] > A[end-1]) {
      if (target < A[mid] && target >= A[begin]) {
        return bs(A, begin, mid, target);
      } else {
        return bs(A, mid+1, end, target);
      }
    } else {
      if (target > A[mid] && target <= A[end-1]) {
        return bs(A, mid+1, end, target);
      } else {
        return bs(A, begin, mid, target);
      }
    }
  }
  int search(int A[], int n, int target) {
    return bs(A, 0, n, target);
  }
};
