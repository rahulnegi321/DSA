class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {0,-1,0,1};
        int dcol[] = {1,0,-1,0};
        queue<pair<int,pair<int,int>>>q;
        queue<pair<int,pair<int,int>>>p;
        vector<vector<int>>vis(n,vector<int>(m,0));
        bool found = false;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0){
                    continue;
                }
                q.push({0,{i,j}});
                p.push({0,{i,j}});
                vis[i][j] = 1;
                while(q.size()){
                  int curr = q.front().first;
                  int row = q.front().second.first;
                  int col = q.front().second.second;
                  q.pop();
                  for(int k = 0;k<4;k++){
                    int nrow = drow[k] + row;
                    int ncol = dcol[k] + col;
                    if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                        q.push({curr,{nrow,ncol}});
                        p.push({0,{nrow,ncol}});
                        vis[nrow][ncol] = 1;
                    }
                  }
                }
                found = true;
                break;
            }
            if(found){
                break;
            }
        }
        while(p.size()){
                  int curr = p.front().first;
                  int row = p.front().second.first;
                  int col = p.front().second.second;
                  p.pop();
                  for(int k = 0;k<4;k++){
                    int nrow = drow[k] + row;
                    int ncol = dcol[k] + col;
                    if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && vis[nrow][ncol] == 0){
                        if(grid[nrow][ncol] == 1){
                           return curr;
                        }
                        else{
                            vis[nrow][ncol] = 1;
                            p.push({curr+1,{nrow,ncol}});
                        }
                    }
                  }
                }
                return -1;
    }
};