#include "LeetCode.h"

class Solution {
public:
  bool isPalindrome(int x) {
    if (x<0) return false;
    int r = 0;
    for (int t=x; t; t/=10) r=r*10+t%10;
    return x==r;
  }
};
