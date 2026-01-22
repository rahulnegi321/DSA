class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights[0].size();
        vector<vector<pair<int,int>>>adj(n);
        vector<bool>vis(n,false);
        int maxflights = k+1;
        vector<vector<int>>dis(n,vector<int>(maxflights+1,INT_MAX));
        dis[src][0] =0;
       for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
       }
       priority_queue<pair<int,pair<int,int>>>q;
       q.push({0,{src,0}});
       while(!q.empty()){
        int distance = -q.top().first;
        int node = q.top().second.first;
        int count = q.top().second.second;
        q.pop();
        if(node == dst){
            return distance;
        }
        if(count == maxflights){
            continue;
        }
       
        for(auto it : adj[node]){
          int b = it.first;
          int w = it.second;
          if(distance + w < dis[b][count+1]){
            dis[b][count+1] = distance+w;
            q.push({-dis[b][count+1],{b,count+1}});
          }
        }
       }
       return -1;
    }
};