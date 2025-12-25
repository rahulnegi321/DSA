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
    void dfs(int target,TreeNode* root,vector<vector<int>>&st,vector<int>&ans){
        // if(root == nullptr){
        //    st.insert(ans);
        //    return;
        // } 
        if(root == nullptr){
            return;
        }
        ans.push_back(root->val);
        target -= root->val;
        if(root->left == nullptr && root->right == nullptr){
          if(target == 0){
            st.push_back(ans);
          }
          ans.pop_back();
          return;
        }
        if(root->left != nullptr){
          dfs(target,root->left,st,ans);
        }
        if(root->right != nullptr){
           dfs(target,root->right,st,ans);
        }
        target = target + root->val;
        ans.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>st;
        vector<int>temp;
        dfs(targetSum,root,st,temp);
        bool ans = false;
        for(auto it : st){
            if(it.size() > 0){
                ans = true;
                break;
            }
        }
        if(!ans){
            return {};
        }
        return st;
    }
};