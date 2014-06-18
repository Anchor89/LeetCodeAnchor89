#include "LeetCode.h"

class Solution {
public:
  void rotateLayer(vector<vector<int>> & matrix, int x, int y, int n) {
    n--;
    for (int i=0; i<n; i++) {
      int t = matrix[x][y+i];
      matrix[x][y+i] = matrix[x+n-i][y];
      matrix[x+n-i][y] = matrix[x+n][y+n-i];
      matrix[x+n][y+n-i] = matrix[x+i][y+n];
      matrix[x+i][y+n] = t;
    }
  }
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    if (n == 0) return;
    int x = 0, y = 0;
    for(; n>1; x++, y++,n-=2) {
      rotateLayer(matrix, x, y, n);
    }
  }
};
