class Solution {
public:
  int maxProduct(int A[], int n) {
    if (n == 0) return 0;
    int maxv = A[0], minv = A[0], result = A[0];
    for (int i=1; i<n; i++) {
      int nmaxv = maxv * A[i], nminv = minv * A[i];
      maxv = max(max(nmaxv, nminv), A[i]);
      minv = min(min(nmaxv, nminv), A[i]);
      result = max(result, maxv);
    }
    return result;
  }
};
