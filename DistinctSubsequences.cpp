#include "LeetCode.h"

class Solution {
public:
  int numDistinct(string S, string T) {
    int slen = S.size(), tlen = T.size();
    vector<vector<int>> dp(tlen+1, vector<int>(slen+1, 0));
    fill(dp[0].begin(), dp[0].end(), 1); // For empty T, the distinct subsequences is always 1.
    for(int i=1; i<=tlen; i++) {
      for (int j=1; j<=slen; j++) {
	dp[i][j] = dp[i][j-1] + (T[i-1] == S[j-1]? dp[i-1][j-1]:0);
      }
    }
    return dp[tlen][slen];
  }
};
