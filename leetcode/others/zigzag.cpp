#include <bits/stdc++.h>
using namespace std;

// 6.
// my code !
string convert(string s, int numRows) {
    if(numRows == 1) return s;
    vector<string> vec;
    string ret = "";
    for(int i = 0; i <= numRows; i ++) {
        vec.push_back("");
    }
    int p = 1;
    bool increase = true;
    for(int i = 0; i < s.length(); i ++) {
        // cout << p << endl;
        vec[p] += s[i];
        if(p == numRows) increase = increase ?false :true;
        if(p == 1) {
            p += 1; 
            increase = true;
        }
        else p += increase ?1 :-1;
    }
    for(auto x:vec)
        ret += x;
    return ret;
}

int main() {
    string test = "PAYPALISHIRING";
    cout << convert(test, 4) << endl;
}