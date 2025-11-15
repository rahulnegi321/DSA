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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val  = 0;
        vector<TreeNode*>arr;
        arr.push_back(root);
        dfs(vector<TreeNode*>{root});
        return root;
    }
    private:
    void dfs(vector<TreeNode*>arr){
        if(arr.empty()){
            return;
        }
        int sum = 0;
        for(auto it : arr){
             if(it->left){
                sum = sum + it->left->val;
             }
             if(it->right){
                sum = sum + it->right->val;
             }
        }
        vector<TreeNode*>child;
        for(auto it : arr){
            int currsum = 0;
            if(it->left){
               currsum = currsum + it->left->val;
            }
            if(it->right){
                currsum = currsum + it->right->val;
            }
            if(it->left){
                it->left->val = sum-currsum;
                child.push_back(it->left);
            }
            if(it->right){
                it->right->val = sum-currsum;
                child.push_back(it->right);
            }
        }
        dfs(child);
    }
};