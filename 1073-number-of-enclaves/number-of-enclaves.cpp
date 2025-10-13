class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int j = 0;
        for(int i = 0;i<n;i++){
           if(grid[i][j] == 1){
            q.push({i,j});
           }
        }
        j = m-1;
        for(int i = 0;i<n;i++){
            if(grid[i][j] == 1){
                q.push({i,j});
            }
        }
        int i = 0;
        for(int k = 0;k<m;k++){
            if(grid[i][k] == 1){
                q.push({i,k});
            }
        }
        i = n-1;
        for(int k = 0;k<m;k++){
            if(grid[i][k] == 1){
                q.push({i,k});
            }
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            grid[row][col] = 0;
             q.pop();
            if(vis[row][col] == 1){
                continue;
            }
            vis[row][col] = 1;
            int drow[] = {-1,0,0,1};
            int dcol[] = {0,-1,1,0};
            for(int i = 0;i<4;i++){
               int nrow = drow[i] + row;
               int ncol = dcol[i] + col;
               if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
                 q.push({nrow,ncol});
               }
            }
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};