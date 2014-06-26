#include "LeetCode.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        int sum[3] = {0};
        for (int i=0; i<n; i++) sum[A[i]]++;
        fill_n(A, sum[0], 0);
        fill_n(A+sum[0], sum[1], 1);
        fill_n(A+sum[0]+sum[1], sum[2], 2);
    }
};
