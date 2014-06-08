#include "LeetCode.h"

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int i, carry = 0, size = digits.size();
    for (i=size-1; i>=0 && digits[i] == 9; i--) {
      digits[i] = 0;
      carry = 1;
    }
    if (i >= 0) digits[i]++; else digits.insert(digits.begin(), 1);
    vector<int> res;
    for (i=0; digits[i]==0; i++){
      ;
    }
    res.insert(res.end(), digits.begin()+i, digits.end());
    return res;
  }
};
