#include <bits/stdc++.h>
using namespace std;

// my shitty code
string shiftingLetters(string s, vector<int>& shifts) {
    string ret = s;
    int size = s.size();
    for(int i = 0; i < size; i ++) {
        int num = 0;
        for(int j = i; j < size; j ++) 
            num += shifts[j];
        cout << num << endl;
        ret[i] = ( ret[i] + num % 26 )>'z' ? ( ret[i] + num % 26 - 'z') : ( ret[i] + num % 26 );
    }
    return ret;
}

// sol
string shiftingLetters(string s, vector<int>& shifts) {
    long shift = 0; // save the prefix sum, long to avoid overflow by huge number
    // go through each of them backwardly, since the prefix sum could help it
    for(int i = s.size()-1 ; i >= 0 ; i -- ){
        //  ( (count from 0) + shift_num%26 ) %26 + 'a'to get back to ascii
        s[i] = ((s[i]-'a')+(shift+shifts[i]) % 26) % 26 + 'a';
        shift += shifts[i]; // prefix sum
    }
    return s;
}

// me after sol
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long sum = 0;
        int size = s.size();
        for(int i = size-1; i >= 0; i --) {
            int num = (sum + shifts[i]) % 26;
            s[i] =  ( (s[i] - 'a') + num ) % 26 + 'a';
            sum += shifts[i];
        }
        return s;
    }
};

int main() {
    string s = "ruu";
    vector<int> v = {26, 9, 17};
    string ret = shiftingLetters(s, v);
    for(int i = 0; i < s.size(); i ++)
        cout << ret[i] << " ";
    cout << endl;
    return 0;
}