#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// trying to build a minHeap
void swap( int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MaxHeap {
    vector<int> arr;
    int capacity;
    int k;
    int size = 0; // current size;


    public:
        MaxHeap(int capcity, int k);
        MaxHeap(int capcity, int k, vector<int>& nums);

        void Heapify(int v);
        int parent(int v) { return (v-1)/2 ; };
        int left(int v) { return (2*v + 1); }; // get left child
        int right(int v) { return (2*v + 2); }; 
        int getMax(int v);
        
        // Inserts a new key 'k'
        void insertKey(int k);

        void debug();
};

MaxHeap::MaxHeap(int cap, int k_)
{
    k = k_;
    capacity = cap;
}

MaxHeap::MaxHeap(int cap, int k_, vector<int>& nums)
{
    sort(nums.end(),nums.begin());
    for(int i = 0; i < nums.size(); i ++)
        arr.push_back(nums[i]);
    k = k_;
    capacity = cap;
    size = nums.size();
}

void MaxHeap::debug()
{
    cout << "cap: " << capacity << endl;
    cout << "k: " << k << endl;
    cout << "size: " << size << endl;

    for(int i = 0 ; i < size; i ++)
        cout << arr[i] << ",";
    cout << endl;
}

void MaxHeap::Heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int cur = i;
    if(l < size && arr[l] > arr[i])
        cur = l;
    if(r < size && arr[r] > arr[cur])
        cur = r;
    if(cur != i) {
        swap(&arr[i], &arr[cur]);
        Heapify(cur);
    }
}

// insert val into heap
void MaxHeap::insertKey(int val)
{
    arr.push_back(val);
    int i = size;
    size ++;
    // if not min heap, swap
    while(i != 0 && arr[parent(i)] < arr[i] ) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
    Heapify(0);
}

int MaxHeap::getMax(int k)
{
    錯了錯了錯了！
    int cur = 0;
    int val = arr[cur];
    while( !k ) {
        cur = arr[left(cur)] > arr[right(cur)]? left(cur):right(cur);
        k--;
    }
    return arr[k];
}

int main() {
    // vector<int> vec;
    // for(int i = 1; i <= 5; i ++)
    //     vec.push_back(10-i);
    // MinHeap heap(10, 3, vec);

    MaxHeap heap(10,3);
    heap.insertKey(1);
    heap.insertKey(5);
    heap.insertKey(3);
    heap.insertKey(10);
    heap.insertKey(15);
    heap.insertKey(4);
    heap.insertKey(2);
    heap.debug();
    int i = 3;
    cout << i << " biggest: " << heap.getMax(i) << endl;
}