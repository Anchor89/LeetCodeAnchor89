#include "LeetCode.h"

class Solution {
public:
  bool search(int A[], int n, int target) {
    return find(A, A+n, target) != A+n;
  }
};
