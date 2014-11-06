#include "LeetCode.h"

class LRUCache{
public:
  using Container = list<pair<int, int>>;
  using ContainerPtr = Container::iterator;
  using Index = unordered_map<int, ContainerPtr>;
    
  Container container;
  Index index;
  int capacity;
  LRUCache(int capacity_) {
    capacity = capacity_;
  }
    
  int get(int key) {
    int result = -1;
    if (index.count(key) > 0) {
      result = index[key]->second;
      set(key, result);
    }
    return result;
  }
    
  void set(int key, int value) {
    if (index.count(key) > 0) {
      container.erase(index[key]);
      container.push_front(make_pair(key,value));
      index[key] = container.begin();
    } else {
      container.push_front(make_pair(key, value));
      index[key] = container.begin();
      while (container.size() > capacity) {
	index.erase(container.back().first);
	auto last = container.end();
	last--;
	container.erase(last);
      }
    }
        
  }
};
