
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ds course knowledge
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *prev = nullptr;
        while(cur != nullptr) {
            ListNode *pp = prev;
            prev = cur;
            cur = cur->next;
            prev->next = pp;
        }
        return prev;
    }
};