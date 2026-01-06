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
    int maxLevelSum(TreeNode* root) {
        int val = INT_MIN;
        int ans = -1;
        int count  = 0;
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(1){
            int sum = 0;
            int s = q.size();
            if(s == 0){
                break;
            }
            count++;
            while(s){
               auto temp = q.front();
               q.pop();
               sum += temp->val;
               if(temp->left != nullptr){
                q.push(temp->left);
               }
               if(temp->right != nullptr){
                q.push(temp->right);
               }
               s--;
            }
            if(sum > val){
                ans = count;
                val = sum;
            }
        }
        return ans;
    }
};