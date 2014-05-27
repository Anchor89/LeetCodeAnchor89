#include "LeetCode.h"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    if (sz < 2) return 0;
    int minv = prices[0], maxv = 0;
    for (int i=1; i<sz; i++) {
      maxv = max(maxv, prices[i]-minv);
      minv = min(minv, prices[i]);
    }
    return maxv;
  }
};
