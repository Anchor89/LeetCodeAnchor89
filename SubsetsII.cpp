#include "LeetCode.h"

class Solution {
public:
  vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    int sz = S.size(), count;
    vector<vector<int>> res(1, vector<int>());
    for(int i=0; i<sz; i+=count) {
      for (count = 0; i+count<sz && S[i+count]==S[i]; count++) {}
      int len = res.size();
      for (int j=1; j<=count; j++) {
        res.resize(res.size()+len);
        copy_n(res.begin(), len, res.end()-len);
        for_each(res.end()-len, res.end(), [&](vector<int>& v) {v.resize(v.size()+j, S[i]);});
      }
    }
    return res;
  }
};
