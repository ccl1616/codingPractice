#include <bits/stdc++.h>
using namespace std;

int main() {
    int r = 5;
    int c = 10;
    int arr[r][c];
    for(int i = 0 ; i < r; i ++){
        for(int j = 0; j < c; j ++)
            arr[i][j] = c*i + j;
    }
    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}