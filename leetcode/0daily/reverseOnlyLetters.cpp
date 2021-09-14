#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l < r && l < s.size() ) {
            if( !isalpha(s[l]) ) {
                l ++;
            }
            if( !isalpha(s[r])) {
                r --;
            }

            if( isalpha(s[l])&&isalpha(s[r]) ) {
                // swap
                char tmp = s[r];
                s[r] = s[l];
                s[l] = tmp;
                l ++;
                r --;
            }
        }
        return s;
    }
};