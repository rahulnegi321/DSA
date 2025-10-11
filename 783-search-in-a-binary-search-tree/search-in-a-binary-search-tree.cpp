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
    void preorder(TreeNode* root,int val,vector<TreeNode*>&ans){
        if(root == nullptr){
            return;
        }
        if(root->val == val){
            ans.push_back(root);
            return;
        }
        if(root->val > val){
            preorder(root->left,val,ans);
        }
        if(root->val<val){
            preorder(root->right,val,ans);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<TreeNode*>ans;
        preorder(root,val,ans);
        if(ans.empty()){
            return nullptr;
        }
        return ans[0];
    }
};