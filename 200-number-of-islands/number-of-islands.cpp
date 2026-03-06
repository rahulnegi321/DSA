class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 1 || grid[i][j] == '0'){
                    continue;
                }
                count++;
                queue<pair<int,int>>q;
                vis[i][j] = 1;
                q.push({i,j});
                while(q.size()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    int drow[] = {-1,0,1,0};
                    int dcol[] = {0,1,0,-1};
                    for(int k = 0;k<4;k++){
                        int nrow = drow[k] + row;
                        int ncol = dcol[k] + col;
                        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                            vis[nrow][ncol] = 1;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
        return count;
    }
};