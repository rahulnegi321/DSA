class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
      priority_queue<pair<int,pair<int,int>>>q;
      q.push({-grid[0][0],{0,0}});
      int ans = INT_MAX;
      while(!q.empty()){
        int distance = -q.top().first;
        int row = q.top().second.first;
        int col = q.top().second.second;
        q.pop();
        if(row == n-1 && col == n-1){
          ans = min(ans,distance);
          continue;
        }
        int drow[] = {1,0,0,-1};
        int dcol[] = {0,-1,1,0};
        for(int i =0;i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && dis[nrow][ncol] > max(distance,grid[nrow][ncol])){
                dis[nrow][ncol] = max(distance,grid[nrow][ncol]);
                q.push({-dis[nrow][ncol],{nrow,ncol}});
            }
        }
      }
      return ans;   
    }
};