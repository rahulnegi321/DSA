class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : edges){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],2*it[2]});
        }
        vector<int>dis(n,INT_MAX);
        dis[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        while(q.size()){
            int curr = q.top().first;
            int node = q.top().second;
            q.pop();
            if(dis[node] < curr){
                continue;
            }
            if(node == n-1){
                return curr;
            }
            for(auto it : adj[node]){
                if(dis[it.first] > curr + it.second){
                    dis[it.first] = curr + it.second;
                    q.push({dis[it.first],it.first});
                }
            }
        }
        return -1;
    }
};