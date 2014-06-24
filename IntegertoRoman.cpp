#include "LeetCode.h"

class Solution {
public:
  string form(int num, char n1, char n5, char n10) {
    if (num == 0) {
      return string();
    } else if (num < 4) {
      return string(num, n1);
    } else if (num == 4) {
      return string(1, n1) + n5;
    } else if (num == 5) {
      return string(1, n5);
    } else if (num < 9) {
      return string(1, n5) + string(num-5, n1);
    } else if (num == 9) {
      return string(1, n1) + n10;
    }
  }
  string intToRoman(int num) {
    string result;
    if(num > 0) {
      result = form(num%10, 'I', 'V', 'X');
      num/=10;
      result = form(num%10, 'X', 'L', 'C') + result;
      num/=10;
      result = form(num%10, 'C', 'D', 'M') + result;
      num/=10;
      result = form(num%10, 'M', 'M', 'M') + result;
    }
    return result;
  }
};
