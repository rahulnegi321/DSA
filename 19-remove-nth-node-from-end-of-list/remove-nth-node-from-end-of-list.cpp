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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        if(n == size){
            return head->next;
        }
        int count  = 0;
        int t = size-n+1;
   
        ListNode* curr = head;
        while(curr){
            count++;
            if(count + 1 == t){
              curr->next = curr->next->next;
              break;
            }
            curr = curr->next;
        }
        return head;
    }
};