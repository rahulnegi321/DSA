class Solution {
public:
    long long helper(int ind,int taken,vector<int>&prices,int k,vector<vector<vector<long long>>>&dp){\
        if(ind == prices.size() && taken != 0){
            return -1e9;
        }
        if(ind == prices.size() && taken == 0){
            return 0;
        }
        if(k == 0){
            return 0;
        }
        if(dp[ind][taken][k] != -1){
            return dp[ind][taken][k];
        }
        long long take = 0;
        long long skip = 0;
        long long maxi = 0;
        if(taken == 0){
        take = prices[ind] + helper(ind+1,1,prices,k,dp);
        maxi = max(take,maxi);
        take = -prices[ind] + helper(ind+1,2,prices,k,dp);
        maxi = max(take,maxi);
        take = maxi;
        }
        else if(taken == 1){
            take = -prices[ind] + helper(ind+1,0,prices,k-1,dp);
        }
        else{
            take = prices[ind] + helper(ind+1,0,prices,k-1,dp);
        }
        skip = helper(ind+1,taken,prices,k,dp);

        return dp[ind][taken][k] = max(take,skip);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(3,vector<long long>(k+1,-1)));
        return helper(0,0,prices,k,dp);
    }
};