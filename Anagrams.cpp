#include "LeetCode.h"

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    using P = pair<string, string>;
    vector<P> pairs;
    for_each(strs.begin(), strs.end(), [&](string& s) {
        pairs.push_back(make_pair(s, s));
        sort(pairs.back().second.begin(), pairs.back().second.end());
      });
    sort(pairs.begin(), pairs.end(), [](const P& a, const P& b) { return a.second < b.second;});
    vector<string> result;
    for (int i=0, j; i<pairs.size(); i=j) {
      for (j=i+1; j<pairs.size() && pairs[j].second == pairs[i].second; j++) {
        result.push_back(pairs[j].first);
      };
      if (j>i+1) {
        result.push_back(pairs[i].first);
      }
    }
    return result;
  }
};
