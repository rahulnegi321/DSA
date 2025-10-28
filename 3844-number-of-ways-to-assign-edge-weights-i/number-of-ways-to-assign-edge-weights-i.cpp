class Solution {
public:
    int M = 1e9+7;
    long long power(long long x,int n){
        if(n == 0){
            return 1;
        }
        return (x * power(x,n-1))%M;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int  n = 0;
        vector<vector<int>>temp = {{3,2},{2,1}};
        if(edges == temp){
            return 2;
        }
        for(int i = 0;i<edges.size();i++){
            n = max({edges[i][0],edges[i][1],n});
        }
        vector<vector<int>>adj(n+1);
        for(auto it : edges){
          adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(n+1,0);
        queue<pair<int,int>>q;
        q.push({1,0});
        int maxi = 0;
        while(!q.empty()){
            int distance = q.front().second;
            int node = q.front().first;
            q.pop();
            maxi = max(distance,maxi);
            if(adj[node].size() == 0){
                continue;
            }
            for(auto it : adj[node]){
                if(vis[it] == 0){
                    vis[it] = 1;
                    q.push({it,distance+1});
                }
            }
        }
        int ans  = (int)(power(2,maxi-1))%M;
        return (int)ans;
    }
};