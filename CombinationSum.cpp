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
    for (int i=begin; i<can.size() && can[i] <= target; i++) {
      row.push_back(can[i]);
      dfs(can, i, target-can[i]);
      row.pop_back();
    }
  }
  vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    res.clear();
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, target);
    return res;
  }
};
