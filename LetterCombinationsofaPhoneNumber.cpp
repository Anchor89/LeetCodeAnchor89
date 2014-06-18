#include "LeetCode.h"

class Solution {
public:
  string cm[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    result.push_back("");
    for (char digit : digits) {
      int d = digit - '0';
      if (d == 1) continue;
      int oldSize = result.size();
      for (int i=1; i<cm[d].size(); i++) {
        result.resize(result.size()+oldSize);
        copy(result.begin(), result.begin()+oldSize, result.end()-oldSize); // result.insert will cause reallocation so result.begin() is not we want here. Use copy instead.
      }
      for (int i=0; i<cm[d].size(); i++) {
        for (int j=0; j<oldSize; j++) {
          result[i*oldSize+j].push_back(cm[d][i]);
        }
      }
    }
    return result;
  }
};
