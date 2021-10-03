
// key: use a min heap pq
#include <iostream>
#include <queue>
  
using namespace std;


class KthLargest {
public:
    int k_;
    priority_queue<int, vector<int>, greater<int> > pq; // min heap pq

    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(int x: nums) add(x);
    }
    
    int add(int val) {
        if(pq.size() < k_) pq.push(val);
        else {
            if(val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
  
};