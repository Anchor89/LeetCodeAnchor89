#include "LeetCode.h"

class Solution {
public:
  int maxRow(vector<int>& row) {
    if (row.empty()) return 0;
    row.push_back(0);
    typedef pair<int, int> Pair;
    stack<Pair> s;
    s.push(Pair(0, row[0]));
    int size = row.size(), result = 0, lb;
    for (int i=1; i<size; i++) {
      lb = i;
      while(!s.empty() && s.top().second > row[i]) {
	lb = s.top().first;
	result = max(result, s.top().second*(i-lb));
	s.pop();
      }
      s.push(Pair(lb, row[i]));
    }
    return result;
  }
  int maximalRectangle(vector<vector<char> > &matrix) {
    int row = matrix.size();
    if (row == 0) return 0;
    int col = matrix[0].size();
    int result = 0;
    vector<int> height(col, 0);
    for_each(matrix.begin(), matrix.end(), [&](vector<char>& R) {
	transform(R.begin(), R.end(), height.begin(), height.begin(), [](char c, int a) {
	    return c=='0'?0:a+1;
	  });
	result = max(result, maxRow(height));    
      });
    return result;
  }
};
