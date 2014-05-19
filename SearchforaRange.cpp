#include "LeetCode.h"

class Solution {
public:
    pair<int, int> searchPair(int A[], int n, int target) {
        int lt = 0, rht = n-1;
        while(rht-lt>1) {
            int mid=(rht+lt) >> 1;
            if (A[mid] >= target) rht = mid;
            else lt = mid;
        }
        return make_pair(lt, rht);
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        if (n == 0 || target < A[0] || target > A[n-1]) return result;
        if (A[0] == target) result[0] = 0;
        else result[0] = searchPair(A, n, target).second;
        if (A[n-1] == target) result[1] = n-1;
        else result[1] = searchPair(A, n, target+1).first;
        return A[result[0]] == target? result:vector<int>(2, -1);
    }
};