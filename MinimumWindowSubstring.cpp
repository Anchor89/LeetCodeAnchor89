#include "LeetCode.h"

class Solution {
public:
  // cost too much time
  string minWindow(string S, string T) {
    unordered_map<char, int> limit;
    for (char c : T) {
      limit.insert(make_pair(c, 0)).first->second++;
    }
    int head = 0, tail = 0;
    int minh = 0, mint = INT_MAX;
    int count = 0;
    int size = S.size();
    while(head < size) {
      for(;tail<size && count < limit.size(); tail++) {
        if (limit.find(S[tail]) != limit.end()) {
          limit[S[tail]]--;
          if (limit[S[tail]] == 0) {
            count++;
          }
        }
      }
      if (count == limit.size() && tail-head < mint-minh) {
        tie(minh, mint) = tie(head, tail);
      }
      if (limit.find(S[head]) != limit.end()) {
        if (limit[S[head]] == 0) count--;
        limit[S[head]]++;
      }
      head++;
      if (count == limit.size() && tail-head < mint-minh) {
        tie(minh, mint) = tie(head, tail);
      }
    }
    return mint != INT_MAX? S.substr(minh, mint-minh):string();
  }
};
