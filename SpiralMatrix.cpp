#include "LeetCode.h"

class Solution {
public:
  // Tip: Edge case is single row/single column/single element
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    int m = matrix.size();
    if (m == 0) return vector<int>();
    int n = matrix[0].size();
    if (n == 0) return vector<int>();
    int lenm = m-1, lenn = n-1;
    int x = 0, y = 0;
    vector<int> result;
    for (; lenm>0 && lenn > 0; lenm-=2, lenn-=2, x++, y++) {
      for (int i=0; i<lenn; i++) result.push_back(matrix[x][y++]);
      for (int i=0; i<lenm; i++) result.push_back(matrix[x++][y]);
      for (int i=0; i<lenn; i++) result.push_back(matrix[x][y--]);
      for (int i=0; i<lenm; i++) result.push_back(matrix[x--][y]);
    }
    if (lenm == 0 && lenn == 0) { // Only one element left
      result.push_back(matrix[x][y]);
    } else if (lenm > 0 && lenn == 0) { // Only one column
      for (int i=0; i<lenm+1; i++) result.push_back(matrix[x++][y]);
    } else if (lenn > 0 && lenm == 0) { // Only one row
      for (int i=0; i<lenn+1; i++) result.push_back(matrix[x][y++]);
    }
    return result;
  }
};
