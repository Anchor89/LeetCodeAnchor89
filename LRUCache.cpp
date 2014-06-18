#include "LeetCode.h"

class LRUCache{
public:
  int size = 0;
  int capacity = 0;
  using Content = list<pair<int, int>>;
  using ContentIte = Content::iterator;
  using Index = unordered_map<int, ContentIte>;
  Index index;
  Content content;
  LRUCache(int capacity) {
    this->capacity = capacity;
  }
    
  int get(int key) {
    if (index.find(key) == index.end()) return -1;
    moveToHead(key);
    return content.front().second;
  }
    
  void set(int key, int value) {
    erase(key);
    index[key] = content.insert(content.begin(), make_pair(key, value));
    size++;
    if (size > capacity && content.size() > 0) {
      erase(content.back().first);
    }
  }
    
  void erase(int key) {
    if (index.find(key) != index.end()) {
      content.erase(index.find(key)->second);
      index.erase(key);
      size--;
    }
  }
    
  void moveToHead(int key) {
    if (index.find(key) != index.end()) {
      auto ite = index.find(key)->second;
      content.insert(content.begin(), *ite);
      content.erase(ite);
      index[key] = content.begin();
    }
  }
};
