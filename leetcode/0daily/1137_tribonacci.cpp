#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int arr[38];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        int ret = 0;
        if(n <= 2) {
            if(n == 0) return 0;
            else return 1;
        }
        for(int i = 3; i <= n; i ++) 
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        return arr[n];
    }
};