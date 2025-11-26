class Solution {
public:
    int M = 1e9+7;
    int helper(int row,int col,int sum,int k,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid){
      int n = grid.size();
      int m = grid[0].size();
      if(row == n-1 && col == m-1){
        return ((sum+grid[row][col])%k == 0);
      }
      if(row >= n || col >= m){
        return 0;
      }
      sum = (sum + grid[row][col])%k;
      if(dp[row][col][sum] != -1){
        return dp[row][col][sum];
      }
      int right = 0;
      int down = 0;
      right = helper(row,col+1,sum,k,dp,grid);
      down =  helper(row+1,col,sum,k,dp,grid);

      return dp[row][col][sum] = (right+down)%M;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return helper(0,0,0,k,dp,grid);
    }
};