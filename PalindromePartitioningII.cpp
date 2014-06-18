#include "LeetCode.h"

class Solution {
public:
  int minCut(string s) {
    vector<vector<int>> palinNext(s.size());
    for (int i=0; i<s.size(); i++) {
      for (int l=i, r=i; l>=0 && r<=s.size() && s[l] == s[r]; l--, r++) {
        palinNext[l].push_back(r);
      }
      for (int l=i, r=i+1; l>=0 && r<=s.size() && s[l] == s[r]; l--, r++) {
        palinNext[l].push_back(r);
      }
    }
    vector<int> dp(s.size()+1, INT_MAX);
    dp[0] = -1;
    for (int i=1; i<=s.size(); i++) {
      for (int j : palinNext[i-1]) {
        dp[j+1] = min(dp[j+1], dp[i-1]+1);
      }
    }
    return dp[s.size()];
  }
};
