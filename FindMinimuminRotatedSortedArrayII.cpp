class Solution {
public:
  int findMin(vector<int> &num) {
    return *min_element(num.begin(), num.end());
  }
};
