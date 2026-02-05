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
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans = 0;
        while(1){
            int size = q.size();
            if(size == 0){
                break;
            }
            long long start = q.front().second;
            long long last = q.back().second;
            ans = max(ans,last-start+1);
            while(size--){
                auto it = q.front();
                q.pop();
                long long ind = it.second-start;
                if(it.first->left != nullptr){
                    q.push({it.first->left,(2*1LL*ind)+1});
                }
                if(it.first->right != nullptr){
                    q.push({it.first->right,(2*1LL*ind)+2});
                }
            }
        }
        return (int)ans;
    }
};