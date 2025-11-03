class Solution {
public:
    long long dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col){
        vis[row][col] = 1;
        int drow[] = {-1,0,0,1};
        int dcol[] = {0,1,-1,0};
        long long sum = grid[row][col];
        for(int i = 0;i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && grid[nrow][ncol] != 0 && vis[nrow][ncol] == 0){
             sum = sum + dfs(grid,vis,nrow,ncol);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>>vis(n+1,vector<int>(m+1,0));
      int count = 0;

      for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] == 0 && grid[i][j] != 0){
                long long sum = dfs(grid,vis,i,j);
                if((int)(sum % k) == 0){
                    count++;
                }
            }
        }
      }
      return count;
    }
};