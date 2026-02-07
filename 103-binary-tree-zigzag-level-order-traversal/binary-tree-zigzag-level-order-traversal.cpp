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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>finalans;
        if(root == nullptr){
            return finalans;
        }
        q.push(root);
        while(1){
            int size = q.size();
            if(size == 0){
                return finalans;
            }
            vector<int>ans;
            while(size > 0){
                TreeNode* temp = q.front();
                q.pop();
                ans.push_back(temp->val);

                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
                size--;
            }
            if(finalans.size()%2 == 1){
                reverse(ans.begin(),ans.end());
            }
            finalans.push_back(ans);
        }
        return finalans;
    }
};