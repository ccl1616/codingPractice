#include <bits/stdc++.h>
using namespace std;
// 13
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i ++) {
            char x = s[i];
            if(x == 'I') {
                if(s[i+1] == 'V' || s[i+1] == 'X') 
                    sum -= 1;
                else sum ++;
            }
            else if(x == 'X') {
                if(s[i+1] == 'L' || s[i+1] == 'C') 
                    sum -= 10;
                else sum += 10;
            }
            else if(x == 'C') {
                if(s[i+1] == 'D' || s[i+1] == 'M') 
                    sum -= 100;
                else sum += 100;
            }
                
            else if(x == 'V') sum += 5;
            else if(x == 'L') sum += 50;
            else if(x == 'D') sum += 500;
            else if(x == 'M') sum += 1000;
        }
        return sum;
    }
};