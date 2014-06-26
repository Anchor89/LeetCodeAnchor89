#include "LeetCode.h"
class Solution {
public:
  vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    vector<vector<string>> result[2];
    if (start == "" || end == "" ) return result[0];
    if (start == end) return vector<vector<string>>{vector<string>{start, end}};
    unordered_map<string, int> depth;
    vector<string> tree;
    tree.push_back(end);
    depth[end] = 0;
    dict.insert(start);
    int head = 0, size = start.size();
    while(head < tree.size()) {
      string cur = tree[head++];
      int d = depth[cur];
      for (int i=0; i<size; i++) {
	char ori = cur[i];
	for (char c='a'; c<='z'; c++) {
	  cur[i] = c;
	  if (dict.find(cur) == dict.end()) continue;
	  if (depth.find(cur) != depth.end()) continue;
	  depth[cur] = d+1;
	  tree.push_back(cur);
	}
	cur[i] = ori;
      }
    }
    if (depth[start] == 0) return result[0];
    result[depth[start]&1].push_back(vector<string>{start});
#define pre(lvl) ((lvl&1)^1)
    for(int lvl = depth[start]; lvl > 0; lvl--) {
      result[pre(lvl)].clear();
      for (auto& path : result[lvl&1]) {
	string back = path.back();
	for (int i=0; i<size; i++) {
	  char ori = back[i];
	  for (char c='a'; c<='z'; c++) {
	    back[i] = c;
	    if (depth.find(back) == depth.end() || depth[back] != lvl-1) continue;
	    result[pre(lvl)].push_back(path);
	    result[pre(lvl)].back().push_back(back);
	  }
	  back[i] = ori;
	}
      }
    }
    return result[0];
  }
};
