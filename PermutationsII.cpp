#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> res;
  typedef vector<int>::iterator T;
  bool next_perm(T begin, T end) {
    T cur;
    for (cur=end-1; cur>begin && *cur<=*(cur-1); cur--) ;
    if (cur == begin) return false;
    T pivot = cur-1, mid = cur+(end-cur)/2, tail=end;
    while(tail-cur > 1) {
      if (*mid>*pivot) {
	cur = mid;
      } else {
	tail = mid;
      }
      mid = cur+(tail-cur)/2;
    }
    iter_swap(cur, pivot);
    sort(pivot+1, end);
    return true;
  }
  vector<vector<int>> permuteUnique(vector<int>&num) {
    vector<vector<int>> res;
    sort(num.begin(), num.end());
    do {
      res.push_back(num);
    } while(next_perm(num.begin(), num.end()));
    return res;        
  }
};
