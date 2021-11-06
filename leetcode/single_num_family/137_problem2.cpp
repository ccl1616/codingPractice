#include <bits/stdc++.h>
using namespace std;
// related to finite state? bit manipulation
// todo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Solution {
public:
    int singleNumber(vector<int>& A) {
        /*
    First time number appear -> save it in "ones"

    Second time -> clear "ones" but save it in "twos" for later check

    Third time -> try to save in "ones" but value saved in "twos" clear it.
        */
        int ones = 0, twos = 0;
        for(int i = 0; i < A.size(); i++){
            ones = (ones ^ A[i]) & ~twos;
            twos = (twos ^ A[i]) & ~ones;
        }
        return ones;
    }
};