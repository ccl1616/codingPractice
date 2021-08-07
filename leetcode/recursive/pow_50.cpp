#include <bits/stdc++.h>
using namespace std;

// 50
// sol
// https://leetcode.com/problems/powx-n/discuss/739646/C%2B%2B-Iterative-vs.-Recursive-Bitwise-Solutions-Explained-100-Time-80-space
class Solution {
public:
    double myPow(double x, int n) {
        // if(n == 0) return 1;
        // else if(n > 0) return x*myPow(x, n-1);
        // else if(n < 0) return (1/x)*myPow(x, n+1);
        // else return 1;
        double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }
    double myPow(double x, int n, double res = 1) {
        return n ? myPow(x * x, n / 2, n % 2 ? (n > 0 ? res * x : res / x) : res) : res;
    }
};