#include <iostream>
#include <string>
using namespace std;

// comparator
int compare( const void *arg1 , const void *arg2) {
    return ( *(int*)arg1 - *(int*)arg2 );
}

int main() {
    string tmp = "-489";
    cout << "str len: " << tmp.length() << endl; 
    int num;
    if(tmp.length() != 1) {
        if(tmp[0] != '-') 
            num = (int)tmp[0] - '0';
        for(int i = 1; i < tmp.length(); i ++) {
            num *= 10;
            num += (int)tmp[i] - '0';
        }
        if(tmp[0] == '-') num *= (-1);
    }
    else {
        cout << "hi\n";
        num = (int)tmp[0] - '0';
    }
    cout << num+10 << endl;
    return 0;
}