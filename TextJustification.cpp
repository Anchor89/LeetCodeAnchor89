#include "LeetCode.h"

class Solution {
public:
  string format(vector<string>& words, int head, int tail, int cur, int L) {
    int rest = L - cur;
    int len = tail - head;
    if (len == 1) {
      return words[head] + string(L-cur, ' ');
    }
    int single = rest % (len-1);
    int multi = rest / (len-1);
    string res = words[head++];
    for(;head < tail; head++) {
      res += string(multi, ' ') + (single-->0?"  ":" ") + words[head];
    }
    return res;
  }
  vector<string> fullJustify(vector<string> &words, int L) {
    vector<string> res;
    if (words.size() == 0) return res; 
    int head = 0, tail = 1, size = words.size();
    int cur;
    while(head < size) {
      cur = words[head].size();
      while(tail<size && cur+1+words[tail].size() <= L) cur+=1+words[tail++].size();
      if (tail < size) res.push_back(format(words, head, tail, cur, L)); 
      else {
        string line = words[head++];
        for (; head<tail;head++) {
          line += " " + words[head];
        }
        line += string(L-line.size(), ' ');
        res.push_back(line);
      }
      head = tail++;
    }
    return res;
  }
};
