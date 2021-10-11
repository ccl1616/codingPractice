#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int p, int r)
{
    int pivot = a[p];
    int i = p - 1;
    int j = r + 1;
    while (1)
    {
        do {
            i++;
        } while (a[i] < pivot); // until a[i] >= pivot stop
 
        do {
            j--;
        } while (a[j] > pivot); // until a[i] <= pivot stop
 
        if(i < j)
            swap(a[i], a[j]);
        else {
            cout << "i: " << i << endl << "j: ";
            return j;
        }
    }
}

int main()
{
    int a[] = {13,19,9,5,12,8,7,4,11,2,6,21};
    cout << partition(a, 0, 11) << endl;
    for(int i = 0; i < 12; i ++)
        cout << a[i] << " ";
    cout << endl;
}