#include "LeetCode.h"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int sz = s.size();
    if (sz == 0) return 0;
    unordered_set<char> in;
    int head=0, tail = 1, result = 1;
    in.insert(s[head]);
    while(tail < sz) {
      if (!in.insert(s[tail++]).second) {
	while(s[head] != s[tail-1]) {
	  in.erase(s[head++]);
	}
	if (s[head] == s[tail-1]) head++; // head++ instead of in.erase(s[head++])
      } else {
	result = max(result, tail-head);
      }
    }
    return result;
  }
};
