class Solution {
public:
    int N = 0;
    int M = 0;
    int helper(int row,int col,int skip,vector<vector<int>>&coins,vector<vector<vector<int>>>&dp){
         if(dp[row][col][skip] != INT_MIN){
            return dp[row][col][skip];
        }
        if(row == N-1 && col == M-1){
            if(skip != 0){
                return dp[row][col][skip] = max(0,coins[row][col]);
            }
            return dp[row][col][skip] = coins[row][col];
        }
        int down = INT_MIN;
        int right = INT_MIN;
        if(row + 1 < N){
            int temp = INT_MIN;
            int next1 = coins[row][col] + helper(row+1,col,skip,coins,dp);
            if(skip && coins[row][col] < 0){
             temp = max(helper(row+1,col,skip-1,coins,dp),next1);
            }
            else{
                temp = next1;
            }
            down = temp;
        }

        if(col + 1 < M){
            int temp2 = INT_MIN;
            int next2 = coins[row][col] + helper(row,col+1,skip,coins,dp);
            if(skip && coins[row][col] < 0 ){
             temp2 = max(helper(row,col+1,skip-1,coins,dp),next2);
            }
            else{
                temp2 = next2;
            }
            right = temp2;
        }
       return dp[row][col][skip] = max(right,down);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        N = n;
        M = m;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return helper(0,0,2,coins,dp);
    }
};