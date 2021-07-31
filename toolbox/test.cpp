#include <bits/stdc++.h>
using namespace std;

void func(int& j)
{
    j ++;
    return;
}
int main() {
    int val = 10;
    int* dp = new int[val];
    dp[5] = 50;
    cout << dp[5] << endl;
    return 0;
}