#include <bits/stdc++.h>
using namespace std;


int main() {
    // convert string to num
    string str = "12345";
    int num = 0;
    for(int i = 0; i < str.size(); i ++) {
        num *= 10;
        num += str[i]-'0';
    }
    cout << num << endl;

    // convert num to string type
    ostringstream ss;
    ss << num;
    string ret = ss.str();
    ret = ret + "yo!";
    cout << ret << endl;
}
