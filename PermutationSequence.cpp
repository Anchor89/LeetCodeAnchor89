#include "LeetCode.h"

class Solution {
public:
  int fac(int k) {
    int sum = 1;
    for (int i=1; i<=k; i++) {
      sum *= i;
    }
    return sum;
  }
  string cal(vector<int>& num, int k) {
    int n = num.size(), sub = fac(n), idx;
    string res = "";
    for (;n>0; n--) {
      sub /= n;
      idx = k / sub;
      k = k % sub;
      res += '0'+num[idx];
      num.erase(num.begin()+idx);
    }
    return res;
  }
  string getPermutation(int n, int k) {
    vector<int> num;
    for (int i=1; i<=n; i++) {
      num.push_back(i);
    }
    return cal(num, k-1);
  }
};
