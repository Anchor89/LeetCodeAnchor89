#include "LeetCode.h"

class Solution {
public:
  inline bool same(char a, char b) {
    return a==b || isalpha(a) && isalpha(b) && (a-b=='A'-'a' || a-b=='a'-'A');
  }
  bool isPalindrome(string s) {
    for(int head = 0, tail = s.size()-1; head<tail; head++,tail--;) {
      while(head<tail && !isalnum(s[head])) head++;
      while(head<tail && !isalnum(s[tail])) tail--;
      if (head<tail && !same(s[head], s[tail])) return false;
    }
    return true;
  }
};
