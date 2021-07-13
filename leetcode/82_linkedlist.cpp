
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// first try, requires clear brain
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode *nh = head; //newhead
        ListNode *cur = head;
        ListNode *prev = head;
        
        ListNode *tail = head->next;
        
        while(cur != nullptr && cur->next != nullptr) {
            tail = cur->next;
            if(cur->val == tail->val) {
                while(tail->next != nullptr && cur->val == tail->next->val)
                    tail = tail->next;
                // got the chain
                if(cur == nh) {
                    nh = tail->next;
                    prev = nh;
                    cur = nh;
                }
                else {
                    prev->next = tail->next;
                    cur = tail->next;
                }
            }
            else {
                prev = cur;
                cur = cur->next;
            }
        }
        return nh;
    }
};