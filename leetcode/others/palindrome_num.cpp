#include <bits/stdc++.h>
using namespace std;

// 9
// chenk if it is a palindrome number

// string method
class Solution {
public:
    bool isPalindrome(int x) {
        string s1 = to_string(x);
        string s2 = s1;
        reverse(s2.begin(), s2.end() );
        return (s1 == s2);
    }
};

// reverse number method, faster
class Solution {
public:
    bool isPalindrome(int x) {
        long ret = 0;
        int d = 0;
        int original = x;

        if(x < 0) return false;
        while(x != 0) {
            d = x % 10;
            ret = ret*10 + d;
            x /= 10;
        }

        return (ret == original);
    }
};