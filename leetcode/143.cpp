#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// first try (WA)
// failed reason: cannot determine the stopiing time just by comparing ptr and stacl.top()
class Solution {
public:
    void reorderList(ListNode* head) {
        if( (!head) || (!head->next) || (!head->next->next) ) return;
        
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
            else if(ptr->next->val == topnode->val){
                ptr->next->next = nullptr;
                return;
            }
            else {
                ptr->next = nullptr;
                return;
            }
        }
        
        return;
    }
};

// sol
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return; // Edge cases
        
        stack<ListNode*> my_stack;
        ListNode* ptr = head;
        int size = 0;
        while (ptr != NULL) // Put all nodes in stack
        {
            my_stack.push(ptr);
            size++;
            ptr = ptr->next;
        }
        
        ListNode* pptr = head;
        for (int j=0; j<size/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = my_stack.top();
            my_stack.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};