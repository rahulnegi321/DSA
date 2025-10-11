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
    void preorder(TreeNode* root,priority_queue<int>&q){
        if(root == nullptr){
            return;
        }
        q.push(root->val);
        preorder(root->left,q);
        preorder(root->right,q);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int>q;
        preorder(root,q);
        while(!q.empty() && q.size() != k){
            q.pop();
        }
        return q.top();
    }
};