#include <bits/stdc++.h>
using namespace std;

// wa
int reverse(int x) {
    if(x == 0) return 0;
    bool neg = (x < 0) ?true:false;
    int ret = 0;
    while(x != 0) {
        ret *= 10;
        ret += x%10;
        x /= 10;
        // cout << ret << endl;
    }
    return ret;
}

// ac
int reverse(int x) {
    int y = 0;
    while(x != 0)
    {
        if((y > (INT_MAX/10))||(y < (INT_MIN/10))) return 0; // to handle overflow
        y = 10 * y + x % 10;
        x = x / 10;
    }
    return y;
}

int main() 
{
    int x = -123;
    cout << "main: " << reverse(x) << endl;
}
