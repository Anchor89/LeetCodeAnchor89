#include "LeetCode.h"

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    vector<vector<int>>& g = obstacleGrid;
    for (auto& row : g) {
      replace(row.begin(), row.end(), 1, -1);
    }
    int row = g.size();
    if (row == 0) return 0;
    int col = g[0].size();
    g[0][0] = g[0][0] == 0? 1:0;
    for (int i=1; i<col; i++) g[0][i] = g[0][i] == 0? g[0][i-1]:0; // start from 1
    for (int i=1; i<row; i++) g[i][0] = g[i][0] == 0? g[i-1][0]:0; // start from 1
    for (int i=1; i<row; i++) {
      for (int j=1; j<col; j++) {
	g[i][j] = g[i][j] == 0? g[i-1][j]+g[i][j-1]:0;
      }
    }
    return g[row-1][col-1];
  }
};
