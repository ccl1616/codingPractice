#include <bits/stdc++.h>
using namespace std;
// 404
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        // if(root == nullptr) return 0;
        // int sum = 0;
        // if(root->left != nullptr) {
        //     if(root->left->left == nullptr) sum += root->left->val;
        //     else sum += sumOfLeftLeaves(root->left);
        // }
        // if(root->right != nullptr) {
        //     sum += sumOfLeftLeaves(root->right);
        // }
        // cout << sum << endl;
        // return sum;
        
        if(!root) return 0;
        int sum = 0;

        if(root->left && !root->left->left && !root->left->right) sum += root->left->val;
        
        if(root->left) sum += sumOfLeftLeaves(root->left);
        if(root->right) sum += sumOfLeftLeaves(root->right);
        
        return sum;
    }
    
};