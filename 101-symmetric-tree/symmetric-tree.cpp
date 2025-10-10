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
    void preorder(TreeNode* root,vector<int>&ans){
        if(root == nullptr){
            ans.push_back(101);
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }

    void postorder(TreeNode* root,vector<int>&ans){
        if(root == nullptr){
            ans.push_back(101);
            return;
        }
        ans.push_back(root->val);
        postorder(root->right,ans);
        postorder(root->left,ans);   
    }

    bool isSymmetric(TreeNode* root) {
        vector<int>pre;
        vector<int>post;
        if(!root){
            return true;
        }
        preorder(root->left,pre);
        postorder(root->right,post);
        if(pre == post){
            return true;
        }
        return false;
    }
};