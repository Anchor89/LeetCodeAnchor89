#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> res;
  vector<int> row;
  void dfs(vector<int>& can, int begin, int target) {
    if (target == 0) {
      if (!row.empty()) res.push_back(row);
      return;
    }
    if (target < 0) return;
    for (int i=begin; i<can.size() && can[i] <= target;) {
      row.push_back(can[i]);
      dfs(can, i+1, target-can[i]);
      row.pop_back();
      do i++; while(i<can.size() && can[i] == can[i-1]);
    }
  }
  vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    res.clear();
    sort(num.begin(), num.end());
    dfs(num, 0, target);
    return res;
  }
};
