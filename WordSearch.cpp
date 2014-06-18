#include "LeetCode.h"

class Solution {
public:
  const int dx[4]= {-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
  int row, col;
  bool dfs(vector<vector<char>>& board, string& word, int x, int y, int idx) {
    if (idx == word.size()-1) {
      return true;
    }
    board[x][y] = '\1';
    for (int i=0; i<4; i++) {
      int nx = x+dx[i], ny=y+dy[i];
      if (nx < 0 || nx >= row || ny < 0 || ny>= col) continue;
      if (board[nx][ny] != word[idx+1]) continue;
      if (dfs(board, word, nx, ny, idx+1)) return true;
    }
    board[x][y] = word[idx];
    return false;
  }
  bool exist(vector<vector<char> > &board, string word) {
    if (word.size() == 0) return true;
    row = board.size();
    if (row == 0) return false;
    col = board[0].size();
    for (int i=0; i<row; i++) {
      for (int j=0; j<col; j++) {
        if (board[i][j] == word[0]) {
          if (dfs(board, word, i, j, 0)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
