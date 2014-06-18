#include "LeetCode.h"

class Solution {
public:
  typedef pair<int,int> Pair;
  int largestRectangleArea(vector<int> &height) {
    if (height.empty()) return 0;
    stack<Pair> s;
    s.push(Pair(0, height[0]));
    height.push_back(0);
    int size = height.size(), result = 0, l;
    for (int i=1; i<size; i++) {
      l = i;
      while(!s.empty() && s.top().second > height[i]) {
        result = max(result, s.top().second*(i-s.top().first));
        l = s.top().first;
        s.pop();
      }
      s.push(Pair(l, height[i]));
    }
    return result;
  }
};
