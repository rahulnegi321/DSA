class Solution {
public: 

    int find(int x,vector<int>&parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }

    void Union(int x,int y,vector<int>&parent,vector<int>&rank){
        int parent_x = find(x,parent);
        int parent_y = find(y,parent);
        if(parent_x == parent_y){
            return;
        }
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
        return;
    }
   
    int largestIsland(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<int>rank(n*m+1,0);
       vector<int>parent;
       for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
           int temp = i*m + j;
           parent.push_back(temp);
        }
       }
       queue<pair<int,int>>q;
       for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 1){
                q.push({i,j});
            }
        }
       }
       while(!q.empty()){
          int row = q.front().first;
          int col = q.front().second;
          q.pop();
          int drow[] = {-1,0,0,1};
          int dcol[] = {0,1,-1,0};
          for(int i = 0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow >= 0 && ncol >=0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
                int temp = nrow*m + ncol;
                int temp2 = row*m + col;
                int parent_x = find(temp,parent);
                int parent_y = find(temp2,parent);
                if(parent_x != parent_y){
                    Union(temp,temp2,parent,rank);
                }
            }
          }
        }
        int ans  = 0;
        unordered_map<int,int>mpp;
        for(int i = 0;i<n*m;i++){
            int parent_x = find(i,parent);
            mpp[parent_x]++;
            ans = max(mpp[parent_x],ans);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0){
                   int drow[] = {-1,0,0,1};
                   int dcol[] = {0,1,-1,0};
                   unordered_set<int> unique_parents;
                   for(int t = 0;t<4;t++){
                    if(i+drow[t] < 0 || j+dcol[t] <0 || i+drow[t] >= n || j + dcol[t] >=m){
                        continue;
                    }
                    if(grid[i+drow[t]][j+dcol[t]] == 0){
                        continue;
                    }
                    int temp = (i+drow[t])*m+(j+dcol[t]);
                    int parent_x = find(temp,parent);
                    ans = max(ans,1+mpp[parent_x]);
                    unique_parents.insert(parent_x);
                   }
                   int current = 0;
                   for(auto it:unique_parents){
                     current = current + mpp[it];
                   }
                   ans = max(current+1,ans);
                }
            }
        }
        return ans;
    }
};