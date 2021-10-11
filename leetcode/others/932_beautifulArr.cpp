#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        int mid = ( n%2 ) ?( n/2 +1) : ( n/2 );
        cout << mid;
        int l = 1;
        int r = n;
        vector<int> ret;
        ret.push_back(mid);
        while(ret.size() != n && r > l) {
            if(l < mid) {
                ret.push_back(l); 
                l++;
            }
            if(r > mid) {
                ret.push_back(r); 
                r--;
            }
            
        }
        return ret;
    }
};