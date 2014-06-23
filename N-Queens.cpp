#include "LeetCode.h"

class Solution {
public:
  // 4'02"
  int mask, N;
  vector<vector<string>> result;
  void dfs(int n, int col, int d, int rd, vector<string>& board) {
    if (n == N) {
      result.push_back(board);
    } else {
      int av = mask ^ (col|d|rd) & mask;
      for(; av>0; av&=av-1) {
        int cur = av&(-av);
        string line(N, '.');
        line[__builtin_ctz(cur)] = 'Q';
        board.push_back(line);
        dfs(n+1, col|cur, (d|cur) >> 1, (rd|cur) << 1, board);
        board.pop_back();
      }
    }
  }
  vector<vector<string> > solveNQueens(int n) {
    result.clear();
    vector<string> board;
    N = n;
    mask = (1 << n) - 1;
    dfs(0,0,0,0,board);
    return result;
  }
};
