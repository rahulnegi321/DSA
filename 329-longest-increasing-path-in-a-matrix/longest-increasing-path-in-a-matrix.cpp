class Solution {
public: 
    int helper(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i >= matrix.size()){
            return 0;
        }
        if(j >= matrix[0].size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        int drow[] = {0,-1,0,1};
        int dcol[] = {1,0,-1,0};
        for(int k = 0;k<4;k++){
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            int temp = 0;
            if(nrow >= 0 && ncol >= 0 && nrow < matrix.size() && ncol < matrix[0].size() && matrix[nrow][ncol] > matrix[i][j]){
                temp = 1 + helper(nrow,ncol,matrix,dp);
                ans = max(temp,ans);
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int temp = 0;
                temp = helper(i,j,matrix,dp);
                ans = max(temp,ans);
            }
        }
        return ans+1;
    }
};