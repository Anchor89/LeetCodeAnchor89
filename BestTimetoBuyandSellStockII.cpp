#include "LeetCode.h"

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int sz = prices.size(), sum = 0;
    for (int i=1; i<sz; i++) {
      sum+=max(prices[i]-prices[i-1], 0);
    }
    return sum;
  }
};
