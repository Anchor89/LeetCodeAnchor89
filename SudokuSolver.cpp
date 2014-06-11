#include "LeetCode.h"

class Solution {
public:
  bool col[9][10], row[9][10], grid[3][3][10];
  bool dfs(vector<vector<char>>& board, int i, int j) {
    if (i == 9) {
      return true;
    }
    if (j == 9) {
      return dfs(board, i+1, 0);
    }
    if (board[i][j] == '.') {
      for (int n=1; n<10; n++) {
	if (col[j][n] || row[i][n] || grid[i/3][j/3][n]) continue;
	col[j][n] = row[i][n] = grid[i/3][j/3][n] = true;
	board[i][j] = '0' + n;
	if (dfs(board, i, j+1)) return true;
	board[i][j] = '.';
	col[j][n] = row[i][n] = grid[i/3][j/3][n] = false;
      }
    } else {
      return dfs(board, i, j+1);
    }
  }
  void solveSudoku(vector<vector<char> > &board) {
    memset(col, false, sizeof col);
    memset(row, false, sizeof row);
    memset(grid, false, sizeof grid);
    for (int i=0; i<9; i++) {
      for (int j=0; j<9; j++) {
	if (board[i][j] != '.') {
	  int n = board[i][j] - '0';
	  col[j][n] = true;
	  row[i][n] = true;
	  grid[i/3][j/3][n] = true;
	}
      }
    }
    dfs(board, 0, 0);
  }
};
