#include "LeetCode.h"

class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        bool neg = n<0;
        n = abs(n);
        double ret = pow(x, n>>1);
        ret *= ret * ((n&1)? x:1);
        return neg? 1/ret:ret;
    }
};