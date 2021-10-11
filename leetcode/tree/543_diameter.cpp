#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// by myself
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root->left && !root->right) return 0;
        else if(root->left && root->right) {
            return max( 1+diameterOfBinaryTree(root->left), 1+diameterOfBinaryTree(root->right) );
        }
        else {
            if(!root->right) return 1+diameterOfBinaryTree(root->left);
            else if(!root->left) return 1+diameterOfBinaryTree(root->right);
        }
        return 0;
    }
};

// sol
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int h = 0;
        count(root, h);
        return h;
    }
    int count(TreeNode* root, int &h) {
        if(!root) return 0;
        // get left, right sub
        int l = count(root->left, h);
        int r = count(root->right, h);
        h = max( h, l+r ); // record max
        return max(l, r) +1; // return max sub
    }
};