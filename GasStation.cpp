#include "LeetCode.h"

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    if (gas.empty()) return -1;
    vector<int> rest(gas.size()<<1); // expand the circle
    transform(gas.begin(), gas.end(), cost.begin(), rest.begin(), minus<int>());
    int head = 0, tail = 1, left=rest[0], sz = gas.size();
    copy(rest.begin(), rest.begin()+sz, rest.begin()+sz);
    while(tail-head<sz && head < sz) {
      if(left < 0) {
        head = tail++;
        left = rest[head];
      } else {
        left += rest[tail++];
      }
    }
    return left<0 || head == sz? -1:head;
  }
};
