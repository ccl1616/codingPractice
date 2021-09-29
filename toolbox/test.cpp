#include <bits/stdc++.h>
using namespace std;


int main() {
    int len = 18;
    int k = 4;
    int n = len / k, r = len % k; 
    for (int i = 0; i < k; i++, r--) {
        cout << (r > 0) << endl;
        // cout << ( n + (r>0)) << endl;
        for (int j = 0; j < n + (r > 0); j++) {
            cout << "inner\n";
        }
        
    }
}