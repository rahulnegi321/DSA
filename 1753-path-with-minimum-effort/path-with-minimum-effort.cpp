class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<pair<int,int>>st;
        priority_queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        int ans = 0;
        while(!q.empty()){
            int dist = -q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if(row == n-1 && col == m-1){
                ans = dist;
                break;
            }
            if(vis[row][col] == 1){
                continue;
            }
            vis[row][col] = 1;
            int drow[] = {-1,0,0,1};
            int dcol[] = {0,-1,1,0};
            for(int i = 0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && vis[nrow][ncol] == 0){
                   int temp = max(dist,abs(heights[nrow][ncol] - heights[row][col]));
                   q.push({-temp,{nrow,ncol}});
                }
            }
        }
        return ans;
    }
};