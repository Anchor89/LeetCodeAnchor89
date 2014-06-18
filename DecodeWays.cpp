#include "LeetCode.h"

class Solution {
public:
  bool valid(int a, int low, int high) {
    return a>=low && a<=high;
  }
  int numDecodings(string s) {
    if (s.empty()) return 0;
    vector<int> dp(s.size()+1, 0);
    dp[0] = 1;
    for (int i=1; i<=s.size(); i++) {
      if (valid(s[i-1]-'0', 1, 9)) dp[i] += dp[i-1];
      if (i-1>=1 && valid(atoi(s.substr(i-2, 2).c_str()), 10, 26)) {
        dp[i] += dp[i-2];
      }
    }
    return dp[s.size()];
  }
};
