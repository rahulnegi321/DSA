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
    int M = 1e9+7;
    long long ans = 0;
    long long baap = 0;
    void dfs(TreeNode* root,map<TreeNode*,long long>&mpp){
        if(root == nullptr){
            return;
        }
        if(root->left != nullptr){
            long long temp = baap - mpp[root->left];
            long long curr = temp*1LL*mpp[root->left];
            if(curr > ans){
                ans = curr;
            }
        }
        if(root->right != nullptr){
            long long temp = baap - mpp[root->right];
            long long curr = temp*1LL*mpp[root->right];
            if(curr > ans){
                ans = curr;
            }
        }
        dfs(root->left,mpp);
        dfs(root->right,mpp);
        return;
    }
    long long helper(TreeNode* root,map<TreeNode*,long long>&mpp){
        if(root== nullptr){
            return 0;
        }
        long long ans = root->val;
        if(root->left != nullptr){
            ans = (ans + helper(root->left,mpp));
        }
        if(root->right != nullptr){
            ans = (ans + helper(root->right,mpp));
        }
        return mpp[root] = ans;
    }

    int maxProduct(TreeNode* root) {
        map<TreeNode*,long long>mpp;
        baap = helper(root,mpp);

        dfs(root,mpp);
        return (int)(ans%M);
    }
};