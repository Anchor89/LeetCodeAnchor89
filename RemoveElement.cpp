#include "LeetCode.h"

class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    int len = 0;
    for (int i=0; i<n; i++) {
      if (A[i] == elem) continue;
      A[len++] = A[i];
    }
    return len;
  }
};

class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    return copy_if(A, A+n, A, [=](int i) {return i!=elem;})-A;
  }
};
