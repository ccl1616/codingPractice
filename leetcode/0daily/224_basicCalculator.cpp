#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int sign = 1;
        stack<pair<int, int>> S;
        for(int i = 0; i < s.size(); i ++) {
            char ch = s[i];
            if( isdigit(ch) ) {
                long long int num = 0;
                // get number that has more than one digit
                while( i < s.size() && isdigit(s[i]) ) {
                    num *= 10;
                    num += (s[i] - '0');
                } 
                i --;
                // put it into sum, don't forget the sign
                sum += (num *= sign);
                sign = 1;
            }
            else if( ch == '(') {
                S.push(make_pair(sum, sign)); // save result before bracket
                sum = 0;
                sign = 1;
            }
            else if( ch == ')') {
                // get S out
                sum = S.top().first + S.top().second * sum; // sum is the result inside the bracket, mix it with the outer bracket
                S.pop();
            }
            else if( ch == '-') {
                // don't forget the minus number
                sign = (-1) * sign;
            }
            else continue;
        }
        return sum;
    }
};