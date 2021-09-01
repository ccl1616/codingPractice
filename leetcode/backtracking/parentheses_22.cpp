#include <bits/stdc++.h>
using namespace std;

// 22

// after sol
// not really understand why we don't need to flush the str
class Solution {
public:
    vector<string> ret;
    int N;
    vector<string> generateParenthesis(int n) {
        N = n;
        func("", 0, 0);
        return ret;
    }
    void func(string str, int left, int right) {
        if(str.length() == N*2) {
            ret.push_back(str);
            return;
        }
        if(left < N) func( str+"(", left+1, right);
        if(right < left) func( str+")", left, right+1);
    }
};

class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        func("", 0, 0, n);
        return ret;
    }
    void func(string str, int left, int right, int n) {
        if(str.length() == n*2) {
            ret.push_back(str);
            return;
        }
        if(left < n) func( str+"(", left+1, right, n);
        if(right < left) func( str+")", left, right+1, n);
    }
};