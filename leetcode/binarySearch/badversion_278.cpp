#include <bits/stdc++.h>
using namespace std;

// 278, after sol, classic bs
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        while(left < right) {
            int mid = left + (right-left)/2 ;
            if( !isBadVersion(mid) ) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};