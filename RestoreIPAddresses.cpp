#include "LeetCode.h"

class Solution {
public:
  vector<string> res;
  vector<vector<int>> validNext;
  void parse(string& s, int ind, int seg, string got) {
    if (seg == 4 || ind == s.size()) {
      if (seg == 4 && ind == s.size()) {
        res.push_back(got);
      } 
      return;
    }
    for (int next : validNext[ind]) {
      parse(s, ind+next, seg+1, got+(ind==0?"":".")+s.substr(ind, next));
    }
  }
  vector<string> restoreIpAddresses(string s) {
    res.clear();
    validNext.clear();
    int sz = s.size();
    validNext.resize(sz, vector<int>());
    for (int i=0; i<sz; i++) {
      if (s[i] == '0') {
        validNext[i].push_back(1);
        continue;
      }
      for (int j=1; j<4 && i+j<=sz; j++) {
        int n = atoi(s.substr(i, j).c_str());
        if (n>0 && n<256) {
          validNext[i].push_back(j);
        }
      }
    }
    parse(s, 0, 0, string(""));
    return res;
  }
};
