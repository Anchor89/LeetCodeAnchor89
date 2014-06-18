#include "LeetCode.h"

class Solution {
public:
  bool canJump(int A[], int n) {
    int farest = 0;
    for (int i=0; farest < n && i<=farest; i++) {
      farest = max(farest, i+A[i]);
    }
    return farest >= n-1;
  }
};
