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
        vector<int>updated;
        set<int>values(nums.begin(),nums.end());
        vector<int>temp;
        while(head){
            temp.push_back(head->val);
            head = head->next;
        }
        for(int i = 0;i<temp.size();i++){
            if(values.count(temp[i])){
                continue;
            }
            else{
                updated.push_back(temp[i]);
            }
        }
        if(updated.size() == 0){
            return nullptr;
        }
        ListNode* start = new ListNode(updated[0]);
        ListNode* dummy = start;
        for(int i = 1;i<updated.size();i++){
            ListNode* curr = new ListNode(updated[i]);
            start->next = curr;
            start = start->next;
        }
        return dummy;
    }
};