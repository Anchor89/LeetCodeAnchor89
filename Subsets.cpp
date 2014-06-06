#include "LeetCode.h"

class Solution {
public:
  vector<vector<int> > subsets(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> res;
    res.push_back(vector<int>());
    for (auto s : S) {
      int len = res.size();
      for (int i=0;i<len; i++) {
	res.push_back(res[i]);
      }
      for_each(res.begin()+len, res.end(), [&](vector<int>& v) {v.push_back(s);});
    }
    return res;
  }
};
