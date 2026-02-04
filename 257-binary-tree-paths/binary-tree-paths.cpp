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
    vector<string>finalans;
    void helper(TreeNode* root,string temp){
        if(!root->left && !root->right){
            temp += to_string(root->val);
            finalans.push_back(temp);
            return;
        }
        temp += to_string(root->val);
        temp += "->";
        if(root->left)
        {
           
            helper(root->left,temp);
        }
        if(root->right){
         
            helper(root->right,temp);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp = "";
        helper(root,temp);
        return finalans;
    }
};