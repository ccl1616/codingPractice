#include <bits/stdc++.h>
using namespace std;

// 779
// myself AC :)
class Solution {
public:
    int kthGrammar(int n, int k) {
        // all 1-indexed
        // n,k 
        // n-1, prevk
        // prevk = k/2 ? 0 : 1; // bitwise
        
        int ret = 0;
        if(n == 1) return 0;
        bool isOdd = k%2;
        int i = (k == 1) ?1:( isOdd ?(k/2+1):k/2 );
        return isOdd ?kthGrammar(n-1, i):( kthGrammar(n-1, i) ?0:1);
    }
};