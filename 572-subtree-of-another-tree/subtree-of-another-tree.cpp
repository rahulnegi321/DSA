/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root,TreeNode* subRoot){
        if(root == nullptr){
            if(subRoot == nullptr){
                return true;
            }
            return false;
        }
        if(subRoot == nullptr){
            return false;
        }
        if(root->val != subRoot->val){
            return false;
        }
        bool l = check(root->left,subRoot->left);
        bool r = check(root->right,subRoot->right);
        return l&&r;
    }

    bool helper(TreeNode* root,TreeNode* subRoot){
        if(!root){
            return false;
        }
        bool ans = false;
        if(root->val == subRoot->val){
            ans = ans | check(root,subRoot);
        }
        bool l = helper(root->left,subRoot);
        bool r = helper(root->right,subRoot);
        return (ans|l|r);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return helper(root,subRoot);
    }
};