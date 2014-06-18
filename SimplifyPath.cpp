#include "LeetCode.h"

class Solution {
public:
  string simplifyPath(string path) {
    int head = 0, tail = 1;
    vector<string> dir;
    vector<string> out;
    while(head < path.size()) {
      while(tail < path.size() && path[tail] != '/') tail++;
      if (tail - head > 1) dir.push_back(path.substr(head+1, tail-head-1));
      head = tail;
      tail++;
    }
    for (auto& d : dir) {
      if (d == ".") continue;
      if (d == ".." && !out.empty()) out.pop_back();
      if (d != ".." ) out.push_back(d);
    }
    string result;
    for (auto& d : out) {
      result += "/";
      result += d;
    }
    return result == ""? "/":result;
  }
};
