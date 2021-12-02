#include <bits/stdc++.h>
using namespace std;


int main() {
    bool flag = true;
    for(int i = 0; i < 3; i ++) {
        cout << i << ": " << flag << endl;
        flag = !flag;
    }
    return 0;
}
