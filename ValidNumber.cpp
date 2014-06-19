#include "LeetCode.h"

class Solution {
public:
  const char* skipWs(const char* s) {
    while(*s != '\0' && isblank(*s)) s++;
    return s;
  }
  const char* skipInt(const char* s) {
    while(*s != '\0' && isdigit(*s)) s++;
  }
  const char* skipSign(const char* s) {
    return (*s == '+' || *s == '-')? s+1:s;
  }
  const char* skipDot(const char* s) {
    return (*s == '.')? s+1:s;
  }
  const char* skipEe(const char* s) {
    return (*s == 'e' || *s == 'E')? s+1:s;
  }
  bool isNumber(const char *s) {
    const char* tail = s;
    while(*tail != '\0') tail++;
    for(tail--;tail>=s && isblank(*tail); tail--);
    if (tail<s) return false;
    tail++;
#define fail(i) if (i>=tail) return false
#define success(i) if (i >=tail) return true
    const char* cur = skipWs(s);
    fail(cur); // fail empty string
    cur = skipSign(cur);
    fail(cur); // fail +/-
    cur = skipInt(cur);
    success(cur); // success +/-1334
    cur = skipDot(cur);
    success(cur); // success +/-1234.
    cur = skipInt(cur);
    success(cur); // success +/-123.123
    cur = skipEe(cur);
    fail(cur); // fail +/-123E/e
    cur = skipSign(cur);
    fail(cur); // fail +/-123E/e+/-
    cur = skipInt(cur);
    success(cur); // success +/-123E/e+/-234
    fail(cur);
  }
};

int main() {
  Solution s;
  cout << s.isNumber("3") << endl;
  return 0;
}
