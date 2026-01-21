class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            q.push({i,0});
            vis[i][0] = 1;
        }
        for(int j = 0;j<m;j++){
            q.push({0,j});
            vis[0][j] = 1;
        }
        while(q.size()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[] = {1,0,-1,0};
            int dcol[] = {0,-1,0,1};
            for(int i = 0;i<4;i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && heights[nrow][ncol] >= heights[row][col]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        
        queue<pair<int,int>>p;
        vector<vector<int>>vis1(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            p.push({i,m-1});
            vis1[i][m-1] = 1;
        }
        for(int j = 0;j<m;j++){
            p.push({n-1,j});
            vis1[n-1][j] = 1;
        }
    
         while(p.size()){
            int row = p.front().first;
            int col = p.front().second;
            p.pop();
            int drow[] = {1,0,-1,0};
            int dcol[] = {0,-1,0,1};
            for(int i = 0;i<4;i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis1[nrow][ncol] == 0 && heights[nrow][ncol] >= heights[row][col]){
                    vis1[nrow][ncol] = 1;
                    p.push({nrow,ncol});
                }
            }
        }
        vector<vector<int>>ans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 1 && vis1[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};