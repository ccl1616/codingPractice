#include <bits/stdc++.h>
using namespace std;


int myAtoi(string s) {
    long long int num = 0;
    bool isNeg = false;
    int i = 0;
    // leading white space
    while( (int)s[i] == 32 ) i ++;
    while( i < s.size() ) {
        
        if( s[i] == '-' ) {
            if( !isdigit(s[i+1]) )
                return 0;
            isNeg = true;
        }
        else if( s[i] == '+' && s[i+1] == '-' )
            return 0;
        else if( !isdigit(s[i]) && s[i] != '+' ) 
            break;
        else if( s[i] != '+') {
            num *= 10;
            num += s[i]-'0';
        }
        i ++;
    }
    if( num > numeric_limits<int>::max() ) {
        num = isNeg ?numeric_limits<int>::min():numeric_limits<int>::max();
        return num;
    }
    return isNeg ? (-1)*num : num;
}

int main() {
    int sign = 1;
    sign = (3 > 2) ?:-1;
    cout << sign << endl;
    return 0;
}