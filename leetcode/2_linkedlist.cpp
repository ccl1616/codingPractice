
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

// my v2
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

// ref
// recursion sol
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		// base case
        if(l1 == nullptr && l2 == nullptr) return nullptr;
		
        int sum = 0;
        if(l1 != nullptr){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr){
            sum += l2->val;
            l2 = l2->next;
        }
        
        ListNode* res = new ListNode(sum%10);
		// if sum > 9 ( not a digit) carry 1 to next node
        if(sum > 9){
            if(l1 != nullptr) l1->val ++;
            else if(l2 != nullptr) l2->val ++;
            else{
				// if both l1 and l2 are nullptr,  create new node with value 1
                res->next = new ListNode(sum/10);
                return res;
            }
        }
        res->next = addTwoNumbers(l1, l2);
        
        return res;
    }
};

// faster sol 16ms, this is really neat
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            curr->val += l1 ? l1->val : 0; // if(l1) add l1->val
            curr->val += l2 ? l2->val : 0;
            curr->val += carry;
            carry = curr->val/10;
            curr->val %= 10;
            
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            if(l1 || l2 || carry)
                curr->next = new ListNode(0);
            curr = curr->next;
        }
        
        return head;
    }
};