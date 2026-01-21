class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int ans = 0;
        dis[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        while(q.size()){
          int curr = q.top().first;
          int node = q.top().second;
          q.pop();
          if(curr > dis[node]){
            continue;
          }
          ans = max(ans,curr);
          for(auto it : adj[node]){
             int temp = it.first;
             int val = it.second;
             if(dis[temp] > curr + val){
                dis[temp] = curr + val;
                q.push({curr+val,temp});
             }
          }
        }
        for(int i = 1;i<=n;i++){
            if(dis[i] == 1e9){
                return -1;
            }
        }
        return ans;
    }
};