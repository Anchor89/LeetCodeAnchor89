#include "LeetCode.h"

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int sz1 = s1.size(), sz2 = s2.size(), sz3 = s3.size();
    if (sz1+sz2!=sz3) return false;
    vector<vector<bool>> dp(sz3+1, vector<bool>(sz1+1,false));
    dp[0][0] = true;
    for (int i=1; i<=sz3; i++) {
      for (int j=0; j<=min(i, sz1); j++) {
	dp[i][j] = (j>0 && dp[i-1][j-1] && s3[i-1]==s1[j-1]) || (i-j>0 && dp[i-1][j] && s3[i-1] == s2[i-j-1]);
      }
    }
    for (int i=0; i<=sz1; i++) {
      if (dp[sz3][i]) return true;
    }
    return false;
  }
};
