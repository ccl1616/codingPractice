
#include <iostream>
#include <string>
#include <queue>
using namespace std;

// myself after some study from gg (https://www.geeksforgeeks.org/implement-stack-using-queue/)
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    queue<int> q1;
    queue<int> q2;
    
    /** Push element x onto stack. */
    void push(int x) {
        // queue<int> q2;
        q2.push(x);
        while( !q1.empty() ) {
            q2.push( q1.front());
            q1.pop();
        }
        q1.swap(q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q1.front();
        q1.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        int ret = q1.front();
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */