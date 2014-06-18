#include "LeetCode.h"

class Solution {
public:
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int row = matrix.size();
    if (row== 0) return false;
    int col = matrix[0].size();
    for (int x=row-1, y=0; x>=0; x--) {
      for (; y<col && target > matrix[x][y]; y++) {
        // blank loop
      }
      if (y<col && target == matrix[x][y]) return true;
    }
    return false;
  }
};
