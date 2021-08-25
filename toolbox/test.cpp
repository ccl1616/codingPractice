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
    vector<vector<int> > v;
    vector<int> j;
    vector<int> k;
    for(int i = 0; i < 10; i ++) {
        j.push_back(i);
        k.push_back(i);
    }
    v.push_back(j);
    v.push_back(k);
    cout << v.size() << endl;
    cout << v[0].size() << endl;
    return 0;
}