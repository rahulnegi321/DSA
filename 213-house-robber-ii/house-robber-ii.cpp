class Solution {
public:
    int helper(int ind,int n,vector<int>&nums,vector<int>&dp){
        if(ind >= n){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int take = nums[ind] + helper(ind+2,n,nums,dp);
        int nottake = helper(ind+1,n,nums,dp);
        return dp[ind] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        if(n == 1){
            return nums[0];
        }
        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);
        return max(helper(0,n-1,nums,dp),helper(1,n,nums,dp1));
    }
};