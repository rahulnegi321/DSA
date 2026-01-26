class Solution {
public:
    int helper(int amount,vector<int>&coins,int ind,vector<vector<int>>&dp){
        if(ind >= coins.size()){
            if(amount == 0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        int take = 0;
        int nottake = 0;
        if(amount >= coins[ind]){
          take = helper(amount-coins[ind],coins,ind,dp);
        }
        nottake = helper(amount,coins,ind+1,dp);
        return dp[ind][amount] = (take + nottake);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans =  helper(amount,coins,0,dp);
        if(ans == -1 || ans == 0){
            return 0;
        }
        return ans;

    }
};