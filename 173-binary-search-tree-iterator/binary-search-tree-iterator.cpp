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
class BSTIterator {
public:
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return;
    }
    vector<int>ans;
    int i;
    int n;
    BSTIterator(TreeNode* root) {
        inorder(root);
        n = ans.size();
        i = -1;
    }
    
    int next() {
        i++;
        return i >= n ? -1 :ans[i];
    }
    
    bool hasNext() {
        if(i >= n-1){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */