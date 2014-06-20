#include "LeetCode.h"

class Solution {
public:
  bool isMatch(char s, char p) {
    return p == '*' || p == '?' || p == s;
  }
  /** 
   * dp[i][j]: length i of p and length j of s;
   * dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1] when p[i-1]=='*'
   *                ^                 ^           ^
   *          match s[j-1]     * match nothing    * match s[..(j-1)]
   *          = dp[i-1][j-1] && p[i-1] == s[j-1]  when p[i-1] != '*'
   */
  bool isMatch(const char *s, const char *p) {
    int lens = strlen(s), lenp = strlen(p);
    if (lenp - count(p, p+lenp, '*') > lens) return false;
    if (lenp == 0) return lens == 0;
    vector<vector<bool>> dp(2, vector<bool>(lens+1, false));
    dp[0][0] = true;
    bool heading = true; // Deal with heading ***
    for (int i=1; i<=lenp; i++) {
      heading = dp[i&1][0] = (heading && p[i-1] == '*'); 
      for (int j=1; j<=lens; j++) {
        int pre = 1-(i&1);
        if (p[i-1] == '*') {
          dp[i&1][j] = dp[pre][j-1] || dp[pre][j] || dp[i&1][j-1];
        } else {
          dp[i&1][j] = dp[pre][j-1] && isMatch(s[j-1], p[i-1]);
        }
      }
    }
    return dp[lenp&1][lens];
  }
};
