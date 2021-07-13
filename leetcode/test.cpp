#include <iostream>
#include <string>
#include <queue>
using namespace std;

// comparator
int compare( const void *arg1 , const void *arg2) {
    return ( *(int*)arg1 - *(int*)arg2 );
}

int main() {
    int arr[3] = {0,0,0};
    for(int i = 0; i < 3; i ++)
        cout << arr[i] << endl;
    cout << "-" << endl;
    return 0;
}