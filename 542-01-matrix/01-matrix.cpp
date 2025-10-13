class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       priority_queue<pair<int,pair<int,int>>>q;
       set<pair<int,int>>st;
       for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(mat[i][j] == 0){
                st.insert({i,j});
                q.push({0,{i,j}});
            }
        }
       }
       vector<vector<int>>dis(n,vector<int>(m,0));
       while(!q.empty()){
        int dist = -q.top().first;
        int row = q.top().second.first;
        int col = q.top().second.second;
        q.pop();
        dis[row][col] = dist;
        int drow[] = {-1,0,0,1};
        int dcol[] = {0,-1,1,0};
        for(int i =0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

        if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !st.count({nrow,ncol})){
            st.insert({nrow,ncol});
            q.push({-(dist + 1), {nrow,ncol}});
        }
       }
       }
       return dis;
    }
};