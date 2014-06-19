#include "LeetCode.h"

class Solution {
public:
  int longestValidParentheses(string s) {
    int size = s.size();
    vector<int> pre(size, -1);
    stack<int> left;
    for(int i=0; i<size; i++) {
      if (s[i] == '(') {
        left.push(i);
      } else if (!left.empty()) {
        pre[i] = left.top();
        left.pop();
      }
    }
    vector<int> dp(size, 0);
    int result = 0;
    for (int i=0; i<size; i++) {
      if (s[i] == ')' && pre[i] >= 0) {
        if (pre[i] == i - dp[i-1] - 1) {
          dp[i] = 2 + dp[i-1];
          if (pre[i]-1 >= 0 && dp[pre[i]-1] > 0) {
            dp[i] += dp[pre[i]-1];
          } 
        }
        result = max(result, dp[i]);
      }
    }
    return result;
  }
};
