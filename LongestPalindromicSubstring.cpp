#include "LeetCode.h"

/* O(n) Manacher */
class Solution {
public:
  string manacher(string& s) {
    int rm = 1, rmIdx = 1, maxRad = 0;
    vector<int> rad(s.size(), 0);
    for (int i=2; i<s.size()-1; i++) {
      rad[i] = i<rm? min(rad[(rmIdx<<1)-i], rm-i):0;
      while(s[i-rad[i]]==s[i+rad[i]]) rad[i]++;
      rad[i]--;
      if (i+rad[i]>rm) {
        rm = i+rad[i];
        rmIdx = i;
      }
      if (rad[i] > rad[maxRad]) maxRad = i;
    }
    string res="";
    if (rad[maxRad] == 0) {
      res = s[2];    
    } else {
      for (int i=maxRad-rad[maxRad]; i<=maxRad+rad[maxRad]; i++) {
        if (s[i] != '\2') res+=s[i];
      }
    }
    return res;
  }
  string longestPalindrome(string s) {
    if (s.empty()) return string();
    string ns = string("\1\2") + s[0];
    for (int i=1; i<s.size(); i++) {
      ns += string("\2") + s[i];
    }
    ns += "\2\3";
    return manacher(ns);
  }
};

/* O(n^2) */
class Solution {
public:
  string longestPalindrome(string s) {
    int size = s.size(), result = 0, h;
    for (int i=0,j; i<size; i++) {
      for (j=0; i-j>=0 && i+1+j<size && s[i-j] == s[i+1+j]; j++);
      if (j<<1 > result) {
        result = j<<1;
        h = i-j+1;
      }
      for (j=1; i-j>=0 && i+j <size && s[i-j] == s[i+j]; j++);
      if ((j<<1)-1 > result) {
        result = (j<<1)-1;
        h = i-j+1;
      }
    }
    return s.substr(h, result);
  }
};
