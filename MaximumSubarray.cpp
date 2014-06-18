#include "LeetCode.h"

class Solution {
public:
  int maxSubArray(int A[], int n) {
    // dp[i] = max{0, dp[i-1]} + A[i]
    if (n == 0) return 0;
    int dp = A[0];
    int result = dp; 
    for (int i=1; i<n; i++) {
      dp = max(dp, 0) + A[i];
      result = max(result, dp);
    }
    return result;
  }
};
