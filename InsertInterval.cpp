#include "LeetCode.h"

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int i, j, size = intervals.size();
    for (i=0; i<size && intervals[i].end < newInterval.start; i++);
    if (i == size) {
      intervals.push_back(newInterval);
    } else if (intervals[i].start > newInterval.end) {
      intervals.insert(intervals.begin()+i, newInterval);
    } else {
      intervals[i].start = min(intervals[i].start, newInterval.start);
      int curEnd = max(intervals[i].end, newInterval.end);
      for (j=i+1; j<size && intervals[j].start <= curEnd; j++) {
        curEnd = max(curEnd, intervals[j].end);
      }
      intervals[i].end = curEnd;
      intervals.erase(intervals.begin()+i+1, intervals.begin()+j);
    }
    return intervals;
  }
};
