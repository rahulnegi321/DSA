/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node*>q;
        q.push(root);
        while(1){
            int size  = q.size();
            if(size == 0){
                break;
            }
            int curr = size;
            Node* prev = nullptr;
            while(size--){
                auto it = q.front();
                q.pop();
                if(prev == nullptr){
                    prev = it;
                }
                else{
                    prev->next = it;
                    prev = it;
                }
                if(size == 0){
                    it->next = nullptr;
                }
                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
            }
        }
        return root;
    }
};