#include "LeetCode.h"

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    auto cur = adjacent_find(num.rbegin(), num.rend(), [](int a, int b) {return a>b;});
    if (cur != num.rend()) {
      cur++;
      auto big = find_if(num.rbegin(), num.rend(), [&](int i) { return i>*cur;});
      iter_swap(big, cur);
    }
    reverse(num.rbegin(), cur);
  }
};
