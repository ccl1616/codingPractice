#include <bits/stdc++.h>
using namespace std;
// 328

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        queue<int> oddnum;
        queue<int> evennum;
        ListNode* pt = head;
        bool odd = true;
        while(pt != NULL) {
            if(!odd) 
                evennum.push(pt->val);
            else 
                oddnum.push(pt->val);
            odd = !odd;
            pt = pt->next;
        }
        pt = head;
        odd = true;
        int tmp = 0;
        while(!oddnum.empty() && pt != NULL) {
            pt->val = oddnum.front();
            oddnum.pop();
            pt = pt->next;
        }
        while(!evennum.empty() && pt != NULL) {
            pt->val = evennum.front();
            evennum.pop();
            pt = pt->next;
        }

        return head;
    }
};
