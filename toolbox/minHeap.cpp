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

class MinHeap {
    vector<int> arr;
    int capacity;
    int k;
    int size = 0; // current size;


    public:
        MinHeap(int capcity, int k);
        MinHeap(int capcity, int k, vector<int>& nums);

        void MinHeapify(int v);
        int parent(int v) { return (v-1)/2 ; };
        int left(int v) { return (2*v + 1); }; // get left child
        int right(int v) { return (2*v + 2); }; 
        int extractMin();
        int getMin(int v);
        
        void decreaseKey(int i, int new_val);
        // Deletes a key stored at index i
        void deleteKey(int i);
    
        // Inserts a new key 'k'
        void insertKey(int k);

        void debug();
};

MinHeap::MinHeap(int cap, int k_)
{
    k = k_;
    capacity = cap;
}

MinHeap::MinHeap(int cap, int k_, vector<int>& nums)
{
    for(int i = 0; i < nums.size(); i ++)
        arr.push_back(nums[i]);
    sort(arr.begin(), arr.end() );
    k = k_;
    capacity = cap;
    size = nums.size();
}

void MinHeap::debug()
{
    cout << "cap: " << capacity << endl;
    cout << "k: " << k << endl;
    cout << "size: " << size << endl;

    for(int i = 0 ; i < size; i ++)
        cout << arr[i] << ",";
    cout << endl;
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < size && arr[l] < arr[i])
        smallest = l;
    if(r < size && arr[r] < arr[smallest])
        smallest = r;
    if(smallest != i) {
        swap(&arr[i], &arr[smallest]);
        MinHeapify(smallest);
    }
}

// insert val into heap
void MinHeap::insertKey(int val)
{
    arr.push_back(val);
    int i = size;
    size ++;
    // if not min heap, swap
    while(i != 0 && arr[parent(i)] > arr[i] ) {
        swap(&arr[i], &arr[parent(i)]);
        i = parent(i);
    }
    MinHeapify(0);
}

int main() {
    // vector<int> vec;
    // for(int i = 1; i <= 5; i ++)
    //     vec.push_back(10-i);
    // MinHeap heap(10, 3, vec);

    MinHeap heap(10,3);
    heap.insertKey(10);
    heap.insertKey(8);
    heap.insertKey(1);
    heap.insertKey(7);
    heap.insertKey(5);
    heap.insertKey(3);
    heap.debug();
}