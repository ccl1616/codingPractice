#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace  std;

void func(int& j)
{
    j ++;
    return;
}
int main() {
    int j = 0;
    func(j);
    cout << j << endl;
    return 0;
}