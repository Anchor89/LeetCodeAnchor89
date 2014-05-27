#include "LeetCode.h"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size();
    if (sz < 2) return 0;
    vector<int> back(sz, 0), forw(sz, 0);
    int other = prices[0];
    for (int i=1; i<sz; i++) {
      forw[i] = max(prices[i]-other, forw[i-1]);
      other = min(prices[i], other);
    }
    other = prices[sz-1];
    for (int i=sz-2; i>=0; i--) {
      back[i] = max(other-prices[i], back[i+1]);
      other = max(prices[i], other);
    }
    other = 0;
    for (int i=0; i<sz; i++) {
      other = max(other, back[i]+forw[i]);
    }
    return other;
  }
};
