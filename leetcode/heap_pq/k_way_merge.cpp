#include <bits/stdc++.h>
using namespace std;

// 23.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = new ListNode();
        ListNode* cur = ret;
        
        priority_queue<int, vector<int>, greater<int>> mh; //min heap
        if(lists.size() <= 0 || lists[0] == nullptr) {
            return nullptr;
        } 
        else {
            // don't know n
        }

        return ret;
    }
};