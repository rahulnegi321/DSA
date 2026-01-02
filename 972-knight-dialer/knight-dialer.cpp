class Solution {
public:
    int M = 1e9+7;
    int ans  = 1;
    int helper(int n,int i,int row,int col,vector<vector<vector<int>>>&dp){
        if(row < 0 || col < 0 || row > 3 || col > 2){
            return 0;
        }
        if(row == 3 && (col == 0 || col == 2)){
            return 0;
        }
        if(i == n){
          return 1;
        }
        if(dp[row][col][i] != -1){
            return dp[row][col][i];
        }
        long long ans = 0;
        ans = (ans + helper(n,i+1,row-2,col-1,dp))%M ;
        ans = (ans + helper(n,i+1,row-2,col+1,dp))%M;
        ans = (ans + helper(n,i+1,row-1,col-2,dp))%M;
        ans = (ans + helper(n,i+1,row-1,col+2,dp))%M;
        ans = (ans + helper(n,i+1,row+1,col-2,dp))%M;
        ans = (ans + helper(n,i+1,row+1,col+2,dp))%M;
        ans = (ans + helper(n,i+1,row+2,col-1,dp))%M;
        ans = (ans + helper(n,i+1,row+2,col+1,dp))%M;
        return dp[row][col][i] = (int)ans;
    }
    int knightDialer(int n) {
        vector<vector<vector<int>>>dp(5,vector<vector<int>>(3,vector<int>(5001,-1)));
        long long ans = 0;
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                ans = (ans + helper(n,1,i,j,dp))%M;
            }
        }
        ans = (ans + helper(n,1,3,1,dp))%M;
        return (int)ans;
    }
};