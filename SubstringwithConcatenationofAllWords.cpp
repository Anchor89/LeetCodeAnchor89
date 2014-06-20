#include "LeetCode.h"

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> result;
    if (S.empty() || L.empty()) return result;
    int len = L[0].size();
    int size = S.size();
    unordered_map<string, int> limit, cur; // Use two counter
    for ( auto& l : L) {
      limit[l]++;
    }
    for (int i=0; i<len; i++) {
      cur.clear();
      int count = 0;
      for (int head = i, tail=i; tail+len<=size; head+=len) {
        string sub = S.substr(tail, len);
        while (!sub.empty() && limit.count(sub) > 0 && cur[sub] < limit[sub]) {
          count += ++cur[sub] == limit[sub]? 1:0;
          tail+=len;
          sub = tail+len <= size? S.substr(tail, len):"";
        }
        if (count == limit.size()) {
          result.push_back(head);
        }
        if (!sub.empty() && limit.count(sub) > 0) {
          count -= cur[S.substr(head, len)]--==limit[S.substr(head, len)]? 1:0;
        } else {
          cur.clear();
          count = 0;
          head = tail;
          tail+=len;
        }
      }
    }
    return result;
  }
};

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> result;
    if (S.empty() || L.empty()) return result;
    int len = L[0].size();
    int size = S.size();
    unordered_map<string, int> limit; // Use only one counter
    for ( auto& l : L) {
      limit[l]++;
    }
    for (int i=0; i<len; i++) {
      int count = limit.size();
      for (int head = i, tail=i; head+len<=size; head+=len, tail = max(tail, head)) {
        string sub = tail+len <= size? S.substr(tail, len):"";
        while (sub.size() == len && limit.count(sub) > 0 && limit[sub] > 0) {
          limit[sub]--;
          count -= limit[sub] == 0? 1:0;
          tail+=len;
          sub = S.substr(tail, len);
        }
        if (count == 0) {
          result.push_back(head);
        }
        if (limit.count(S.substr(head, len)) > 0) {
          if (limit[S.substr(head, len)]++ == 0) count++;
        }
      }
    }
    return result;
  }
};
