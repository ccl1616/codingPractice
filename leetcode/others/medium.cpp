#include <bits/stdc++.h>
using namespace std;

// 31, next permutation
// two pointers
// ref sol1
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i, tmp;
        while (i > 0 && nums[i-1] >= nums[i])
            i--;
        for (int j=i; j<k; j++, k--)
            tmp = nums[j], nums[j] = nums[k], nums[k] = tmp;
        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i])
                k++;
            tmp = nums[i], nums[i] = nums[k], nums[k] = tmp;
        }
    }
};
// sol2
class Solution {
public:
    void nextPermutation(vector<int> &num) 
    {
        if (num.empty()) return;
        
        // in reverse order, find the first number which is in increasing trend (we call it violated number here)
        int i;
        for (i = num.size()-2; i >= 0; --i)
        {
            if (num[i] < num[i+1]) break;
        }
        
        // reverse all the numbers after violated number
        reverse(begin(num)+i+1, end(num));
        // if violated number not found, because we have reversed the whole array, then we are done!
        if (i == -1) return;
        // else binary search find the first number larger than the violated number
        auto itr = upper_bound(begin(num)+i+1, end(num), num[i]);
        // swap them, done!
        swap(num[i], *itr);
    }
};
// ================================================================================================

// 8. Atoi ,string to num

// my code, broken :')
int myAtoi(string s) {
    long long int num = 0;
    bool isNeg = false;
    int i = 0;
    // leading white space
    while( (int)s[i] == 32 ) i ++;
    while( i < s.size() ) {
        
        if( s[i] == '-' ) {
            if( !isdigit(s[i+1]) )
                return 0;
            isNeg = true;
        }
        else if( s[i] == '+' && s[i+1] == '-' )
            return 0;
        else if( !isdigit(s[i]) && s[i] != '+' ) 
            break;
        else if( s[i] != '+') {
            num *= 10;
            num += s[i]-'0';
        }
        i ++;
    }
    if( num > numeric_limits<int>::max() ) {
        num = isNeg ?numeric_limits<int>::min():numeric_limits<int>::max();
        return num;
    }
    return isNeg ? (-1)*num : num;
}

// sol, so good and straight foward !
class Solution {
public:
    int myAtoi(string s) {
        bool start = false;
        int sign = 1;
        long res = 0;
        for (char c: s) {
            if ('0' <= c && c <= '9') {
                start = true;
                res = res * 10 + (c - '0');
                if (res > INT_MAX) {
                    break;
                }
            } else if (!start && c == ' ') {
                continue;
            } else if (!start && c == '+') {
                start = true;
            } else if (!start && c == '-') {
                sign = -1;
                start = true;
            } else {
                break;
            }
        }
        res *= sign;
        if (res < INT_MIN) {
            res = INT_MIN;
        } else if (res > INT_MAX) {
            res = INT_MAX;
        }
        return int(res);
    }
};