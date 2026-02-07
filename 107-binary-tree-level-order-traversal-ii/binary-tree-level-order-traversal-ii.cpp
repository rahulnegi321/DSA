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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>>result;
        queue<TreeNode*>q;
        if(root == nullptr){
            return result;
        }
        q.push(root);
        while(1){
            int size = q.size();
            if(size == 0){
                break;
            }
            vector<int>ans;
            while(size>0){
                TreeNode* front = q.front();
                ans.push_back(front->val);
                q.pop();

                if(front->left != nullptr){
                    q.push(front->left);
                }
                if(front->right != nullptr){
                    q.push(front->right);
                }
                size--;
            } 
            result.push_back(ans);
        }          
        reverse(result.begin(),result.end());                                                                                                                                                                                                                                                                                                                                                 
                return result;
    }
};