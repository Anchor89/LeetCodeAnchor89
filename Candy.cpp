#include "LeetCode.h"

class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> candy(ratings.size(), 1);
    int sz = ratings.size(), sum=0;
    for (int i=1; i<sz; i++) {
      if (ratings[i]>ratings[i-1]) {
	candy[i] = candy[i-1]+1;
      }
    }
    for (int i=sz-2; i>=0; i--) {
      if (ratings[i] > ratings[i+1]) {
	candy[i] = max(candy[i], candy[i+1]+1);
      }
    }
    for_each(candy.begin(), candy.end(), [&](int a){sum+=a;});
    return sum;
  }
};
