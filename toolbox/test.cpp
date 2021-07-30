#include <bits/stdc++.h>
using namespace std;

void func(int& j)
{
    j ++;
    return;
}
int main() {
    vector< vector<int> > arr;
    vector<int> vect{ 10, 20, 30 };
    vector<int> vect2{ 10, 20, 30 };
    arr.push_back(vect);
    arr.push_back(vect2);
    cout << arr.size()<< endl; // row num
    cout << arr[0].size()<< endl;
    return 0;
}