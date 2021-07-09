
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// first try
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        else if(l2 == nullptr) return l1;
        else {
            ListNode *p1 = l1;
            ListNode *p2 = l2;
            int temp = 0;
            // accumulate value on l2
            while(p1->next != nullptr && p2->next != nullptr) {
                temp += p1->val; temp += p2->val;
                
                p1->val = temp % 10;
                temp /= 10;
                
                p1 = p1->next;
                p2 = p2->next;
            }
            if(!p1->next && !p2->next) {
                temp += p1->val; temp += p2->val;
                
                p1->val = temp % 10;
                temp /= 10;
                if(temp > 0) {
                    p1->next = new ListNode(temp);
                }
                return l1;
            }
            else {
                if(p2->next == nullptr) {
                    temp += p1->val; temp += p2->val;

                    p1->val = temp % 10;
                    temp /= 10;
                }
                else if(p1->next == nullptr) {
                    temp += p1->val; temp += p2->val;
                    p1->val = temp % 10;
                    temp /= 10;
                    p1->next = p2->next;
                }
                
                p1 = p1->next;
                while(p1->next != nullptr) {
                    temp += p1->val;
                    p1->val = temp % 10;
                    temp /= 10;
                    
                    p1 = p1->next;
                }
                
                // last digit
                temp += p1->val;
                p1->val = temp % 10;
                temp /= 10;
                // add new
                if(temp > 0) {
                    p1->next = new ListNode(temp);
                }
                return l1;
            }
            
        }
    }
};

// v2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        else if(l2 == nullptr) return l1;
        else {
            ListNode *l3 = new ListNode();
            ListNode *cur = l3;
            int sum = 0;
            while(l1 != nullptr || l2 != nullptr || sum > 0 ) {
                if(l1 != nullptr) {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if(l2 != nullptr) {
                    sum += l2 ->val;
                    l2 = l2->next;
                }
                
                cur->val = sum % 10;
                sum /= 10;
                if(l1 != nullptr || l2 != nullptr || sum > 0 )
                    cur->next = new ListNode(0);
                cur = cur->next;
            }
            return l3;
        }
    }
};