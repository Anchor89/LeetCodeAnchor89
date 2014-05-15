#include "LeetCode.h"

class Solution {
public:
  inline int minAbs(int a, int b) {
    return abs(a)<abs(b)? a:b;
  }
  int threeSumClosest(vector<int> &num, int target) {
    int sz = num.size(), delta=0x3f3f3f3f, sum;
    sort(num.begin(), num.end());
    for (int i=0; i<sz; i++) {
      for (int j=i+1, k=sz-1; j<k; j++) {
	while(k>j && (sum=num[i]+num[j]+num[k])>target) {
	  k--;
	  delta = minAbs(sum-target, delta);
	}
	delta = minAbs(sum-target, delta);
      }
    }
    return target+delta;
  }
};
