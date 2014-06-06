#include "LeetCode.h"

class Solution {
public:
    
  int uniquePaths(int m, int n) {
    if (m <=0 || n<=0) return 0;
    vector<int> lvl[2];
    lvl[0].push_back(1);
    for(int cur = 1; cur<=m+n-2; cur++) {
      vector<int> &cl = lvl[cur&1];
      vector<int> &pl = lvl[1-(cur&1)];
      cl.clear();
      cl.push_back(1);
      for (int j=1; j<min(cur, m); j++) {
	cl.push_back(pl[j]+pl[j-1]);
      }
      cl.push_back(1);
    }
    return lvl[(m+n)&1][m-1];
  }
};
