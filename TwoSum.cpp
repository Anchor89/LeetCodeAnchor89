#include "LeetCode.h"

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    using Pair = pair<int, int>;
    vector<Pair> num(numbers.size());
    int count = 1;
    transform(numbers.begin(), numbers.end(), num.begin(), [&](int n) {return Pair(count++, n);});
    sort(num.begin(), num.end(), [](const Pair& p1, const Pair& p2) {return p1.second < p2.second; });
    auto head = num.begin(), tail = num.end()-1;
    while(head<tail) {
      int t = head->second + tail->second;
      if ( t == target) {
        return vector<int>{min(head->first, tail->first), max(head->first, tail->first)};
      } else if (t < target) {
        head++;
      } else {
        tail--;
      }
    }
    return vector<int>(2, 0);
  }
};
