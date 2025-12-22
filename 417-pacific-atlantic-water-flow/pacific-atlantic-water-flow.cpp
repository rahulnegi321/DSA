class Solution {
public:
    bool dfs(int row,int col,vector<vector<int>>&heights,vector<vector<int>>&vis,vector<vector<bool>>&ans){
        int n = heights.size();
        int m = heights[0].size();
        if(row == heights.size()-1 || col == heights[0].size()-1){
            return true;
        }
        vis[row][col] = 1;
        // if(ans[row][col] == true){
        //     return true;
        // }
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        bool temp = false;
        for(int i = 0;i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && heights[nrow][ncol] <= heights[row][col]){
              temp = temp || dfs(nrow,ncol,heights,vis,ans);
            }
        }
        vis[row][col] = 0;
        return temp;
    }

    bool dfs1(int row,int col,vector<vector<int>>&heights,vector<vector<int>>&vis,vector<vector<bool>>&ans){
        if(row == 0 || col == 0){
            return true;
        }
         int n = heights.size();
        int m = heights[0].size();
        vis[row][col] = 1;
        // if(ans[row][col] == true){
        //     return true;
        // }
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};
        bool temp = false;
        for(int i = 0;i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;

            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0 && heights[nrow][ncol] <= heights[row][col]){
              temp = temp || dfs1(nrow,ncol,heights,vis,ans);
            }
        }
        vis[row][col] = 0;
        return temp;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>ans(n,vector<bool>(m,false));
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                    bool temp = true;
                    temp = temp && dfs(i,j,heights,vis,ans);
                    if(temp == false){
                        continue;
                    }
                    temp = temp && dfs1(i,j,heights,vis,ans);
                    if(temp == true){
                        ans[i][j] = true;
                    }
                }
        }
        vector<vector<int>>finalans;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(ans[i][j] == true){
                    finalans.push_back({i,j});
                }
            }
        }
        return finalans;
    }
};