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

/* Solution 2 */
int findMin(vector<int>& num) {
  if (num.size() == 1 || num.front() < num.back()) return num.front();
  int head = 0, tail = num.size()-1;
  while(tail-head>1) {
    int mid = (head&tail) + ((head^tail)>>1); // prevent overflow
    *(num[mid]<num[head]? &tail:&head) = mid;
  }
  return num[tail];
}
