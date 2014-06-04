#include "LeetCode.h"

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> row[2] = {vector<int>(rowIndex+1, 1), vector<int>(rowIndex+1, 1)};
    for(int i=1; i<rowIndex; i++) {
      for (int j=0; j<i; j++) {
	row[1-(i&1)][j+1] = row[(i&1)][j] + row[(i&1)][j+1];
      }
    }
    return row[rowIndex&1];
  }
};
