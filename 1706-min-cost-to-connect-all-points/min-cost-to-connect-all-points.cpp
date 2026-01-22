class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0;i<points.size();i++){
            for(int j = 0;j<points.size();j++){
                if(i == j){
                   continue;
                }
                int r1 = points[i][0];
                int c1 = points[i][1];
                int r2 = points[j][0];
                int c2 = points[j][1];
                int dist = abs(r1 - r2) + abs(c1 - c2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int count = n;
        q.push({0,0});
        vector<int>vis(n,0);
        int ans = 0;
        while(q.size()){
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();
            if(vis[node]){
                continue;
            }
            vis[node] = 1;
            count--;
            ans += dist;
            if(count == 0){
                break;
            }
            for(auto it : adj[node]){
                if(vis[it.first] == 0){
                    q.push({it.second,it.first});
                }
            }
        }
        return ans;
    }
};