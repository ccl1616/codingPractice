#include <bits/stdc++.h>
using namespace std;

// 6.
// my code !
string convert(string s, int numRows) {
    if(numRows == 1) return s;
    vector<string> vec;
    string ret = "";
    for(int i = 0; i <= numRows; i ++) 
        vec.push_back("");
    
    int row = 1;
    bool increase = true;
    for(int i = 0; i < s.length(); i ++) {
        vec[row] += s[i];
        if(row == numRows) increase = increase ?false :true;
        if(row == 1) {
            row += 1; 
            increase = true;
        }
        else row += increase ?1 :-1;
    }
    for(auto x:vec)
        ret += x;
    return ret;
}

int main() {
    string test = "abcd";
    cout << convert(test, 2) << endl;
}