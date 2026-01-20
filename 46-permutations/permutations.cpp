class Solution {
public:
    vector<vector<int>>finalans;
    void helper(int ind,vector<int>&nums){
        if(ind >= nums.size()){
            finalans.push_back(nums);
            return;
        }
        for(int i = ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            helper(ind+1,nums);
            swap(nums[i],nums[ind]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(0,nums);
        return finalans;
    }
};