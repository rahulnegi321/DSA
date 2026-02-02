/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mpp;
        Node* curr = head;
        while(curr){
            mpp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr){
            mpp[curr]->next = curr->next ? mpp[curr->next] : nullptr;
            mpp[curr]->random = curr->random ? mpp[curr->random] : nullptr;
            curr = curr->next;
        }
        return mpp[head];
    }
};