class Solution {
public:
     int find(int x,vector<int>&parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }
    void Union(int x,int y,vector<int>&rank,vector<int>&parent){
        int parent_x = find(x,parent);
        int parent_y = find(y,parent);
        if(parent_x == parent_y){
            return;
        }
        if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
        return;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>rank(n,0);
        vector<int>parent;
        for(int i = 0;i<n;i++){
            parent.push_back(i);
        }
        for(auto it : edges){
            int x = it[0];
            int y = it[1];
            Union(x,y,rank,parent);
        }
        
        unordered_map<int,int>mpp;
        for(int i = 0;i<n;i++){
           int x_parent = find(i,parent);
           mpp[x_parent]++;
        }
        long long ans = 0;
        int count = 0;
        set<int>st;
        for(int i = 0;i<n;i++){
            int x_parent = find(i,parent);
            if(st.empty() || !st.count(x_parent)){
              ans = ans + 1LL*mpp[x_parent]*1LL*(n-count-mpp[x_parent]);
              count = count + mpp[x_parent];
              st.insert(x_parent);
            }
        }
        return ans;
    }
};