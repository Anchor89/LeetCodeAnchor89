#include "LeetCode.h"

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    int h,t,*B=new int[n]; // Need a new Array
    for(h=t=0;t<n;) {
      while(t<n && t>1 && A[t]==A[t-1] && A[t]==A[t-2]) t++;
      if (t<n) B[h++]=A[t++];
    }
    copy_n(B,n,A);
    return h;
  }
};
