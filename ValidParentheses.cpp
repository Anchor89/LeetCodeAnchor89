#include "LeetCode.h"

class Solution {
public:
  bool isLeft(char c) {
    return c=='[' || c=='{' || c=='(';
  }
  bool isPair(char l, char r) {
    return (l=='(' && r==')') || (l=='[' && r==']') || (l=='{' && r=='}');
  }
  bool isValid(string s) {
    stack<char> par;
    for (char c:s) {
      if (isLeft(c)) { 
        par.push(c);
      } else if (!par.empty() && isPair(par.top(), c)) {
        par.pop();
      } else {
        return false;
      }
    }
    return par.empty();
  }
};
