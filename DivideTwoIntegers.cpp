#include "LeetCode.h"

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (divisor == 0) return dividend>0? INT_MAX:(dividend<0? INT_MIN:0);
    bool neg = (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0);
    int s = 0, result = 0, count = 0;
    dividend = -abs(dividend);
    divisor = -abs(divisor);
    while(dividend <= divisor) {
      for (s = divisor, count=1; s>=dividend-s; s+=s, count+=count);
      result += count;
      dividend -= s;
    }
    return neg? -result:result;
  }
};
