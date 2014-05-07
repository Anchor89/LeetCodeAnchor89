#include "LeetCode.h"

class Solution {
public:
  void reverse(string& s, int h, int t) {
    while(h<t) swap(s[h++], s[t--]);
  }
  void reverseWords(string &s) {
    int sz,p,g;
    for (sz = s.size(), g = 0, p = 0; g < sz;) {
      while(g < sz && s[g] == ' ') g++;
      while(g < sz && s[g] != ' ') s[p++]=s[g++];
      if (g < sz) s[p++] = ' ';
    }
    if (p>0 && s[p-1]==' ') s.erase(p-1); else s.erase(p);
    int sz = s.size();
    reverse(s, 0, sz-1);
    for(int h = 0,t = 0; h < sz; h = t++ + 1) {
      while(t < sz && s[t] != ' ') t++;
      reverse(s, h, t-1);
    }
  }
};
