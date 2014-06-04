#include "LeetCode.h"

class Solution {
public:
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> all;
    all.insert(num.begin(), num.end());
    int result = 0, cur = 0, t;
    for (int n : num) {
      for (cur = 0,t = n; all.erase(t) > 0; t++) cur++;
      for (t=n-1; all.erase(t) > 0; t--) cur++;
      result = max(result, cur);
    }
    return result;
  }
};
