#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int count = n;
        for(int i = 1; i <= n; i ++) {
            count -= i;
            if(count < 0) return i-1;
            if(count == 0) return i;
        }
        return count;
    }
};