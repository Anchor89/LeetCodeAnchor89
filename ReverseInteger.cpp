#include "LeetCode.h"

class Solution {
public:
  int reverse(int x) {
    bool neg = x<0;
    x = abs(x);
    int res = 0;
    while(x) {
      res = res*10+x%10;
      x/=10;
    }
    return neg?-res:res;
  }
};
