#include "LeetCode.h"

class Solution {
public:
  bool isScramble(string s1, string s2) {
    int size1 = s1.size();
    int size2 = s2.size();
    if (size1 != size2) return false;
    if (size1 == 0) return true;
    vector<vector<vector<bool>>> dp(size1+1, vector<vector<bool>>(size1, vector<bool>(size1, false)));
    for (int i=0; i<size1; i++) {
      for (int j=0; j<size2; j++) {
	dp[1][i][j] = s1[i] == s2[j];
      }
    }
    for (int k=2; k<=size1; k++) {
      for (int i=0; i + k<=size1; i++) {
	for (int j=0; j + k<=size2; j++) {
	  for (int d=1; d<k; d++) {
                        dp[k][i][j] = dp[k][i][j] 
			  || (dp[d][i][j] && dp[k-d][i+d][j+d])
			  || (dp[d][i][j+k-d] && dp[k-d][i+d][j]);
	  }
	}
      }
    }
    return dp[size1][0][0];
  }
};
