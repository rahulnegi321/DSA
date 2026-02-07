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
    vector<TreeNode*>ans;
    void preorder(TreeNode* root){
        if(!root){
            return;
        } 
        ans.push_back(root);
        preorder(root->left);
        preorder(root->right);
        return;
    }
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        preorder(root);
        for(int i = 0;i<ans.size()-1;i++){
            TreeNode* curr = ans[i];
            TreeNode* next = ans[i+1];
            curr->left = nullptr;
            curr->right = next;
        }
        return;
    }
};