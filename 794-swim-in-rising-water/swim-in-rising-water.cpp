class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,3000));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({grid[0][0],{0,0}});
        while(q.size()){
            int curr = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if(curr > dis[row][col]){
                continue;
            }
            if(row == n-1 && col == m-1){
                return curr;
            }
            int drow[] = {0,-1,0,1};
            int dcol[] = {-1,0,1,0};
            for(int i = 0;i<4;i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && dis[nrow][ncol] > max(curr,grid[nrow][ncol])){
                    dis[nrow][ncol] = max(curr,grid[nrow][ncol]);
                    q.push({max(curr,grid[nrow][ncol]),{nrow,ncol}});
                }
            }
        }
        return 1;
    }
};