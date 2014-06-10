#include "LeetCode.h"

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    vector<vector<int>> result;
    int sz = num.size();
    sort(num.begin(), num.end());
    for (int i=0; i<sz; i++) {
      if (i && num[i] == num[i-1]) continue;
      for (int j=i+1, k=sz-1; j<k; j++) {
	if (j > i+1 && num[j]==num[j-1]) continue;
	while(k>j && num[i]+num[j]+num[k] > 0) k--;
	if (k>j && num[i] + num[j] + num[k] == 0) {
	  result.push_back(vector<int>{num[i], num[j], num[k]});
	}
      }
    }
    return result;
  }
};
