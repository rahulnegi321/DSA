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
    TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* left = LCA(root->left,p,q);
        TreeNode* right = LCA(root->right,p,q);
        if(left == nullptr){
            return right;
        }
        if(right == nullptr){
            return left;
        }
        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*>leaf;
        queue<TreeNode*>q;
        q.push(root);
        while(1){
            int size = q.size();
            if(size == 0){
                break;
            }

            while(size--){
                auto node = q.front();
                leaf.push_back(node);
                q.pop();
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }

            }
            if(q.size() != 0){
              leaf.clear();
            }
        }
        if(leaf.size() == 1){
            return leaf[0];
        }
        int n =leaf.size();
        TreeNode* first = leaf[0];
        TreeNode* last = leaf[n-1];
        return LCA(root,first,last);
    }
};