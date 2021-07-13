#include <iostream>
#include <string>
#include <queue>
using namespace std;

// comparator
int compare( const void *arg1 , const void *arg2) {
    return ( *(int*)arg1 - *(int*)arg2 );
}

int main() {
    queue <int> q1,q2;
    for(int i = 0; i < 5; i ++)
        q1.push(i+1);
    q2.swap(q1);
    while( !q2.empty()) {
        cout << q2.front() << endl;
        q2.pop();
    }
    return 0;
}