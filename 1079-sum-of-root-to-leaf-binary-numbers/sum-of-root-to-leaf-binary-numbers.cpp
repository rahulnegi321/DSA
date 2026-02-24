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
    int ans = 0;
    int convert(string s){
      if(s.size() == 0){
        return 0;
      }
      int count = 0;
      int temp = 0;
      int n = s.size();
      for(int i = n-1;i>=0;i--){
         if(s[i] == '1'){
           temp += pow(2,count);
         }
         count++;
      }
      return temp;
    }
    void helper(string s,TreeNode* root){
        if(!root){
            return;
        }
        s += (char)(root->val + '0');
        if(!root->left && !root->right){
          ans += convert(s);
        }
        if(root->left){
            helper(s,root->left);
        }
        if(root->right){
            helper(s,root->right);
        }
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
       string temp = "";
       helper(temp,root);
       return ans;
    }
};