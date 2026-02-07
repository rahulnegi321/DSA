class Solution {
public:
    int helper(int ind,vector<int>&prices,vector<vector<vector<int>>>&dp,int canbuy,int t){
        if(t > 2 || ind >= prices.size()){
            return 0;
        }
        if(dp[ind][t][canbuy] != -1){
            return dp[ind][t][canbuy];
        }
        int profit = 0;
        if(canbuy){
           int take = -prices[ind] + helper(ind+1,prices,dp,0,t+1);
           int skip = helper(ind+1,prices,dp,1,t);
           profit = max(take,skip);
        }
        else{
            int sell = prices[ind] + helper(ind+1,prices,dp,1,t);
            int skip = helper(ind+1,prices,dp,0,t);
            profit = max(sell,skip);
        }
        return dp[ind][t][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return helper(0,prices,dp,1,0);
    }
};