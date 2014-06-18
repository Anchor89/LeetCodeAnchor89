#include "LeetCode.h"

class Solution {
public:
  bool isValidSudoku(vector<vector<char> > &board) {
    bool row[9][10], col[9][10], grid[3][3][10];
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(grid, 0, sizeof grid);
    for (int i=0; i<9; i++) {
      for (int j=0; j<9; j++) {
        if (board[i][j] != '.') {
          int n = board[i][j] - '0';
          if (row[i][n] || col[j][n] || grid[i/3][j/3][n]) return false;
          row[i][n] = col[j][n] = grid[i/3][j/3][n] = true;
        }
      }
    }
    return true;
  }
};
