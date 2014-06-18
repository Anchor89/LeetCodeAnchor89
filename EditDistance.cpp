#include "LeetCode.h"

class Solution {
public:
  /**
   * dp[i][j]: steps convert word1[0..i) to word2[0..j)
   * dp[i][j] = dp[i-1][j-1] when word1[i-1] == word2[j-1]
   *          = min{ dp[i-1][j] + 1   // delete word1[i-1]
   *                 dp[i-1][j-1] + 1 // change word1[i-1] to word2[j-1]
   *                 dp[i][j-1] + 1   // insert word2[j-1]
   *               }
   **/
  int minDistance(string word1, string word2) {
    if (word1 == word2) return 0;
    vector<int> dp[2]{vector<int>(word2.size()+1, INT_MAX), vector<int>(word2.size()+1, INT_MAX)};
    for (int j=0; j<=word2.size(); j++) dp[0][j] = j;
    for (int i=1; i<=word1.size(); i++) {
      int cur = i&1;
      dp[cur][0] = i;
      for (int j=1; j<=word2.size(); j++) {
        dp[cur][j] = word1[i-1]==word2[j-1]? dp[cur^1][j-1]:min(dp[cur^1][j], min(dp[cur^1][j-1], dp[cur][j-1]))+1;
      }
    }
    return dp[word1.size()&1][word2.size()];
  }
};
