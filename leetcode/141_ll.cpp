// linked list cycle
// this is a problem of Floyd Cycle detection

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        if( head == nullptr || head->next == nullptr) return false;
        
        while( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true; // there's a loop found
        }
        return false; // no loop
    }
};