#include <iostream>
#include <vector>
using namespace std;

// 104. Maximum Depth of Binary Tree, count the max deoth
// sol
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
    int maxDepth(TreeNode* root) {
        return !root ? 0 : max(maxDepth(root->right), maxDepth(root->left))+1;
    }
};

// me after sol
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else {
            return 1 + max(maxDepth(root->left),maxDepth(root->right));
        }
    }
};


// ===============================================================================================
// 111
// tle version
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        else {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            if(!left && right) 
                return 1+right;
            else if(!right && left) 
                return 1+left;
            return 1 + min(minDepth(root->left),minDepth(root->right)); // here's the bug 
        }
    }
};

// AC, found out that I'was stupid
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        else {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            if(!left && right) 
                return 1+right;
            else if(!right && left) 
                return 1+left;
            return 1 + min(left,right);
        }
    }
};

// cleaner version
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){ return 0;}
        int l = minDepth(root->left), r = minDepth(root->right);
        return 1 + (min(l, r) ? min(l, r) : max(l, r));
    }
};

// ===============================================================================================
// 617, after sol
// recursive, really straight foward
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 && root2) {
            TreeNode* root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
            return root;
        }
        else {
            if(root1) return root1;
            else return root2;
        }
    }
};