class Solution {
public:
    int ans  = 0,K;
    vector<vector<int>>adj;
    
    long dfs(int node,int parent,vector<int>&values){
       long sum = values[node];
       for(auto it : adj[node]){
        if(it != parent){
            sum = sum + dfs(it,node,values);
        }
       }
       if(sum%K == 0){
        ans++;
       }
       return sum%K;
    }
    
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        K = k;
        adj.assign(n,{});
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,values);
        return ans;
    }
};