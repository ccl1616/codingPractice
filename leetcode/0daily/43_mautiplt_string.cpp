#include <bits/stdc++.h>
using namespace std;

// simiar to old times big number mulpitlication question!
// 1107 daily
// WA when number is super large
class Solution {
public:
    
    long long int getnum(string str) {
        long long int num = 0;
        for(int i = 0; i < str.size(); i ++) {
            num *= 10;
            num += str[i]-'0';
        }
        return num;
    }
    
    string multiply(string num1, string num2) {
        long long int n1 = getnum(num1);
        long long int n2 = getnum(num2);
        
        ostringstream ss;
        ss << n1*n2;
        string ret = ss.str();
        return ret;
    }
};

// sol, https://leetcode.com/problems/multiply-strings/discuss/1563507/C%2B%2B-Simple-Easy-and-Short-Solution-Brief-Explanation
// multiply like human, traverse the number by using m*n time
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        vector<int> res(num1.size()+num2.size(), 0);
        
        // start from right side
        for (int i = num1.size()-1; i >= 0; i--) {
            for (int j = num2.size()-1; j >= 0; j--) {
                res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0'); // first save mul result int [i+j+1]
                res[i + j] += res[i + j + 1] / 10; // carry out
                res[i + j + 1] %= 10; // modify the lower bit to correct number
            }
        }
        
        int i = 0;
        string ans = "";
        while (res[i] == 0) i++; // skip leading 0
        // while (i < res.size()) ans += to_string(res[i++]);
        while (i < res.size()) ans.push_back(res[i++] + '0'); // transfer by ourself would be faster, using to_string is slow
        
        return ans;
    }
};