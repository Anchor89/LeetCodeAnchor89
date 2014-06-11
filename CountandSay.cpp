#include "LeetCode.h"

class Solution {
public:
  string next(string& s) {
    string result = "";
    auto head = s.begin();
    while(head != s.end()) {
      auto tail = find_if_not(head, s.end(), [&](char c) {return c == *head;});
      result += '0' + (tail-head);
      result += *head;
      head = tail;
    }
    return result;
  }
  string countAndSay(int n) {
    if (n == 0) return string();
    string s = "1";
    while(--n) {
      s = next(s);
    }
    return s;
  }
};
