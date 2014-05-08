/**************** String *******************/
//Remove extra spaces:
// Given string s, remove heading and tailing spaces.
// Compress continuous spaces to one space.
void removeExtraSpaces(string &s) {
  int sz,p,g;
  for (sz = s.size(), g = 0, p = 0; g < sz;) {
    while(g < sz && s[g] == ' ') g++;
    while(g < sz && s[g] != ' ') s[p++]=s[g++];
    if (g < sz) s[p++] = ' ';
  }
  if (p>0 && s[p-1]==' ') p--;
  s.erase(p);
}

/***************** List ********************/
// Use super head:
ListNode h, *t=&h;
