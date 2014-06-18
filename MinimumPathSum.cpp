#include "LeetCode.h"

class Solution {
public:
  int col, row;
  int minPathSum(vector<vector<int> > &grid) {
    row = grid.size();
    if (row == 0) return 0;
    col = grid[0].size();
    for (int i=1; i<row; i++) grid[i][0] += grid[i-1][0];
    for (int j=1; j<col; j++) grid[0][j] += grid[0][j-1];
    for (int i=1; i<row; i++) {
      for (int j=1; j<col; j++) {
        grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
      }
    }
    return grid[row-1][col-1];
  }
};
