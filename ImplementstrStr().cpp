#include "LeetCode.h"

class Solution {
public:
  char *strStr(char *s, char *t) {
    int lens = strlen(haystack);
    int lent = strlen(needle);
    vector<int> next(lent, -1);
    for (int i=1; i<lent; i++) {
      int j=next[i-1]+1;
      while(j > 0 && t[i]!=t[j]) j=next[j-1]+1;
      next[i] = t[i] == t[j]? j:-1;
    }
    int i,j=0;
    for (i=0; i<lens; i++) {
      if (j==lent) break;
      while(j>0 && s[i]!=t[j]) j=next[j-1]+1;
      j = s[i]==t[j]?j+1:0;
    }
    return j==lent?s+i-j:nullptr;
  }
};
