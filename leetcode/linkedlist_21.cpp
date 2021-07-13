#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

// first try
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        // while the head of both are still exist
        while(l1 && l2) {
            if(l1->val <= l2->val){
                prev->next = l1;
                l1 = l1->next;
            }
            else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        // two list are checked

        if(l1 == NULL)
            prev->next = l2;
        if(l2 == NULL)
            prev->next = l1;
        return dummy->next;
    }
};

// generate a new list to save the result
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // determine who would be the head
        if(!l1) return l2;
        else if(!l2) return l1;
        else {
            // use a real head here !
            ListNode* head = new ListNode();
            ListNode* prev = head;

            
            if(l1->val <= l2->val){
                head = l1;
                l1 = l1->next;
            }
            else {
                head = l2;
                l2 = l2->next;
            }
            prev = head;
            
            // compare and append
            while(l1 && l2) {
                if(l1->val <= l2->val){
                    prev->next = l1;
                    l1 = l1->next;
                }
                else {
                    prev->next = l2;
                    l2 = l2->next;
                }
                prev = prev->next;
            }
            // deal with left overs
            if(!l1) prev->next = l2;
            if(!l2) prev->next = l1;
            return head;
        }
    }
};

// recursive !!
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val>=l2->val) {
        l2->next = mergeTwoLists(l1, l2-> next);
        return l2;
    }
    else{
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
}