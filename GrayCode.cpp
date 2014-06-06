#include "LeetCode.h"

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> result;
    result.push_back(0);
    if (n <= 0) return result;
    result.push_back(1);
    for (int i=1; i<n; i++) {
      result.resize(1<<(i+1));
      copy_n(result.rbegin()+(1<<i), 1<<i, result.begin()+(1<<i));
      for_each(result.begin()+(1<<i), result.end(), [=](int& j) {j|=(1<<i);});
    }
    return result;
  }
};
