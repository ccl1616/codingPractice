#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
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

// ===============================================================================================
// 103
// sol1 : zigzag, reverse particular level
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
        for(int i = 1; i < ret.size(); i += 2) {
            reverse(ret[i].begin(), ret[i].end());
        }
        return ret;
    }
};

// 103. sol2
// reverse particular vector before push_back into ret
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;

        queue<TreeNode*> q;
        q.push(root);
        int lev = 0;
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
            lev ++;
            // if( !lev%2 ) reverse(holder.begin(), holder.end()); WA
            if( !(lev%2) ) reverse(holder.begin(), holder.end());
            if( lev%2 == 0 ) reverse(holder.begin(), holder.end());
            ret.push_back(holder);
            holder.clear();
        }

        return ret;
    }
};
// ===============================================================================================

// 98. 
// me, WA, the val limit is wrong!
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        else if(!root->left && !root->right) return true;
        else {
            int l = (root->left)?root->left->val:-1;
            int r = (root->right)?root->right->val:10001;
            
            if(root->val <= l || root->val >= r) return false;
            else return isValidBST(root->left) && isValidBST(root->right);
        }
    }
};

// sol1
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, nullptr, nullptr);
    }
    bool valid(TreeNode* root, int* lower, int* upper) {
        if(!root) return true;
        if(lower && root->val <= *lower) return false;
        if(upper && root->val >= *upper) return false;

        return valid(root->left, lower, &(root->val)) && valid(root->right, &(root->val), upper);
    }
};

// sol2 , construct an array
class Solution {
public:
    void inOrder(TreeNode* root) {
        if (!root)
            return;
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }
   
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        
        inOrder(root);
        for (int i=1; i<tree.size(); i++)
            if (tree[i] <= tree[i-1])
                return false;
        return true;
    }
private:
    vector<int> tree;
};
// ===============================================================================================

// 105
// construct binary tree by preorder & inorder
// sol1 , use unordered map
class Solution {
public:
    TreeNode* buildTree(vector<int>& P, vector<int>& I) {
        unordered_map<int, int> M;
        // put them into map, num-(inorder)id
        for (int i = 0; i < I.size(); i++)
            M[I[i]] = i;
        return splitTree(P, M, 0, 0, I.size()-1);
    }
    
private:
    TreeNode* splitTree(vector<int>& P, unordered_map<int, int>& M, int pix, int ileft, int iright) {
        // pix: (preorder)index of root node
        int rval = P[pix], imid = M[rval];
        TreeNode* root = new TreeNode(rval);            
        if (imid > ileft)
            root->left = splitTree(P, M, pix+1, ileft, imid-1);
        if (imid < iright)
            root->right = splitTree(P, M, pix+imid-ileft+1, imid+1, iright);
        return root;
    }
};

// me after sol
class Solution {
public:
    vector<int> pr;
    vector<int> in;
    unordered_map<int, int> M;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        this->in = inorder;
        this->pr = preorder; 
        for(int i = 0; i < inorder.size(); i ++) 
            M[inorder[i]] = i;
        return build(0, 0, inorder.size()-1);
    }
    
    TreeNode* build(int pix, int ileft, int iright) {
        int rval = this->pr[pix];
        int imid = this->M[rval]; // inorder id
        TreeNode* root = new TreeNode(rval);
        if(imid > ileft)
            root->left = build(pix+1, ileft, imid-1);
        if(imid < iright)
            root->right = build(pix+1+(imid-ileft), imid+1, iright);
        return root;
    }
};