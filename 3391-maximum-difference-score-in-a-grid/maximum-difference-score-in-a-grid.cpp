class Solution {
public:
    int helper(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int n = grid.size();
        int m = grid[0].size();
        if(row >= n || col >= m){
            return INT_MIN;
        } 
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int max_future = max(helper(row+1,col,grid,dp),helper(row,col+1,grid,dp));
        return dp[row][col] = max(grid[row][col],max_future);
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        helper(0,0,grid,dp);
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
               int temp = helper(i+1,j,grid,dp);
               int temp1 = helper(i,j+1,grid,dp);

               int temp2 = max(temp,temp1);
               if(temp2 != INT_MIN){
                ans = max(ans,temp2-grid[i][j]);
               }
            }
        }
        return ans;
    }
};