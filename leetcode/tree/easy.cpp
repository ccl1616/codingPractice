#include <iostream>
#include <vector>
using namespace std;

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