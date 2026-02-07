/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while(temp){
            int curr = temp->val;
            if(temp->next == nullptr || temp->next->val != curr){
                dummy->next = temp;
                dummy = dummy->next;
                temp = temp->next;
                dummy->next = nullptr;
                continue;
            }
            while(temp && temp->val == curr){
              temp = temp->next;
            }
        }
        return ans->next;
    }
};