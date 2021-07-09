#include <iostream>
using namespace std;

// comparator
int compare( const void *arg1 , const void *arg2) {
    return ( *(int*)arg1 - *(int*)arg2 );
}

int main() {
    int values[6] = {6,5,4,3,2,1};
    int n;
    qsort (values, 6, sizeof(int), compare);
    for (n = 0; n < 6; n ++)
        printf ("%d ",values[n]);
    return 0;
}