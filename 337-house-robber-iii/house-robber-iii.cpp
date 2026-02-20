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
    int helper(TreeNode* root,long long curr,unordered_map<long long,int>&dp){
        if(!root){
            return 0;
        }
        if(dp[curr] != 0){
            return dp[curr];
        }
        int nottake = 0;
        int take = root->val;
        if(root->left){
            take += helper(root->left->left,2*(2*curr+1)+1,dp);
            take += helper(root->left->right,2*(2*curr+1)+2,dp);
        }
        if(root->right){
            take += helper(root->right->left,2*(2*curr+2)+1,dp);
            take += helper(root->right->right,2*(2*curr+2)+2,dp);
        }
        nottake = helper(root->left,2*curr+1,dp) + helper(root->right,2*curr+2,dp);
        return dp[curr] = max(nottake,take);
    }
    int rob(TreeNode* root) {
        unordered_map<long long,int>dp;
        return helper(root,0,dp);
    }
};