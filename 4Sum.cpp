#include "LeetCode.h"

class Solution {
public:
  struct Com{
    int sum, a, b;
    Com(int o_sum, int o_a, int o_b) : sum(o_sum), a(o_a), b(o_b) {}
  };
  vector<vector<int> > fourSum(vector<int> &num, int target) {
    set<vector<int>> filter;
    vector<vector<int>> res;
    sort(num.begin(), num.end());
    vector<Com> coms;
    for (int i=0,j; i<num.size(); i++) {
      for (j=i+1; j<num.size(); j++) {
        coms.push_back(Com(num[i]+num[j], i, j));
      }
    }
    sort(coms.begin(), coms.end(), [](const Com& a, const Com& b) {
        return a.sum<b.sum || (a.sum == b.sum && (a.a < b.a || (a.a == b.a && a.b < b.b)));
      });
        
    for (int i=0, j=coms.size()-1; i<coms.size(); i++) {
      for (; j>i && coms[i].sum+coms[j].sum>target; j--);
      if (j > i &&  coms[i].sum+coms[j].sum==target) {
        for (int k=j; k>i && coms[i].sum+coms[k].sum==target && coms[i].b < coms[k].a; k--) {
          filter.insert(vector<int>{num[coms[i].a], num[coms[i].b], num[coms[k].a], num[coms[k].b]});
        }
      }
    }
    res.insert(res.end(), filter.begin(), filter.end());
    return res;
  }
};
