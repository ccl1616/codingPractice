#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// first try (failed)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head = nullptr) return;
        
        std::stack<ListNode*> ns; //node stack
        ListNode* ptr = head;
        while(ptr != nullptr) {
            ns.push(ptr);
            ptr = ptr->next;
        }
        
        ptr = head;

        while(ptr != nullptr && ptr->next != nullptr) {
            ListNode* topnode = ns.top();
            if( ptr->val != topnode->val && ptr->next->val != topnode->val ){
                ListNode* nxt = ptr->next;
                ns.pop();

                ptr->next = topnode;
                topnode->next = nxt;
                ptr = nxt;
            }
            else {
                ptr->next = nullptr;
                return;
            }
        }
        
        return;
    }
};