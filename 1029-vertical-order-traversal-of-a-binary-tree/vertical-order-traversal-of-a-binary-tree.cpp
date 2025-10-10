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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>nodes;
        vector<vector<int>>finalans;
        if(!root){
            return finalans;
        }
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int col = it.second.first;
            int row = it.second.second;
            nodes[col][row].insert(node->val);
            if(node->left){
                q.push({node->left,{col-1,row+1}});
            }
            if(node->right){
                q.push({node->right,{col+1,row+1}});
            }
        }
        for(auto column: nodes){
            vector<int>ans;
            for(auto row: column.second){
                for(auto it: row.second){
                    ans.push_back(it);
                }
            }
            finalans.push_back(ans);
        }
        return finalans;
    }
};