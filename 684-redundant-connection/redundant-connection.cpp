class Solution {
public:
    int find(vector<int>&parents,int x){
        int parent_x = parents[x];
        if(x == parent_x){
            return x;
        }
        return parents[x] = find(parents,parents[x]);
    }
    void Union(int x,int y,vector<int>&parents,vector<int>&rank){
        int parent_x = find(parents,x);
        int parent_y = find(parents,y);
        if(parent_x == parent_y){
            return;
        }
        if(rank[parent_x] > rank[parent_y]){
            parents[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parents[parent_x] = parent_y;
        }
        else{
            parents[parent_x] = parent_y;
            rank[parent_y]++;
        }
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>parents;
        for(int i = 0;i<=n;i++){
            parents.push_back(i);
        }
        vector<int>ranks(n+1,0);
        vector<int>ans;
        for(auto it : edges){
          int parent_x = find(parents,it[0]);
          int parent_y = find(parents,it[1]);
          if(parent_x == parent_y){
            ans = {it[0],it[1]};
          }
          else{
            Union(it[0],it[1],parents,ranks);
          }
        }
        return ans;
    }
};