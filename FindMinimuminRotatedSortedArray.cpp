class Solution {
public:
  template<class T>
  int findMin(T head, T tail) {
    if (head == tail || *head < *tail) return *head;
    while(tail-head>1) {
      T mid = head + ((tail-head) >>1);
      if (*mid < *head) {
	tail = mid;
      } else {
	head = mid;
      }
    }
    return *tail;
  }
  int findMin(vector<int> &num) {
    return findMin(num.begin(), num.end()-1);
  }
};
