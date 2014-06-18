#include "LeetCode.h"

class Solution {
public:
  int size;
  vector<vector<int>> next;
  vector<string> line;
  vector<string> result;
  string join(vector<string> line) {
    if (line.size() == 0) return string();
    string result = line[0];
    for (int i=1; i<line.size(); i++) {
      result += " ";
      result += line[i];
    }
    return result;
  }
  void dfs(const string& s, int idx) {
    if (idx == size) {
      result.push_back(join(line));
      return;
    }
    for (int n : next[idx]) {
      line.push_back(s.substr(idx, n-idx));
      dfs(s, n);
      line.pop_back();
    }
  }
  vector<string> wordBreak(string s, unordered_set<string> &dict) {
    result.clear();
    size = s.size();
    next.clear();
    next.resize(size, vector<int>());
    bool arrive = false;
    for (int i=0; i<size; i++) {
      for (int j=1; i+j<=size; j++) {
        if (dict.find(s.substr(i,j)) != dict.end()) {
          next[i].push_back(i+j);
          arrive = arrive || i+j==size;
        }
      }
    }
    if (arrive) {
      line.clear();
      dfs(s, 0);
    }
    return result;
  }
};
