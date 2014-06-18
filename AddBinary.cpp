#include "LeetCode.h"

class Solution {
public:
  string addBinary(string a, string b) {
    int size = max(a.size(), b.size());
    a = string(size-a.size(), '0') + a;
    b = string(size-b.size(), '0') + b;
    string res = string(size, '0');
    int sum=0, carry = 0;
    for (int i=size-1; i>=0; i--) {
      int x = a[i]-'0', y = b[i]-'0';
      sum = x+y+carry;
      carry = sum >> 1;
      res[i] = '0' + (sum&1);
    }
    return carry==0? res:"1"+res;
  }
};
