class Solution {
public:
    vector<vector<int>>finalans;
    void helper(int ind,vector<int>&nums){
        if(ind == nums.size()){
            finalans.push_back(nums);
            return;
        }
        unordered_set<int>st;
        for(int i = ind;i<nums.size();i++){
            if(st.count(nums[i])){
                continue;
            }
            st.insert(nums[i]);
            swap(nums[i],nums[ind]);
            helper(ind+1,nums);
            swap(nums[i],nums[ind]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(0,nums);
        return finalans;
    }
};