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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        if(root == nullptr){
            return 0;
        }
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            long long size = q.size();
            long long offset = q.front().second;
            long long start = 0;
            long long end = q.back().second - offset;
            ans = max(ans,end-start+1);
            while(size){
                TreeNode* node = q.front().first;
                long long ind = q.front().second - offset;
                q.pop();
                if(node->left){
                    q.push({node->left,2*ind+1});
                }
                if(node->right){
                    q.push({node->right,2*ind+2});
                }
                size--;
            }
        }
        return (int)ans;
    }
};