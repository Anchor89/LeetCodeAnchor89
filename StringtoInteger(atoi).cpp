#include "LeetCode.h"

class Solution {
public:
  int atoi(const char *str) {
    int size = strlen(str);
    const char* cur = find_if_not(str, str+size, [](const char c) { return isspace(c);});
    if (cur == str+size) return 0;
    bool neg = *cur == '-';
    if (*cur == '-' || *cur=='+') cur++;
    if(cur >= str+size|| !isdigit(*cur)) return 0;
    long long res = 0;
    while(cur<str+size && isdigit(*cur)) {
      res = res*10L + (*cur-'0');
      cur++;
    }
    res = neg? -res:res;
    if (res > INT_MAX) res = INT_MAX;
    if (res < INT_MIN) res = INT_MIN;
    return res;
  }
};
