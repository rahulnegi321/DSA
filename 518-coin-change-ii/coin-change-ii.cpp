class Solution {
public:
    int helper(int amount,int i,vector<int>&coins,vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(i >= coins.size()){
            return 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = 0;
        int nottake = 0;
        if(coins[i] <= amount){
            take = helper(amount-coins[i],i,coins,dp);
        }
        nottake = helper(amount,i+1,coins,dp);
        return dp[i][amount] = take + nottake;
    }
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(amount,0,coins,dp);
    }
};