class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>>q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                }
            }
        }
        int ans = 0;
        while(q.size()){
            int curr = -q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            ans = curr;
            int drow[] = {0,-1,0,1};
            int dcol[] = {-1,0,1,0};
            for(int i = 0;i<4;i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 && grid[nrow][ncol] == 1){
                   grid[nrow][ncol] = 2;
                    q.push({-(curr+1),{nrow,ncol}});
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};