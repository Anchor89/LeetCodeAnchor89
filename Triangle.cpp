#include "LeetCode.h"

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    int sz = triangle.size(), result = INT_MAX;
    vector<int> row[2] = {vector<int>(sz, INT_MAX), vector<int>(sz, INT_MAX)};
    row[0][0] = triangle[0][0];
    for (int i=0; i<sz-1; i++) {
      fill_n(row[1-(i&1)].begin(), i, INT_MAX);
      for (int j=0; j<=i; j++) {
	row[1-(i&1)][j] = min(row[1-(i&1)][j], row[i&1][j]+triangle[i+1][j]);
	row[1-(i&1)][j+1] = min(row[1-(i&1)][j+1], row[i&1][j]+triangle[i+1][j+1]);
      }
    }
    for (int i=0; i<sz; i++) {
      result = min(result, row[1-(sz&1)][i]);
    }
    return result;
  }
};
