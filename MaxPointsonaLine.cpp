#include "LeetCode.h"

class Solution {
public:
  int maxPoints(vector<Point> &points) {
    vector<Point> lines;
    int size = points.size();
    int sameCount = 0;
    int result = 0;
    for (auto& point : points) {
      sameCount = 0;
      lines.clear();
      for (auto& other : points) {
        Point vec(point.x-other.x, point.y-other.y);
        if (vec.x == 0 && vec.y == 0) {
          sameCount++;
        } else {
          lines.push_back(vec);
        }
      }
      sort(lines.begin(), lines.end(), [](const Point& a, const Point& b) {
          return (long long)a.y*b.x<(long long)b.y*a.x;
        });
      auto isSame = [](const Point& a, const Point& b) {return (long long)a.y*b.x==(long long)b.y*a.x;};
      for (int i=0, j=1; i<lines.size(); i=j++) {
        for (; j<lines.size() && isSame(lines[j], lines[i]); j++);
        result = max(result, j-i+sameCount);
      }
      result = max(result, sameCount);
    }
    return result;
  }
};
