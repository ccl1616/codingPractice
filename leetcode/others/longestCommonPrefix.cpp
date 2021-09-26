#include <bits/stdc++.h>
using namespace std;
// 14.

// sol1, clear and good
string longestCommonPrefix(vector<string>& strs) {
    string res;
    char c;
    // Dealt with empty input
    if(strs.size() < 1) return res;
    // Loop through the length of each word
    for(int i = 0; i < strs[0].size(); i++){
        c = strs[0][i];
        // if current length is longer than the word length
        for(auto s : strs)
            if(i+1 > s.size() || c != s[i]) return res;
        // if the current character is shared by all of the words
        // then add to the result string
        res.push_back(c);
    }
    return res;
}