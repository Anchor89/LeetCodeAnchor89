#include "LeetCode.h"

class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0) return result;
    result.push_back(vector<int>(1,1));
    for (int i=2; i<=numRows; i++) {
      result.push_back(vector<int>(i, 1));
      transform(result[i-2].begin()+1, result[i-2].end(), result[i-2].begin(), result.back().begin()+1, plus<int>());
    }
    return result;
  }
};
