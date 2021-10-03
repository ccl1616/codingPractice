// queue, medium

#include <iostream>
#include <queue>

// my first try
class MyCircularQueue {
public:
    int *arr;
    int front = 0;
    int rear = -1;
    int capacity = -1;
    int cur_size = 0;
    
    MyCircularQueue(int k) {
        capacity = k;
        arr = new int[k];
    }
    
    bool enQueue(int value) {
        if(this->isFull()) return false;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        cur_size ++;
        return true;
    }
    
    bool deQueue() {
        if(this->isEmpty()) return false;
        front = (front + 1) % capacity;
        cur_size --;
        return true;
    }
    
    int Front() {
        if(this->isEmpty()) return -1;
        else {
            return arr[front];
        }
    }
    
    int Rear() {
        if(this->isEmpty() || rear == -1) return -1;
        else {
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(capacity != -1 && cur_size == 0) return true; // capacity has been changed, but element num=0
        else return false;
    }
    
    bool isFull() {
        if(cur_size == capacity) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */