#include "LeetCode.h"

class Solution {
public:
  void removeHeadingZeros(string& num) {
    auto nz = find_if_not(num.begin(), num.end(), [](char c) {return c=='0';});
    num = nz == num.end() ? "0": num.substr(nz-num.begin());
  }
  string multiply(string num1, string num2) {
    if (num1.empty() || num2.empty()) return string();
    removeHeadingZeros(num1);
    removeHeadingZeros(num2);
    int size1 = num1.size();
    int size2 = num2.size();
    int carry = 0;
    string result(size1+size2, '0');
    for (int i=size1+size2-2; i>=0; i--) {
      int sum = carry;
      for (int j=min(size1-1, i), k=i-j; j>=0 && k<size2; j--, k++) {
        sum += (num1[j]-'0') * (num2[k]-'0');
      }
      carry = sum / 10;
      result[i+1] = (sum%10)+'0';
    }
    if (carry > 0) result[0] = carry+'0';
    removeHeadingZeros(result);
    return result;
  }
};
