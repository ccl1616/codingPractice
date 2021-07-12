#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        for(int i = 0; i < tokens.size(); i ++) {
            string tmp = tokens[i];
            
            if( !tmp.compare("+") || !tmp.compare("-") || !tmp.compare("*") || !tmp.compare("/")  ) {
                int a = stack.top(); stack.pop();
                int b = stack.top(); stack.pop();
                int num = 0;
                if(!tmp.compare("+")) num = a + b;
                else if(!tmp.compare("-")) num = b - a;
                else if(!tmp.compare("*")) num = a * b;
                else if(!tmp.compare("/")) num = b / a;
                stack.push(num);
            }
            else {
                int num = 0;
                if(tmp.length() != 1) {
                    if(tmp[0] != '-') 
                        num = (int)tmp[0] - '0';
                    for(int i = 1; i < tmp.length(); i ++) {
                        num *= 10;
                        num += (int)tmp[i] - '0';
                    }
                    if(tmp[0] == '-') num *= (-1);
                }
                else {
                    num = (int)tmp[0] - '0';
                }
                stack.push(num);
            }
        }
        int ret = stack.top();
        return ret;
    }
};