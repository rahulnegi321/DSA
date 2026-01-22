class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,src}});
       
        map<int,map<int,int>>vis;
         vis[src][0] = 0;
        int ans = -1;
        while(q.size()){
            int curr = q.top().first;
            int count = q.top().second.first;
            int node = q.top().second.second;
            q.pop();
            if(curr > vis[node][count]){
                continue;
            }
            if(count > k+1){
                continue;
            }
            if(node == dst && count <= k+1){
               return curr;
            }
            for(auto it : adj[node]){
                int temp = it.first;
                int dis = it.second;
                if(temp != src){
                    if(!vis.count(temp)){
                        vis[temp][count+1] = curr+dis;
                        q.push({curr+dis,{count+1,temp}});
                    }
                    else{
                       if(vis[temp].count(count+1)){
                            if(curr+dis < vis[temp][count+1]){
                                vis[temp][count+1] = curr+dis;
                                bool need = true;
                                for(auto it : vis[temp]){
                                    if(it.first == count+1){
                                        break;
                                    }
                                    if(it.second <= curr+dis){
                                        need = false;
                                        break;
                                    }
                                }
                                if(!need){
                                    continue;
                                }
                                q.push({curr+dis,{count+1,temp}});
                            }
                        }
                        vis[temp][count+1] = curr+dis;
                        bool need = true;
                                for(auto it : vis[temp]){
                                    if(it.first == count+1){
                                        break;
                                    }
                                    if(it.second <= curr+dis){
                                        need = false;
                                        break;
                                    }
                                }
                                if(!need){
                                    continue;
                                }
                        q.push({vis[temp][count+1],{count+1,temp}});
                    }
                }
            }
        }
        return ans;
    }
};