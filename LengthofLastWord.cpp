#include "LeetCode.h"

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    const char *head, *tail;
    int result = 0;
    for(head = s; *head != '\0'; head = tail) {
      for(;*head == ' '; head++);
      tail = head;
      for(;*tail != '\0' && *tail != ' '; tail++);
      if (tail-head>0) result = tail-head;
    }
    return result;
  }
};
