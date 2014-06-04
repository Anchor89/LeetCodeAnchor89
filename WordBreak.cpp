#include "LeetCode.h"

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    vector<bool> dp(s.size());
    int sz = s.size();
    dp[0] = true;
    for (int i=0; i<sz; i++) {
      dp[i] = dict.find(s.substr(0, i+1)) != dict.end();
      for (int j=0; j<i; j++) {
	dp[i] = dp[i] || (dp[j] && dict.find(s.substr(j+1, i-j)) != dict.end());
      }
    }
    return dp[sz-1];
  }
};
