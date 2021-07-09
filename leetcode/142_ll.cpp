
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// algo: Floyd Cycle detection - adv
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        if(head == nullptr || head->next == nullptr) return nullptr;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                ListNode *temp = head;
                if(temp == slow) return temp; // they meet at 0
                // on the way they meet
                while(temp != slow) {
                    temp = temp->next;
                    slow = slow->next;
                    if(temp == slow){
                        // they meet at the beginning of the loop
                        return temp;
                    }
                }
            }
        }
        return nullptr;
    }
};