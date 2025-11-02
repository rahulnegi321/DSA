class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
      
        vector<vector<int>>vis(m,vector<int>(n,0));
        set<pair<int,int>>w;
        for(auto it : walls){
            w.insert({it[0],it[1]});
        }
        set<pair<int,int>>g;
        for(auto it : guards){
            g.insert({it[0],it[1]});
        }
        queue<pair<int,int>>q;
        for(auto it : guards){
            q.push({it[0],it[1]});
            vis[it[0]][it[1]] = 1;
        }
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = row+1;i<m;i++){
                if(w.count({i,col})){
                    break;
                }
                else if(g.count({i,col})){
                   break;
                }
                else{
                    vis[i][col] = 1;
                }
            }
             for(int i = col+1;i<n;i++){
                if(w.count({row,i})){
                    break;
                }
                else if(g.count({row,i})){
                   break;
                }
                else{
                    vis[row][i] = 1;
                }
            }
             for(int i = row-1;i>=0;i--){
                if(w.count({i,col})){
                    break;
                }
                else if(g.count({i,col})){
                   break;
                }
                else{
                    vis[i][col] = 1;
                }
            }
             for(int i = col-1;i>=0;i--){
                if(w.count({row,i})){
                    break;
                }
                else if(g.count({row,i})){
                   break;
                }
                else{
                    vis[row][i] = 1;
                }
            }
        }
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j] == 0){
                    count++;
                }
            }
        }
        return count-walls.size();
    }
};