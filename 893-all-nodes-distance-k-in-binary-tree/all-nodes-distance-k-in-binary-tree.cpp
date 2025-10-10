/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,TreeNode*>parent;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left->val] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right->val] = node;
                q.push(node->right);
            }
        }
        unordered_map<TreeNode*,int>vis;
        queue<TreeNode*>nodes;
        nodes.push(target);
        while(k-- && !nodes.empty()){
            int size = nodes.size();
            while(size--){
                TreeNode* node = nodes.front();
                nodes.pop();
                vis[node] = 1;
                if(node->left && !vis[node->left]){
                    nodes.push(node->left);
                    vis[node->left] = 1;
                }
                if(node->right && !vis[node->right]){
                    nodes.push(node->right);
                    vis[node->right] = 1;
                }
                if(parent[node->val] && !vis[parent[node->val]]){
                    nodes.push(parent[node->val]);
                    vis[parent[node->val]] = 1;
                }
            }
        }
        vector<int>ans;
        while(!nodes.empty()){
            ans.push_back(nodes.front()->val);
            nodes.pop();
        }
        return ans;
    }
};