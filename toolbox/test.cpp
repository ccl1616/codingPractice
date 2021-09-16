#include <bits/stdc++.h>
using namespace std;


int main() {
    vector< vector<int> > big;
    vector<int> ret = { 1,2,3 };
    big.push_back(ret);
    for(int i = 0; i < ret.size(); i ++)
        cout << ret[i] << endl;
    cout << "size: " << big.size() << endl;
    cout << "size[0]: " << big[0].size() << endl;
}