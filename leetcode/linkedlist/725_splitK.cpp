#include <bits/stdc++.h>
using namespace std;
// 0929 daily
// split into k parts

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// shit :)
// class Solution {
// public:
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         ListNode* cur = head;
//         int N = 0;
//         while(cur != NULL) {
//             cur = cur->next;
//             N ++;
//         }
//         int width = N / k, rem = N % k;
//         // vector<ListNode*> ret;
//         vector<ListNode*> ret(k, nullptr);
//         cur = head;
//         for(int i = 0; i < k; i ++) {
//             ListNode tmp = ListNode(0);
//             ListNode write = tmp;
//             for (int j = 0; j < width + (i < rem ? 1 : 0); ++j) {
//                 write -> next = ListNode(cur->val);
//                 write = write -> next;
//                 if (cur != NULL) cur = cur->next;
//             }
//             ans[i] = head.next;
//         }
//     }
// };

// sol
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        int len = 0;

        // count list length
        for (ListNode* node = root; node; node = node->next)
            len++;
        // n : minimum guaranteed part size; r : extra nodes spread to the first r parts;
        int n = len / k, r = len % k; 

        // put node in
        ListNode* node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--) {
            parts[i] = node;

            // (r>0) , then this part need one more extra node, this j < n+1
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }
};