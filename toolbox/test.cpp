#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,bool> m;
    m["hi"] = 1;
    auto iter = m.find("hi");
    if(iter != m.end()) cout << "1" << endl;
    else cout << "0" << endl;
    return 0;
}