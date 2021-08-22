#include <bits/stdc++.h>
using namespace std;

// 1011 
// sol
class Solution {
public:
    int countDays(vector<int>& ws, int tot_cap, int cur_cap = 0, int res = 1) {
        for (auto w : ws) {
            cur_cap += w;
            if (cur_cap > tot_cap) ++res, cur_cap = w;
        }
        return res;
    }
    int shipWithinDays(vector<int>& ws, int D) {
        auto r = accumulate(begin(ws), end(ws), 0);
        auto l = max(r / D, *max_element(begin(ws), end(ws)));
        while (l < r) {
            auto m = (l + r) / 2;
            if (countDays(ws, m) <= D) r = m;
            else l = m + 1;
        }
        return l;
    }
};

// doing
class Solution {
public:
    // int func( vector<int> w, int total, int cur = 0, int ret = 1) {
    //     for(auto x : w) {
    //         cur += x;
    //         if( cur > total) {
    //             ret += 1;
    //             cur = x;
    //         }
    //     }
    //     return ret;
    // }
    int func(vector<int>& ws, int tot_cap, int cur_cap = 0, int res = 1) {
        for (auto w : ws) {
            cur_cap += w;
            if (cur_cap > tot_cap) ++res, cur_cap = w;
        }
        return res;
    }
    int shipWithinDays(vector<int>& w, int d) {
        // return least capacity
        int r = accumulate( w.begin(), w.end(), 0 );
        int l = max ( r/d, *max_element( w.begin(), w.end()) );
        while( l < r ) {
            int m = (l + 1) / 2 ;
            if( func( w, m ) <= d ) r = m;
            else l = m + 1;
        }
        return l;
    }
};