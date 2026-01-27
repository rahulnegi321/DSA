class Solution {
public:
    int helper(vector<int>&coins,int amount,vector<int>&dp){
        if(amount == 0){
            return 0;
        }
        if(amount < coins[0]){
            return 1e5;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int take = 1e5;
        for(int i = 0;i<coins.size();i++){
            if(coins[i] <= amount){
                take = min(take,1 + helper(coins,amount-coins[i],dp));
            }
            else{
                break;
            }
        }
        return dp[amount] = take;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        sort(coins.begin(),coins.end());
        if(helper(coins,amount,dp) >= 1e5){
            return -1;
        }
        return helper(coins,amount,dp);
    }
};