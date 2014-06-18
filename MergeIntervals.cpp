#include "LeetCode.h"

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start || (a.start == b.start && a.end < b.end);
      });
    int curEnd, i,j;
    for (i=0; i<intervals.size(); i++) {
      curEnd = intervals[i].end;
      for (j=i+1; j<intervals.size() && intervals[j].start <= curEnd; j++) {
        curEnd = max(curEnd, intervals[j].end);
      }
      intervals[i].end = curEnd;
      intervals.erase(intervals.begin()+i+1, intervals.begin()+j);
    }
    return intervals;
  }
};
