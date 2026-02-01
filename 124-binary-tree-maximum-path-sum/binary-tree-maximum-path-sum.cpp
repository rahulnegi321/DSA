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
    int ans = INT_MIN;
    int helper(TreeNode* root){
        if(!root){
            return -1e4;
        }
        int l = helper(root->left);
        int r = helper(root->right);
        int maxi = max({l+root->val,r+root->val,root->val,root->val+l+r});
        int temp = max({l+root->val,r+root->val,root->val});
        ans = max(ans,maxi);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};