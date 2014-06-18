#include "LeetCode.h"

class Solution {
public:
  string convert(string s, int nRows) {
    if (nRows <= 1) return s;
    int item = (nRows-1) << 1;
    int group = (s.size()+item-1)/item;
    string result;
    for (int i=0; i<nRows; i++) {
      for (int j=0; j<group; j++) {
        if (i == 0 || i << 1 == item) {
          if (j*item+i < s.size()) result += s[j*item+i];
        } else {
          if (j*item+i<s.size()) result += s[j*item+i];
          if (j*item+item-i<s.size()) result += s[j*item+item-i];
        }
      }
    }
    return result;
  }
};
