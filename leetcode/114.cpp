#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// sol
class Solution {
public:
    void flatten(TreeNode* root) {
        if( root )
        {
            /*Move the left node to the right node*/
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* node = root;
            
            /*Move to the end of the prev left node which is the new right node*/
            while( node->right )
            {
                node = node->right;
            }
            
            /*Append the right node to its end*/
            node->right = temp;
            flatten( root->right ); 
        } 
        return;
               
    }
};

// me after sol
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root) {
            if(root->left != nullptr) {
                TreeNode* sub_r = root->right;
                root->right = root->left;
                root->left = nullptr; //clear its left sub tree !
                
                TreeNode* tmp = root;
                while(tmp->right != nullptr) {
                    tmp = tmp->right;
                }
                tmp->right = sub_r;
                
                flatten(root->right);
            }
            else flatten(root->right);
        }
        return;
        
    }
};

// sol using stack
class Solution {
public:
    void flatten(TreeNode* root) 
    {
        //empty tree
        if(root == nullptr)
            return;
        
        //use stack to keep storing elements 
        stack<TreeNode*> stack;
        stack.push(root);
        
        //somewhat similar to level order
        //pop each element from the stack (starting from root)
        //add its right and left child to the stack
		//(explained below why right child is added before left)
        //repeat till stack is empty.
        while(!stack.empty())
        {
            TreeNode* currentNode = stack.top();
            stack.pop();
            
            //push the right node first, because when we pop
            //left child will be on top and we want left child first.
            if(currentNode->right != NULL)
                stack.push(currentNode->right);
            
            //push left child, this will be on top of stack now.
            if(currentNode->left != NULL)
                stack.push(currentNode->left);
            
            //assign the top most(left child) as right. 
            if(!stack.empty())
                currentNode->right = stack.top();
            
            //make all left children NULL. 
            currentNode->left = NULL;
        }
    }    
};