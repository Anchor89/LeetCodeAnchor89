#include "LeetCode.h"

class Solution {
public:
  int jump(int A[], int n) {
    if (n <= 0) return 0;
    vector<int> step(n, n+1);
    step[0] = 0;
    int next = 1, i, j; // Use next to optimize the algorithm to O(n)
    for (i=0; i<n && next<n; i++) {
      for (j=next-i; j<=A[i] && i+j<n; j++) { // j<=A[i] instead of j<A[i]; j=next-i instead of j=next
	step[i+j] = min(step[i+j], step[i]+1);
      }
      next = max(next, i+j);
    }
    return step[n-1];
  }
};
