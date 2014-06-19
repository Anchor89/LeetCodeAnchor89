#include "LeetCode.h"

class Solution {
public:
  typedef pair<int, int> POS;
  const int dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
  int row, col;
  bool inMap(const POS& p) {
    return p.first >= 0 && p.second >= 0 && p.first < row && p.second < col;
  }
  void spread(vector<vector<char>> &board, int x, int y) {
    queue<POS> q;
    q.push(POS(x,y));
    board[x][y] = 'o';
    while(!q.empty()) {
      POS cur = q.front();
      q.pop();
      for (int i=0; i<4; i++) {
        POS newp = POS(cur.first+dx[i], cur.second+dy[i]);
        if (inMap(newp) && board[newp.first][newp.second] == 'O') {
          board[newp.first][newp.second] = 'o';
          q.push(newp);
        }
      }
    }
  }
  void solve(vector<vector<char>> &board) {
    row = board.size();
    if (row == 0) return;
    col = board[0].size();
    for (int i=0; i<row; i++) {
      if (board[i][0] == 'O') spread(board, i,0);
      if (board[i][col-1] == 'O') spread(board, i, col-1);
    }
    for (int j=0; j<col; j++) {
      if (board[0][j] == 'O') spread(board, 0, j);
      if (board[row-1][j] == 'O') spread(board, row-1, j);
    }
    for_each(board.begin(), board.end(), [](vector<char>& row) {
        replace(row.begin(), row.end(), 'O', 'X');
      });
    for_each(board.begin(), board.end(), [](vector<char>& row) {
        replace(row.begin(), row.end(), 'o', 'O');
      });
  }
};
