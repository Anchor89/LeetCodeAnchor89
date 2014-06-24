#include "LeetCode.h"

class Solution {
public:
  bool isMatch(char p, char s) {
    return p=='.' || p==s;
  }
  inline int cur(int a) {
    return a%3;
  }
  inline int pre1(int a) {
    return (a-1)%3;
  }
  inline int pre2(int a) {
    return (a-2)%3;
  }
  bool isMatch(const char *s, const char *p) {
    int lens = strlen(s);
    int lenp = strlen(p);
    vector<vector<bool>> dp(3, vector<bool>(lens+1, false));
    dp[0][0] = true;
    for (int i=1; i<=lenp; i++) {
      dp[cur(i)][0] = i>1 && p[i-1] == '*' && dp[pre2(i)][0];
      for (int j=1; j<=lens; j++) {
	if (p[i-1] == '*') {
	  dp[cur(i)][j] = dp[pre2(i)][j] || ((dp[pre2(i)][j-1] || dp[cur(i)][j-1]) && isMatch(p[i-2], s[j-1]));
	} else {
	  dp[cur(i)][j] = dp[pre1(i)][j-1] && isMatch(p[i-1], s[j-1]);
	}
      }
    }
    return dp[cur(lenp)][lens];
  }
};
