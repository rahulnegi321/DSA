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
    vector<int>ans;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* build(int left,int right){
       if(left > right){
        return nullptr;
       }
       int mid = (left+right)/2;
       TreeNode* node = new TreeNode(ans[mid]);
       node->left = build(left,mid-1);
       node->right = build(mid+1,right);
       return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root){
            return root;
        }
        inorder(root);
        return build(0,ans.size()-1);
    }
};