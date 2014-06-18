#include "LeetCode.h"

class Solution {
public:
  bool next_permutation(vector<int>& num) {
    int size = num.size();
    int cur = size-2;
    for(; cur>=0 && num[cur] >= num[cur+1]; cur--);
    if (cur == -1) return false;
    auto first = find_if(num.rbegin(), num.rend(), [&](int a) { return a>num[cur];});
    iter_swap(num.begin()+cur, first);
    reverse(num.begin()+cur+1, num.end());
    return true;
  }
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int>> result;
    sort(num.begin(), num.end());
    do {
      result.push_back(num);
    } while(next_permutation(num));
    return result;
  }
};
