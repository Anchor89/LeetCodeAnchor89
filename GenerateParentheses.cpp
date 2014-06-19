#include "LeetCode.h"

class Solution {
public:
  vector<string> result;
  int leftNum;
  void dfs(string& path, int idx, int n) {
    if (idx == leftNum << 1) {
      result.push_back(path);
    } else {
      if (n<leftNum) {
        path[idx] = '(';
        dfs(path, idx+1, n+1);
      }
      if (n << 1 > idx) {
        path[idx]=')';
        dfs(path, idx+1, n);
      }
    }
  }
  vector<string> generateParenthesis(int n) {
    leftNum = n;
    result.clear();
    string path(n<<1,' ');
    dfs(path, 0, 0);
    return result;
  }
};
