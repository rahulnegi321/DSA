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
    int ans = 0;
    void helper(TreeNode* root,int curr){
        if(!root){
            return;
        }
        curr = (curr*10)+root->val;
        if(root->left == nullptr && root->right == nullptr){
           ans += curr;
           return;
        }
        if(root->left){
            helper(root->left,curr);
        }
        if(root->right){
            helper(root->right,curr);
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};