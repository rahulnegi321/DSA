class Solution {
public:
    int helper(int n,vector<int>&nums,vector<int>&dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int mini = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > n){
                break;
            }
            int ans = 1 + helper(n-nums[i],nums,dp);
            mini = min(ans,mini);
        }
        return dp[n] = mini;
    }
    int numSquares(int n) {
        vector<int>nums;
        for(int i = 1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        vector<int>dp(n+1,-1);
        return helper(n,nums,dp);
    }
};