#include "LeetCode.h"

class Solution {
public:
  using Node = UndirectedGraphNode;
  Node* getOther(unordered_map<Node*, Node*>& shadow, Node* ori) {
    if (ori == nullptr) return nullptr;
    if (shadow.find(ori) == shadow.end()) {
      shadow.insert(make_pair(ori, new Node(ori->label)));
    }
    return shadow.find(ori)->second;
  }
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) return nullptr;
        
    unordered_map<Node*, Node*> shadow;
    queue<Node*> q;
    unordered_set<Node*> visited;
    q.push(node);
    visited.insert(node);
    while(!q.empty()) {
      Node* cur = q.front();
      q.pop();
      Node* other = getOther(shadow, cur);
      for (auto adj : cur->neighbors) {
        other->neighbors.push_back(getOther(shadow, adj));
        if (visited.find(adj) == visited.end()) {
          visited.insert(adj);
          q.push(adj);
        }
      }
    }
    return getOther(shadow, node);
  }
};
