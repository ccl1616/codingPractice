/*
    some stack op

    std::stack<int> myStack; 
    myStack.push(sth);
    myStack.pop();
    myStack.top();
    myStack.empty();
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// first try
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ms;
        for(int i = 0; i < s.length(); i ++){
            char cur = s[i];
            if(cur == '(' || cur == '{' || cur == '[') {
                ms.push(cur);
            }
            else{
                if(ms.empty()) return false; // check before pop 
                char tmp = ms.top();
                if(tmp == '(' && cur != ')') return false;
                else if(tmp == '{' && cur != '}') return false;
                else if(tmp == '[' && cur != ']') return false;
                else ms.pop();
            }
        }
        if(!ms.empty()) return false; // check if the stack is empty
        return true;
    }
};