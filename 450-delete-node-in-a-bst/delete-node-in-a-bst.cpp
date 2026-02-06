/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        if (root->val == key) {
            return helper(root);
        }
        TreeNode* curr = root;
        while (root != nullptr) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                } else {
                    root = root->right;
                }
            }
        }

        return curr;
    }
    
    TreeNode* helper(TreeNode* root){
        if(!root){
            return root;
        }
        if(!root->left){
            return root->right;
        }
        if(!root->right){
            return root->left;
        }
        TreeNode* firstright = root->right;
        TreeNode* Lastright = lastright(root->left);
        Lastright->right = firstright;
        return root->left;
    }
    TreeNode* lastright(TreeNode* root){
        if(root->right == nullptr){
            return root;
        }
        return lastright(root->right);
    }
};