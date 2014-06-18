#include "LeetCode.h"

class Solution {
public:
  bool isOp(const string& s) {
    return s=="+" || s=="-" || s=="*" || s=="/";
  }
    
  int op(const string& op, int left, int right) {
    if (op == "+") return left+right;
    if (op == "-") return left-right;
    if (op == "*") return left*right;
    if (op == "/") return left/right;
  }
  int evalRPN(vector<string> &tokens) {
    stack<int> result;
    if (tokens.size() == 0) return 0;
    for (int i=0; i<tokens.size(); i++) {
      if (isOp(tokens[i])) {
        int right = result.top(); result.pop();
        int left = result.top(); result.pop();
        result.push(op(tokens[i], left, right));
      } else {
        result.push(atoi(tokens[i].c_str()));
      }
    }
    return result.top();
  }
};
