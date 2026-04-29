class Solution {
public:
    int helper(int ind,vector<int>&nums,vector<int>&dp){
        if(ind >= nums.size()){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int take = nums[ind] + helper(ind+2,nums,dp);
        int nottake = helper(ind+1,nums,dp);
        return dp[ind] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans =  helper(0,nums,dp);
        return ans;
    }
};