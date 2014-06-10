#include "LeetCode.h"

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) return string();
    if (strs.size() == 1) return strs[0];
    int len = -1;
    bool done = false;
    while(!done) {
      len++;
      if (len == strs[0].size()) break;
      char c = strs[0][len];
      for (string& s : strs) {
	done = done || len == s.size() || s[len] != c;
      }
    }
    return strs[0].substr(0, len);
  }
};
