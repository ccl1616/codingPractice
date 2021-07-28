#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ===============================================================================================
// 102.
// myself + geek O(n^2)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        int h = height(root);
        for(int i = 1; i <= h ; i ++ ) {
            vector<int> cur;
            func(cur, root, i);
            ret.push_back(cur);
        }
        return ret;
    }
    void func(vector<int> &cur, TreeNode* root, int level) {
        // current level
        if(!root) return;
        if(level == 1) 
            cur.push_back(root->val);
        else {
            func(cur, root->left, level-1);
            func(cur, root->right, level-1);
            return;
        }
    }
    
    int height(TreeNode* root) {
        // count the tree height
        if(!root)
            return 0;
        else {
            int left = height(root->left);
            int right = height(root->right);
            return max(left,right)+1;
        }
    }
};

// 102. queue version, O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> holder;
            int N = q.size();

            for(int i = 0; i < N; i ++) {
                TreeNode* f = q.front();
                q.pop();
                holder.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ret.push_back(holder);
            holder.clear();
        }
        return ret;
    }
};