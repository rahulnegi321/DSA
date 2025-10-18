class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i<points.size();i++){
            for(int j = i+1;j<points.size();j++){
                int distance = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,distance});
                adj[j].push_back({i,distance});
            }
        }
        priority_queue<pair<int,int>>q;
        vector<int>vis(n,0);
        int ans = 0;
        q.push({0,0});
        while(!q.empty()){
            int dist = -q.top().first;
            int node = q.top().second;
            q.pop();
            if(vis[node]){
                continue;
            }
            ans = ans + dist;
            vis[node] = 1;
            for(auto it : adj[node]){
                int dis = it.second;
                int temp = it.first;
                if(!vis[temp]){
                    q.push({-dis,temp});
                }
            }
        }
        return ans;
    }
};