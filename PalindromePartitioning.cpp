#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> nextIdx;
  vector<vector<string>> result;
  void dfs(vector<string>& line, int idx, string& s) {
    if (idx == s.size()) {
      result.push_back(line);
      return;
    }
    for (int next : nextIdx[idx]) {
      line.push_back(s.substr(idx, next-idx));
      dfs(line, next, s);
      line.pop_back();
    }
  }
  vector<vector<string>> partition(string s) {
    nextIdx.clear();
    nextIdx.resize(s.size());
    int size = s.size();
    for (int i=0; i<size; i++) {
      int p,q;
      for(p=i,q=i; p>=0 && q<size && s[p] == s[q]; p--, q++) {
        nextIdx[p].push_back(q+1);
      }
      for (p=i,q=i+1; p>=0 && q<size && s[p] == s[q]; p--, q++) {
        nextIdx[p].push_back(q+1);
      }
    }
    vector<string> line;
    dfs(line, 0, s);
    return result;
  }
;}
