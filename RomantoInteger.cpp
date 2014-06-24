#include "LeetCode.h"

class Solution {
public:
  using T = string::iterator;
  int form(T& begin, T end, char n1, char n5, char n10) {
    int result = 0;
    T t1m = find_if_not(begin, end, [&](char c) {return c==n1;});
    T t5 = find_if_not(t1m, end, [&](char c) {return c==n5;});
    T t1p = find_if_not(t5, end, [&](char c) {return c==n1;});
    T t10 = find_if_not(t1p, end, [&](char c) {return c==n10;});
    if (t5 != t1m) {
      if (t1m != begin) {
	result = 5 - distance(begin, t1m);
      } else if (t1p != t5) {
	result = 5 + distance(t5, t1p);
      } else {
	result = 5;
      }
    } else {
      result = t10 == t1m? distance(begin, t1m):9;
    }
    begin = max(max(t1m, t5), max(t1p, t10));
    return result;
  }
  int romanToInt(string s) {
    T begin = s.begin();
    int result = 0;
    int radix = 1000;
    while(begin != s.end()) {
      result += radix*form(begin, s.end(), 'M', 'M', 'M');
      radix/=10;
      result += radix*form(begin, s.end(), 'C', 'D', 'M');
      radix/=10;
      result += radix*form(begin, s.end(), 'X', 'L', 'C');
      radix/=10;
      result += radix*form(begin, s.end(), 'I', 'V', 'X');
    }
    return result;
  }
};
