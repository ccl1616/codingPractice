#include <bits/stdc++.h>
using namespace std;

// wa, i'm silly
class Solution {
public:
    string breakPalindrome(string palindrome) {
        string ret = "";
        int n = palindrome.size();
        if(n <= 1) return ret;
        ret = palindrome;
        for(int i = 0; i < n; i ++) {
            if(ret[i] != 'a') {
                ret[i] = 'b'; // accidently wrong
                return ret;
            }
        }
        ret[n-1] = 'b';
        return ret;
    }
};

// ac, simple and clear
class Solution {
public:
    string breakPalindrome(string palindrome) {
        // string ret = "";
        int n = palindrome.size();
        if(n <= 1) return "";
        
        // for(int i = 0; i < n ; i ++) {
        for(int i = 0; i < n/2 ; i ++) { // becareful, only check the first partition
            if(palindrome[i] != 'a') {
                palindrome[i] = 'a'; // change the first non-a into a
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};