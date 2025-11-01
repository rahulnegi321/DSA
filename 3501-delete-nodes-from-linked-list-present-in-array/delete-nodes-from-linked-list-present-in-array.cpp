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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>store(nums.begin(),nums.end());
        ListNode* prev = new ListNode(-1);
        ListNode* ans = prev;
        prev->next = head;
        while(head){
            if(store.count(head->val)){
                head = head->next;
                prev->next = head;
            }
            else{
                prev->next = head;
                prev = prev->next;
                head = head->next;
            }
        }
        return ans->next;
    }
};