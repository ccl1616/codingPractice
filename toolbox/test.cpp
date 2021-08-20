#include <bits/stdc++.h>
using namespace std;

void func(int x) {
    int y = 0;
    int i = 0;
    stack<int> st;
    while( x != 0) {
        cout << x % 10 << endl;
        y += (x % 10) * pow(10,i);
        i ++;
        x /= 10;
    }
    cout << y << endl;
}

int main() {
    func(1234567890);
    return 0;
}