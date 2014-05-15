#include "LeetCode.h"

class Solution {
public:
  int trap(int A[], int n) {
    if (n == 0) return 0;
    int ret = 0;
    vector<int> lt(n, A[0]), rht(n, A[n-1]);
    for (int i=1; i<n; i++) {
      lt[i] = max(lt[i-1], A[i]);
      rht[n-1-i] = max(rht[n-i], A[n-1-i]);
    }
    for (int i=0; i<n; i++) {
      ret += max(0, min(lt[i], rht[i])-A[i]);
    }
    return ret;
  }
};
