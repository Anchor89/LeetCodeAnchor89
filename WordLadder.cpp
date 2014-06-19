#include "LeetCode.h"

class Solution {
public:
  inline string& next(string& s, int i) {
    s[i] = s[i] == 'z'?'a':s[i]+1;
    return s;
  }
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    int lvl = 0;
    queue<string> q[2];
    q[0].push(start);
    while(!q[lvl&1].empty()) {
      string front = q[lvl&1].front();
      q[lvl&1].pop();
      if (front == end) return lvl+1;
      int sz = front.size();
      for (int i=0; i<sz; next(front, i++)) {
        for (int j=1; j<26; j++) {
          if (dict.erase(next(front, i)) == 1) {
            q[(lvl+1)&1].push(front);
          }
        }
      }
      if (q[lvl&1].empty()) lvl++;
    }
    return 0;
  }
};
