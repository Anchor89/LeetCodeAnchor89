#include "LeetCode.h"

class Solution {
public:
  int singleNumber(int A[], int n) {
    int res = 0;
    for_each(A, A+n, [&](int a){res^=a;});
    return res;
  }
};
