#include "LeetCode.h"

class Solution {
public:
  int result;
  vector<vector<bool>> board;
  vector<bool> col, diag, rdiag;
  void solve(vector<vector<bool>>& board, int line) {
    if (line == board.size()) {
      result++;
      return;
    }
    int n = board.size();
    for (int i=0; i<n; i++) {
      if (col[i] || diag[i+line] || rdiag[line-i+n-1]) continue;
      board[line][i] = col[i] = diag[i+line] = rdiag[line-i+n-1] = true;
      solve(board, line+1);
      board[line][i] = col[i] = diag[i+line] = rdiag[line-i+n-1] = false;
    }
  }
  int totalNQueens(int n) {
    result = 0;
    board.clear(); board.resize(n, vector<bool>(n, false));
    col.clear(); col.resize(n, false);
    diag.clear(); diag.resize(n<<1, false);
    rdiag.clear(); rdiag.resize(n<<1, false);
    solve(board, 0);
    return result;
  }
};
