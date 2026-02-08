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
    bool ans = true;
    int helper(TreeNode* root,int curr){
        if(!root){
            return curr;
        }
        int l = helper(root->left,curr+1);
        int r = helper(root->right,curr+1);
        if(abs(l-r) > 1){
            ans = false;
        }
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        helper(root,0);
        return ans;
    }
};