#include "LeetCode.h"

class Solution {
public:
  // n==1 is a special case that must be handled alone
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, n*n));
    int start = 1, x=0, y=0, len=n-1, n2 = n*n;
    for(;start < n2; len-=2) {
      for(int i=0; i<len; i++) {
        result[x][y++] = start++;
      }
      for(int i=0; i<len; i++) {
        result[x++][y] = start++;
      }
      for(int i=0; i<len; i++) {
        result[x][y--] = start++;
      }
      for(int i=0; i<len; i++) {
        result[x--][y] = start++;
      }
      x++, y++;
    }
    return result;
  }
};
