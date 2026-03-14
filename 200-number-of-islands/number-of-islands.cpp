class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '0' || vis[i][j] == 1){
                    continue;
                }
                count++;
                queue<pair<int,int>>q;
                q.push({i,j});
                while(q.size()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    if(vis[row][col]){
                        continue;
                    }
                    vis[row][col] = 1;
                    int drow[] = {0,1,0,-1};
                    int dcol[] = {1,0,-1,0};
                    for(int k = 0;k<4;k++){
                        int nrow = drow[k] + row;
                        int ncol = dcol[k] + col;
                        if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == '1' && vis[nrow][ncol] == 0){
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
        return count;
    }
};