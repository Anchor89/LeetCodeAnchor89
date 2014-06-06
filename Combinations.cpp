#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> result;
  vector<int> row;
  int n, k;
  void dfs(int idx, int begin) {
    if (idx == k) {
      result.push_back(row);
      return;
    }
    for (int i=begin; i<=n; i++) {
      row[idx] = i;
      dfs(idx+1, i+1);
    }
  }
  vector<vector<int> > combine(int n, int k) {
    result.clear();
    if (k<=0) {
      result.push_back(vector<int>());
    } else {
      row.resize(k, 0);
      this->n = n;
      this->k = k;
      dfs(0, 1);
    }
    return result;
  }
};
