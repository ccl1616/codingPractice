#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace  std;

int main() {
    unordered_map<int, int> m;
    m[1] = 1;
    if(m.count(1)) cout << "exist\n";
    else cout << "nah\n";
    return 0;
}