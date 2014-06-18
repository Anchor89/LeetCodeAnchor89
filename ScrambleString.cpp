#include "LeetCode.h"

class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    int size = s1.size();
    if (size == 0) return true;
    vector<vector<vector<bool>>> dp(size, vector<vector<bool>>(size, vector<bool>(size+1, false)));
    for (int i=0; i<size; i++) {
      for (int j=0; j<size; j++) {
        dp[i][j][1] = s1[i] == s2[j];
      }
    }
    for (int len=2; len<=size; len++) {
      for (int i=0; i+len <= size; i++) { // i+len <= size Not <
        for (int j=0; j+len <= size; j++) { // j+len <= size Not <
          for (int t=1; t<len; t++) {
                        dp[i][j][len] = dp[i][j][len] || dp[i][j][t] && dp[i+t][j+t][len-t] 
                          || dp[i][j+len-t][t] && dp[i+t][j][len-t];
          }
        }
      }
    }
    return dp[0][0][size];
  }
};
